//OM NAMO NARAYANA//OM NAMO NARAYANA
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
    //can be viewed as how many times you need to recharge. At each time of recharge
    // it is guranteed that the maximum recharge available at and before that is made
    int maxReach=arr[0], steps=arr[0], jump=1;
    for(int n=1; n<N; n++)
    {
        if(steps == 0)
        {
            steps = maxReach-n;
            jump++;
        }
        steps--;
        if(steps<0)
        {
            ofile<<"-1\n";
            exit(0);
        }
        maxReach = max(maxReach, arr[n]+n);
    }
    ofile<<"Minimum number of jumps = "<<str(jump)<<endl;
    cout<<jump<<endl;
    logs<<"Terminated.\n";
    return 0;
}