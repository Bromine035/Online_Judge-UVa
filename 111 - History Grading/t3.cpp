#include <iostream>
#include <string>
#include <vector>

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
    int n0 = 0;
    vector<int> v0;
    string s0 = "495243";
    n0 = stoi(s0);
    cout<<n0<<endl;
    s0 = "495 435 643";
    v0 = stovi(s0);
    showv(v0);
    return 0;
}