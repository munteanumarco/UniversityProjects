clc
conf_level = input('confidence level=');
alpha = 1 - conf_level;
X = [7 7 4 5 9 9 4 12 8 1 8 7 3 13 2 1 17 7 12 5 6 2 1 13 14 10 2 4 9 11 3 5 12 6 10 7];
sigma = 5;
n = length(X);
 xbar = mean(X);
 
 q1 = norminv(alpha/2, 0, 1);
 q2 = norminv(1-alpha/2, 0, 1);
 
 ci1 = xbar - sigma/sqrt(n) * q2;
 ci2 = xbar - sigma/sqrt(n) * q1;
 
 fprintf('confidence interval for the population mean, miu, case sigma known is: (%3.3f, %3.3f)\n', ci1, ci2)
 
 s = std(X); % sigma unknown
 q3 = tinv(alpha/2, n - 1);
 q4 = tinv(1-alpha/2, n - 1);
 
 ci3 = xbar - s/sqrt(n) * q2;
 ci4 = xbar - s/sqrt(n) * q1;
 
 fprintf('Confidence interval for the population mean, miu, case sigma unknown is: (%3.3f, %3.3f)\n', ci3, ci4)
 
 ssq = var(X); % sample variance
 q5 = chi2inv(alpha/2, n-1);
 q6 = chi2inv(1-alpha/2, n-1);
 
 ci5 = (n-1)*ssq/q6;
 ci6 = (n-1)*ssq/q5;
 fprintf('Confidence interval for the population variance, sigma square: (%3.3f, %3.3f)\n', ci5, ci6)
 fprintf('Confidence interval for the population std dev, sigma square: (%3.3f, %3.3f)\n', sqrt(ci5), sqrt(ci6))
 

 clear;
conflevel = input('confidence level= '); % 1 - alpha
alpha = 1 - conflevel;
X1 = [22.4 21.7 24.5 23.4 21.6 23.3 22.4 21.6 24.8 20.0];
X2 = [17.7 14.8 19.6 19.6 12.1 14.8 15.4 12.6 14.0 12.2];
m1 = mean(X1);
m2 = mean(X2);
m = m1 - m2;
n1 = length(X1);
n2 = length(X2);
v1 = var(X1);
v2 = var(X2);

% a) sigma1 == sigma2
sp = sqrt(((n1-1)*v1 + (n2-1)*v2)/(n1+n2-2));
t1 = tinv(1 - alpha/2, n1+n2-2);
t2 = tinv(alpha/2, n1+n2-2); % t2 = -t1
ci1 = m - t1 * sp * sqrt(1/n1+1/n2);
ci2 = m - t2 * sp * sqrt(1/n1+1/n2);
fprintf('C.I. for the difference of means (sigma1 == sigma2): (%3.3f, %3.3f)\n', ci1, ci2);

c = (v1/n1) / (v1/n1 + v2/n2);
n = 1/(c^2/(n1-1) + (1-c)^2/(n2-1));
t1 = tinv(1 - alpha/2, n);
t2 = tinv(alpha/2, n); % t2 = -t1
ci1 = m - t1 * sqrt(v1/n1 + v2/n2);
ci2 = m - t2 * sqrt(v1/n1 + v2/n2);
fprintf('C.I. for the difference of means (sigma1 != sigma2): (%3.3f, %3.3f)\n', ci1, ci2);


f1 = finv(1 - alpha/2, n1-1, n2-1);
f2 = finv(alpha/2, n1-1, n2-1);
ci1 = 1/f1 * v1/v2;
ci2 = 1/f2 * v1/v2;
fprintf('C.I. for the ratio of variances: (%3.3f, %3.3f)\n', ci1, ci2);
fprintf('C.I. for the ratio of std. deviations: (%3.3f, %3.3f)\n', sqrt(ci1), sqrt(ci2));

 
