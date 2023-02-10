clear all;
clc;

p=input ('p=');
N=input('number of simulations=');
for i=1:N
    U=rand;
    x(i)= (U<p);
end
UX=unique (x);
NX=hist(x,length(UX));
[UX;NX/N];