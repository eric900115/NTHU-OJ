#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){

    long long int *prefix=new long long int[1000003];
    char str[10];
    prefix[0]=0;
    for(int i=1;i<=1000000;i++){
        //cout<<1;
        sprintf(str,"%d",i);//**//

        int counter=0;
        for(int j=0;str[j]!='\0';j++){
            if(str[j]=='1')counter++;
        }
        prefix[i]=prefix[i-1]+counter;
    }

    int t;
    scanf("%d",&t);

    while(t--){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%lld\n",prefix[b]-prefix[a-1]);
    }
}
