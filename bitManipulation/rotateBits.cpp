//OM NAMO NARAYANA
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
    bool flag=n&1;
    n=(flag<<(8*sizeof(int)-1)|(n>>1));
    ofile<<str(m)<<" is rotates clockwise to give "<<str(m)<<".\n";
    cout<<n<<endl;
    logs<<"Terminated.\n";
    return 0;
}