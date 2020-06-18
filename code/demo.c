/* An implementation of the Particle Swarm Optimization algorithm

   === DEMONSTRATION CODE ===

   Copyright 2010 Kyriakos Kentzoglanakis

   This program is free software: you can redistribute it and/or
   modify it under the terms of the GNU General Public License version
   3 as published by the Free Software Foundation.

   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see
   <http://www.gnu.org/licenses/>.
*/


#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h> // for printf
#include "pso.h"

//define boolean for c
#ifndef BOOLEAN
#define BOOLEAN

typedef enum {true, false} boolean;

#endif

//==============================================================
//           Prameteres Of Mobile Edge Computing
//==============================================================

double Wu;
double Wd;
double d=10;
double h1=0.99;
double h2=0.99;
double N0;
double P0=0.4;
double kt=18;
double Pr=0.4;
double PF=0.1;
double Ptmax=0.1;
double fc;
double fImax;
double K;
double alpha=40;
double I=10*1024*1024*8;
double v=4;
double Lmax=4.5;
double beta1=1;
double beta2=0.2;
double F;
double Ru;
double Rd;

void initiate(){
    Wu = pow(10,7);
    //printf("Wu:%lf\n",Wu);
    Wd = pow(10,7);
    //printf("Wd:%lf\n",Wd);
    N0 = 174*pow(10,-13);
    //printf("N0:%lf\n",N0);
    fc = 8*pow(10,8);
    //printf("fc:%lf\n",fc);
    fImax = 4*pow(10,8);
    //printf("fImax:%lf\n",fImax);
    K = pow(10,-26);
    F = 6*pow(10,9);
    Rd = Wd*((log(1+PF*pow(d,-v)*pow(fabs(h2),2)/N0))/log(2));
    //printf("Rd:%lf\n",Rd);
}

//==============================================================
//                  BENCHMARK FUNCTIONS
//==============================================================

double pso_sphere(double *vec, int dim, void *params) {

    double sum = 0;
    int i;
    for (i=0; i<dim; i++)
        sum += pow(vec[i], 2);

    return sum;
}



double pso_rosenbrock(double *vec, int dim, void *params) {

    double sum = 0;
    int i;
    for (i=0; i<dim-1; i++)
        sum += 100 * pow((vec[i+1] - pow(vec[i], 2)), 2) +	\
            pow((1 - vec[i]), 2);

    return sum;

}


double pso_griewank(double *vec, int dim, void *params) {

    double sum = 0.;
    double prod = 1.;
    int i;
    for (i=0; i<dim;i++) {
        sum += pow(vec[i], 2);
        prod *= cos(vec[i] / sqrt(i+1));
    }

    return sum / 4000 - prod + 1;

}

//==============================================================
//              Consuption Functions about Energe
//==============================================================

//公式4 约束条件
int L(double *pos)
{
	double tl,tc,tu,td,tlc;
	double fl=pos[0];
    double Pt=pos[1];
    double lamda=pos[2];
    double Ru=Wu*((log(1+(Pt*pow(d,-v)*pow(fabs(h2),2))/N0))/log(2));
    
	tl = alpha*lamda*I/fl;
    tu = beta1*(1 - lamda)*I/Ru;
	td = beta2*(1 - lamda)*I/Rd;
	tlc = alpha*(1 - lamda)*I/fc;
	tc = tu + td + tlc;
    printf("tl: %.6f\ntc: %.6f\n", tl, tc);
	if (tl <= Lmax && tc <= Lmax)
		return 1;
	else
		return 0;
}

//公式11 约束条件
int f(double *pos)
{
    double lamda=pos[2];
    double f=I*(1-lamda)*alpha;
    printf("f: %.6f\n", f);
	if (f <= F)
		return 1;
	else
		return 0;
}

//耗能方程
double pso_E(double *vec, int dim, void *params) {

    double fl=vec[0];
    double Pt=vec[1];
    double lamda=vec[2];
    double Ru=Wu*((log(1+Pt*pow(d,-v)*pow(fabs(h2),2)/N0))/log(2));
    double E = alpha*I*K*lamda*pow(fl,2)+(P0+kt*Pt)*(beta1*(1-lamda)*I)/Ru+Pr*beta2*(1-lamda)/Rd;

    //printf("fl:%.2f\tPt:%.2f\tlambada:%.2f\n",vec[0],vec[1],vec[2]);
    //printf("E is %lf\n",E);
    return E;
}

//==============================================================

// int main(int argc, char **argv) {

//     pso_settings_t *settings = NULL;
//     pso_obj_fun_t obj_fun = NULL;

//     // parse command line argument (function name)
//     if (argc == 2) {
//         if (strcmp(argv[1], "rosenbrock") == 0) {
//             obj_fun = pso_rosenbrock;
//             settings = pso_settings_new(30, -2.048, 2.048);
//             printf("Optimizing function: rosenbrock (dim=%d, swarm size=%d)\n",
//                    settings->dim, settings->size);
//         } else if (strcmp(argv[1], "griewank") == 0) {
//             obj_fun = pso_griewank;
//             settings = pso_settings_new(30, -600, 600);
//             printf("Optimizing function: griewank (dim=%d, swarm size=%d)\n",
//                    settings->dim, settings->size);
//         } else if (strcmp(argv[1], "sphere") == 0) {
//             obj_fun = pso_sphere;
//             settings = pso_settings_new(30, -100, 100);
//             printf("Optimizing function: sphere (dim=%d, swarm size=%d)\n",
//                    settings->dim, settings->size);
//         } else {
//             printf("Unsupported objective function: %s", argv[1]);
//             return 1;
//         }
//     } else if (argc > 2) {
//         printf("Usage: demo [PROBLEM], where problem is optional with values [sphere|rosenbrock|griewank]\n ");
//         return 1;
//     }

//     // handle the default case (no argument given)
//     if (obj_fun == NULL || settings == NULL) {
//         obj_fun = pso_sphere;
//         settings = pso_settings_new(30, -100, 100);
//         printf("Optimizing function: sphere (dim=%d, swarm size=%d)\n",
//                    settings->dim, settings->size);
//     }

//     // set some general PSO settings
//     settings->goal = 1e-5;
//     settings->size = 30;
//     settings->nhood_strategy = PSO_NHOOD_RING;
//     settings->nhood_size = 10;
//     settings->w_strategy = PSO_W_LIN_DEC;

//     // initialize GBEST solution
//     pso_result_t solution;
//     // allocate memory for the best position buffer
//     solution.gbest = (double *)malloc(settings->dim * sizeof(double));

//     // run optimization algorithm
//     pso_solve(obj_fun, NULL, &solution, settings);

//     // free the gbest buffer
//     free(solution.gbest);

//     // free the settings
//     pso_settings_free(settings);

//     return 0;

// }

int main( int argc, char** argv){

    pso_settings_t *settings = NULL;
    pso_obj_fun_t obj_fun = NULL;

    //定义两个判断函数 L f
    pso_obj_judge obj_L = NULL;
    pso_obj_judge obj_f = NULL;

    initiate();//初始化变量

    obj_fun = pso_E;//定义被优化函数为耗能函数
    
    obj_L = L;//提供约束函数
    obj_f = f;

    double range_lo[3] = {0, 0, 0};
    double range_hi[3] = {fImax, Ptmax, 1};//先设置为很小的值 fl Pt lambada

    settings = pso_settings_new(3, range_lo, range_hi);//dim: 3 
    printf("Optimizing function: sphere (dim=%d, swarm size=%d)\n", settings->dim, settings->size);

    // set some general PSO settings
    settings->goal = 1e-5;
    settings->size = 30;    //swarm size: 30
    settings->nhood_strategy = PSO_NHOOD_GLOBAL;  //using global topology
    settings->nhood_size = 10;  //choose 10 neighbors
    settings->w_strategy = PSO_W_LIN_DEC;

    printf("====Setting part accomplishes====\n\n");

    // initialize GBEST solution
    pso_result_t solution;
    // allocate memory for the best position buffer
    solution.gbest = (double *)malloc(settings->dim * sizeof(double));

    printf("====Initializing part accomplishes====\n\n");

    // run optimization algorithm
    pso_solve(obj_fun, NULL, &solution, settings, L, f);

    // free the gbest buffer
    free(solution.gbest);

    // free the settings
    pso_settings_free(settings);
    return 0;
}
