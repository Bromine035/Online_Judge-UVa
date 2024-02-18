#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int vtod(vector<int> v0)
{
    int n0 = 0;
    for(int i0 = 9; i0 > -1; i0--)
    {
        if(v0[i0] == 0)
        {
            continue;
        }
        else
        {
            for(int i1 = 0; i1 < v0[i0]; i1++)
            {
                n0 *= 10;
                n0 += i0;
                //cout<<"check 2: "<<n0<<endl;
            }
        }
    }
    return n0;
}

int vtoa(vector<int> v0)
{
    int n0 = 0;
    for(int i0 = 1; i0 < 10; i0++)
    {
        if(v0[i0] == 0)
        {
            continue;
        }
        else
        {
            for(int i1 = 0; i1 < v0[i0]; i1++)
            {
                n0 *= 10;
                n0 += i0;
                //cout<<"check 2: "<<n0<<endl;
            }
        }
    }
    return n0;
}

vector<int> itov(int n0)
{
    vector<int> v0;
    v0.assign(10, 0);
    while(n0>9)
    {
        v0[n0%10] += 1;
        n0 = n0/10;
    }
    v0[n0] += 1;
    return v0;
}

int main()
{
    vector<int> v0{1, 1, 1, 0, 0, 2, 1, 0, 0, 1};
    cout<<vtod(v0)<<endl;
    cout<<vtoa(v0)<<endl;
    cout<<87%10<<' '<<87/10<<endl;

    int n0 = 10974257;
    v0 = itov(n0);
    cout<<vtod(v0)<<endl;
    cout<<vtoa(v0)<<endl;
}