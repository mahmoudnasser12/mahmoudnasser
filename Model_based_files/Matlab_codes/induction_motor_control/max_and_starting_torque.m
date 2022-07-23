%% Finding max and starting torque 
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
end


%--------------------------------------------------------------------------
% @ starting slip = 1 and rotor speed = 0 
u = find (s==1);
starting_torque = T_d(u)
starting_Rotor_speed = n_m(u)

%--------------------------------------------------------------------------

plot (n_m,T_d,'r--')
title ({'induction motor performance curve '}, 'fontsize',15)
xlabel ('speed (RPM)', 'fontsize',15)
ylabel ('torque (N.M)','fontsize',15)
legend ('Torque - speed')
grid on


