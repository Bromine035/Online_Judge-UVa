#include <iostream>
#include <vector>
// #include <fstream>

using namespace std;

void showv(vector<int> v0)
{
    if(v0.empty())
    {
        cout<<endl;
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

vector<int> qs(vector<int> vi)
{
    if(vi.empty() or vi.size() == 1)
    {
        return vi;
    }
    else
    {
        int n0 = 0;
        int np = vi.back();
        vector<int> v0;
        vector<int> v1;
        for(int i0 = 0; i0 < vi.size() - 1; i0++)
        {
            if(vi[i0] < np)
            {
                v0.push_back(vi[i0]);
                n0 += v1.size();
            }
            else
            {
                v1.push_back(vi[i0]);
            }
            // cout<<"check: "<<vi[i0]<<' '<<n0<<endl;
        }
        n0 += v1.size();
        // cout<<"v0:";
        // showv(v0);
        // cout<<"v1:";
        // showv(v1);
        // cout<<"check: "<<n0<<endl;
        if(v0.size() > 1)
        {
            v0 = qs(v0);
        }
        if(v1.size() > 1)
        {
            v1 = qs(v1);
        }
        v0.push_back(np);
        v0.insert(v0.end(), v1.begin(), v1.end());
        return v0;
    }
}

long long int qsn(vector<int> vi)
{
    if(vi.empty() or vi.size() == 1)
    {
        return 0;
    }
    else
    {
        long long int n0 = 0;
        int np = vi.back();
        vector<int> v0;
        vector<int> v1;
        for(int i0 = 0; i0 < vi.size() - 1; i0++)
        {
            if(vi[i0] < np)
            {
                v0.push_back(vi[i0]);
                n0 += v1.size();
            }
            else
            {
                v1.push_back(vi[i0]);
            }
            // cout<<"check: "<<vi[i0]<<' '<<n0<<endl;
        }
        n0 += v1.size();
        // cout<<"v0:";
        // showv(v0);
        // cout<<"v1:";
        // showv(v1);
        // cout<<"check: "<<n0<<endl;
        if(v0.size() > 1)
        {
            n0 += qsn(v0);
        }
        if(v1.size() > 1)
        {
            n0 += qsn(v1);
        }
        // v0.push_back(np);
        // v0.insert(v0.end(), v1.begin(), v1.end());
        return n0;
    }
}

int main()
{
    int n0 = 0;
    int n1 = 0;
    long long int na;
    vector<int> v0;
    // fstream fp1;
    // fstream fp2;
    // fp1.open("p2_test2.txt");
    // fp2.open("p2_out.txt");
    while(1)
    {
        cin>>n0;
        // fp1>>n0;
        if(n0 == 0)
        {
            break;
        }
        else if(n0 == 1)
        {
            cin>>n1;
            cout<<0<<endl;
            // fp2<<0<<endl;
            continue;
        }
        v0.clear();
        for(int i0 = 0; i0 < n0; i0++)
        {
            cin>>n1;
            // fp1>>n1;
            v0.push_back(n1);
        }
        // cout<<"check v0 : ";
        // showv(v0);
        na = qsn(v0);
        cout<<na<<endl;
        // fp2<<na<<endl;
        // v0 = qs(v0);
        // cout<<"check qs : ";
        // showv(v0);
        // cout<<n3<<endl;
        // fp<<n3<<endl;
    }
    // fp.close();
    return 0;
}