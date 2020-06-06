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
    int N, M;
    ifile>>N>>M;
    int s[M];
    for(int m=0; m<M; m++)
    {
        ifile>>s[m];
    }
    int dp[N+1]={0};
    dp[0]=1;
    // for(int n=1; n<=N; n++)
    // {
    //     dp[n]=dp[n-1];
    //     for(int m=0; m<M; m++)
    //     {
    //         if(n-s[m]>=0)
    //         {
    //             dp[n]+=dp[n-s[m]];
    //         }
    //     }
    // }
    //NOTE THE ABOVE LOGIC IS WRONG AS IT CONSIDERS {1, 2, 2} AND {2, 1, 2} AS TWO DIFFERENT SETS
    //so we should include only one permutation of a set
    //so we keep adding same number and after finishing it, we never use the number again
    for(int m=0; m<M; m++)
    {
        for(int n=s[m]; n<=N; n++)
        {
            dp[n]+=dp[n-s[m]];
        }
    }
    ofile<<"total possibilities = "<<dp[N]<<endl;
    cout<<dp[N]<<endl;
    logs<<"Terminated.\n";
    return 0;
}