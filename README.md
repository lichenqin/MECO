# MECO

> This project is aimed to resolve optimization problem of Mobile Edge Computing by PSO optimization algorithm.

## File Structure

there are three directories in this project folder:

- code: contains source code for solving optimization problem

- paper: contains relative papers about optimization algorithm

- report: contains experiment results and paper of final project

## Experiment Record

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