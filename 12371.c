#include <stdio.h>
#include <string.h>
int main(){

    char s[1001],p[1001];

    while(scanf("%s%s",&s,&p)!=EOF)
    {
        int num,slen,plen;
        scanf("%d",&num);
        slen=strlen(s);
        plen=strlen(p);



        int prefix[slen+1],counter=0;

        for(int i=0;i<=slen;i++)
            prefix[i]=0;

        for(int i=0;i<slen;i++)
        {

            if(strncmp(&s[i],p,plen)==0)
            {

                counter++;
                for(int j=i;j<i+plen;j++)
                    prefix[j+1]=counter;


                //i=i+plen-1;
            }
            else prefix[i+1]=counter;///***//
        }

        //prefix[0]=1;
        //for(int i=0;i<=slen;i++)
          //printf("%d",prefix[i]);
        //for(int i=0;i<slen)
        int max=0;
        for(int i=1;i<=num;i++)
        {
            int L,R;
            scanf("%d%d",&L,&R);

            //R=R-plen+1;

            int tmp;

            if(R-L+1>=plen)
                tmp=prefix[R-plen+1] - prefix[L-1];
            else
                tmp=0;
           // printf("%d ",tmp);

            if(tmp>max)
                max=tmp;

        }
        printf("%d\n",max);

    }

}
