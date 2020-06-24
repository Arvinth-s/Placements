//OM NAMO NARAYANA
#include "myTemplate.h" 
using namespace std;

struct node{
    int val;
    node* next;
};

void insert(node** head, int val);
void reverse(node** head);
void print(node* head);

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
    node* head=NULL;
    int arr[]={1, 2, 34, 14, 12, 56, 15, 625, 724, 25, 3, 16};
    int s=sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<s; i++)
    {
        insert(&head, arr[i]);
    }
    print(head);
    reverse(&head);
    print(head);
    logs<<"Terminated.\n";
    return 0;
}

void insert(node** head, int val)
{
    node* Node=new node;
    Node->next=*head;
    Node->val=val;
    *head=Node;
    return;
}

void reverse(node** head)
{
    if(*head==NULL)
    {
        cout<<"The list is empty.\n";
        return;
    }
    node *lead=(*head)->next, *lag=NULL, *Node=*head;
    while(Node!=NULL)
    {
        lead=Node->next;
        Node->next=lag;
        lag=Node;
        Node=lead;
    }
    *head=lag;
    return;
}

void print(node* head)
{
    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
    return;
}