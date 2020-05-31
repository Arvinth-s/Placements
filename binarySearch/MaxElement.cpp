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
    int start = 0, last = N-1;
    int idx = -1;
    while(start <= last)
    {
        int mid = start + (last - start)/2;
        if((mid==0||arr[mid] > arr[mid-1])&&(mid+1==N||arr[mid] > arr[mid+1]))
        {
            idx=mid;
            break;
        }
        else if(mid==0||arr[mid] > arr[mid-1])
        {
            start = mid+1;
        }
        else 
        {
            last = mid-1;
        }
    }
    if(idx == -1)
    {
        ofile<<"pattern mismatch."<<endl;
        exit(0);
    }
    ofile<<str(arr[idx])<<" is the largest element.\n";
    logs<<"Terminated.\n";
    return 0;
}