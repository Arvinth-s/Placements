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
    int a[N], b[N];
    for(int n=0; n<N; n++)
    {
        ifile>>a[n];
    }
    for(int n=0;n <N; n++)
    {
        ifile>>b[n];
    }
    int start=0, last = N-1, idx=-1;
    while(start <= last)
    {
        int i = start + (last-start)/2;
        int j = N-1-i;
        if((j==0||a[i] > b[j-1]) && (i==0||b[j] > a[i-1]))
        {
            idx=i;
            break;
        }
        else if(j==0||a[i] > b[j-1])
        {
            last = i-1;
        }
        else
        {
            start = i+1;
        }
    }
    int i = idx;
    int j = N-1-idx;
    ofile<<"median "<<str((a[i] + b[j])/2.0)<<endl;
    logs<<"Terminated.\n";
    return 0;
}