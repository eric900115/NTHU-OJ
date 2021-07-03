#include <stdio.h>

int main(){

    int m,n;
    scanf("%d%d",&m,&n);
    int min=1000000000;
    for(int i=0;i<m*n;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        if(tmp<min) min=tmp;
    }
    printf("%d\n",min);
}
