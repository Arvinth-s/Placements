//OM NAMO NARAYANA
//OM NAMO NARAYANA
#include "myTemplate.h" 
#define hh ss
#define bb ff.ff
#define dd ff.ss
using namespace std;

bool mysort(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    if(a.bb != b.bb)
    {
        return (a.bb > b.bb);
    }
    if(a.dd != b.dd)
    {
        return (a.dd > b.dd);
    }
    else
    {
        return(a.hh > b.hh);
    }
    
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
    pair<pair<int, int>, int> box[3*N];
    for(int n=0; n<N; n++)
    {
        ifile>>box[3*n].bb>>box[3*n].dd>>box[3*n].hh;
        box[3*n+1].bb=box[3*n].dd;
        box[3*n+1].dd=box[3*n].hh;
        box[3*n+1].hh=box[3*n].bb;
        box[3*n+2].bb=box[3*n+1].dd;
        box[3*n+2].dd=box[3*n+1].hh;
        box[3*n+2].hh=box[3*n+1].bb;
    }
    sort(box, box+3*N, mysort);
    int _max=0;
    int dp[3*N];
    for(int n=0; n<3*N; n++)
    {
        dp[n]=box[n].hh;
        for(int m=0; m<n;m++)
        {
            if((box[m].bb > box[n].bb) && (box[m].dd > box[n].dd))
            {
                dp[n]=max(dp[n], box[n].hh+dp[m]);
            }
        }
        _max=max(_max,dp[n]);
    }
    ofile<<"The maximum height of the boxes = "<<str(_max)<<endl;
    cout<<_max<<endl;
    logs<<"Terminated.\n";
    return 0;
}