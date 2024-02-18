#include <iostream>
#include <vector>
#include <fstream>

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

int maxv(vector<int> v0)
{
    if(v0.empty())
    {
        return 0;
    }
    else if(v0.size() == 1)
    {
        return v0[0];
    }
    else
    {
        int n0 = v0[0];
        for(int i0 = 1; i0 < v0.size(); i0++)
        {
            if(v0[i0] > n0)
            {
                n0 = v0[i0];
            }
        }
        return n0;
    }
}


int main()
{
    vector<vector<int>> vv0;
    vector<int> v0{1, 2, 3, 4, 5, 6};
    vector<int> v1{4, 5, 6};
    fstream fp;
    // fp.open("p2_test1.txt");
    // int n0 = 100000;
    // vv0.push_back(v0);
    // vv0.resize(6);
    // vv0[3] = v0;
    // vv0[4].push_back(100);
    // for(int i0 = 0; i0 < vv0.size(); i0++)
    // {
    //     cout<<"check "<<i0<<" : ";
    //     showv(vv0[i0]);
    // }
    // cout<<maxv(v0)<<endl;
    // v0.clear();
    // cout<<v0.size()/2<<endl;
    // fp<<n0+2<<endl;
    // for(int i1 = 0; i1 < n0/2+1; i1++)
    // {
    //     fp<<i1<<endl;
    //     fp<<n0-i1<<endl;
    // }
    // fp<<0<<endl;
    // fp.close();
    // v1.insert(v1.end(), v0.size(), 8);
    // showv(v1);
    // cout<<v0.front()<<' '<<v0.back()<<endl;;
    // v0.resize(8);
    showv(v0);
    swap(v0[2], v0[4]);
    showv(v0);
    v0.assign(v0.begin()+1, v0.begin()+1);
    showv(v0);
    v0.insert(v0.end(), v1.begin(), v1.end());
    showv(v0);
    cout<<(5-3-1)<<endl;
    v0.assign(v1.begin(), v1.end()-1);
    showv(v0);
    cout<<v0.back()<<endl;
    return 0;
}