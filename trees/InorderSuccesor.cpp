//OM NAMO NARAYANA
#include "myTemplate.h"
using namespace std;

/*
interesting solution: 
1. two pointers pCrawl and succ. 
2. pCrawl will move towards the data point
3. If it's sure that the data point lies in the left subtree of pCrawl, then surely anything above pCrawl can't be the inorder successor
*/


struct node{
    int data;
    node *left, *right;
    node(int data);
    void insert(int data);
};

node *suc(node *root, node *n);
node *minNode(node *root);
void printInOrder(node *root);


int main()
{
    struct node root(20);
    root.insert(8);
    root.insert(22);
    root.insert(4);
    root.insert(12);
    root.insert(10);
    root.insert(14);
    printInOrder(&root);
    node *inp = (root.left)->right->left;
    node *ans = suc(&root, inp);
    printf("\nSuccessor of %d is %d\n", inp->data, ans->data);
    return 0;
}


node *suc(node *root, node *n)
{
    if(n->right)
    {
        return minNode(n->right);
    }
    node *ans=NULL;
    while(root!=NULL)
    {
        if(root->data > n->data)
        {
            ans=root;
            root=root->left;
        }
        else
        {
            root=root->right;
        }
    }
    return ans;
}


node *minNode(node *root)
{
    if(root==NULL)return root;
    while(root->left != NULL)
    {
        root=root->left;
    }
    return root;
}

node::node(int data)
{
    this->data=data;
    this->left=this->right=NULL;
    return;
}

void node::insert(int data)
{
    node* root=this;
    if(root==NULL)return;
    while(root!=NULL)
    {
        if(data > root->data)
        {
            if(root->right==NULL)
            {
                root->right = new node(data);
                return;
            }
            root=root->right;
        }
        else
        {
            if(root->left==NULL)
            {
                root->left= new node(data);
                return;
            }
            root=root->left;
        }
    }
    return;
}

void printInOrder(node *root)
{
    if(root==NULL)return;
    printInOrder(root->left);
    cout<<root->data<<" ";
    printInOrder(root->right);
    return;
}