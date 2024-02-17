#include <iostream>
#include <vector>
#include <cmath>

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
    vector<int> v0;
    v0.assign(6, 0);
    v0[0] = 0; v0[1] = 9; v0[2] = 9; v0[3] = 9; v0[4] = 9; v0[5] = 5;
    cout<<"orig: "<<vtod(v0)<<endl;
    v0 = roundv(v0);
    cout<<"round: "<<vtod(v0)<<endl;

    v0[0] = 0; v0[1] = 9; v0[2] = 9; v0[3] = 9; v0[4] = 9; v0[5] = 3;
    cout<<"orig: "<<vtod(v0)<<endl;
    v0 = roundv(v0);
    cout<<"round: "<<vtod(v0)<<endl;

    v0[0] = 0; v0[1] = 9; v0[2] = 9; v0[3] = 9; v0[4] = 6; v0[5] = 5;
    cout<<"orig: "<<vtod(v0)<<endl;
    v0 = roundv(v0);
    cout<<"round: "<<vtod(v0)<<endl;

    v0[0] = 0; v0[1] = 9; v0[2] = 4; v0[3] = 9; v0[4] = 9; v0[5] = 7;
    cout<<"orig: "<<vtod(v0)<<endl;
    v0 = roundv(v0);
    cout<<"round: "<<vtod(v0)<<endl;

    cout<<"test show: ";
    showv(v0);
}