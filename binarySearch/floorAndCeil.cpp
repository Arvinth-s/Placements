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
    for(int n = 0; n < N; n++)
    {
        ifile>>arr[n];
    }
    int ele;
    ifile>>ele;
    int floor=-1, ceil=N;

    int start = 0, last = N-1;
    while(start <= last)
    {
        int mid = start + (last-start)/2;
        if(arr[mid] <= ele && (mid==0||arr[mid-1]<ele) && (mid+1==N||arr[mid+1] > ele))
        {
            floor = mid;
            break;
        }
        else if(arr[mid] < ele)
        {
            start = mid+1;
        }
        else
        {
            last = mid-1;
        }
        
    }
    start = 0, last = N-1;
    while(start <= last)
    {
        int mid = start + (last - start)/2;
        if(arr[mid] >= ele && (mid==0||arr[mid-1] < ele) && (mid+1==N||arr[mid+1] > ele))
        {
            ceil = mid;
            break;
        } 
        else if(arr[mid] < ele)
        {
            start = mid+1;
        }
        else
        {
            last = mid-1;
        }
    }

    ofile<<"ceil: "+str(ceil)+" floor: "+str(floor)<<endl;
    cout<<floor<<" "<<ceil<<endl;
    logs<<"Files created Successfully\n";
    logs<<"Terminated.\n";
    return 0;
}