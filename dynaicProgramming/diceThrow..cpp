//OM NMAO NARYANA
//OM NAMO NARAYANA
#include "myTemplate.h" 
using namespace std;

int diceThrow(int n, int m, int x)
{
    int dp[n+1][x+1];
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<=min(x, m); i++)
    {
        dp[1][i]=1;
    }
    dp[1][0]=0;
    for(int i=0; i <= n; i++)
    {
        dp[0][i]=0;
    }
    for(int i=2; i<=n; i++)
    {
        for(int j=1;j<=x; j++)
        {
            for(int k=1; k<=min(j-1, m); k++)
            {
                dp[i][j]+=dp[i-1][j-k];
            }
        }
    }
    return dp[n][x];
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
    int n, m, x;
    ifile>>m>>n>>x;
    int d=diceThrow(n, m, x);
    ofile<<str(d)<<endl;
    cout<<d<<endl;
    logs<<"Terminated.\n";
    return 0;
}