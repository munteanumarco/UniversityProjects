clear all;
clc;
 
p=input('p=');
N=input('Number of simulations=');
n=input('Number of successes');
for i = 1 : N
    X(i)=0;
    j=0;
    U=rand;
    while j<n
        if U >=p
            X(i) = X(i)+1;
        else
            j=j+1;
        end
        U=rand;
    end
end
k=0:20;
U_X = unique(X);
n_X = hist(X, length(U_X)); 
rel_freq = n_X / N; 
[U_X; n_X; rel_freq];
plot(U_X,rel_freq,'o',0:max(U_X),nbinpdf(0:max(U_X),n,p),'*r');
legend('simulation','nbinpdf');