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
    int sign = 1<<(8*sizeof(int)-1);
    int val = ((sign&n)>>(8*sizeof(int)-1))&1;
    int ans = (1-val)*n - val*n;
    ofile<<"absolute value of "<<str(n)<<" = "<<str(ans)<<".\n";
    cout<<ans;
    logs<<"Terminated.\n";
    return 0;
}