//OM NAMO NARAYANA
#include "myTemplate.h" 
using namespace std;

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
    uint n, m;
    ifile>>n;
    m = n;
    queue<bool> st;
    int size = 8*sizeof(int);
    while(size--)
    {
        st.push(n&1);
        n = n>>1;
    }
    while(!st.empty())
    {
        n=n<<1;
        n|=st.front();
        st.pop();
    }
    ofile<<str(n)<<" is reverse of "<<str(m)<<endl;
    logs<<"Terminated.\n";
    return 0;
}