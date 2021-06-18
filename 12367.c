#include <stdio.h>

int main(){
    int n,q;
    while(scanf("%d %d",&n,&q)!=EOF)
    {
        long long int sum[n+1];


        sum[0]=0;

        for(int i=1;i<=n;i++){
            sum[i]=0;
            scanf("%lld",&sum[i]);
            sum[i]+=sum[i-1];
            //printf("%lld ",sum[i]);
            }


        long long int max=0;
        int max1,max2;

        for(int i=0;i<q;i++)
        {
            int num1,num2;
            long long int tmp=0;

            scanf("%d%d",&num1,&num2);

            if(num1>num2)
                tmp=sum[num2]+sum[n]-sum[num1-1];

            else
                tmp=sum[num2]-sum[num1-1];


            if(tmp>max)
            {
                max=tmp;
                max1=num1;
                max2=num2;
            }

        }

        printf("Max_range: (%d,%d); Value: %lld\n",max1,max2,max);
    }
    return 0;
}
