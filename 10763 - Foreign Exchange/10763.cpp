#include <iostream>
#include <vector>
// #include <fstream>

using namespace std;

int main()
{
    vector<vector<int>> vv0;
    vector<int> v0;
    int n0 = 0;
    int n1 = 0;
    int n2 = 0;
    int nt = 0;

    while(1)
    {
        cin>>n0;
        if(n0 == 0)
        {
            break;
        }
        nt = 0;
        for(int i0 = 0; i0 < n0; i0++)
        {
            cin>>n1;
            cin>>n2;
            if(n1+1 > vv0.size())
            {
                vv0.resize(n1+1);
            }
            if(n2+1 > vv0[n1].size())
            {
                vv0[n1].resize(n2+1);
            }
            if(vv0[n1][n2] != 0)
            {
                vv0[n1][n2] -= 1;
                nt--;
            }
            else
            {
                if(n2+1 > vv0.size())
                {
                    vv0.resize(n2+1);
                }
                if(n1+1 > vv0[n2].size())
                {
                    vv0[n2].resize(n1+1);
                }
                vv0[n2][n1] += 1;
                nt++;
            }
        }
        if(nt == 0)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}