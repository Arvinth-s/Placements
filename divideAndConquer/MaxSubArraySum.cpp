//OM NAMO NARAYANA
//OM NAMO NARAYANA
#include "myTemplate.h" 
using namespace std;

int maxSumUtil(int arr[], int start, int last)
{
    if(start==last)return arr[start];
    if(start > last)return 0;
    int mid=start + (last-start)/2;
    int l=maxSumUtil(arr, start, mid), r=maxSumUtil(arr, mid+1, last);
    int lmid=INT_MIN, rmid=INT_MIN;
    int psum=0;
    for(int i = mid; i>=start; i--)
    {
        psum+=arr[i];
        lmid=max(lmid, psum);
    }
    psum =0;
    for(int i=mid+1; i<= last; i++)
    {
        psum+=arr[i];
        rmid=max(rmid, psum);
    }
    return max(max(l, r), lmid+rmid);
}

int maxSubSum(int arr[], int N)
{
    return maxSumUtil(arr, 0, N-1);
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
    for(int n=0; n<N; n++)ifile>>arr[n];
    int ans = maxSubSum(arr, N);
    ofile<<str(ans)<<" is the max subarray sum.\n";
    logs<<"Terminated.\n";
    return 0;
}