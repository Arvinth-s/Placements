//OM NAMO NARAYANA
#include "myTemplate.h" 
#define INF 1e9
using namespace std;

inline double dist(pii a, pii b)
{
    return sqrt((a.ff - b.ff)*(a.ff - b.ff) + (a.ss - b.ss)*(a.ss - b.ss));
}


void msort(pii arr[], int start, int last)
{
    if(start>=last)return;
    int mid = start + (last - start)/2;
    msort(arr, start, mid);
    msort(arr, mid+1, last);
    int i = start, j = mid+1;
    pii temp[last - start + 1];
    int count = 0;
    while(i <= mid && j <= last)
    {
        if(arr[i] < arr[j])
            temp[count++]  = arr[i++];
        else
            temp[count++] = arr[j++];
    }
    while(i <= mid)temp[count++] = arr[i++];
    while(j <= last)temp[count++] = arr[j++];
    for(i = start; i <= last; i++) arr[i] = temp[i-start];
    return;
}

void cp(pii arr[], int start, int last, double& ans)
{
    if(start >= last)return;
    int mid=start+(last-start)/2;
    cp(arr, start, mid, ans);
    cp(arr, mid+1, last, ans);
    vector<pii > a, b;
    for(int i = start; i <= mid; i++)
    {
        if(arr[mid+1].ff - arr[i].ff < ans)
        {
            a.pb(arr[i]);
        }
    }
    for(int i=mid+1; i <= last; i++)
    {
        if(arr[i].ff - arr[mid].ff < ans)
        {
            b.pb(arr[i]);
        }
    }
    for(auto i = a.begin(); i != a.end(); i++)
    {
        pii temp;
        temp.ss = INT_MIN;
        temp.ff = (*i).ff-ans;
        vector<pii >::iterator s = lower_bound(b.begin(), b.end(), temp);
        temp.ff = (*i).ff + start;
        temp.ff;
        vector<pii >::iterator l = lower_bound(b.begin(), b.end(), temp)+1;
        for(auto j = s; j != l; j++)
        {
            ans = min(ans, dist(*i, *j));
        }
    }
    return;
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
    pii arr[N];
    for(int n=0;n<N;n++)
    {
        ifile>>arr[n].ff>>arr[n].ss;
    }
    double ans = INF;
    msort(arr, 0, N-1);
    cp(arr, 0, N-1, ans);
    ofile<<str(ans)<<" is the shortest distance.\n";
    logs<<"Terminated.\n";
    return 0;
}