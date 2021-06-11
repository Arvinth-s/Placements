//OM NAMO NARAYANA
#include "myTemplate.h"
using namespace std;

struct node{
    int data;
    node *left, *right;
};

node* newNode(int data);
node* insert(node *root, int ele);
node* kth(node *root, int &count, int k);
void printInOrder(node* root);

int main()
{
    node* root = NULL; 
    int keys[] = { 20, 8, 22, 4, 12, 10, 14 }; 
  
    for (int x : keys) 
        root=insert(root, x); 
  
    // int k = 1; 
    for(int k=1; k < 6; k++)
    {
        int count=0;
        printInOrder(root);
        cout<<endl;
        node* ans = kth(root, count, k); 
        cout<<ans->data<<endl;
    }
    return 0;
}

node* kth(node *root, int &count, int k)
{
    if(root==NULL)return root;
    node *left=kth(root->left, count, k);
    if(count==k){return left;}
    if(count==k-1){count++;return root;}
    count++;
    return kth(root->right, count, k);
    
}

node* insert(node *root, int ele)
{
    node *Node=newNode(ele);
    if(root==NULL)
    {
        return Node;
    }
    if(root->data < ele)
    {
        root->right=insert(root->right, ele);
    }
    else
    {
        root->left=insert(root->left, ele);
    }
    return root;
    
}

node* newNode(int data)
{
    node *Node=new node();
    Node->data=data;
    Node->left=Node->right=NULL;
    return Node;
}

void printInOrder(node* root)
{
    if(root==NULL)return;
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
    return;
}