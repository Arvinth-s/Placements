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
    uint n;
    ifile>>n;
    uint m=n;
    n=(n&(n-1));
    ofile<<str(m)<<" => "<<str(n)<<"./n";
    cout<<n<<endl;
    logs<<"Terminated.\n";
    return 0;
}