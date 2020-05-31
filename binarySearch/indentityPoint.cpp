//OM NAMO NARAYANA
#include "myTemplate.h" 
using namespace std;

//assuming no repeated elements
int binSearch(int arr[], int start, int last)
{
    while(start <= last)
    {
        int mid = start + (last - start)/2;
        if(arr[mid] == mid)
        {
            return mid;
        }
        else if(arr[mid] > mid)
        {
            last = mid-1;
        }
        else 
        {
            start = mid+1;
        }
    }
    return -1;
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
    int arr[N];
    for(int n=0; n < N; n++)
    {
        ifile>>arr[n];
    }
    int ans = binSearch(arr, 0, N-1);
    ofile<<str(ans)<<" is an identity point\n";
    logs<<"Terminated.\n";
    return 0;
}