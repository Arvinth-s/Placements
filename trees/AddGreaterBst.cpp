//OM NAMO NARAYANA
#include "myTemplate.h"
using namespace std;

/*
mistakes:
sum += root->data;
root->data=sum-root->data;wrong
root->data=sum;correct;
*/

struct node{
    int data;
    node *left, *right;
    node(int data)
    {
        this->data=data;
        this->left=this->right=NULL;
    }
    void insert(int data);
};

void node::insert(int data)
{
    node* ref=this;
    if(ref==NULL){ref = new node(data);return;}
    while(ref != NULL)
    {
        if(data < ref->data)
        {
            if(ref->left==NULL)
            {
                ref->left=new node(data);
                return;
            }
            ref=ref->left;
        }
        else 
        {
            if(ref->right==NULL)
            {
                ref->right=new node(data);
                return;
            }
            ref=ref->right;
        }
    }
    return;
}

void addGreaterUtil(node* root, int &sum);
void addGreater(node* root);
void printInOrder(node *root);

int main()
{
    struct node root(50);
    root.insert(30);
    root.insert(20);
    root.insert(40);
    root.insert(70);
    root.insert(60);
    root.insert(80);
    addGreater(&root);
    printInOrder(&root);
    return 0;
}

void addGreater(node *root)
{
    int sum=0;
    addGreaterUtil(root, sum);
    return;
}

void addGreaterUtil(node *root, int &sum)
{
    if(root==NULL)return;
    addGreaterUtil(root->right, sum);
    sum += root->data;
    root->data=sum;
    addGreaterUtil(root->left, sum);
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