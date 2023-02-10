%2
%A manufacturer of gunpowder has developed a new powder which was tested in 12 shells. The resulting muzzle velocities in m/s are (they are assumed to be approximately normally distributed)

x=[1001.7,975.0,978.3,988.3,978.7,988.9,1000.3,979.2,968.9,983.5,999.2,985.6];
n=columns(x);
averageOfX = mean(x);

fprintf('\n Part a.\n')
%a)At a 5% significance level,does the data suggest that, on average, the muzzles are faster than 995m/s
printf("We have a left tailed test. Sigma is unknown\n");
alpha=0.05;
m0 = 995;

[H, P, CI, stat] = ttest(x, m0, "alpha",alpha,"tail","right")
%H is the rejection of the null hypothesis, P is the P-value, CI is the Confidence interval, stat is the value of the test statistic
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

%b) Find a 99% confidence interval for the standard deviation of the velocity of shells of thsi type
fprintf('\n Part b.\n')
%confidence = input("Confidence interval = ");
confidence=0.99
alpha = 1-confidence;

% we compute the standard deviation of the vector
standardDeviationOfX = std(x);

%We need the standard deviation of x. This gives us the variance so we need to sqrt to convert to standard deviation
o1 = (n-1)*standardDeviationOfX*standardDeviationOfX/chi2inv(1-alpha/2, n-1)
o2 = (n-1)*standardDeviationOfX*standardDeviationOfX/chi2inv(alpha/2, n-1)

s1 = sqrt(o1);
s2 = sqrt(o2);

fprintf("The interval is (%f, %f)\n", s1, s2)
