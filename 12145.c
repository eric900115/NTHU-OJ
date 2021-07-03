#include <stdio.h>
#include <string.h>


int main(){


    int num;
    scanf("%d\n",&num);


    if(num>1&&num<=26){
        /*char arr[num+1];
        scanf("%s",&arr);*/
        int length[26]={0};
        int flag=-1;
        char ch;
        int k;

        for(int i=0;i<num;i++){

            scanf("%c",&ch);
            //int k=(int)arr[i]-97;
            k=(int)ch-97;
            length[k]++;
            //printf("%d %c %d %d",num,ch,k,length[k]);
            if(length[k]>=2)
            {
                flag=1;
                printf("I'm the god of Knuckles!\n");
                break;
            }
        }

        /*for(int i=0;i<26;i++)
        {
            //printf("%d aavd\1",length[i]);

        }*/

        if(flag==-1)
            printf("Different makes perfect\n");

    }
    else
        {printf("I'm the god of Knuckles!\n");
        }
        return 0;
}
