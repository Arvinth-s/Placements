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
    int N, L;
    ifile>>N>>L;
    pair<int, int> rod[N];
    for(int n=0; n<N; n++)
    {
        ifile>>rod[n].ff>>rod[n].ss;
    }
    int dp[L+1];
    memset(dp, 0, sizeof(dp));
    dp[0]=0;
    for(int l=1; l <= L; l++)
    {
        dp[l]=dp[l-1];
        for(int n=0; n<N; n++)
        {
            if(l >= rod[n].ff)
                dp[l]=max(dp[l], dp[l-rod[n].ff]+rod[n].ss);
        }
    }
    ofile<<"The maximum value = "<<str(dp[L])<<endl;
    cout<<dp[L]<<endl;
    logs<<"Terminated.\n";
    return 0;
}