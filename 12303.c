#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Node{
    int data;
    struct Node *next,*prev;
} node;

static int length=1;//***/

void insert (node *cur);
node* erase(node *cur,node *head);
node* move(node *cur);
void show(node *mhead);

int main(){
    int a,n,count;
    scanf("%d%d",&a,&n);

    node *head=(node *)malloc(sizeof(node));
    head->data=a;
    head->next=head->prev=head;
    node *cur=head;

    for(count=1;count<=n;count++)
    {
        char ch[15];
        scanf("%s",ch);//***/

        if(strcmp(ch,"insert")==0)
            insert(cur);
        else if(strcmp(ch,"erase")==0)
            head=erase(cur,head);
        else if(strcmp(ch,"move")==0)
            cur=move(cur);
        else if(strcmp(ch,"show")==0)
            show(cur);
    }

}

void insert (node *cur)
{
    int num,times;
    scanf("%d%d",&num,&times);

    for(int i=1;i<=times;i++)
    {
        node *np=(node*)malloc(sizeof(node));
        np->next=cur->next;
        np->prev=cur;
        (cur->next)->prev=np;
        cur->next=np;
        np->data=num;

    }
      length+=times;


}
node* erase(node *cur,node *head)
{
    int times;
    scanf("%d",&times);

    node *np,*np1;
    if(length>=times){
    for(int i=1;i<=times;i++)
    {

        np=cur->next;
        //printf("%d ",np->data);
        np1=np->next;
        if(np==head)
            head=np1;
        cur->next=np1;
        np1->prev=cur;
        free(np);

    }

    length-=times;}
    return head;
}
node* move(node *cur)
{
    int moves;
    scanf("%d",&moves);

    if(moves>0)
    {
        if(moves%length==0)//***/
            moves=length;
        else moves=moves%length;


        for(int c=1;c<=moves;c++)
            cur=cur->next;


    }
    else if(moves<0)
    {
        moves=abs(moves);

            if(moves%length==0)
                moves=length;
            else moves=moves%length;


        for(int c=1;c<=moves;c++)
            cur=cur->prev;
        //printf("m=%d data=%d",moves,cur->data);

    }
    //printf("%d",cur->data);
    return cur;
}
void show(node *cur)
{
    //node *cur=mhead;
    if(cur!=NULL)
    {
        if(cur->next==cur&&cur->prev==cur)
            printf("%d\n",cur->data);
        else
        {
            printf("%d ",cur->data);
            node *s=cur;
            cur=cur->next;

            while(cur!=s)
            {
                if(cur->next!=s)
                    printf("%d ",cur->data);
                else printf("%d",cur->data);
                cur=cur->next;
            }
            printf("\n");
        }
    }
}
