//OM NAMO NARAYANA
#include "myTemplate.h"
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int data);
};

void printInOrder(node *root);
bool isSumProperty(node *root);

int main()
{
    struct node *root = new node(10); 
    root->left     = new node(8); 
    root->right = new node(2); 
    root->left->left = new node(3); 
    root->left->right = new node(5); 
    root->right->right = new node(2); 
    if(isSumProperty(root)) 
        cout << "The given tree satisfies "
            << "the children sum property "; 
    else
        cout << "The given tree does not satisfy "
            << "the children sum property "; 
  
    getchar(); 
    return 0; 
    return 0;
}

bool isSumProperty(node* root)
{
    if(root==NULL || (root->left==NULL && root->right==NULL))return true;
    int l=0, r=0;
    if(root->left)l=(root->left)->data;
    if(root->right)r=(root->right)->data;
    if(l+r != root->data)return false;
    return isSumProperty(root->left) && isSumProperty(root->right);
}

void printInOrder(node *root)
{
    if(root==NULL)return;
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

node::node(int data)
{
    this->data=data;
    this->left=this->right=NULL;
}

