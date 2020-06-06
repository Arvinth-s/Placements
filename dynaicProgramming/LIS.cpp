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
    int N;
    ifile>>N;
    int arr[N];
    for(int n=0; n<N; n++)
    {
        ifile>>arr[n];
    }
    int dp[N];
    dp[0]=1;
    int _max=0;
    for(int n=0; n<N; n++)
    {
        dp[n]=1;
        for(int j=0;j<n;j++)
        {
            if(arr[j] < arr[n])
                dp[n]=max(dp[n],dp[j]+1);
        }
        _max = max(_max,dp[n]);
    }
    ofile<<"Length of longest increasing subsequence = "<<str(_max)<<endl;
    cout<<_max<<endl;
    logs<<"Terminated.\n";
    return 0;
}