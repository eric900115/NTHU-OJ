#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#define next ptr_to_next_node
#define prev ptr_to_prev_node
#define ch character

static int count=1;
Node *head, *tail;
void insert(Node**cur, char c)
{
    Node *np=(Node*)malloc(sizeof(Node));
    np->ch=c;
    np->next=(*cur)->next;
    (*cur)->next->prev=np;
    (*cur)->next=np;
    np->prev=(*cur);
    if(np->next==head)
        tail=np;

    count++;

}

void deletion(Node**mcur)
{

    Node *cur=*mcur;
    Node *np1;
    if(cur!=tail){

        if((cur->next)==tail)
            tail=cur;

        Node *np=cur->next;
        np1=np->next;
        cur->next=np1;
        np1->prev=cur;
        free(np);

        if(cur==head&&(cur->next)==tail)
            head->next = head->prev = head;

        count--;

    }

}

void backspace(Node**mcur)
{
    Node *cur=*mcur;

    Node *np=cur->prev;
    Node *np1=cur->next;

    if((cur!=head))//&&(cur->prev)!=head
    {
        if(cur==tail)
            tail=np;

        np1->prev=np;
        np->next=np1;
        free(cur);

        count--;
        *mcur=np;/**/
    }

    	//printf("%d",count);
}

void go_left(Node**mcur, int s)
{
    Node *cur=(*mcur);
    int l=0;

    if(s>0){
        s=s%count;
        l=count-s;
    }
    //printf("%d %d %d",s,l,s%count);
    //printf("%d",s%count);
    if(l<s){
        for(int i=1;i<=l;i++)
        cur=cur->next;
       //printf(" r");
    }
    else
    {
        for(int i=1;i<=s;i++){
            cur=cur->prev;
        }
       // printf(" l");
    }

    *mcur=cur;

}

void go_right(Node**mcur, int s)
{
    int l=0;


    if(s>0){
        s=s%count;//*//
        l=count-s;}

    Node *cur=*mcur;

    if(s<=l){
        for(int i=1;i<=s;i++)
            cur=cur->next;
        }
    else{
        for(int i=1;i<=l;i++){
            cur=cur->prev;}
        //printf(" l");
    }
    *mcur=cur;/**///wrong place

}

void go_home(Node**cur )
{
    *cur=head;
}

void go_end(Node**cur)
{
    *cur=tail;
}

