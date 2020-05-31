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
    for(int n = 0; n < N; n++)
    {
        ifile>>arr[n];
    }
    int ele;
    ifile>>ele;
    int start = 0, last = N-1;
    int floor = N, ceil = -1;
    while(start <= last)
    {
        int mid = start + (last - start)/2;
        if(arr[mid] == ele && (mid==0 || arr[mid-1] < ele))
        {
            floor = mid;
            break;
        }
        else if(arr[mid] >= ele && (mid>0 && (arr[mid-1] >= ele)))
        {
            last = mid-1;
        }
        else
        {
            start = mid+1;
        }
    }
    start = 0, last = N-1;
    while(start <= last)
    {
        int mid = start + (last - start)/2;
        if(arr[mid] == ele && (mid+1 == N || arr[mid+1] > ele))
        {
            ceil = mid;
            break;
        }
        else if(arr[mid] <= ele && (mid+1<N && (arr[mid+1] <= ele)))
        {
            start = mid+1;
        }
        else
        {
            last = mid-1;
        }
        
    }
    ofile<<"start: "<<str(floor)<<" last: "<<str(ceil)<<endl;
    cout<<ceil-floor+1<<endl;
    logs<<"Terminated.\n";
    return 0;
}