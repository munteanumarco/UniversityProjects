%Ex1-drive
%14 A study is conducted to compare heat loss in glass pipes, versus steel pipes of the same size. Various liquids at identical starting temperature are run through segments of each type and the heat loss in celsius degrees is measured. These data result (normality of the two populations is assumed)
%Heat loss:(Steel: 4.6,0.7,4.2,1.9,4.8,6.1,4.7,5.5,5.4)(Glass:2.5,1.3,2.0,1.8,2.7,3.2,3.0,3.5,3.4)
%a) At the 5% significance level, do the population variances seem to differ?
%b) At the same significance level,does it seem that on average, steel pipes lose more heat than glass pipes?

steel = [4.6, 0.7, 4.2, 1.9, 4.8, 6.1, 4.7, 5.5, 5.4];
glass = [2.5, 1.3, 2.0, 1.8, 2.7, 3.2, 3.0, 3.5, 3.4];


%alpha=input('significance level alpha =');
alpha=0.05
%a)
fprintf('\n part a. Comparing variances\n')
[h,p,ci,stats]=vartest2(steel,glass, 'alpha',alpha,'tail','left')
if h == 0
    fprintf('Variances do not differ at %g significance level\n', alpha);
else
    fprintf('Variances differ at %g significance level\n', alpha);
end

%b)
 fprintf('\n part b. Comparing means when variances are equal\n')
[h,p] = ttest2(steel , glass, 'Vartype', 'unequal', 'Alpha', alpha)
if h == 0
    fprintf('Heat loss is the same for steel and glass pipes at %g significance level\n', alpha);
else
    fprintf('Heat loss is higher in steel pipes at %g significance level\n', alpha);
end
