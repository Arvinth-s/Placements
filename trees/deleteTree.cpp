//OM NAMO NARAYANA
#include "myTemplate.h" 
using namespace std;

struct node{
    int data;
    node *left, *right;
};

struct node* newNode(int data)
{
    node* Node=new node;
    Node->data=data;
    Node->right=Node->left=NULL;
    return Node;
}

void deleteTree(node* root);

int main()
{
    // fastio;
    // string fname = c_dir(__FILE__);
    // ifstream ifile(fname+"/input.txt");
    // ofstream ofile(fname+"/output.txt");
    // ofstream logs(fname+"/log.txt", ios::app);
    // if(!ifile)
    // {
    //     cout<<"input file not found\n";
    //     exit(0);
    // }
    // logs<<"Files created Successfully\n";
    
    // logs<<"Terminated.\n";
    node *root = newNode(1);  
    root->left     = newNode(2);  
    root->right     = newNode(3);  
    root->left->left = newNode(4);  
    root->left->right = newNode(5);  
    deleteTree(root);
    return 0;
}

void deleteTree(node *root)
{
    if(root==NULL)return;
    deleteTree(root->left);
    deleteTree(root->right);
    cout<<"deleting :"<<root->data<<endl;
    delete root;
}