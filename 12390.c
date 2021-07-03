#include "function.h"
#include <stdio.h>
#include <stdlib.h>

#define right ptr_to_right_node
#define left ptr_to_left_node
#define num number
static int preorder_id=0;

Node* buildTree(int* inorder, int* preorder, int inorder_start, int inorder_end)
{

    int inorder_id;

    if(inorder_start>inorder_end)
        return NULL;

    Node *ptr=(Node*)malloc(sizeof(Node));
    ptr->number=preorder[preorder_id];
    ptr->left=NULL;
    ptr->right=NULL;
    preorder_id++;

    if(inorder_start==inorder_end)
        return ptr;

    for(inorder_id=inorder_start;inorder_id<=inorder_end;inorder_id++)
        if(inorder[inorder_id]==ptr->number)
            break;

    ptr->left=buildTree(inorder,preorder,inorder_start,inorder_id-1);
    ptr->right=buildTree(inorder,preorder,inorder_id+1,inorder_end);

    return ptr;
}

void showPostorder(Node* root)
{
    if(root!=NULL)
    {
        showPostorder(root->left);
        showPostorder(root->right);
        printf("%d ",root->number);
    }
}

void freeTree(Node *root)
{
    if(root!=NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
        root=NULL;
    }
    preorder_id=0;
}
