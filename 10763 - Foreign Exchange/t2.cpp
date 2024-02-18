#include <iostream>
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

int main()
{
    vector<vector<int>> vv0;
    vector<int> v0;

    vv0.resize(6);
    vv0[3].resize(5);
    showv(vv0[3]);
    return 0;
}