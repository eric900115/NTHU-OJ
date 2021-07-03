#include <stdio.h>

typedef struct node{
    int n;
    struct node *l,*r;
}Node;

static int po_id;

Node *build(int *in,int *po,int l,int r)
{
    if(r<l)
        return NULL;

    Node *np=(Node*)malloc(sizeof(Node));
    np->n=po[po_id--];
    int mid;
    np->l=np->r=NULL;

    if(l==r)
        return np;

    for(int i=l;i<r;i++){
        if(np->n==in[i]){
            mid=i;
            break;}}

        np->r=build(in,po,mid+1,r);
        np->l=build(in,po,l,mid-1);

     return np;
    preorder(np);
}


void preorder(Node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->n);
        preorder(root->l);
        preorder(root->r);
    }


}

int main(){

    int num;
    while(scanf("%d",&num)!=EOF)
    {
        Node *root;
        int in[num],po[num];
        for(int i=0;i<num;i++)
            scanf("%d",&in[i]);
        for(int i=0;i<num;i++)
            scanf("%d",&po[i]);
        po_id=num-1;
        root=build(in,po,0,num-1);
        preorder(root);
    }


}
