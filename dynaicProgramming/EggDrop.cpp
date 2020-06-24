//OM NAMO NARAYANA
#include "myTemplate.h" 
using namespace std;

int eggdrop(int n, int k)
{
    int dp[k+1][n+1];
    // memset(dp, -1, sizeof(dp));
    for(int i=0; i<=k; i++)
    for(int j=0; j<=n; j++)
    dp[i][j]=INT_MAX/2;
    for(int i=0; i<=k; i++)
    {
        dp[i][1]=i;
    }
    for(int i=1; i<=n; i++)
    {
        dp[1][i]=1;
        dp[0][i]=0;
    }
    dp[0][0]=0;
    for(int i=2; i<=k; i++)
    {
        for(int j=0; j<=n; j++)
        {
            for(int x=1; x<=i; x++)
            {
                int a=dp[x-1][j-1], b=dp[i-x][j];
                int val= 1 + max(a, b);
                dp[i][j]=min(dp[i][j], val);
            }
        }
    }
    // for(int i=0; i<=k; i++)
    // {
    //     for(int j=0; j<=n; j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return dp[k][n];
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
    int n, k;
    ifile>>n>>k;
    int ans=eggdrop(n, k);
    ofile<<str(ans)<<" drops to be performed with "<<str(n)<<" eggs for"<<str(k)<<" floors.\n";
    cout<<ans<<endl;
    logs<<"Terminated.\n";
    return 0;
}