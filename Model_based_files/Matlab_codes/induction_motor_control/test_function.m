%% Performance curve for induction motor 

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

s = -1 : 0.001 : 2;
n_m = (1-s) * n_s;

for i = 1 :3001
num = (3*(v_ph^2) * (r2/s(i))) ;
denum = (w_s * (r1 + (r2 / s(i))^2) + ((x1 + x2)^2));
T_d(i) = num / denum; %Developed toruqe 
end