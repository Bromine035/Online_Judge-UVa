#include <iostream>
#include <vector>
#include <cmath>
// #include <fstream>

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
                // cout<<"check 2: "<<n0<<endl;
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
                // cout<<"check 2: "<<n0<<endl;
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

bool findv(vector<int> v0, int n0)
{
    if(!v0.empty())
    {
        for(int i0 = 0; i0 < v0.size(); i0++)
        {
            if(n0 == v0[i0])
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n0 = 0;
    int n1 = 0;
    int n2 = 0;
    int nd = 0;
    int na = 0;
    vector<int> v0;
    vector<int> v1;
    v0.assign(10, 0);
    v1.assign(10, 0);
    // fstream fp;
    // fp.open("p3_out.txt");

    while(1)
    {
        cin>>n0;
        if(n0 == 0)
        {
            break;
        }
        n1 = 0;
        v1.clear();
        cout<<"Original number was "<<n0<<endl;
        // fp<<"Original number was "<<n0<<endl;
        while(1)
        {
            v0 = itov(n0);
            nd = vtod(v0);
            na = vtoa(v0);
            n2 = nd - na;
            cout<<nd<<" - "<<na<<" = "<<n2<<endl;
            // fp<<nd<<" - "<<na<<" = "<<n2<<endl;
            n1++;
            if(findv(v1, n2))
            {
                break;
            }
            else
            {
                v1.push_back(n2);
                n0 = n2;
            }
        }
        cout<<"Chain length "<<n1<<endl<<endl;
        // fp<<"Chain length "<<n1<<endl<<endl;
    }
    return 0;
}