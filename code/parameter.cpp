#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
//����������pso.h 
double Wu=pow(10,7);
double Wd=10;
double d=10;
double h1=0.99;
double h2=0.99;
double N0=174*pow(10,-13);
double P0=0.4;
double kt=18;
double Pr=0.4;
double PF=0.1;
double Ptmax=0.1;
double fc=8*pow(10,8);
double fImax=4*pow(10,8);
double k=pow(10,-26);
double alpha=40;
double I=10*1024*1024*8;
double v=4;
double Lmax=4.5;
double beta1=1;
double beta2=0.2;
double F=6*pow(10,9);
double Ru=Wd*((log(1+(PF*pow(d,-v)*pow(abs(h2),2))/N0))/log(2));
double Rd=Wd*((log(1+(PF*pow(d,-v)*pow(abs(h2),2))/N0))/log(2));
//Լ������4 
bool L(double *pos)
{
	double tl,tc,tu,td,tlc;
	double fl=pos[0];
    double Pt=pos[1];
    double lamda=pos[2];
    double Ru=Wu*((log(1+(Pt*pow(d,-v)*pow(abs(h2),2))/N0))/log(2));;
    
	tl = alpha*lamda*I/fl;
    tu = beta1*(1 - lamda)*I/Ru;
	td = beta2*(1 - lamda)*I/Rd;
	tlc = alpha*(1 - lamda)*I/fc;
	tc = tu + td + tlc;
	if (tl <= Lmax && tc <= Lmax)
		return true;
	else
		return false;
}
//Լ������11 
bool f(double *pos)
{
    double lamda=pos[2];
    double f=I*(1-lamda)*alpha;
	if (f <= F)
		return true;
	else
		return false;
}
//���Ż����� 
double pso_E(double *vec, int dim, void *params) {

    double fl=vec[0];
    double Pt=vec[1];
    double lamda=vec[2];
    double Ru=Wu*((log(1+(Pt*pow(d,-v)*pow(abs(h2),2))/N0))/log(2));;
    double E = alpha*I*K*lamda*pow(fl,2)+(P0+kt*Pt)*(beta1*(1-lamda)*I)/Ru+Pr*beta2*(1-lamda)/Rd;

    return E;
}

int main(int argc, char *argv[])
{	
	printf("Hello, world\n");
	return 0;
}
