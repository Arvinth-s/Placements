//OM NAMO NARAYANA
#include "myTemplate.h"
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int data);
};

int toSumTree(node *root);
void printInOrder(node *root);

int main()
{
    node *root = NULL;  
    int x;  
      
    /* Constructing tree given in the above figure */
    root = new node(10);  
    root->left = new node(-2);  
    root->right = new node(6);  
    root->left->left = new node(8);  
    root->left->right = new node(-4);  
    root->right->left = new node(7);  
    root->right->right = new node(5);  
      
    toSumTree(root);  
      
    // Print inorder traversal of the converted 
    // tree to test result of toSumTree()  
    cout<<"Inorder Traversal of the resultant tree is: \n";  
    printInOrder(root);  
    return 0;  
}

int toSumTree(node *root)
{
    if(root==NULL)return 0;
    int temp=root->data;
    root->data=toSumTree(root->left)+toSumTree(root->right);
    return root->data+temp;
}

node::node(int data)
{
    this->data=data;
    this->left=this->right=NULL;
}

void printInOrder(node *root)
{
    if(root==NULL)return;
    printInOrder(root->left);
    printf("%d ", (root->data));
    printInOrder(root->right);
}