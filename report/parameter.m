%常量定义
Wu = 10e6;
Wd = 10e6;
d=10;
h1=0.99;
h2=0.99;
N0=174e-13;
P0=0.4;
kt=18;
Pr=0.4;
PF=0.1;
Ptmax=0.1;
fc=8e8;
fImax=4e8;
K=1e-26;
alpha=40;
I=5*1024*1024*8;
v=4;
Lmax=4.5;
beta1=1;
beta2=0.2;
F=6e9;
Rd=Wd*(log2(1+PF*power(d,-v)*power(abs(h2),2)/N0));
%自变量定义
lambada = 0.5;
Pt = 0.05;
f1 = 2e8;
% 因变量定义
tlc = 0.0;
tc = 0.0;
%计算
tL = cal_tL(alpha,lambada,I,f1);
Ru = cal_Ru(Pt,Wd,d,v,h1,N0);
tu = cal_tu(beta1,lambada,I,Ru);
td = cal_td(beta2,lambada,I,Rd);
energe = cal_E(alpha,I,K,lambada,f1,P0,kt,Pt,tu,Pr,td);
%函数定义
function [tL] = cal_tL(alpha,lambada,I,f1)
tL = alpha*lambada*I/f1;
end

function [Ru] = cal_Ru(Pt,Wd,d,v,h1,N0)
Ru = Wd*(log2(1+Pt*power(d,-v)*power(abs(h1),2)/N0));
end

function [tu] = cal_tu(beta1,lambada,I,Ru)
tu = beta1*(1 - lambada)*I/Ru;
end

function [td] = cal_td(beta2,lambada,I,Rd)
td = beta2*(1 - lambada)*I/Rd;
end

function [energe] = cal_E(alpha,I,K,lamda,f1,P0,kt,Pt,tu,Pr,td)
energe = alpha*I*K*lamda*power(f1,2)+(P0+kt*Pt)*tu+Pr*td;
end
