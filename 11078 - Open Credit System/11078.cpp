#include <iostream>

using namespace std;

int main()
{
    int cases = 0;
    int n0 = 0;
    int n1 = 0;
    int n2 = 0;
    int n3 = 0;
    int max = 0;
    int rec = 0;

    cin>>cases;
    for(int i0 = 0; i0<cases; i0++)
    {
        cin>>n0;
        cin>>n1;
        cin>>n2;
        if(n0 == 2)
        {
            //cout<<"answer: "<<n1-n2<<endl;
            cout<<n1-n2<<endl;
            continue;
        }
        rec = n1-n2;
        if(n1 < n2)
        {
            max = n2;
        }
        else
        {
            max = n1;
        }
        for(int i3 = 0; i3 < n0-2; i3++)
        {
            cin>>n3;
            if(max-n3 > rec)
            {
                rec = max-n3;
            }
            if(n3 > max)
            {
                max = n3;
            }
        }
        //cout<<"answer: "<<rec<<endl;
        cout<<rec<<endl;
    }
    

    return 0;
}