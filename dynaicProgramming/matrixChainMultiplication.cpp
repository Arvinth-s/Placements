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
    int N;//N-1 matrices
    ifile>>N;
    int arr[N];
    for(int n=0; n<N; n++)
    {
        ifile>>arr[n];
    }
    int cost[N-1][N-1];
    for(int n=0; n<N-1; n++)
    {
        for(int m=0; m<N-1; m++)
        {
            cost[n][m]=INT_MAX/5;
        }
    }
    for(int n=0; n<N-1;n++)
    {
        cost[n][n]=0;
    }
    for(int n=1; n<N-1; n++)
    {
        for(int m=0; m<N-1-n;m++)
        {
            for(int k=0; k<n;k++)
            {
                int m_n=m+n, m_k=m+k;
                cost[m][n+m]=min(cost[m][m+n], cost[m][m+k]+cost[m+k+1][m+n]+arr[m]*arr[m+k+1]*arr[m+n+1]);
            }
        }
    }
    ofile<<"minimum multiplication = "<<cost[0][N-1]<<endl;
    cout<<cost[0][N-2]<<endl;
    logs<<"Terminated.\n";
    return 0;
}