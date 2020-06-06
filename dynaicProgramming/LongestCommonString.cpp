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
    string a, b;
    ifile>>a>>b;
    int N=a.size(), M=b.size();
    int dp[N][M];
    memset(dp, 0, sizeof(dp));
    int _max=0;
    for(int n=0; n<N; n++)
    {
        for(int m=0; m<M; m++)
        {
            if(a[n]==b[m])
            {
                if((n>0&&m>0) && (a[n-1]== b[m-1]))
                {
                    dp[n][m]=dp[n-1][m-1]+1;
                }
                else
                {
                    dp[n][m]=1;
                }
            }
            _max=max(_max, dp[n][m]);
        }
    }
    ofile<<"The length of largest common string = "<<str(_max)<<endl;
    cout<<_max<<endl;
    logs<<"Terminated.\n";
    return 0;
}