% Initialization
N = 500; % number of samples
a_true = 0.5;
b_true = 0.8;
y = zeros(N, 1);
e = sqrt(0.1) * randn(N, 1); % white noise with zero mean and 0.1 variance

for scenario = 1:5
    % Reinitialize for each case
    P = 10^10 * eye(2); % Initialize covariance matrix
    theta = [0; 1]; % Initialize parameter vector [a; b]
    a_est = zeros(N, 1);
    b_est = zeros(N, 1);
    y(1) = 0;
    u = zeros(N, 1);

    switch scenario
        case 1
            % u(t) = 0 is already initialized
        case 2
            %u = ones(N, 1);
            u = 0.5 * square(2*pi*(1:N)/25) + 0.5;
        case 3
            u = randn(N, 1);
        % Cases 4 and 5 will have u(t) updated inside the loop
    end

    % RLS Implementation
    for t = 2:N
        % For case 4: u(t) = 0.1y(t)
        if scenario == 4
            u(t) = 0.1 * y(t-1);
        end

        % For case 5: u(t) = 0.1*sign(y(t))
        if scenario == 5
            u(t) = 0.1 * sign(y(t-1));
        end

        % Vector phi represents the regressors
        phi = [y(t-1); u(t-1)];
        K = (P*phi) / (1 + phi'*P*phi);  
        y(t) = a_true*y(t-1) + b_true*u(t-1) + e(t);
        e_est = y(t) - theta'*phi;
        theta = theta + K*e_est;
        P = P - K*phi'*P;  
        a_est(t) = theta(1);
        b_est(t) = theta(2);
    end

    % Plotting
    figure(scenario);
    subplot(4,1,1);
    plot(y);
    title(['Output y(t) for Case ', num2str(scenario)]);

    subplot(4,1,2);
    plot(u);
    title(['Input u(t) for Case ', num2str(scenario)]);

    subplot(4,1,3);
    plot(a_est);
    hold on;
    plot(repmat(a_true, N, 1), 'r--'); 
    legend('Estimated a', ' a actual');
    title(['Estimated Parameters for Case ', num2str(scenario)]);


    subplot(4,1,4);
    plot(b_est);
    hold on;
    plot(repmat(b_true, N, 1), 'r--'); 
    legend('Estimated b', ' b actual');
    title(['Estimated Parameters for Case ', num2str(scenario)]);

    
end
