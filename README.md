## MECO

> This project is aimed to resolve optimization problem of Mobile Edge Computing by PSO optimization algorithm.



#### File Structure

there are three directories in this project folder:

- code: contains source code for solving optimization problem
- paper: contains relative papers about optimization algorithm
- report: contains experiment results and paper of final project



#### PSO Algorithm

本次实验主要基于PSO粒子群算法进行相关优化。PSO( particle swarm optimization )的原理是通过观察鸟群与鱼群的运动，得到的相应群优化规律，并以此为基础发展出了粒子群优化算法。

粒子群的基础是个体，单个个体具有一个多维位置值，个体通过群策略在迭代过程中调整自身位置，最终通过多次迭代达到收敛，此收敛值变为抽象多维问题的较优解。

原始版本的PSO存在问题: 对c1 c2取固定值 导致容易陷入局部搜索中。本次实验采用惯性权重线性递减的PSO算法，这样可以解决范围搜索问题， 通过权重 ω 可以调节个体的三个部分经验所占比重，ω越小则群体越稳定，更偏向于局部搜索。同时还对c1 c2进行进一步限制，通过 constriction coefficients 对c1 c2进行约束，采用此种方式即可抛弃[-Vmax, Vmax]对速度的限制。


#### Experiment Record

**第一次实验**

**过程:** 设置三个变量的值在[0-1]之间	Swarm个体数为30	迭代500次	选择 global topology 

**结果:** 产生最小值为 10^380 次方 而且500次迭代后无明显变化

**结论:** 还需继续改进

**第二次实验**

**过程:** 设置三个变量 fl, Pt, lambada 范围分别为[0-fImax] [0-Ptmax] [0-1] 更改 abs() 为 fabs() 防止0值出现

**结果:** 产生最小值为0.0xxx 数据看起来较为工整，但由于约束函数未填入，所以还存在0值出现这种本不应出现

**结论:** 还需继续改进

**第三次实验**

**过程** 增加了约束函数 初始化粒子群处于正常范围内

**结果** 不会产生0值情况 在30个粒子 迭代500次的情况下 在200-300次间就已经收敛

**结论** 约束函数会导致多次重复计算 效率较差 仍须进一步改进

**第四次实验**

**过程** 增加了文件输出函数 可以定制 d 和 lmax 的值

**结果** 可以产生 result 文件

**结论** 约束函数 仍须进一步改进