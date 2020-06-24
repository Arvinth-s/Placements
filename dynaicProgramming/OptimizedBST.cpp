//OM NAMO NARAYANA
#include "myTemplate.h" 
using namespace std;

int optimizedBST(pii arr[], int n)
{
    
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
    int n;
    ifile>>n;
    pii arr[n];
    for(int i=0; i<n; i++)ifile>>arr[i].ff;
    for(int i=0; i<n; i++)ifile>>arr[i].ss;
    int ans=optimizedBST(arr, n);
    ofile<<"Minimum cost = "<<str(ans)<<endl;
    cout<<ans<<endl;
    logs<<"Terminated.\n";
    return 0;
}