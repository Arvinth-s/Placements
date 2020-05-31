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
    int start=0, last=N-1;
    int idx=0;
    while(start<=last)
    {
        int mid = start + (last-start)/2;
        if(arr[mid] < arr[0] && arr[mid-1] > arr[0])
        {
            idx=mid;
            break;
        }
        else if(arr[mid] < arr[0])
        {
            last = mid-1;
        }
        else
        {
            start=mid+1;
        }
        
    }
    ofile<<"smallest element: "<<str(arr[idx])<<"\n";
    logs<<"Terminated.\n";
    return 0;
}