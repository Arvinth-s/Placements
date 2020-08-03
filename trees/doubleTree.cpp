//OM NAMO NARAYANA
#include "myTemplate.h"
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int data)
    {
        this->data=data;
        this->left=this->right=NULL;
    }
};

void doubleTree(node *root);
void bfs(node *root);

int main()
{
    node *root = new node(1);  
    root->left = new node(2);  
    root->right = new node(3);  
    root->left->left = new node(4);  
    root->left->right = new node(5);  
    bfs(root);
    doubleTree(root);
    bfs(root);
    return 0;
}

void doubleTree(node *root)
{
    if(root==NULL)return;   
    if(root->left)
    {
        node *Node=new node(root->data);
        Node->left=root->left;
        Node->right=NULL;
        root->left=Node;
        doubleTree((root->left)->left);
    }
    doubleTree(root->right);
    return;
}

void bfs(node* root)
{
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        int count=q.size();
        for(int i=0; i<count; i++)
        {
            node *Node=q.front();
            q.pop();
            if(Node->left)q.push(Node->left);
            if(Node->right)q.push(Node->right);
            cout<<Node->data<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return;
}

