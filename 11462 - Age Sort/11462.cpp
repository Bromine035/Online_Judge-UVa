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

int main()
{
    int n0 = 0;
    int n1 = 0;
    int n2 = 0;
    vector<int> v0;
    vector<int> v1;
    while(1)
    {
        cin>>n0;
        if(n0 == 0)
        {
            break;
        }
        else if(n0 == 1)
        {
            cin>>n1;
            cout<<n1<<endl;
            continue;
        }
        v0.clear();
        for(int i0 = 0; i0 < n0; i0++)
        {
            cin>>n1;
            if(n1+1 > v0.size())
            {
                v1.assign(n1 - v0.size() + 1, 0);
                v0.insert(v0.end(), v1.begin(), v1.end());
            }
            v0[n1] += 1;
        }
        n1 = n0;
        for(int i2 = 0; i2 < v0.size(); i2++)
        {
            if(v0[i2] == 0)
            {
                continue;
            }
            else
            {
                for(int i3 = 0; i3 < v0[i2]; i3++)
                {
                    n1--;
                    if(n1 == 0)
                    {
                        break;
                    }
                    else
                    {
                        cout<<i2<<' ';
                    }
                }
                if(n1 == 0)
                {
                    n2 = i2;
                    break;
                }
            }
        }
        cout<<n2<<endl;
    }
    return 0;
}