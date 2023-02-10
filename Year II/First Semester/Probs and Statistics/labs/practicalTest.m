clc
clear

x=[1001.7,975.0,978.3,988.3,978.7,988.9,1000.3,979.2,968.9,983.5,999.2,985.6];
n=length(x);

%a) Find a 95% confidence interval for the average of the velocity of shells of this type
fprintf('Subpoint a:\n')
confidence=0.95;
alpha = 1-confidence;

m1=mean(x)-std(x)/sqrt(n)*tinv(1-alpha/2,n-1);
m2=mean(x)+std(x)/sqrt(n)*tinv(1-alpha/2,n-1);


fprintf("The interval is (%f, %f)\n", m1, m2)


fprintf('\n Subpoint b:.\n')
%a)At a 1% significance level,does the data suggest that, on average, the
%muzzles are faster than 995m/s?
fprintf("We have a right tailed test. Sigma is unknown\n");
alpha=0.01;
m0 = 995;

[H, P, CI, stat] = ttest(x, m0, "alpha",alpha,"tail","right");
%H is the rejection of the null hypothesis
% P is the P-value
% CI is the Confidence interval
% stat is the value of the test statistic
if H == 0
	fprintf("The null hypothesis is accepted, the particles seem to be slower than 995\n")
else
	fprintf("The null hypothesis is rejected, the particles  seem to be faster than 995\n")
end

q = tinv(alpha, n - 1);

fprintf("\nThe rejection region is (%6.4f, %6.4f).\n", q, inf)
fprintf("The confidence interval is (%4.4f,%4.4f).\n", CI)
fprintf("The value of the test statistic is %6.4f.\n", stat.tstat)
fprintf("The P-value for the variances test is %6.4f.\n", P)




