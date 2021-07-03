#include <stdio.h>

int search(int *arr,int l,int u,int x){
    int flag=0;
    while(l<=u){///*****//////
        int mid=(l+u)/2;
//printf("f=%d ",mid);
        if(arr[mid]==x){
            flag=mid+1;
            break;}
        else if(arr[mid]>x)
            u=mid-1;///*****////
        else l=mid+1;///*****/////
    }

    return flag;
}


int main(){

    int n,q;

    while(scanf("%d%d",&n,&q)!=EOF){
        int arr[n];
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);


        for(int i=1;i<=q;i++)
        {
            int num;
            scanf("%d",&num);

            int flag=search(arr,0,n-1,num);

            if(flag==0)
                printf("Break your bridge!\n");
            else printf("%d\n",flag);
        }

    }
}
