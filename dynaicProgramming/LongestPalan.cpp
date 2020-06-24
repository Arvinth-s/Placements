//OM NAMO NARAYANA
//OM NAMO NARAYANA

//longest palandromic subsequence
#include "myTemplate.h" 
using namespace std;
int lcs(string r, string s)
{
    int n=s.size();
    int dp[n+1][n+1];
    for(int i=0; i<n; i++)
    {
        dp[0][i]=dp[i][0]=0;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(s[i]==r[j])
            {
                dp[i+1][j+1]=dp[i][j]+1;
            }
            else
            {
                dp[i+1][j+1]=max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }
    return dp[n][n];
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
    string s, r;
    ifile>>s;
    r=s;
    reverse(r.begin(), r.end());
    int l=lcs(s, r);
    ofile<<"lcs of "<<s<<" is "<<str(l)<<endl;
    cout<<l<<endl;
    logs<<"Terminated.\n";
    return 0;
}