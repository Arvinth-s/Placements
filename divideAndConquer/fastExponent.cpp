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
    int x, n;
    ifile>>x>>n;
    ll buf = 1;
    int piv = 1<<8;
    while(piv&n==0 && piv>0)piv=piv>>1;
    for(; piv > 0; piv=piv>>1)
    {
        buf *= buf;
        if(piv&n)buf *= x;
    }
    ofile<<str(buf)<<endl;
    logs<<"Terminated.\n";
    return 0;
}