#include <iostream>
#include <vector>
// #include <fstream>

using namespace std;

int maxv(vector<int> v0)
{
    int ni = 0;
    if(v0.empty())
    {
        return -1;
    }
    else if(v0.size() == 1)
    {
        // return v0[0];
        return 0;
    }
    else
    {
        int n0 = v0[0];
        for(int i0 = 1; i0 < v0.size(); i0++)
        {
            if(v0[i0] > n0)
            {
                n0 = v0[i0];
                ni = i0;
            }
        }
        return ni;
    }
}

class ele
{
    public:
    int ni; // index
    int iq;
    int we;
    ele()
    {
        this->ni = 0;
        this->iq = 0;
        this->we = 0;
    }
    ele(int n, int i, int w)
    {
        this->ni = n;
        this->iq = i;
        this->we = w;
    }
};

void showe(vector<ele> v0)
{
    for(int i5 = 0; i5 < v0.size(); i5++)
    {
        cout<<"ele #"<<v0[i5].ni<<", weight: "<<v0[i5].we<<", IQ: "<<v0[i5].iq<<endl;
    }
}

// void showe(vector<ele> v0, fstream& fp)
// {
//     for(int i5 = 0; i5 < v0.size(); i5++)
//     {
//         fp<<"ele #"<<v0[i5].ni<<", weight: "<<v0[i5].we<<", IQ: "<<v0[i5].iq<<endl;
//     }
// }

int main()
{
    int n0 = 0;
    int n1 = 0;
    int n2 = 0;
    ele e0(0, 0, 0);
    vector<ele> ve0;
    vector<ele> ve1;
    vector<int> v0;
    vector<int> v1;
    vector<vector<ele>> vv0;
    vector<vector<ele>> vv1;
    vector<vector<ele>> vve;
    // fstream fp;
    // fp.open("p1_out.txt", ios::out);
    while(cin>>n0)
    {
        // if(n0 == -1)
        // {
        //     break;
        // }
        cin>>n1;
        e0.ni = n2;
        e0.we = n0;
        e0.iq = n1;
        // ve0.push_back(e0);
        if(n0 + 1 > vv0.size())
        {
            vv0.resize(n0+1);
        }
        vv0[n0].push_back(e0);
        n2++;
    }

    if(n2 == 1)
    {
        cout<<"1\n1"<<endl;
        // fp<<"1\n1"<<endl;
        return 0;
    }

    for(int i0 = 0; i0 < vv0.size(); i0++)
    {
        if(vv0[i0].empty())
        {
            continue;
        }
        for(int i1 = 0; i1 < vv0[i0].size(); i1++)
        {
            if(vv0[i0][i1].iq + 1 > vv1.size())
            {
                vv1.resize(vv0[i0][i1].iq + 1);
            }
            vv1[vv0[i0][i1].iq].push_back(vv0[i0][i1]);
        }
        for(int i7 = vv1.size() - 1; i7 > -1; i7--)
        {
            if(vv1[i7].empty())
            {
                continue;
            }
            for(int i8 = 0; i8 < vv1[i7].size(); i8++)
            {
                ve1.push_back(vv1[i7][i8]);
            }
        }
        vv1.clear();
    }

    // showe(ve1);
    // showe(ve1, fp);
    // cout<<" _______   _______ "<<endl;
    // fp<<" _______   _______ "<<endl;

    vve.resize(1);
    vve[0].push_back(ve1[0]);

    for(int i2 = 1; i2 < ve1.size(); i2++)
    {
        for(int i3 = 0; i3 < vve.size(); i3++)
        {
            if((ve1[i2].we > vve[i3].back().we) and (ve1[i2].iq < vve[i3].back().iq))
            {
                // cout<<"check: "<<ve1[i2].iq<<endl;
                // cout<<"check: "<<ve1[i2].we<<endl;
                // cout<<"check: "<<vve[i3].back().iq<<endl;
                // cout<<"check: "<<vve[i3].back().we<<endl;
                // vve[i3].push_back(ve1[i2]);
                v0.push_back(i3);
                v1.push_back(vve[i3].size());
            }
        }
        if(v0.empty())
        {
            vector<ele> ve2{ve1[i2]};
            vve.push_back(ve2);
        }
        else
        {
            n0 = maxv(v1);
            ve0 = vve[v0[n0]];
            ve0.push_back(ve1[i2]);
            vve.push_back(ve0);
        }
        // else if(v0.size() > 1)
        // {
        //     n0 = maxv(v1);
        //     cout<<"check n0: "<<n0<<' '<<v0.size()<<' '<<vve.size()<<' '<<v0[0]<<endl;
        //     fp<<"check n0: "<<n0<<' '<<v0.size()<<' '<<vve.size()<<' '<<v0[0]<<endl;
        //     vve[v0[0]] = vve[v0[n0]];
        //     for(int i4 = v0.size()-1; i4 > 0; i4--)
        //     {
        //         vve.erase(vve.begin() + v0[i4]);
        //     }
        //     cout<<"check vve size: "<<vve.size()<<endl;
        // }
        v0.clear();
        v1.clear();

        // cout<<"check vve: "<<endl;
        // fp<<"check vve: "<<endl;
        // for(int i3 = 0; i3 < vve.size(); i3++)
        // {
        //     showe(vve[i3]);
        //     showe(vve[i3], fp);
        //     cout<<" _____ ____ _______ "<<endl;
        //     fp<<" _____ ____ _______ "<<endl;
        // }
        // cout<<endl;
        // fp<<endl;
    }

    for(int i5 = 0; i5 < vve.size(); i5++)
    {
        v0.push_back(vve[i5].size());
        // showe(vve[i5]);
        // showe(vve[i5], fp);
        // cout<<"________"<<endl;
        // fp<<"________"<<endl;
    }
    ve0 = vve[maxv(v0)];
    // cout<<"check answer: "<<endl;
    // fp<<"check answer: "<<endl;
    // showe(ve0);
    // showe(ve0, fp);

    cout<<ve0.size()<<endl;
    // fp<<ve0.size()<<endl;
    for(int i6 = 0; i6 < ve0.size(); i6++)
    {
        cout<<ve0[i6].ni+1<<endl;
        // fp<<ve0[i6].ni+1<<endl;
    }
    // fp.close();
    return 0;
}