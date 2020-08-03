//OM NAMO NARAYANA
#include "myTemplate.h" 
using namespace std;

struct node{
    int data;
    node *left, *right;
};

struct node *newNode(int data)
{
    node *Node = new node;
    Node->left=Node->right=NULL;
    Node->data=data;
    return Node;
}

void verticalSumUtil(node *root, map<int, int> &vs, int h);
void verticalSum(node *root);

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
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
    root->right->right->right = newNode(9); 
    verticalSum(root);
    logs<<"Terminated.\n";
    return 0;
}

void verticalSum(node *root)
{
    map<int, int> vs;
    int h=0;
    verticalSumUtil(root, vs, h);
    for(auto itr=vs.begin(); itr !=vs.end(); itr++)
    {
        cout<<itr->first<<":"<<itr->second<<endl;
    }
}

void verticalSumUtil(node *root, map<int, int> &vs, int h)
{
    if(root==NULL)return;
    vs[h] += root->data;
    verticalSumUtil(root->left, vs, h-1);
    verticalSumUtil(root->right, vs, h+1);
    return;
}