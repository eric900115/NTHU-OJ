#include <stdio.h>
#include <string.h>
#include <math.h>


typedef struct Data{
    int round;
    long long int result;
}data;


int cmp(void *a,void *b)
{
    data *pa=(data*)a;
    data *pb=(data*)b;
    if(pa->result!=pb->result)
        return (int)(pa->result - pb->result);
    else return (int)(pa->round - pb->round);
}

int binary(data a[],int l,int r,long long int x)
{
    int flag=-1;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(x<=a[mid].result)
            r=mid;
        else
            l=mid+1;
    }

    if(a[r].result==x)
        return a[r].round;
    else return -1;
}

long long int fpow(long long int a,int b)
{
    long long int ans=1;
    while(b){
        if(b&1) ans=((ans%1000000007)*(a%1000000007))%1000000007;
        a=((a%1000000007)*(a%1000000007))%1000000007;
        b=b>>1;
    }
    //printf("%lld \n",ans);
    return ans;
}

int main(){

    int n,q;
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        data s[n];
        int tmp;

        for(int i=0;i<n;i++)
        {
            scanf("%d(/`A`)/ ~I__I",&tmp);
            s[i].round=i+1;
            if(tmp%2==0)
                s[i].result=fpow(2,tmp/2);
            else s[i].result=0;
        }


        qsort(s,n,sizeof(data),cmp);


        for(int i=1;i<=q;i++)
        {

            long long int x;
            scanf("%lld",&x);

            int q=binary(s,0,n-1,x);

            if(q==-1)
                printf("Go Down Chicken 404\n");
            else
                printf("%d\n",q);
        }

    }

}
