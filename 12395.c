#include <stdio.h>
#include <ctype.h>

int value[3]={0};
static int times=0;
typedef struct node{
    int type;// 0: operator, 1: value, 2: variable
    char ch;
    int val;
    struct node *l,*r;
}Node;

void build_tree(Node**root)
{
    (*root)=(Node*)malloc(sizeof(Node));
    char c=getchar();

    if(c=='\n')
        return;

    while(isspace(c))
        c=getchar();

    if(c=='+'||c=='-'||c=='*'||c=='/'){
        (*root)->type=0;
        (*root)->ch=c;
        build_tree(&((*root)->l));
        build_tree(&((*root)->r));
    }
    else if (isdigit(c))
    {
        ungetc(c,stdin);
        int s;
        scanf("%d",&s);
        ((*root)->val)=s;
        (*root)->type=1;
        (*root)->l=(*root)->r=NULL;
    }
    else if(c=='x'||c=='y'||c=='z')
    {
        (*root)->type=2;
        (*root)->ch=c;
        (*root)->l=(*root)->r=NULL;
    }
}

void inorder(Node *root)
{
    if(root!=NULL)
    {
        inorder(root->l);

        if(root->type==0||root->type==2)
            printf("%c",root->ch);
        else printf("%d",root->val);

        inorder(root->r);
    }
}

int cal(Node *now)
{

    if(now->type==0){
        int left,right,ans;
        left=cal(now->l);
        right=cal(now->r);

        if(now->ch=='+')
            ans=left+right;
        else if(now->ch=='-')
            ans=left-right;
        else if(now->ch=='*')
            ans=left*right;
        else if(now->ch=='/')
            ans=left/right;
        return ans;
    }
    else if(now->type==1)
        return now->val;
    else if(now->type==2)
    {
        int s=value[times];
        times++;
        return s;

        /*int s;
        scanf("%d",&s);
        return s*/
    }
}

int main(){

    Node *head;

    build_tree(&head);
    inorder(head);
    printf("\n");

    for(int i=0;i<3;i++)
        scanf("%d",&value[i]);

    int s=cal(head);
    printf("%d\n",s);
    times=0;
}
