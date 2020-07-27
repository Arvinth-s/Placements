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
    Node->right=Node->left=NULL;
    Node->data=val;
    return Node;
}

bool identical(node* r1, node* r2);

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
    node *root1 = newNode(1);  
    node *root2 = newNode(1);  
    root1->left = newNode(2);  
    root1->right = newNode(3);  
    root1->left->left = newNode(4);  
    root1->left->right = newNode(5);  
  
    root2->left = newNode(2);  
    root2->right = newNode(3);  
    root2->left->left = newNode(4);  
    root2->left->right = newNode(5);  
  
    if(identical(root1, root2))  
    {
        cout << "Both tree are identical.";
        ofile << "Both tree are identical.";
    } 
    else
    {
        cout << "Trees are not identical.";
        ofile << "Trees are not identical.";
    }
    logs<<"Terminated.\n";
    return 0;
}

bool identical(node* r1, node* r2)
{
    if((r1==NULL && r2!=NULL) || (r1!=NULL && r2==NULL))return false;
    if(r1==NULL && r2==NULL)return true;
    if(r1->data != r2->data)
    {
        return false;
    }
    else{return (identical(r1->left, r2->left) & identical(r1->right, r2->right));}
}