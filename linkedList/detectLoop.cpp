//OM NAMO NARAYANA
#include "myTemplate.h" 
using namespace std;

struct node{
    int val;
    bool visited;
    node* next;
    node(int val=0, node* next=NULL, bool visited=false)
    {
        this->val=val;
        this->next=next;
        this->visited=visited;
    }
};

// void print(node* head);
void insert(node** head, int val);
bool dloopf(node* head);
bool dlooph(node* head);
bool dloopfl(node* head);
bool dloope(node* head);
void createLoop(node* head);
void loopDetect(node* head);

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
    createLoop(head);
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

// void print(node* head)
// {
//     if(head==NULL)
//     {
//         cout<<"The linked list is empty.\n";
//         return;
//     }
//     while(head!=NULL)
//     {
//         cout<<head->val<<" ";
//         head=head->next;
//     }
//     cout<<endl;
//     return;
// }

bool dloopf(node* head)
{
    while(head!=NULL)
    {
        if(head->visited==true)return true;
        head->visited=true;
        head=head->next;
    }
    return false;
}

bool dlooph(node* head)
{
    unordered_set<node*> uset;
    while(head != NULL)
    {
        if(uset.find(head)!=uset.end())
        {
            return true;
        }
        uset.insert(head);
        head=head->next;
    }
    return false;
}

bool dloopfl(node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return false;
    }
    node* fast=(head->next)->next, *slow=head->next;
    while(fast != NULL && slow!=NULL)
    {
        if(fast==slow)
        {
            return true;
        }
        fast=(fast->next)->next;
        slow=slow->next;
    }
    return false;
}

bool dloope(node *head)
{
    node* ref=head, *lead;
    while(head!=NULL)
    {
        lead=head->next;
        if(lead==ref)
        {
            return true;
        }
        head->next=ref;
        head=lead;
    }
    return false;
}

void createLoop(node* head)
{
    loopDetect(head);
    if(head==NULL)
    {
        cout<<"The list is empty.\n";
        return;
    }
    node* Node=head;
    while(Node->next!=NULL)
    {
        Node=Node->next;
    }
    if(head->next!=NULL)Node->next=head->next;
    else Node->next=head;
    loopDetect(head);
    return;
}

void loopDetect(node* head)
{
    cout<<"Loop "; 
    if(!dloopf(head))cout<<"not";
    cout<<" found using flag.\n";
    cout<<"Loop ";
    // if(!dloope(head))cout<<"not";
    // cout<<" found using extra pointer.\n";
    // cout<<"Loop ";
    if(!dloopfl(head))cout<<"not";
    cout<<"found using floyd algorithm.\n";
    cout<<"Loop ";
    if(!dlooph(head))cout<<"not";
    cout<<" found using hashing.\n";
    return;
}