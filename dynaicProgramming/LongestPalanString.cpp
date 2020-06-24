//OM NAMO NARAYANA
//OM NAMO NARAYANA
#include "myTemplate.h" 
#define null NULL
using namespace std;

struct node{
    node* children[27];
    bool end;
    bool single;
    string word;
};

struct node* newNode(void)
{
    struct node* n = new node;
    for(int i=0; i<27; i++)
    {
        n->children[i]=NULL;
    }
    n->end=true;
    n->single=false;
    n->word="";
    return n;
}

void insert(struct node* root, string s)
{
    struct node* nn=root;
    int n=s.size();
    string r="";
    for(int i=n-1; i>=0; i--)
    {
        nn->word=r;
        r=s[i]+r;
        int idx=s[i]-'A';
        if(nn->children[idx]==NULL)
        {
            nn->children[idx]=newNode();
        }
        nn->end=false;
        nn=nn->children[idx];
    }
    nn->word=r;
    return;
}

//failure links yet to be modelled
struct node* suffixTrie(string s)
{
    struct node* root = new node;
    int n=s.size();
    for(int i=0; i<n; i++)
    {
        insert(root, s);
        s.pop_back();
    }
    return root;
}

int lcst(string r, string s)
{
    struct node* root=suffixTrie(r);
    struct node* nn=root;
    int count=0;
    int n=s.size();
    string lcs;
    for(int i=0; i<n; i++)
    {
        int idx=s[i]-'A';
        if(nn->end==true||nn->children[idx]==null)
        {
            if(count < (nn->word).size())
            {
                lcs=(nn->word);
                count=(nn->word).size();
            }
            nn=root;
            if(nn->children[idx]!=null)
            {
                nn=nn->children[idx];
            }
        }
        else
        {
            nn=nn->children[idx];
        }
    }
    if(count < (nn->word).size())
    {
        lcs=(nn->word);
        count=(nn->word).size();
    }
    cout<<lcs<<endl;
    return count;
}

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
    string s;
    getline(ifile, s);
    int l=lcst(s, s);
    ofile<<"The longest common substing "<<str(l)<<endl;
    cout<<l<<endl;
    logs<<"Terminated.\n";
    return 0;
}