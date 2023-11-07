clc;

t = 200;
n = 2;

% Assuming you've extracted these values from your Simulink simulation
y_t = out.y;
y_t_1 = out.y1;
u_t_2 = out.u2;

% Construct the phi matrix
phi = [-y_t_1, u_t_2];

% Calculate Theta using least squares
Theta = inv(phi'*phi)*phi'*y_t;

% Calculate residuals
E = y_t - phi*Theta;

% Calculate residual variance
Variance = (E'*E)/(t-n);

% Calculate standard deviation
Standard_deviation = sqrt(Variance);

% 95% Confidence intervals for a
a_min = Theta(1) - 2*Standard_deviation;
a_max = Theta(1) + 2*Standard_deviation;

% 95% Confidence intervals for b
b_min = Theta(2) - 2*Standard_deviation;
b_max = Theta(2) + 2*Standard_deviation;

% Print results
fprintf("The value of element a = %f where a_max= %f and a_min= %f \n", Theta(1), a_max, a_min);
fprintf("The value of element b = %f where b_max= %f and b_min= %f \n", Theta(2), b_max, b_min);
