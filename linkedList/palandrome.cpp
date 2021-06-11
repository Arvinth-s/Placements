//OM NAMO NARAYANA
#include "myTemplate.h" 
using namespace std;

struct node{
    int val;
    node* next;
};

void print(node* head);
void reverse(node** head);
void insert(node** head, int val);
bool palandrome(node* head);

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
    int s;
    ifile>>s;
    int arr[s];
    for(int i=0; i<s; i++)
    {
        ifile>>arr[i];
    }
    for(int i=0; i<s; i++)
    {
        insert(&head, arr[i]);
    }
    bool ans = palandrome(head);
    if(ans)
    {
        ofile<<"The given array is a palandrone.\n";
        cout<<"yes.\n";
    }
    else
    {
        ofile<<"The gicen array is not a palandrone.\n";
        cout<<"no.\n";
    }
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

bool palandrome(node* head)
{   
    if(head==NULL || head->next==NULL)
    {
        return true;
    }
    int count=0;
    node* Node= head;
    while(Node!=NULL)
    {
        count++;
        Node=Node->next;
    }
    Node=head;
    for(int i=0; i<count/2-1; i++)
    {
        Node=Node->next;
    }
    node* right=Node->next;
    if(count%2==1)right=right->next;
    Node->next=NULL;
    reverse(&head);
    // print(head);
    // print(right);
    for(int i=0; i<count/2; i++)
    {
        if(head->val!=right->val)
        {
            return false;
        }
        head=head->next;
        right=right->next;
    }
    return true;
}