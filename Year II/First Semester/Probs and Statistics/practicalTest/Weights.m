%A food store owner receives 1-liter water bottle from 2 suppliers. After some complaints from customers, he wants to check the accurency of the weights of 1-liter bottles. He finds the following weights (the 2 populations are aproximately normally distributed):
%Weights:(Supplier A:1021,980,1017,988,1005,998,1014,985,995,1004,1030,1015,995,1023)(Supplier B:1070,970,993,1013,1006,1002,1014,997,1002,1010,975).
%a) At the 5% significance level, do the populations variances seem to differ?
%b) At the same significance level, on average, does Supplier A seem to be more reliable?
a=[1021,980,1017,988,1005,998,1014,985,995,1004,1030,1015,995,1023]
b=[1070,970,993,1013,1006,1002,1014,997,1002,1010,975]

%alpha=input('significance level alpha =');
alpha=0.05
%a)
fprintf('\n part a. Comparing variances\n')
[h,p,ci,stats]=vartest2(a,b, 'alpha',alpha,'tail','left')
if h == 0
    fprintf('Variances do not differ at %g significance level\n', alpha);
else
    fprintf('Variances differ at %g significance level\n', alpha);
end

%b)
 fprintf('\n part b. Comparing means when variances are equal\n')
[h,p] = ttest2(a,b, 'Vartype', 'unequal', 'Alpha', alpha)
if h == 0
    fprintf('Suppliers seem to be equally reliable at  at %g significance level\n', alpha);
else
    fprintf('Supplier A seem is more reliableat %g significance level\n', alpha);
end
