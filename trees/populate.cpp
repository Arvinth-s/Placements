//OM NAMO NARAYANA
#include "myTemplate.h" 
using namespace std;
struct node{
    node *left, *right, *next;
    int data;
};

struct node* newNode(int val)
{
    node *Node=new node;
    Node->left=Node->right=Node->next=NULL;
    Node->data=val;
    return Node;
}

void populateUtil(node* root, node **ptr, node **head);
struct node* populate(node* root);

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
    node *root = newNode(10);  
    root->left = newNode(8);  
    root->right = newNode(12);  
    root->left->left = newNode(3);  
  
    // Populates nextRight pointer in all nodes  
    struct node* ptr=populate(root);  
  
    // Let us see the populated values  
    while(ptr)  
    {  
        // -1 is printed if there is no successor  
        // cout << "Next of " << *ptr->data << " is "
        //      << (*ptr->next? *ptr->next->data: -1)  
        //      << endl;  
        // ptr = ptr->next; 
        cout<<(ptr)->data<<" ";
        (ptr)=(ptr)->next; 
    }  
  
    logs<<"Terminated.\n";
    return 0;
}

struct node* populate(node* root)
{
    if(root==NULL)return NULL;
    struct node** ptr;
    (*ptr)=NULL;
    struct node** head;
    *head=NULL;
    populateUtil(root, ptr, head);
    return *head;
}

void populateUtil(node *root, node **ptr, node **head)
{
    assert(root!=NULL);
    //head has same address as one of the node of tree
    if(*head==NULL && root->left==NULL)
    {
        *head=root;
        root->left=NULL;
    }
    if(root->left)populateUtil(root->left, ptr, head);
    if(*ptr){ (*ptr)->next=root;}
    *ptr=root;
    if(root->right)populateUtil(root->right, ptr, head);
    return;
}