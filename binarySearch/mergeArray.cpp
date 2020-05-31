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
    int a[N], b[M];
    for(int n = 0; n < N; n++)
    {
        ifile>>a[n];
    }
    for(int m = 0; m < M; m++)
    {
        ifile>>b[m];
    }
    int ii=0, jj=0;
    int arr[N+M];
    while(ii < N && jj < M)
    {
        if(a[ii] <= b[jj])
        {
            arr[ii+jj] = a[ii];
            ii++;
        }
        else
        {
            arr[ii+jj] = b[jj];
            jj++;
        }
    }
    while(ii < N)
    {
        arr[ii+jj] = a[ii];
        ii++;
    }
    while(jj < M)
    {
        arr[ii+jj] = b[jj];
        jj++;
    }
    for(int i = 0; i < N+M; i++)
    {
        ofile<<str(arr[i])<<" ";
    }
    ofile<<"\n";
    logs<<"Terminated.\n";
    return 0;
}