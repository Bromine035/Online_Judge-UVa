#include <iostream>
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
    vector<int> v0{1, 2, 3};
    vector<int> v1;
    v1.assign(5, 0);
    v0.insert(v0.end(), v1.begin(), v1.end());
    showv(v0);
    v0.clear();
    cout<<v0.size()-1<<endl;
}