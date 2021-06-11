//OM NAMO NARAYANA
#include "myTemplate.h" 
using namespace std;

class node{
    public:
    int val;
    node* next;
    node(int val=-1, node* next=NULL)
    {
        this->val=val;
        this->next=next;
    }
};

void insert(node **head, int val);
void revPrint(node* head);

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
    node* head=NULL;
    int arr[]={1, 2, 34, 14, 12, 56, 15, 625, 724, 25, 3, 16};
    int s=sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<s; i++)
    {
        insert(&head, arr[i]);
    }
    revPrint(head);
    logs<<"Files created Successfully\n";
    logs<<"Terminated.\n";
    return 0;
}

void insert(node** head, int val)
{
    if(*head == NULL)
    {
        *head=new node(val);
        return;
    }
    node* Node=*head;
    while(Node->next!=NULL)Node=Node->next;
    Node->next=new node(val);
    return;
}

void revPrint(node* head)
{
    if(head==NULL)return;
    revPrint(head->next);
    cout<<head->val<<" ";
    return;
}