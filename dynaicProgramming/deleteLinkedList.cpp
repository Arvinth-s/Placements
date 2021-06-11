//OM NAMO NARAYANA
#include "myTemplate.h" 
using namespace std;

struct node{
    int val;
    node* next;
};

void print(node* head);
void insert(node** head, int val);
void clear(node** head);

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
    logs<<"Terminated.\n";
    return 0;
}

void print(node* head)
{
    if(head==NULL)
    {
        cout<<"The linked list is empty.\n";
        return;
    }
    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
    return;
}

void insert(node** head, int val)
{
    node* Node=new node;
    Node->next=*head;
    Node->val=val;
    *head=Node;
    return;
}

void clear(node **head)
{
    if(*head==NULL)
    {
        cout<<"The list is already empty.\n";
        return;
    }
    node* Node=(*head)->next, *lag=*head, *lead;
    while(Node!=NULL)
    {
        lead=Node->next;
        lag=Node;
        Node=lead;
        free(lag);
        print(Node);
    }
    return;
}