#include <stdio.h>
#include <stdlib.h>
#define Max(a,b) (a>b ? a : b )
#define Min(a,b) (a<b ? a : b )

int n,q;
int guard[5002]={0};
int arr[5002][2]={0};

int cal(int s){

    int tmp[5002],full=0,prefix[5003]={0};
    for(int i=1;i<=n;i++) tmp[i]=guard[i];

    for(int i=arr[s][0];i<=arr[s][1];i++)
        tmp[i]--;

    for(int i=1;i<=n;i++)
        if(tmp[i]>0) full++;

    for(int i=1;i<=n;i++)///***//
        prefix[i]=prefix[i-1]+ ((tmp[i]==1) ? 1 : 0 );

    int t=5003;
   // printf("q=%d ",q);
    for(int i=0;i<q;i++){
        if(i==s) continue;
            t=Min(prefix[arr[i][1]]-prefix[arr[i][0]-1],t);
    }

    return full-t;

}

int main(){

    int t;
    scanf("%d",&t);

    while(t--){


        scanf("%d%d",&n,&q);

        for(int i=0;i<q;i++){
            scanf("%d%d",&arr[i][0],&arr[i][1]);

            for(int j=arr[i][0];j<=arr[i][1];j++)
                guard[j]++;
        }

        int tmp=0;
        for(int i=0;i<q;i++){
               // printf("%d ",q);
            tmp=Max(cal(i),tmp);
        }

        printf("%d\n",tmp);

        memset(guard,0,sizeof(guard));

    }

}
