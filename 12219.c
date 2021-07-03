#include <stdio.h>

long long int m;

long long int fpw(long long int x,long long int y)
{
    if(y==0) return 1%m;
    else if(y%2==0)
    {
        long long int tmp=fpw(x,y/2);
        return ((tmp%m)*(tmp%m))%m;
    }
    else
    {
        long long int tmp=fpw(x,y/2);
        return ((((tmp%m)*(tmp%m))%m)*(x%m))%m;
    }
}
/*
long long fpw(long long x,long long y)
{
    long long res=1;
    while(y!=0)
    {
        if(y%2==1) res=(res*x)%m;
        y/=2;
        x=(x*x)%m;
    }
    return res%m;
}*/

int main ()
{
    long long int a,b;
    scanf("%lld%lld%lld",&a,&b,&m);
    long long int r=fpw(a,b);
    printf("%lld\n",r);


}
