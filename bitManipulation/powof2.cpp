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
    int n;
    ifile>>n;
    cout<<(n&-n)<<endl;
    if(n==0)
    {
        ofile<<"0 is not a power of 2.\n";
        cout<<"no\n";
    }
    else if(n == (n&-n))
    {
        ofile<<str(n)<<" is a power of 2.\n";
        cout<<"yes\n";
    }
    else 
    {
        ofile<<str(n)<<" is not a power of 2.\n";
        cout<<"no\n";
    }
    logs<<"Terminated.\n";
    return 0;
}