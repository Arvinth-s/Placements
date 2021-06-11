//OM NAMO NARAYANA
#include "myTemplate.h"
using namespace std;
struct node{
    int data;
    node *left, *right;
    node(int data);
};

node* insert(node *root, int data);
node* correct(node *root, node **l, node **r, node **last);
void printInOrder(node *root);

int main()
{
    struct node *root = new node(6); 
    root->left        = new node(10); 
    root->right       = new node(2); 
    root->left->left  = new node(1); 
    root->left->right = new node(3); 
    root->right->right = new node(12); 
    root->right->left = new node(7); 
    node *l, *r, *last;
    l=r=last=NULL;
    printf("Inorder Traversal of the original tree \n"); 
    printInOrder(root); cout<<endl;
    root=correct(root, &l, &r, &last); 
    printf("The swapped elements are %d and %d", l->data, r->data);
    int temp=r->data;
    r->data=l->data;
    l->data=temp;
    printf("\nInorder Traversal of the fixed tree \n"); 
    printInOrder(root); cout<<endl;
    return 0;
}

node* correct(node *root, node **l, node **r, node **last)
{
    if(root==NULL)return NULL;
    correct(root->left, l, r, last);
    if(*l==NULL && (*last)!=NULL)
    {
        if((*last)->data > root->data)
        {
            *l=*last;
        }
    }   
    else if(*r==NULL && (*last)!=NULL)
    {
        if((*last)->data > root->data)
        {
            *r=root;
        }
    }
    (*last)=root;
    correct(root->right, l, r, last);
    return root;
}

node* insert(node *root, int data)
{
    if(root==NULL)return new node(data);
    if(root->data < data)
    {
        root->right=insert(root->right, data);
    }
    else
    {
        root->left=insert(root->left, data);
    }
    return root;
}

void printInOrder(node *root)
{
    if(root==NULL)return;
    printInOrder(root->left);
    printf("%d ", root->data);
    cout<<flush;
    printInOrder(root->right);
    return;
}

node::node(int data)
{
    this->data=data;
    this->left=this->right=NULL;
}