#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

class node
{
    public:
    int order;
    string text;
    int len;
    int left;
    int right;
    int top;
    node(int order = -1, string text = "", int left = -1, int right = -1, int top = -1)
    {
        this->order = order;
        this->text = text;
        this->len = text.length();
        this->left = left;
        this->right = right;
        this->top = top;
    }
    void show()
    {
        cout<<"order: "<<this->order<<endl;
        cout<<"text: "<<this->text<<endl;
        cout<<"length: "<<this->len<<" top: "<<this->top<<endl;
        cout<<"left: "<<this->left<<" right: "<<this->right<<endl;
    }
    void edit(string text = "")
    {
        this->text = text;
        this->len = text.length();
    }
};

int main ()
{
    string s0 = "..-.---.--...";
    string s1 = ".--.-.-...-";\
    int x = 0;
    // node n0(0, "--..--", 3, 2, 1);
    // node n1;
    // node nr;
    // node nt;
    // nt.edit("test");
    // nr.order = -2;
    // n0.show();
    // n1.show();
    // vector<node> v0;
    // v0.clear();
    // v0.push_back(n0);
    // v0[0].show();
    // n0.edit("...---.-");
    // n0.top = 6;
    // n0.order = 1;
    // v0.push_back(n0);
    // v0[1].show();
    // v0.insert(v0.begin(), nr);
    // v0[0].show();
    // v0.insert(v0.begin()+2, nt);
    // v0[2].show();
    cout<<s0.length()<<' '<<s1.length()<<' '<<s1.length()-s0.length()<<endl;
    cout<<typeid(s0.length()).name()<<endl;
    x = s1.length()-s0.length();
    cout<<x<<endl;
}