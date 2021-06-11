//OM NAMO NARAYANA
#include "myTemplate.h" 
using namespace std;

struct node{
    int data;
    node* next;
    node(int data=-1, node* next=NULL){this->data=data;this->next=next;}
};

void insert(node **head, int data);
void mergeSort(node **head);
void merge(node **head, node *a, node *b);

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
    
    logs<<"Terminated.\n";
    return 0;
}

void insert(node **head, int data)
{
    node* nn=new node(data, *head);
    *head=nn;
    return;
}

void mergeSort(node **head)
{
    if(*head==NULL)
    {
        cout<<"The list is empty.\n";
        return;
    }
    if((*head)->next==NULL)
    {
        cout<<(*head)->data<<endl;
        return;
    }
    node *fast=((*head)->next)->next, *slow=(*head)->next;
    while(fast != NULL && fast->next != NULL)
    {
        fast=(fast->next)->next;
        slow=slow->next;
    }
    node *right=slow->next;
    slow->next=NULL;
    mergeSort()
}