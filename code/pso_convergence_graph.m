figure(1);
plot(pso_d_100_L_45,'DisplayName','pso_d_100_L_45');hold on;plot(pso_d_10_L_45,'DisplayName','pso_d_10_L_45');plot(pso_d_20_L_45,'DisplayName','pso_d_20_L_45');plot(pso_d_30_L_45,'DisplayName','pso_d_30_L_45');plot(pso_d_40_L_45,'DisplayName','pso_d_40_L_45');plot(pso_d_50_L_45,'DisplayName','pso_d_50_L_45');plot(pso_d_60_L_45,'DisplayName','pso_d_60_L_45');plot(pso_d_70_L_45,'DisplayName','pso_d_70_L_45');plot(pso_d_80_L_45,'DisplayName','pso_d_80_L_45');plot(pso_d_90_L_45,'DisplayName','pso_d_90_L_45');
title('L=4.5ʱ�ڲ�ͬ��������µ��ƶ��˵��ܺ�����������');
xlabel('��������');
ylabel('�ܺ���');
legend('d=100','d=90','d=80','d=70','d=60','d=50','d=40','d=30','d=20','d=10');
hold on;
%%
figure(2);
plot(pso_d_60_L_35,'DisplayName','pso_d_60_L_35');hold on;plot(pso_d_60_L_40,'DisplayName','pso_d_60_L_40');plot(pso_d_60_L_45,'DisplayName','pso_d_60_L_45');
title('d=60ʱ�ڲ�ͬ�ӳ������µ��ƶ��˵��ܺ�����������');
xlabel('��������');
ylabel('�ܺ���');
legend('L=3.5','L=4.0','L=4.5');
hold on;
%%
figure(3);
plot(pso_d_10_L_35,'DisplayName','pso_d_10_L_35');hold on;plot(pso_d_10_L_40,'DisplayName','pso_d_10_L_40');plot(pso_d_10_L_45,'DisplayName','pso_d_10_L_45');
title('d=10ʱ�ڲ�ͬ�ӳ������µ��ƶ��˵��ܺ�����������');
xlabel('��������');
ylabel('�ܺ���');
legend('L=3.5','L=4.0','L=4.5');
hold on;
%%
figure(4);
plot(pso_d_60_L_45,'DisplayName','pso_d_60_L_45');hold on;plot(pso_d_60_L_45_random,'DisplayName','pso_d_60_L_45_random');plot(pso_d_60_L_45_ring,'DisplayName','pso_d_60_L_45_ring');
title('L=4.5,d=60ʱ�ڲ�ͬ����ͨ�ŷ�ʽ�µ��ƶ��˵��ܺ�����������');
xlabel('��������');
ylabel('�ܺ���');
legend('global','random','ring');
hold on;