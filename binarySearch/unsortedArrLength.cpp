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
    int _max = INT_MIN, _min = INT_MAX;
    int start = N, last = -1;
    int n = 0;
    for(; n < N-1; n++)
    {
        if(arr[n] > arr[n+1])
        break;
    }
    if(n==N)
    {
        ofile<<"It's already sorted.\n";
        exit(0);
    }
    else
    {
        start = n, last = n+1;
        _min = arr[n+1];
        _max = arr[n];
        n++;
        for(; n < N; n++)
        {
            if(arr[n] > arr[n+1])
            {
                last = n+1;
                _min = min(_min, arr[n+1]);
                _max = max(_max, arr[n]);
                if(start==0)continue;
                if(arr[n+1] < arr[start-1])
                {
                    start = lower_bound(arr, arr+start-1, arr[n+1]) - arr;
                }
            }
            else if(arr[n] < _min)
            {
                start = lower_bound(arr, arr+start-1, arr[n+1]) - arr;
            }
        }
        ofile<<"start: "<<str(start)<<" last: "<<last<<endl;
        cout<<last-start<<endl;
    }
    
    logs<<"Terminated.\n";
    return 0;
}