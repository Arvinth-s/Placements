//OM NAMO NARAYANA
//OM NAMO NARAYANA
#include "myTemplate.h" 
using namespace std;

//O(n^2)
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
    int arr[N];
    for(int n=0; n<N; n++)
    {
        ifile>>arr[n];
    }
    int dp[N+1];
    for(int n=0; n<N;n++)
    {
        dp[n]=INT_MAX/2;
    }
    dp[N]=0;
    for(int n=N-1; n>=0; n--)
    {
        for(int j=n; j<min(N, n+arr[n]);j++)
        {
            dp[n]=min(dp[n],dp[j+1]+1);
        }
    }
    ofile<<"minimum number of jumps "<<str(dp[0])<<endl;
    cout<<dp[0]<<endl;
    logs<<"Terminated.\n";
    return 0;
}