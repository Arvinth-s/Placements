//OM NAMO NARAYANA
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
    return;
}

void leftViewUtil(node *root, int cLevel, int &level);
void leftView(node *root);

int main()
{
    node* root = new node(12); 
    root->left = new node(10); 
    root->right = new node(30); 
    root->right->left = new node(25); 
    root->right->right = new node(40); 
  
    leftView(root); 
    return 0;
}

void leftView(node *root)
{
    int level=0;
    leftViewUtil(root, 0, level);
}

void leftViewUtil(node *root, int cLevel, int &level)
{
    if(root==NULL)return;
    if(cLevel==level)
    {
        cout<<root->data<<" ";
        level++;
    }
    leftViewUtil(root->left, cLevel+1, level);
    leftViewUtil(root->right, cLevel+1, level);
    return;
}