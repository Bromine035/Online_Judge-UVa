#include <iostream>
#include <string>
#include <vector>

using namespace std;

void show(vector<int> v0)
{
    if(v0.size() == 1)
    {
        cout<<v0[0]<<endl;
    }
    else if(v0.size() > 1)
    {
        for(int i0 = 0; i0 < v0.size()-1; i0++)
        {
            cout<<v0[i0]<<' ';
        }
        cout<<v0[v0.size() - 1]<<endl;
    }
}

vector<int> press(char note)
{
    vector<int> v0;
    v0.assign(10, 0);
    switch (note)
    {
    case 'c':
        v0[1] = 1; v0[2] = 1; v0[3] = 1; v0[6] = 1; v0[7] = 1; v0[8] = 1; v0[9] = 1; 
        break;
    case 'd':
        v0[1] = 1; v0[2] = 1; v0[3] = 1; v0[6] = 1; v0[7] = 1; v0[8] = 1; 
        break;
    case 'e':
        v0[1] = 1; v0[2] = 1; v0[3] = 1; v0[6] = 1; v0[7] = 1; 
        break;
    case 'f':
        v0[1] = 1; v0[2] = 1; v0[3] = 1; v0[6] = 1; 
        break;
    case 'g':
        v0[1] = 1; v0[2] = 1; v0[3] = 1; 
        break;
    case 'a':
        v0[1] = 1; v0[2] = 1; 
        break;
    case 'b':
        v0[1] = 1; 
        break;
    case 'C':
        v0[2] = 1; 
        break;
    case 'D':
        v0[0] = 1; v0[1] = 1; v0[2] = 1; v0[3] = 1; v0[6] = 1; v0[7] = 1; v0[8] = 1; 
        break;
    case 'E':
        v0[0] = 1; v0[1] = 1; v0[2] = 1; v0[3] = 1; v0[6] = 1; v0[7] = 1; 
        break;
    case 'F':
        v0[0] = 1; v0[1] = 1; v0[2] = 1; v0[3] = 1; v0[6] = 1; 
        break;
    case 'G':
        v0[0] = 1; v0[1] = 1; v0[2] = 1; v0[3] = 1; 
        break;
    case 'A':
        v0[0] = 1; v0[1] = 1; v0[2] = 1; 
        break;
    case 'B':
        v0[0] = 1; v0[1] = 1; 
    
    default:
        break;
    }
    //cout<<"check: "<<note<<' ';
    //show(v0);
    return v0;
}

int main()
{
    int turns = 0;
    vector<int> vt;
    vector<int> v1;
    vector<int> v2;
    string s1;

    vt.assign(10, 0);
    cin>>turns;
    getline(cin, s1);
    if(turns < 1)
    {
        return 0;
    }
    for(int i1 = 0; i1 < turns; i1++)
    {
        getline(cin, s1);
        if(s1.empty())
        {
            show(press('h'));
            continue;
        }
        else if(s1.size() == 1)
        {
            show(press(s1[0]));
            continue;
        }
        vt = press(s1[0]);
        for(int i2 = 0; i2 < s1.size() - 1; i2++)
        {
            v1 = press(s1[i2]);
            v2 = press(s1[i2+1]);
            for(int i3 = 0; i3 < 10; i3++)
            {
                if(v1[i3] == 0 and v2[i3] == 1)
                {
                    vt[i3] ++;
                }
            }
        }
        show(vt);
    }
    

    return 0;
}