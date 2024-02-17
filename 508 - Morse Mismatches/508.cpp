#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class morse
{
    public:
    char c0;
    string s0;
    int len;
    morse(char c1 = '*', string s1 = "")
    {
        this->c0 = c1;
        this->s0 = s1;
        this->len = s1.length();
    }
    void show()
    {
        cout<<this->c0<<" : "<<this->s0<<" length: "<<this->len<<endl;
    }
    void edit(char c1 = '*', string s1 = "")
    {
        this->c0 = c1;
        this->s0 = s1;
        this->len = s1.length();
    }
};

string trans(string s0, vector<morse> vm0)
{
    string s1 = "";
    if(s0.empty())
    {
        return s1;
    }
    else
    {
        for(int i0 = 0; i0 < s0.length(); i0++)
        {
            for(int i1 = 0; i1 < vm0.size(); i1++)
            {
                if(s0[i0] == vm0[i1].c0)
                {
                    s1 += vm0[i1].s0;
                    break;
                }
            }
        }
        return s1;
    }
}


class node
{
    public:
    string text;
    string code;
    int lent;
    int lenc;
    int left;
    int right;
    int top;
    node(string text = "", int left = -1, int right = -1, int top = -1)
    {
        this->text = text;
        this->lent = text.length();
        this->code = "";
        this->lenc = this->code.length();
        this->left = left;
        this->right = right;
        this->top = top;
    }
    void show()
    {
        cout<<"text: "<<this->text<<" length: "<<this->lent<<endl;
        cout<<"code: "<<this->code<<endl;
        cout<<"length: "<<this->lenc<<" top: "<<this->top<<endl;
        cout<<"left: "<<this->left<<" right: "<<this->right<<endl;
    }
    void tran(vector<morse> vm0)
    {
        this->code = trans(this->text, vm0);
        this->lenc = this->code.length();
    }
    void edit(string text = "")
    {
        this->text = text;
        this->lent = text.length();
    }
};

int main()
{
    int x0;
    int x1;
    int x2;
    int x3;
    char c0;
    string s0;
    string ss = "*";
    morse m0;
    node n0;
    bool qm = false;
    bool em = false;
    vector<morse> vm0;
    vector<node> vn0;
    vector<node> vn1;
    // fstream fp;
    // fp.open("p4_out.txt");
    while(cin>>c0)
    {
        if(c0 == '*')
        {
            break;
        }
        cin>>s0;
        m0.edit(c0, s0);
        vm0.push_back(m0);
    }
    if(vm0.empty()){return 0;}
    // for(int i0 = 0; i0 < vm0.size(); i0++)
    // {
    //     vm0[i0].show();
    // }
    //x0 = 0;
    while(cin>>s0)
    {
        if(s0 == ss)
        {
            break;
        }
        else
        {
            n0.edit(s0);
            n0.tran(vm0);
            vn0.push_back(n0);
        }
    }
    if(vn0.empty()){return 0;}

    while(cin>>s0)
    {
        if(s0 == ss)
        {
            break;
        }
        qm = true;
        em = false;
        vn1 = vn0;
        for(int i5 = 0; i5 < s0.length(); i5++)
        {
            for(int i6 = 0; i6 < vn1.size(); i6++)
            {
                if(i5 >= vn1[i6].code.length())
                {
                    continue;
                }
                if(s0[i5] != vn1[i6].code[i5])
                {
                    vn1.erase(vn1.begin()+i6);
                    i6--;
                }
            }
        }
        //cout<<"check for: "<<s0<<endl;
        x1 = s0.length() - vn1[0].lenc;
        x1 = abs(x1);
        x2 = 0;
        for(int i7 = 0; i7 < vn1.size(); i7++)
        {
            //vn1[i7].show();
            //cout<<endl;
            x0 = s0.length() - vn1[i7].lenc;
            x0 = abs(x0);
            if(x0 == 0)
            {
                if(!qm)
                {
                    em = true;
                    // if(vn1[i7].lent < x3)
                    // {
                    //     x3 = vn1[i7].lent;
                    //     x2 = i7;
                    // }
                }
                else
                {
                    x2 = i7;
                    //x3 = vn1[i7].lent;
                }
                qm = false;
                x1 = 0; //ok
            }
            else if(x0 < x1)
            {
                x1 = x0;
                x2 = i7;
            }
        }
        cout<<vn1[x2].text;
        if(qm){cout<<'?';}
        if(em){cout<<'!';}
        cout<<endl;

        // fp<<vn1[x2].text;
        // if(qm){fp<<'?';}
        // if(em){fp<<'!';}
        // fp<<endl;
    }
    // fp.close();
    return 0;
}