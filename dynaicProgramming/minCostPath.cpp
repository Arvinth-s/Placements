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
    int N, M;
    pii position;
    ifile>>N>>M>>position.ff>>position.ss;
    position.ff--;position.ss--;
    int cost[N][M];
    for(int n=0; n<N; n++)
    {
        for(int m=0; m<M; m++)
        {
            ifile>>cost[n][m];
        }
    }
    int dp[N][M];
    // memset(dp, 0, sizeof(dp));
    for(int n=0; n<N; n++)for(int m=0; m<M; m++)dp[n][m]=INT_MAX;
    dp[0][0]=cost[0][0];
    for(int n=1; n<max(M, N); n++)
    {
        dp[n][0] = cost[n][0]+dp[n-1][0];
        dp[0][n] = cost[0][n]+dp[0][n-1];
        for(int j=1; j< min(n+1, M); j++)
        {
            dp[n][j] = cost[n][j] + min(dp[n-1][j], min(dp[n-1][j-1], dp[n][j-1]));
        }
        for(int i=1; i<min(n+1, N); i++)
        {
            dp[i][n] = cost[i][n] + min(dp[i-1][n], min(dp[i][n-1], dp[i-1][n-1]));
        }
    }
    ofile<<"minimum cost to reach ("<<str(position.ff+1)<<", "<<str(position.ss+1)<<"from (0,0) = "<<str(dp[position.ff][position.ss])<<endl;
    cout<<dp[position.ff][position.ss]<<endl;
    logs<<"Terminated.\n";
    return 0;
}