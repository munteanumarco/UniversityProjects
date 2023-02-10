clc
p=input('probability:(0.05-0.95)');

if (p<0.05 || p > 0.95)
    return;
end

for i=1:2:100
    mu=i*p;
    sq=sqrt(i*p*(1-p));
    k=0:1:i;
    n=normpdf(k,mu,sq);
    b=binopdf(k,i,p);
    plot(k,n,k,b);
    title("Aproximation of bino and norm for n="+i);
    legend('bino','norm');
    pause(0.5);
end;
