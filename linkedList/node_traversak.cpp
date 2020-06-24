//OM NAMO NARAYANA
#include "myTemplate.h" 
using namespace std;

class data{
    public:
    int ival;
    char cval;
    data(int ival=0, char cval='0')
    {
        this->ival=ival;
        this->cval=cval;
    }
};

struct node{
    data val;
    node* next;
};

void insert(node** head, data d);
data traverse(node* head, int k);

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
    insert(&head, data(5, 'o'));
    insert(&head, data(1, 'm'));
    for(int i=0; i<10; i++)
    {
        srand(time(0));
        data temp;
        temp.ival=rand();
        temp.cval=rand()%26 + 'a';
        insert(&head, temp);
    }
    int k;
    ifile>>k;
    data ans=traverse(head, k);
    cout<<ans.ival<<" "<<ans.cval<<endl;
    ofile<<k+1<<"th element is: "<<ans.ival<<" "<<ans.cval<<endl;
    logs<<"Terminated.\n";
    return 0;
}

void insert(node** head, data d)
{
    if(*head==NULL)
    {
        *head=new node;
        (*head)->next=NULL;
        (*head)->val=d;
        return;
    }
    node* Node=*head;
    while(Node->next != NULL)
    {
        Node=Node->next;
    }
    node* nn=new node;
    nn->val=d;
    nn->next=NULL;
    Node->next=nn;
    return;
}

data traverse(node *head, int k)
{
    node *Node=head;
    int i=0;
    for(i=0; i<k-1 && Node!=NULL; i++)
    {
        Node=Node->next;
    }
    if(i<k-1 || Node==NULL)
    {
        cout<<"The size of the list is less than k:"<<k<<endl;
        return data(0);
    }
    return Node->val;
}