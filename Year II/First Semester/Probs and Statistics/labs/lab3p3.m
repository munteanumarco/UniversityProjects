clc
n=input('Please insert n:');
if (n < 30) 
    return
end
p=input('Please insert the p:');
if (p > 0.05)
    return
end
k=0:1:n;
bk=binopdf(k,n,p);
lambda=n*p;
nk=poisspdf(k,lambda);
plot(k,bk, k, nk);
title('Aproximation of Poisson');