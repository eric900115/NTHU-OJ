#include <stdio.h>
#include <stdlib.h>
#include "function.h"

void build_tree(Node **now, int *arr, int l, int r)
{

        if(l>r)
            return NULL;

        (*now)=(Node*)malloc(sizeof(Node));
        (*now)->left_child=NULL;
        (*now)->right_child=NULL;

        if(l==r)
        {
            (*now)->left_child=(*now)->right_child=NULL;
            (*now)->level=arr[l];
        }
        else if(l<r)
        {
            int mid=(l+r)/2;
            (*now)->level=arr[mid];
            build_tree(&((*now)->left_child),arr,l,mid-1);
            build_tree(&((*now)->right_child),arr,mid+1,r);

        }


}



void inorder(Node *root)
{
    if(root!=NULL)
    {
        inorder(root->left_child);
        printf("%d ",root->level);
        inorder(root->right_child);
    }
}

int query_heatstroke(Node *now, int x)
{
    if(now==NULL)
        return 0;
    else if(now->level==x)
        return 1;
    else if(now->level<x)
        return query_heatstroke(now->right_child,x);
    else
        return query_heatstroke(now->left_child,x);
}

void eat_rat(Node **root, int x)
{
    Node *pre,*cur;
    pre=cur=*root;

    if((*root)==NULL)
        return;

    while(cur->level!=x)
    {
        pre=cur;
        if(cur->level>x)
            cur=cur->left_child;
        else if(cur->level<x)
            cur=cur->right_child;
    }

    if(cur->left_child==NULL&&cur->right_child==NULL)
    {

        if(cur==*root){
            free(cur);
            *root=NULL;}
        else
        {
            if(pre->left_child==cur)
                pre->left_child=NULL;
            else
                pre->right_child=NULL;
            free(cur);
        }

    }
    else if(cur->left_child!=NULL&&cur->right_child==NULL)
    {
        if(cur!=*root)
        {
            if(pre->left_child==cur)
                pre->left_child=cur->left_child;
            else
                pre->right_child=cur->left_child;
        }
        else
            *root=cur->left_child;

        free(cur);
    }
    else if(cur->left_child==NULL&&cur->right_child!=NULL)
    {
        if(cur!=*root){
            if(pre->left_child==cur)
                pre->left_child=cur->right_child;
            else
                pre->right_child=cur->right_child;}
        else
            *root=cur->right_child;

        free(cur);
    }
    else if(cur->left_child!=NULL&&cur->right_child!=NULL)
    {

        Node *np=((cur)->right_child);
        //(*cur)=(*cur)->right_child;
        while((np)->left_child!=NULL)
            (np)=(np)->left_child;

        int val=np->level;



        eat_rat(&(cur->right_child),val);
        (cur)->level=val;
    }

}

void buy_rat(Node **root, int x){
    Node **now=root;
    while(*now!=NULL){
        if((*now)->level>x)
            now=&((*now)->left_child);
        else now=&((*now)->right_child);
    }

    (*now)=(Node*)malloc(sizeof(Node));
    (*now)->level=x;
    (*now)->left_child=(*now)->right_child=NULL;

}
