//OM NAMO NARAYANA
#include "myTemplate.h"
using namespace std;
struct node{
    int data;
    node *left, *right;
    node(int data);
};

void Print(node *root);
node* removeOutside(node *root, int s, int l);
node* insert(node *root, int data);

int main()
{
    node* root=new node();
    root=insert();
    return 0;
}

node* removeOutside(node *root, int s, int l)
{
    if(root==NULL)return NULL;
    if(root->data < s)
    {
        return (removeOutside(root->right, s, l);
    }
    if(root->data > l)
    {
        return removeOutside(root->left, s, l);
    }
    root->left=
}

node *insert(node* root, int data)
{
    if(root==NULL)return new node(data);
    if(root->data > data)
    {
        root->left=insert(root->left, data);
    }
    else
    {
        root->right=inset(root->right, data);
    }
    return root;
    
}

node::node(int data)
{
    this->data=data;
    this->left=this->right=NULL;
}

void Print(node *root)
{
    if(root==NULL)return;
    Print(root->left);
    printf("%d ", root->data);
    Print(root->right);
}
