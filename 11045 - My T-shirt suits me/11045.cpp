#include <iostream>
#include <vector>
#include <string>
// #include <fstream>

using namespace std;

int enc(string s0) // encode
{
    if(s0 == "XS")
    {
        return 0;
    }
    else if(s0 == "S")
    {
        return 1;
    }
    else if(s0 == "M")
    {
        return 2;
    }
    else if(s0 == "L")
    {
        return 3;
    }
    else if(s0 == "XL")
    {
        return 4;
    }
    else if(s0 == "XXL")
    {
        return 5;
    }
    else
    {
        return -1;
    }
}

class node
{
    public:
    bool color;
    int s1; // size 1
    int s2; // size 2
    node()
    {
        this->color = true;
        this->s1 = -1;
        this->s2 = -1;
    }
    node(int n1, int n2)
    {
        this->color = true;
        this->s1 = n1;
        this->s2 = n2;
    }
};

bool check(vector<node> v0, int n0)
{
    vector<int> v1;
    v1.clear();
    v1.resize(6);

    for(int i0 = 0; i0 < 6; i0++)
    {
        v1[i0] = 0;
    }
    for(int i1 = 0; i1 < v0.size(); i1++)
    {
        if(v0[i1].color)
        {
            v1[v0[i1].s1] ++;
        }
        else
        {
            v1[v0[i1].s2] ++;
        }
    }
    for(int i2 = 0; i2 < 6; i2++)
    {
        if(v1[i2] > n0)
        {
            return false;
        }
    }
    return true;
}

void shownv(vector<node> v0)
{
    if(v0.empty())
    {
        exit(0);
    }
    else
    {
        for(int i0 = 0; i0 < v0.size(); i0++)
        {
            cout<<"node"<<i0<<':'<<v0[i0].color<<v0[i0].s1<<v0[i0].s2<<' ';
        }
        cout<<endl;
    }
}

int main()
{
    vector<node> v0;
    vector<node> v1;
    string s0;
    string s1;
    // fstream f0;
    // f0.open("p1_out.txt", ios::out);
    int n0;
    int n1;
    int n2;
    bool ok0;
    cin>>n0;
    for(int i0 = 0; i0 < n0; i0++)
    {
        v0.clear();
        v1.clear();
        ok0 = false;
        cin>>n1>>n2;
        for(int i1 = 0; i1 < n2; i1++)
        {
            // cout<<"here0"<<endl;
            cin>>s0>>s1;
            node nd0(enc(s0), enc(s1));
            v0.push_back(nd0);
        }
        n1 = int(n1/6);
        v1 = v0;
        while(!v1.empty() && !ok0)
        {
            if(v1.size() == n2)
            {
                if(check(v1, n1))
                {
                    // cout<<"here1"<<endl;
                    ok0 = true;
                }
                else
                {
                    while(!v1.empty() && !v1[v1.size()-1].color)
                    {
                        // cout<<"here2"<<endl;
                        v1.pop_back();
                    }
                    if(!v1.empty())
                    {
                        v1[v1.size()-1].color = false;
                    }
                }
            }
            else
            {
                // cout<<"here3"<<endl;
                v1.push_back(v0[v1.size()]);
            }
            // shownv(v1);
        }
        if(ok0)
        {
            cout<<"YES"<<endl;
            // f0<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
            // f0<<"NO"<<endl;
        }
    }
    // f0.close();
    return 0;
}