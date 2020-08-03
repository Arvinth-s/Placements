//OM NAMO NARAYANA

/*
note a or b can also be considered ancestor of a or b
*/
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

node* lowestCommonAncestor(node *root, node a, node b);

int main()
{
    struct node root(20);
    int arr[]={8, 22, 4, 12, 10, 14};
    int nn=sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<nn; i++)
    {
        root.insert(arr[i]);
    }
    root.print();
    node a(10), b(14);
    node* lca= lowestCommonAncestor(&root, a, b);
    printf("The common ancestor for %d and %d is %d.\n", a.data, b.data, lca->data);
    a.data=14;b.data=8;
    lca= lowestCommonAncestor(&root, a, b);
    printf("The common ancestor for %d and %d is %d.\n", a.data, b.data, lca->data);
    a.data=10;b.data=22;
    lca= lowestCommonAncestor(&root, a, b);
    printf("The common ancestor for %d and %d is %d.\n", a.data, b.data, lca->data);
    return 0;
}

node* lowestCommonAncestor(node *root, node a, node b)
{
    if(a.data > b.data)swap(a, b);
    while(root != NULL)
    {
        if(root->data >= a.data && root->data <= b.data)
        {
            return root;
        }
        if(root->data < a.data)
        {
            root=root->right;
        }
        else 
        {
            root=root->left;
        }
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