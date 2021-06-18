#include <stdio.h>

int main()
{
    float x;

    while(scanf("%f",&x)!=EOF)
    {
        int y;
        if(x==0)
        {
            for(int c=1;c<=32;c++)
            {
                printf("0");
            }
            printf("\n");
            continue;
        }
        int flag=-1;
        if(x<0)
        {
            flag=0;
            x=-x;
        }
        float *a1=&x;
        int *a3=(int *)a1;



        /*float *a1=&x;
        void *a2=(void*)a1;
        int *a3=(int*)(a2);*/
        //printf("%d\n",*a3);
        y=*a3;

        int arr[32],i=-1,arr2[32];
        while(y!=0)
        {
            i++;
            arr[i]=y%2;
            y=y/2;
            //printf("%d ",y);
        }



        if(flag==0)
            printf("1");
        else printf("0");

        //printf("i=%d",i);
        int count=30-i;
        for(;count>0;count--)
            printf("0");
        for(;i>=0;i--)
        {
            printf("%d",arr[i]);
            //count++;
        }


    printf("\n");
    }

}

