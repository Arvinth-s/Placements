//OM NAMO NARAYANA

/*
MISTAKES:
1. The rightboundary was implemented from top to botton
2. The leftboundary was implemented only till the leftmost node i.e., the right child of the leftmost node was not considered
3. Similarly the left child of the rightmost node was not considered.
*/

#include "myTemplate.h"
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int data);
};

node::node(int data)
{
    this->data=data;
    this->left=this->right=NULL;
}

void leftboundary(node* root);
void rightboundary(node* root);
void boundaryTraversalUtil(node *root);
void boundaryTraversal(node *root);

int main()
{
    struct node* root = new node(20); 
    root->left = new node(8); 
    root->left->left = new node(4); 
    root->left->right = new node(12); 
    root->left->right->left = new node(10); 
    root->left->right->right = new node(14); 
    root->right = new node(22); 
    root->right->right = new node(25); 
    boundaryTraversal(root); 
    return 0;
}

void boundaryTraversal(node *root)
{
    cout<<root->data<<" ";
    if(root->left==NULL && root->right==NULL)return;
    if(root->left)leftboundary(root->left);
    boundaryTraversalUtil(root);
    if(root->right)rightboundary(root->right);
}

void boundaryTraversalUtil(node *root)
{
    if(root==NULL)return;
    if(root->left==NULL && root->right==NULL)
    {
        cout<<root->data<<" ";
        return;
    }
    boundaryTraversalUtil(root->left);
    boundaryTraversalUtil(root->right);
    return;
}

void leftboundary(node *root)
{
    if(root==NULL)return;
    if(root->left)
    {
        cout<<root->data<<" ";
        leftboundary(root->left);
    }
    else if(root->right)
    {
        cout<<root->data<<" ";
        leftboundary(root->right);
    }
    return;
}

void rightboundary(node *root)
{
    if(root==NULL)return;
    if(root->right)
    {
        rightboundary(root->right);
        cout<<root->data<<" ";
    }
    else if(root->left)
    {
        rightboundary(root->left);
        cout<<root->data<<" ";
    }
    return;
}