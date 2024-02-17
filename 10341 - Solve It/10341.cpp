#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

double vtod(vector<int> v0)
{
    double x = 0.0;
    for(int i0 = 0; i0 < v0.size(); i0++)
    {
        x += v0[i0]*pow(10, -(i0));
    }
    return x;
}

vector<int> roundv(vector<int> v0)
{
    int n0 = 4;
    if(v0[5] > 4)
    {
        while(v0[n0] == 9 and n0 > 0)
        {
            n0--;
        }
        for(int i0 = 4; i0 > n0; i0--)
        {
            v0[i0] = 0;
        }
        v0[n0] += 1;
        v0[5] = 0;
    }
    else
    {
        v0[5] = 0;
    }
    return v0;
}

void showv(vector<int> v0)
{
    cout<<v0[0]<<'.';
    for(int i0 = 1; i0 < 5; i0++)
    {
        cout<<v0[i0];
    }
    cout<<endl;
}

int main()
{
    int p = 0;
    int q = 0;
    int r = 0;
    int s = 0;
    int t = 0;
    int u = 0;
    double x0 = 0.0;
    int x1 = 0;
    double y0 = 0.0;
    double y1 = 0.0;
    vector<int> v0;
    v0.assign(6, 0);
    //fstream fp;
    //fp.open("./p1_out.txt");

    while(cin>>p)
    {
        if(p == -1)
        {
            break;
        }
        cin>>q;
        cin>>r;
        cin>>s;
        cin>>t;
        cin>>u;

        for(int i0 = 1; i0 < 6; i0++)
        {
            x1 = 0;
            for(int i1 = 0; i1 < 11; i1++)
            {
                x0 = vtod(v0) + i1*pow(10, -(i0));
                y0 = p*exp(-x0) + q*sin(x0) + r*cos(x0) + s*tan(x0) + t*pow(x0, 2) + u;
                if(y0 <= 0 and y1 > 0)
                {
                    x1 = (i1 - 1);
                    //cout<<"check x1: "<<x1<<endl;
                }
                y1 = y0;
            }
            v0[i0] = x1;
            y1 = 0.0;
        }
        v0 = roundv(v0);

        y0 = p + r + u;
        y1 = p*exp(-1) + q*sin(1) + r*cos(1) + s*tan(1) + t*pow(1, 2) + u;
        if(y0 < 0 or y1 > 0.00005)
        {
            cout<<"No solution"<<endl;
        }
        else if(y0 == 0)
        {
            cout<<"0.0000"<<endl;
        }
        else if(0 <= y1 and y1 < 0.00005)
        {
            cout<<"1.0000"<<endl;
        }
        else
        {
            showv(v0);
            // fp<<v0[0]<<'.';
            // for(int i0 = 1; i0 < 5; i0++)
            // {
            //     fp<<v0[i0];
            // }
            // fp<<endl;
        }

        v0.assign(6, 0);
        y1 = 0.0;
    }
    //fp.close();

    return 0;
}