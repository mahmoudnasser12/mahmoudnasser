clear
clc 

s = tf('s');

L = 400e-6;
c = 100e-6;
R = 10.6;

Vin = 340;

Gvd = (Vin/(L*c))*(1/(s^2 + s/(R*c) + 1/L*c));