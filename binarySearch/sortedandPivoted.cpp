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
    int start = 0, last = N-1, pivot = -1;
    while(start <= last)
    {
        int mid = start+(last-start)/2;
        if(mid == 0)
        {
            if(arr[0] > arr[1])pivot = 1;
            else pivot = 0;
            break;
        }
        if(mid == N-1)
        {
            if(arr[N-1] < arr[N-2])pivot=N-1;
            else pivot = N-2;
            break;
        }
        if(arr[mid] < arr[mid-1] && arr[mid] <= arr[mid+1])
        {
            pivot = mid;
            break;
        }
        if(arr[mid] <= arr[mid-1])
        {
            last = mid-1;
        }
        else start = mid+1;
    }
    ofile<<"pivot:"+str(pivot)+"\n";
    int idx;
    if(ele < arr[pivot])
    {
        cout<<-1<<endl;
        ofile<<"Not found\n";
        exit(0);
    }
    if(ele == arr[0])idx=0;
    else if(ele > arr[0])
        idx = lower_bound(arr, arr+pivot-1, ele)-arr;
    else
        idx = lower_bound(arr+pivot, arr+N, ele)-arr;
    if(idx==-1||arr[idx] == ele)
    {
        ofile<<str(ele)<<" found in index "<<idx<<endl;
        cout<<idx;
    }
    else
    {
        ofile<<str(ele)<<" not found."<<endl;
    }
    logs<<"Terminated.\n";
    return 0;
}