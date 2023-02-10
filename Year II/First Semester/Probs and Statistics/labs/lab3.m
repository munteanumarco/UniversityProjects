userInput=input('1.normal\n2.student\n3.chi2\n4.fischer\nPlease choose a model:','s');
alpha=input('Insert alpha:');
if (alpha <= 0 || alpha >= 1)
    fprintf('alpha must be in interval (0,1)');
    return;
end
beta=input('Insert beta:');
if (beta <= 0 || beta >= 1)
    fprintf('alpha must be in interval (0,1)');
    return;
end
switch userInput
    case 'normal'
        mu=input('Please insert mu:');
        sigma=input('Please insert sigma:');
        a1=normcdf(0,mu,sigma);
        a2=1-a1;
        b1=normcdf(1,mu,sigma)-normcdf(-1,mu,sigma);
        b2=1-b1;
        c=norminv(alpha, mu, sigma);
        d=norminv(1-beta, mu,sigma);

    case 'student'
        n=input('Please insert n:');
        a1=tcdf(0,n);
        a2=1-a1;
        b1=tcdf(1,n)-tcdf(-1,n);
        b2=1-b1;
        c=tinv(alpha, n);
        d=tinv(1-beta, n);
    case 'chi2'
        n=input('Please insert n:');
        a1=chi2cdf(0,n);
        a2=1-a1;
        b1=chi2cdf(1,n)-chi2cdf(-1,n);
        b2=1-b1;
        c=chi2inv(alpha, n);
        d=chi2inv(1-beta, n);
    case 'fischer'
        m=input('Please insert m:');
        n=input('Please insert n:');
        a1=fcdf(0,m,n);
        a2=1-a1;
        b1=fcdf(1,m,n)-fcdf(-1,m,n);
        b2=1-b1;
        c=finv(alpha, m, n);
        d=finv(1-beta, m,n);
    otherwise
        fprintf('Invalid option');
end

fprintf('P(X<=0) = %f\n', a1);
fprintf('P(X>=0) = %f\n', a2);
fprintf('P(-1<=X<=1) = %f\n', b1);
fprintf('P(X<=-1 or X>=1) = %f\n', b2);
fprintf('P(X< xalpha) = %f , xalpha = %f\n', alpha, c);
fprintf('P(X > xbeta) = %f, xbeta = %f\n', beta, d);