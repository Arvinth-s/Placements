//OM NAMO NARAYANA
#include "myTemplate.h"
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int data);
};

int main()
{
    
}

node::node(int data)
{
    this->data=data;
    this->left=this->right=NULL;
}