#include <stdio.h>

int main(){

    int n,q;
    scanf("%d%d",&n,&q);

    long long int prefix[n+1];
    //flag=0;
    prefix[0]=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&prefix[i]);
        if(prefix[i]<=0) prefix[i]=0;
        prefix[i]+=prefix[i-1];
    }


    int l,r,m;

    for(int i=1;i<=q;i++)
    {
        scanf("%d%d%d",&l,&r,&m);
        printf("%lld\n",prefix[l+m-1]-prefix[l-1]);

    }
}
