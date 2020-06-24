//OM NAMO NARAYANA
#include<bits/stdc++.h>
#include <sys/stat.h> 
#include <sys/types.h> 
#define ll long long
#define vi vector<int>
#define vvi vector<vi >
#define pii pair<int, int>
#define vll vector<ll>
#define str to_string
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define pb push_back
#define pll pair<ll, ll>
#define vvl vector<vll >
#define umap unordered_map
#define pq priority_queue
#define ff first
#define ss second
#define MOD 1e9+7

using namespace std;


char* bin(ll num, char* binary)
{
    cout<<"enterd bin\n";
    int depth = sizeof(ll)/sizeof(bool);
    // char Bin[depth];
    for(int i = 1; i <= depth; i++)
    {
        if(num&1==1)binary[depth-i]='1';
        else binary[depth-i]='0';
        num=num>>1;
    }
    cout<<"successful\n";
    return binary;
}

string c_dir(string fileN)
{
    int input_number;
    cout<<"testcase number:"<<flush;
    cin>>input_number;
    for(int i = 0; i < 4; i++)fileN.pop_back();
    fileN.pb('F');
    char fileF[fileN.size()+1];
    strcpy(fileF, fileN.c_str());
    char* file = fileF;
    fileN.pop_back();
    string dir="";
    int idx=-1;
    for(int i = fileN.size()-1; i >= 0; i--)
    {
        if(fileN[i] == '/')
        {
            idx=i;
            break;
        }
    }
    if(idx==-1)return dir;
    for(int i = idx; i < fileN.size(); i++)
    {
        dir += fileN[i];
    }
    fileN.pb('F');
    dir.pb('F');
    int check = mkdir(file, 0777);
    string fileM = fileN + "/tc"+str(input_number);
    char fileF_input[fileM.size()+1];
    strcpy(fileF_input, fileM.c_str());
    file = fileF_input;
    check = mkdir(file, 0777);

    string fname = "."+dir+"/tc"+str(input_number);
    ifstream ifile(fname+"/input.txt");
    if(!ifile)
    {
        ofstream ofile(fname+"/input.txt");
        if(!ofile)
        {
            cout<<fname+"/input.txt ";
            cout<<"file not created\n";
            exit(0);
        }
        cout<<"number of lines:"<<flush;
        int number_of_lines;
        cin>>number_of_lines;
        string buf;
        getline(cin, buf);
        while(number_of_lines--)
        {
            getline(cin, buf);
            ofile<<buf<<endl;
        }
        ofile.close();
    }
    ofstream logs(fname+"/log.txt");
    logs<<"Initialization Successful\n";
    logs.close();
    return "."+dir+"/tc"+str(input_number);
}