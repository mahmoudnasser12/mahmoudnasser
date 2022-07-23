%% Performance curve for induction motor Motoring 
%Torque speed and current curve 
clear
clc 
r1 = 0.641;                 % Stator Resistance (ohm)
x1 = 1.106;                 % Stator reactance (ohm)
r2 = 0.332;                 % Rotor Resistance (ohm)
x2 = 0.464;                 % Rotor reactance (ohm)
xm = 26.3;                  % magnetizing reactance (ohm)
v_ph = 460/ sqrt(3);        % phase voltage (voltage)
n_s = 1800;                 % sync speed (RPM)
w_s = 2*pi*n_s/60;          % sync speed (rad / s )

%--------------------------------------------------------------------------

s = 0 : 0.001 : 1;
n_m = (1-s) * n_s;

for i = 1 :1001
num = (3*(v_ph^2) * (r2/s(i))) ;
denum = (w_s * (r1 + (r2 / s(i))^2) + ((x1 + x2)^2));
T_d(i) = num / denum; %Developed toruqe 
T_L(i)= 80;             %load toruqe 
end

for i = 1 :1001
I(i) = v_ph / sqrt((r1+ (r2/s(i))^2)+ (x1 + x2)^2);
end

% i need to know the min difference between developed and load torque
o = find((abs(T_d-T_L)) == min(abs(T_d - T_L)))
rotor_speed = n_m (o)
slip = (n_s - n_m(o)) / n_s

Load_current = I(o)
u = find(s==1)
starting_current = I(u)
%--------------------------------------------------------------------------

subplot(2,1,1)
plot (n_m,T_d,'r--',n_m,T_L,'k')
title ({'induction motor performance curve '}, 'fontsize',15)
xlabel ('speed (RPM)', 'fontsize',15)
ylabel ('torque (N.M)','fontsize',15)
legend ('Torque - speed')
grid on

subplot(2,1,2)
plot (n_m,I,'r--')
title ({'induction motor performance curve '}, 'fontsize',15)
xlabel ('speed (RPM)', 'fontsize',15)
ylabel ('Current (A)','fontsize',15)
legend ('Current - speed')
grid on




