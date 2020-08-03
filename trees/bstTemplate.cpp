//OM NAMO NARAYANA
#include "myTemplate.h"
using namespace std;
struct node{
    int data;
    node *left, *right;
    node(int data);
    node();
    void insert(int data);
    void inorder(node *root);
    void print();
};


int main()
{
    struct node root;
    int arr[]={};
    int nn=sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<nn; i++)
    {
        root.insert(arr[i]);
    }
    root.print();


    return 0;
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
    while(root!= NULL)
    {
        if(root->data < data)
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
                root->left=new node(data);
                return;
            }
            root=root->left;
        }
    }
    return;
}

void node::print()
{
    node *root=this;
    if(root==NULL)
    {
        cout<<"The tree is empty.\n";
        return;
    }
    inorder(root);   
    cout<<endl;
}

void node::inorder(node *root)
{
    if(root)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    return;
}

node::node()
{
    this->data=-1;
    this->left=this->right=NULL;
    return;
}