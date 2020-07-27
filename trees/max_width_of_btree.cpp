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

int maxWidth(node* root);

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
    root->left        = newNode(2); 
    root->right       = newNode(3); 
    root->left->left  = newNode(4); 
    root->left->right = newNode(5); 
    root->right->right = newNode(8); 
    root->right->right->left  = newNode(6); 
    root->right->right->right  = newNode(7); 
    cout << "Maximum width is "<< maxWidth(root) << endl; 
    ofile<<"Maximum width is "+str(maxWidth(root))+"\n";
    logs<<"Terminated.\n";
    return 0;
}

int maxWidth(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    queue<node*> q;
    q.push(root);
    int width=0;
    while(!q.empty())
    {
        int count=q.size();
        width=max(width, count);
        while(count--)
        {
            node* Node=q.front();
            q.pop();
            if(Node->left)q.push(Node->left);
            if(Node->right)q.push(Node->right);
        }
    }
    return width;
}