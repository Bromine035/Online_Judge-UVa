#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

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

void showe(vector<ele> v0, fstream& fp)
{
    for(int i5 = 0; i5 < v0.size(); i5++)
    {
        fp<<"ele #"<<v0[i5].ni<<", weight: "<<v0[i5].we<<", IQ: "<<v0[i5].iq<<endl;
    }
}

int main()
{
    int n0 = 0;
    int n1 = 0;
    int n2 = 0;
    ele e0(0, 0, 0);
    vector<ele> ve0;
    vector<ele> ve1;
    vector<vector<ele>> vv0;
    fstream fp;
    fp.open("t1_out.txt", ios::out);

    while(cin>>n0)
    {
        if(n0 == -1)
        {
            break;
        }
        cin>>n1;
        e0.ni = n2;
        e0.we = n0;
        e0.iq = n1;
        ve0.push_back(e0);
        n2++;
    }

    cin>>n0;
    for(int i0 = 0; i0 < n0; i0++)
    {
        cin>>n1;
        ve1.push_back(ve0[n1-1]);
    }
    cout<<"check correct answer: "<<endl;
    fp<<"check correct answer: "<<endl;
    showe(ve1);
    showe(ve1, fp);
    fp.close();
}