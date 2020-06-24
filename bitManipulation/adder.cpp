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
    int a, b, sum=0;
    ifile>>a>>b;
    int piv=1;
    bool carry=0;
    for(int i = 1; i < sizeof(int); piv=piv<<1, i++)
    {
        int ap = a&piv, bp = b&piv;
        bool cgen = a&b;
        int s = ap^bp;
        carry = (cgen | (s&carry));
        sum |= s;
    }
    ofile<<"Sum of "<<str(a)<<" and "<<str(b)<<" = "<<str(sum)<<endl;
    cout<<sum<<endl;
    logs<<"Terminated.\n";
    return 0;
}