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
    node* root = newNode(5); 
    root->left = newNode(2); 
    root->right = newNode(6); 
    root->left->left = newNode(1); 
    root->left->right = newNode(4); 
    root->left->right->left = newNode(3); 
    root->right->right = newNode(8); 
    root->right->right->right = newNode(9); 
    root->right->right->left = newNode(7); 
    verticalSum(root);
    logs<<"Terminated.\n";
    return 0;
}

void verticalSum(node *root)
{
    map<int, int> vs;
    int h=0;
    verticalSumUtil(root, vs, h);
    int odd=0, even=0;
    for(auto itr=vs.begin(); itr!=vs.end(); itr++)
    {
        if((itr->first)%2==0)
        {
            even+=itr->second;
        }
        else
        {
            odd+=itr->second;
        }
    }
    cout<<even-odd<<endl;
    return;
}

void verticalSumUtil(node *root, map<int, int> &vs, int h)
{
    if(root==NULL)return;
    vs[h] += root->data;
    verticalSumUtil(root->left, vs, h-1);
    verticalSumUtil(root->right, vs, h+1);
    return;
}