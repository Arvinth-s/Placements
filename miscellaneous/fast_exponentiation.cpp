//OM NAMO NARAYANA
#include<bits/stdc++.h>
#define mbit 30

using namespace std;

long pow(int a, int  n, int m)
{
    long res=1;
    int i=(1<<mbit);
    while(i > 0)
    {
        res*=res;
        if(i&n)
        {
            res *= a;
        }
        res%=m;
        i=i>>1;
    }
    return res;
}

int main()
{
    int a, n, m;
    cin>>a>>n>>m;
    cout<<pow(a, n, m)<<endl;
    return 0;
}