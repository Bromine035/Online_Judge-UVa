#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    int n0 = 0;
    int nl = 500000;
    fstream fp;
    fp.open("p2_test2.txt");
    srand(118);
    fp<<nl<<endl;
    for(int i0 = 0; i0 < nl; i0++)
    {
        n0 = rand()%1000000000;
        fp<<n0<<endl;
    }
    fp<<0<<endl;
    fp.close();
    return 0;
}