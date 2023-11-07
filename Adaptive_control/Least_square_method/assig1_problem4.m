N = 1000; % Number of samples
a = 0.7; c = -0.5;
e = randn(N, 1); % White noise signal
y = zeros(N, 1);

for i = 2:N
    y(i) = a * y(i - 1) + c * e(i - 1) + e(i);
end

% RLS Initialization
P = 1000*eye(2); % Covariance matrix
a_hat = 0; c_hat = 0; % Initial estimates

a_estimates = zeros(N, 1);
c_estimates = zeros(N, 1);

for i = 2:N
    phi = [-y(i-1) e(i-1)]'; % Regressor vector
    k = P * phi / (1 + phi' * P * phi);
    e_estimate = y(i) - [a_hat c_hat] * phi;

    a_hat = a_hat + k(1) * e_estimate;
    c_hat = c_hat + k(2) * e_estimate;

    P = P - k * phi' * P;

    a_estimates(i) = a_hat;
    c_estimates(i) = c_hat;
end

% Plotting
figure;
subplot(2,1,1);
plot(a_estimates, 'b'); hold on;
plot(repmat(a, N, 1), 'r--'); % True value of a
legend('Estimated a', 'True a');
xlabel('Sample'); ylabel('Value');
title('Estimate vs True value of a');

subplot(2,1,2);
plot(c_estimates, 'b'); hold on;
plot(repmat(c, N, 1), 'r--'); % True value of c
legend('Estimated c', 'True c');
xlabel('Sample'); ylabel('Value');
title('Estimate vs True value of c');





% N = 1000; % Number of samples
% a = 0.7; c = -0.5;
% e = randn(N, 1); % white noise signal
% y = zeros(N, 1);
% 
% % System simulation
% for i = 2:N
%     y(i) = a * y(i - 1) + c * e(i - 1) + e(i);
% end
% 
% % ERLS Initialization
% P = 1000 * eye(2); % Covariance matrix initialization
% theta_hat = [0; 0]; % Initial parameter estimates
% 
% a_estimates = zeros(N, 1);
% c_estimates = zeros(N, 1);
% 
% for i = 2:N
%     phi = [y(i-1); e(i-1)]; % Regression vector
% 
%     K = (P * phi) / (1 + phi' * P * phi); % Kalman gain
%     e_estimate = y(i) - phi' * theta_hat;
%     theta_hat = theta_hat + K * e_estimate; % Parameter update
%     P = P - K * phi' * P; % Covariance matrix update
% 
%     a_estimates(i) = theta_hat(1);
%     c_estimates(i) = theta_hat(2);
% end
% 
% % Plotting results
% figure;
% subplot(2,1,1);
% plot(a_estimates, 'b'); hold on;
% plot(repmat(a, N, 1), 'r--');
% legend('Estimated a', 'True a');
% xlabel('Sample'); ylabel('Value');
% title('Estimate vs True value of a');
% 
% subplot(2,1,2);
% plot(c_estimates, 'b'); hold on;
% plot(repmat(c, N, 1), 'r--');
% legend('Estimated c', 'True c');
% xlabel('Sample'); ylabel('Value');
% title('Estimate vs True value of c');


% N = 1000; % Number of samples
% a = 0.7; c = -0.5;
% e = randn(N, 1); % white noise signal
% y = zeros(N, 1);
% 
% % System simulation
% for i = 2:N
%     y(i) = a * y(i - 1) + c * e(i - 1) + e(i);
% end
% 
% % RAML Initialization
% theta_hat = [0; 0]; % Initial parameter estimates
% H = 0.001 * eye(2); % Hessian matrix initialization
% 
% a_estimates = zeros(N, 1);
% c_estimates = zeros(N, 1);
% 
% for i = 2:N
%     phi = [y(i-1); e(i-1)]; % Regression vector
% 
%     e_estimate = y(i) - phi' * theta_hat; % Estimation error
%     g = e_estimate * phi; % Gradient
%     H = H + phi * phi'; % Hessian matrix update
%     theta_hat = theta_hat + inv(H) * g; % Parameter update
% 
%     a_estimates(i) = theta_hat(1);
%     c_estimates(i) = theta_hat(2);
% end
% 
% % Plotting results
% figure;
% subplot(2,1,1);
% plot(a_estimates, 'b'); hold on;
% plot(repmat(a, N, 1), 'r--');
% legend('Estimated a', 'True a');
% xlabel('Sample'); ylabel('Value');
% title('Estimate vs True value of a');
% 
% subplot(2,1,2);
% plot(c_estimates, 'b'); hold on;
% plot(repmat(c, N, 1), 'r--');
% legend('Estimated c', 'True c');
% xlabel('Sample'); ylabel('Value');
% title('Estimate vs True value of c');

