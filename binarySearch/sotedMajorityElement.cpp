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

    int N;
    ifile>>N;
    int arr[N];
    for(int n=0; n < N; n++)
    {
        ifile>>arr[n];
    }
    int ele = arr[N/2];
    int start = lower_bound(arr, arr+N, ele)-arr;
    int last = upper_bound(arr, arr+N, ele)-arr;
    ofile<<"Majority ele "+str(ele)+" is repeated "+str(last-start)+" times.\n";
    if(last - start >= N/2)
    {
        cout<<"yes\n";
    }
    else
    {
        cout<<"no\n";
    }
    
    logs<<"Files created Successfully\n";
    logs<<"Terminated.\n";
    return 0;
}