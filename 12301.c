#include <stdio.h>
#include <stdlib.h>
#include "function.h"

static int sum;

Node *createList(int n)
{
    sum=n;
    Node *head=(Node*)malloc(sizeof(Node));
    Node *pre=NULL;
    Node *np=head;
    head->number=1;

    for(int i=2;i<=n;i++)
    {
        pre=np;
        np=(Node*)malloc(sizeof(Node));

        pre->next=np;
        np->number=i;
    }
    np->next=head;
    return head;

}
void freeList(Node* head)
{
    free(head);
    sum--;
}
int solveJosephus(Node **head, int step)
{

    Node *cur,*pre;
    cur=*head;
    pre=cur->next;
    while(pre->next!=cur)
        pre=pre->next;

    while(sum>1)
    {
        int s1;

        if(step%sum==0)//****////
            s1=sum;
        else s1=step%sum;


        for(int i=1;i<s1;i++)
        {
            pre=cur;
            cur=cur->next;
        }
        pre->next=cur->next;
        free(cur);
        cur=pre->next;

        sum--;
    }


   *head=cur;
   return cur->number;
}
