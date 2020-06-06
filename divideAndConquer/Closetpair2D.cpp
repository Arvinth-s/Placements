//OM NAMO NARAYANA
#include "myTemplate.h" 
#define INF 1e9
using namespace std;
//incomplete
float CpUtil(pii ax[], pii ay[], int N, float d)
{
    
}

float Cp(pii arr[], int N)
{
    pii ax[N], ay[N];
    for(int n=0; n<N; n++)
    {
        ax[n] = ay[n] = arr[n];
    }
    return CpUtil(ax, ay, N, INF);
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
    int N;
    ifile>>N;
    pii arr[N];
    for(int n=0; n<N; n++)
    {
        ifile>>arr[n].ff>>arr[n].ss;
    }
    float ans = Cp(arr, N);
    logs<<"Terminated.\n";
    return 0;
}