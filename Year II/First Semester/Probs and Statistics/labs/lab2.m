clc
n = input('Enter the number of trials:');
p = input('Enter the probability of success:');

pdf = binopdf([0:n], n, p);

m = [0:n; pdf]; % matrix for pdf

% plot the pdf
%plot([0:n], pdf, '*b')
%hold on
%axis([-0.1, 3.1, -0.1, 1.1])

%cdf = binocdf([0:0.01:n], n, p);
%plot([0:0.01:n], cdf, '--r');
%title("CDF and PDF graphs");
%legend("pdf", "cdf");
%hold off


c1 = binopdf(0, n, p);
fprintf('P(X=0) : %f ', c1);

c2 = 1 - binopdf(1,n,p);
fprintf('P(X!=1) : %f\n', c2);

d1 = binocdf(2, n, p);
fprintf('P(X<=2) : %f', d1);

d2 = binocdf(1, n, p);
fprintf('P(X<2) : %f\n', d2);

e1 = 1 - binocdf(0, n, p);
fprintf('P(X>=1) : %f',  e1);

e2 = 1 - binocdf(1, n, p);
fprintf('P(X > 1) : %f\n',  e2);

heads = 0;
for i=1:n
    c = rand();
    if c > 0.5
        fprintf('tail\n')
    else 
        heads = heads + 1;
        fprintf('head\n')
    end
end

fprintf('number of heads: %d\n', heads)
res = binopdf(heads, n, p);
fprintf('binopdf : %f\n', res)



