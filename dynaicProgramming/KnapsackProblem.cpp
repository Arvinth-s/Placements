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
    int N;
    ifile>>N;
    pii val[N];
    for(int n=0; n<N; n++)
    {
        ifile>>val[n].ss>>val[n].ff;
    }
    int W;
    ifile>>W;
    sort(val, val+N);
    int dp[N+1][W+1]={0};
    memset(dp, 0, sizeof(dp));
    for(int w=val[0].ff; w<=W; w++)
    {
        dp[0][w]=val[0].ss;
    }
    for(int n=1; n <= N; n++)
    {
        for(int w=1; w<=W; w++)
        {
            if(w >= val[n].ff)dp[n][w]=max(dp[n-1][w], dp[n-1][w-val[n-1].ff]+val[n-1].ss);
            else dp[n][w]=dp[n-1][w];
        }
    }
    ofile<<"Maximum value "<<str(dp[N][W])<<endl;
    cout<<dp[N][W]<<endl;
    logs<<"Terminated.\n";
    return 0;
}