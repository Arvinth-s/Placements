//OM NAMO NARAYANA
#include "myTemplate.h" 
using namespace std;

struct node{
    int val;
    node* next;
    node(int val, node* next=NULL){this->val=val;this->next=next;}
};

void push(node **head, int val);
void intersection(node *a, node*b, node**intersect);
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
    int asize, bsize;
    ifile>>asize>>bsize;
    node *a=NULL, *b=NULL, *intersect=NULL;
    int val;
    for(int i=0; i<asize; i++){ifile>>val;push(&a, val);}
    for(int j=0; j<bsize; j++){ifile>>val;push(&b, val);}
    intersection(a, b, &intersect);
    if(intersect==NULL){ofile<<"The list is empty.\n";cout<<"The list is empty.\n";return 0;}
    ofile<<"Intersection: ";
    while(intersect!=NULL){ofile<<str(intersect->val)<<" ";cout<<intersect->val<<" ";intersect=intersect->next;}
    cout<<endl;
    logs<<"Terminated.\n";
    return 0;
}

//stacked so inverted
void push(node **head, int val)
{
    if(*head==NULL)
    {
        *head=new node(val);
        return;
    }
    node *Node=new node(val, *head);
    *head=Node;
    return;
}

void intersection(node *a, node* b, node**dummy)
{
    // node *dummy=NULL;
    // print(a);
    // print(b);
    while(a!=NULL && b!=NULL)
    {
        if(a->val==b->val)
        {
            push(dummy, a->val);
            a=a->next;
            b=b->next;
        }
        else if(a->val > b->val)
        {
            a=a->next;
        }
        else
        {
            b=b->next;
        }
    }
    print(*dummy);
    return;
}

void print(node *head)
{
    if(head==NULL){cout<<"The list is empty.\n";return;}
    while(head!=NULL){cout<<head->val<<" ";head=head->next;}
    cout<<endl;
    return;
}