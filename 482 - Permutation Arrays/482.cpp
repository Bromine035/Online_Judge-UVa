#include <iostream>
#include <vector>
#include <string>
// #include <fstream>

using namespace std;

void showv(vector<int> v0)
{
    if(v0.empty())
    {
        ;
    }
    else if(v0.size() == 1)
    {
        cout<<v0[0]<<endl;
    }
    else
    {
        for(int i0 = 0; i0 < v0.size() -1; i0++)
        {
            cout<<v0[i0]<<' ';
        }
        cout<<v0[v0.size()-1]<<endl;
    }
}

vector<int> stovi(string s0)
{
    vector<int> vi;
    string s1;
    int foot0 = 0;
    s0.push_back(' ');
    for(int i0 = 0; i0 < s0.length(); i0++)
    {
        if(s0[i0] == ' ')
        {
            s1.assign(s0, foot0, i0-foot0);
            vi.push_back(stoi(s1));
            foot0 = i0+1;
        }
    }
    return vi;
}

int main()
{
    vector<int> v0;
    vector<int> v1;
    vector<string> vs;
    int n0 = 0;
    int turns = 0;
    string s0;
    // fstream fp;
    // fp.open("p4_out.txt");
    cin>>turns;
    getline(cin, s0);
    getline(cin, s0);
    for(int i0 = 0; i0 < turns; i0++)
    {
        vs.clear();
        getline(cin, s0);
        v0 = stovi(s0);
        v1.assign(v0.size()+1, -1);
        for(int i2 = 0; i2 < v0.size(); i2++)
        {
            v1[v0[i2]] = i2;
        }
        for(int i2 = 1; i2 < v1.size(); i2++)
        {
            while(vs.size() < v1[i2]+1)
            {
                cin>>s0;
                vs.push_back(s0);
            }
            cout<<vs[v1[i2]]<<endl;
            // fp<<vs[v1[i2]]<<endl;
        }
        if(i0 != turns-1)
        {
            cout<<endl;
            // fp<<endl;
            getline(cin, s0);
            getline(cin, s0);
        }   
    }
}