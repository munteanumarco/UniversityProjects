%Nickel powders are used in coatings used to shield electronic equipment. A random sample
%is selected, and the sizes of nickel particles in each coating are recorded (they are assumed
%to be approximately normally distributed):
%3.26, 1.89, 2.42, 2.03, 3.07, 2.95, 1.39, 3.06, 2.46, 3.35, 1.56, 1.79, 1.76, 3.82, 2.42, 2.96
%a) Find a 95% confidence interval for the average size of nickel particles.
%b) At the 1% significance level, on average, do these nickel particles seem to be smaller
%than 3?

%alpha = input('Significance level = ');
x = [3.26 1.89 2.42 2.03 3.07 2.95 1.39 3.06 2.46 3.35 1.56 1.79 1.76 3.82 2.42 2.96];
n = columns(x);

%a)
confidence = input('Confidence interval = ');
alpha = 1-confidence;

m1=mean(x)-std(x)/sqrt(length(x))*tinv(1-alpha/2,length(x)-1);
m2=mean(x)+std(x)/sqrt(length(x))*tinv(1-alpha/2,length(x)-1);


fprintf("The interval is (%f, %f)\n", m1, m2)

%b)
alpha=0.1
m0 = 3;
[H, P, CI, stat] = ttest(x, m0, "alpha",alpha,"tail","left");
%H is the rejection of the null hypothesis, P is the P-value, CI is the Confidence interval, zstat is the value of the test statistic
if H == 0
	fprintf("The null hypothesis is not rejected, the particles seem to be larger than 3\n")
else
	fprintf("The null hypothesis is rejected, the particles seem to be smaller than 3\n")
end



