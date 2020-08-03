//OM NAMO NARAYANA
#include "myTemplate.h"
using namespace std;

/*
mistakes:
1. line 36 if(root==NULL)return true;
2. if condition in 39 and 47 not included
*/

struct node{
    int data;
    node *left, *right;
    node(int data);
};

bool isSumTree(node *root);

int main()
{
    node *root = new node(26);
    root->left         = new node(10); 
    root->right        = new node(3); 
    root->left->left   = new node(4); 
    root->left->right  = new node(6); 
    root->right->right = new node(3); 
    if(isSumTree(root)) 
        printf("The given tree is a SumTree "); 
    else
        printf("The given tree is not a SumTree "); 
  
    return 0;
}

bool isSumTree(node *root)
{
    if(root==NULL || (root->left==NULL && root->right==NULL))return true;
    int l=0, r=0;
    if(root->right)
    {
        r=(root->right)->data;
        if((root->right)->left || (root->right)->right)
        {
            r += (root->right)->data;
        }
    }
    if(root->left)
    {
        l=(root->left)->data;
        if((root->right)->left || (root->right)->right)
        {
            l += (root->left)->data;
        }
    }
    if(root->data != l+r){cout<<root->data<<" "<<l<<" "<<r<<endl;return false;}
    return (isSumTree(root->left)&&(root->right));
}

node::node(int data)
{
    this->data=data;
    this->left=this->right=NULL;
    return;
}


