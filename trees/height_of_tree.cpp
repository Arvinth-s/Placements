//OM NAMO NARAYANA
#include "myTemplate.h" 
using namespace std;

struct node{
    node *left, *right;
    int data;
};

struct node* newNode(int val=-1)
{
    node *Node=new node;
    Node->data=val;
    Node->left=Node->right=NULL;
    return Node;
}

int height(node *root)
{
    if(root==NULL)return 0;
    else {return 1 + max(height(root->left) , height(root->right));}
}

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
     node *root = newNode(1);  
  
    root->left = newNode(2);  
    root->right = newNode(3);  
    root->left->left = newNode(4);  
    root->left->right = newNode(5);  
    // root->left->right->right = newNode(5);  
      
    cout << "Height of tree is " << height(root);  
    return 0;  
    logs<<"Terminated.\n";
    return 0;
}