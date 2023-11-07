% Taking inputs from the Simulink model
y_t = out.y;
y_t_1 = out.y1;
u_t_2 = out.u2;

t = length(y_t);

% Form the phi matrix for least squares estimation
phi = [-y_t_1(3:end), u_t_2(3:end)];

% Estimation of Parameters
Theta = inv(phi'*phi)*phi'*y_t(3:end);

% Calculation of Residual Error
E = y_t(3:end) - phi*Theta;

% Variance and Standard Deviation Calculation
Variance = (E'*E)/(t-2);
Standard_deviation = sqrt(Variance);

% 95% Confidence Intervals
a_min = Theta(1) - 2*Standard_deviation;
a_max = Theta(1) + 2*Standard_deviation;
b_min = Theta(2) - 2*Standard_deviation;
b_max = Theta(2) + 2*Standard_deviation;

% Display the Results
fprintf("Estimated a: %f (95%% CI: %f to %f)\n", Theta(1), a_min, a_max);
fprintf("Estimated b: %f (95%% CI: %f to %f)\n", Theta(2), b_min, b_max);

% Plot the actual vs. estimated values
figure;
subplot(2,1,1);
plot(1:t, y_t, 'b', 'LineWidth', 2);
title('Actual Output');
xlabel('Time');
ylabel('Output');

subplot(2,1,2);
plot([1,2], [Theta(1), Theta(2)], 'rx', 'MarkerSize', 10, 'LineWidth', 2);
title('Estimated Parameters');
xlabel('Parameters');
ylabel('Value');
xticks([1,2]);
xticklabels({'a', 'b'});
legend('Estimated');
