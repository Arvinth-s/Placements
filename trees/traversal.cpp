//OM NAMO NARAYANA
#include "myTemplate.h" 
using namespace std;

struct node{
    node* left, *right;
    int data;
};


struct node* newNode(int val)
{
    node *Node=new node;
    Node->left=Node->right=NULL;
    Node->data=val;
    return Node;
}

void inorder(node* root);
void preorder(node* root);
void postorder(node* root);

int main()
{
    fastio;
    string fname = c_dir(__FILE__);
    ifstream ifile(fname+"/input.txt");
    ofstream ofile(fname+"/output.txt");
    ofstream logs(fname+"/log.txt", ios::app);
    if(!ifile)
    {
        cout<<"input file not found\n";
        exit(0);
    }
    logs<<"Files created Successfully\n";
    struct node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5);  
  
    cout << "\nPreorder traversal of binary tree is \n"; 
    preorder(root); 
  
    cout << "\nInorder traversal of binary tree is \n"; 
    inorder(root);  
  
    cout << "\nPostorder traversal of binary tree is \n"; 
    postorder(root); 
    logs<<"Terminated.\n";
    return 0;
}

void inorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return;
}

void preorder(node* root)
{
    if(root)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    return;
}

void postorder(node* root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
    return;
}