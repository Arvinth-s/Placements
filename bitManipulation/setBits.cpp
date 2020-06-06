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
    m=n;
    int count=0;
    while(n > 0)
    {
        count++;
        n=(n&(n-1));
    }
    ofile<<str(count)<<" set bits in "<<str(m);
    cout<<count;
    logs<<"Terminated.\n";
    return 0;
}