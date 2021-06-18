#include <stdio.h>


typedef struct Matrix{

    long long int m[2][2];

}matrix;


matrix mul(matrix C,long long int i)
{

    //printf("%lld\n",i);
    long long int p=1000000007;
    //matrix B,C;
    //B=A;
    //printf("%d\n",i);
    if(i==0)
    {
        matrix tmp,tmp1;
        tmp.m[0][0]=1;
        tmp.m[0][1]=0;
        tmp.m[1][0]=0;
        tmp.m[1][1]=1;
        //printf("c=%lld %lld %lld %lld\n",C.m[0][0],C.m[0][1],C.m[1][0],C.m[1][1]);
        return tmp;
    }
    else if(i%2==0)
    {
        matrix tmp,tmp1;
        tmp=mul(C,i/2);


        tmp1.m[0][0]=((tmp.m[0][0]*tmp.m[0][0])%p+(tmp.m[0][1]*tmp.m[1][0])%p)%p;
        tmp1.m[0][1]=((tmp.m[0][0]*tmp.m[0][1])%p+(tmp.m[0][1]*tmp.m[1][1])%p)%p;
        tmp1.m[1][0]=((tmp.m[1][0]*tmp.m[0][0])%p+(tmp.m[1][1]*tmp.m[1][0])%p)%p;
        tmp1.m[1][1]=((tmp.m[1][0]*tmp.m[0][1])%p+(tmp.m[1][1]*tmp.m[1][1])%p)%p;
        //printf("c=%lld %lld %lld %lld\n",C.m[0][0],C.m[0][1],C.m[1][0],C.m[1][1]);
        //printf("a=%lld %lld %lld %lld %lld\n",i,tmp1.m[0][0],tmp1.m[0][1],tmp1.m[1][0],tmp1.m[1][1]);
        return (tmp1);
    }
    else{
        matrix tmp,tmp1,tmp2;
        tmp=mul(C,i/2);


        tmp1.m[0][0]=((tmp.m[0][0]*tmp.m[0][0])%p+(tmp.m[0][1]*tmp.m[1][0])%p)%p;
        tmp1.m[0][1]=((tmp.m[0][0]*tmp.m[0][1])%p+(tmp.m[0][1]*tmp.m[1][1])%p)%p;
        tmp1.m[1][0]=((tmp.m[1][0]*tmp.m[0][0])%p+(tmp.m[1][1]*tmp.m[1][0])%p)%p;
        tmp1.m[1][1]=((tmp.m[1][0]*tmp.m[0][1])%p+(tmp.m[1][1]*tmp.m[1][1])%p)%p;
//printf("S=%lld %lld %lld %lld %lld\n",i,tmp1.m[0][0],tmp1.m[0][1],tmp1.m[1][0],tmp1.m[1][1]);
//printf("S=%lld %lld %lld %lld %lld\n",i,C.m[0][0],C.m[0][1],C.m[1][0],C.m[1][1]);
        tmp2.m[0][0]=((tmp1.m[0][0]*C.m[0][0])%p+(tmp1.m[0][1]*C.m[1][0])%p)%p;
        tmp2.m[0][1]=((tmp1.m[0][0]*C.m[0][1])%p+(tmp1.m[0][1]*C.m[1][1])%p)%p;
        tmp2.m[1][0]=((tmp1.m[1][0]*C.m[0][0])%p+(tmp1.m[1][1]*C.m[1][0])%p)%p;
        tmp2.m[1][1]=((tmp1.m[1][0]*C.m[0][1])%p+(tmp1.m[1][1]*C.m[1][1])%p)%p;
        //printf("c=%lld %lld %lld %lld\n",C.m[0][0],C.m[0][1],C.m[1][0],C.m[1][1]);
     //   printf("S=%lld %lld %lld %lld %lld\n",i,tmp2.m[0][0],tmp2.m[0][1],tmp2.m[1][0],tmp2.m[1][1]);
        return (tmp2);
    }

}

int main(){

    matrix A,B;
    long long int n;

    while(scanf("%lld",&n)!=EOF)
    {
        A.m[0][0]=1;
        A.m[0][1]=1;
        A.m[1][0]=1;
        A.m[1][1]=0;

        if(n>=2)
        {

            B=mul(A,n-1);
            //printf("A=%lld %lld %lld %lld\n",A.m[0][0],A.m[0][1],A.m[1][0],A.m[1][1]);
            /*if(n%2!=0)
            {
                long long int p=1000000007;
                matrix tmp,tmp1;
                tmp.m[0][0]=0;
                tmp.m[0][1]=1;
                tmp.m[1][0]=1;
                tmp.m[1][1]=-1;

                tmp1.m[0][0]=((tmp.m[0][0]*B.m[0][0])%p+(tmp.m[0][1]*B.m[1][0])%p)%p;
                tmp1.m[0][1]=((tmp.m[0][0]*B.m[0][1])%p+(tmp.m[0][1]*B.m[1][1])%p)%p;
                tmp1.m[1][0]=((tmp.m[1][0]*B.m[0][0])%p+(tmp.m[1][1]*B.m[1][0])%p)%p;
                tmp1.m[1][1]=((tmp.m[1][0]*B.m[0][1])%p+(tmp.m[1][1]*B.m[1][1])%p)%p;
                B=tmp1;
                    printf("%lld %lld %lld %lld\n",tmp1.m[0][0],tmp1.m[0][1],tmp1.m[1][0],tmp1.m[1][1]);
            }*/
            printf("%lld\n",B.m[0][0]*1+B.m[0][1]*0);
        }
       /* else if(n==3)
            printf("2\n");*/

        else if(n==1)
            printf("1\n");


    }



}
