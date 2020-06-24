//OM NAMO NARAYANA
//OM NAMO NARAYANA
#include "myTemplate.h" 
using namespace std;
int lcs(string r, string s)
{
    int N=s.size();
    int dp[N][N];
    memset(dp, 0, sizeof(dp));
    for(int n=0; n<N; n++)
    {
        for(int m=0; m<N; m++)
        {
            if(m==0||n==0)
            {
                if(s[n]==r[m])
                {
                    dp[n][m]=1;
                }
                continue;
            }
            if(s[n]==r[m])
            {
               dp[n][m]=dp[n-1][m-1]+1;
            }
            else
            {
                dp[n][m]=max(dp[n-1][m], dp[n][m-1]);
            }
        }
    }
    return dp[N-1][N-1];
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
    string s;
    ifile>>s;
    string r=s;
    reverse(r.begin(), r.end());
    int l=lcs(s, r);
    int N=s.size();
    int ans=N-l;
    ofile<<str(ans)<<" is the minimum number of characters to be inserted to make it a palandrome\n";
    cout<<ans<<endl;
    logs<<"Terminated.\n";
    return 0;
}