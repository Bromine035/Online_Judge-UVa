#include <iostream>
#include <string>
#include <vector>
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

int lcs(vector<int> vx, vector<int> vy, int nl)
{
    int n0 = 0;
    int n1 = 0;
    vector<vector<int>> vv0;
    vv0.resize(nl+1);
    for(int i0 = 0; i0 < nl+1; i0++)
    {
        vv0[i0].resize(nl+1);
    }
    for(int i1 = 0; i1 < nl; i1++)
    {
        for(int i2 = 0; i2 < nl; i2++)
        {
            if(vx[i1] == vy[i2])
            {
                n0 = vv0[i1][i2] + 1;
                vv0[i1+1][i2+1] = n0;
                if(n0 > n1)
                {
                    n1 = n0;
                }
            }
            else
            {
                if(vv0[i1][i2+1] >= vv0[i1+1][i2])
                {
                    n0 = vv0[i1][i2+1];
                    vv0[i1+1][i2+1] = n0;
                }
                else
                {
                    n0 = vv0[i1+1][i2];
                    vv0[i1+1][i2+1] = n0;
                }
            }
        }
    }
    return n1;
}

int main()
{
    string s0;
    vector<int> v0;
    vector<int> vx;
    vector<int> vy;
    int nl = 0; // length
    int n0 = 0;
    // fstream fp;
    // fp.open("p3_out.txt", ios::out);
    while(getline(cin, s0))
    {
        v0 = stovi(s0);
        if(v0.size() == 1)
        {
            if(v0[0] == -1)
            {
                break;
            }
            nl = v0[0];
            getline(cin, s0);
            v0 = stovi(s0);
            vx.resize(nl);
            vy.resize(nl);
            for(int i0 = 0; i0 < nl; i0++)
            {
                vx[v0[i0]-1] = i0+1;
            }
            // cout<<"check vx: ";
            // showv(vx);
            continue;
        }
        for(int i0 = 0; i0 < nl; i0++)
        {
            vy[v0[i0]-1] = i0+1;
        }
        // cout<<"check vy: ";
        // showv(vy);
        n0 = lcs(vx, vy, nl);
        cout<<n0<<endl;
        // fp<<n0<<endl;
    }
    // fp.close();
    return 0;
}