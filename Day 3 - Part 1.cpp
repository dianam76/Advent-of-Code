#include <fstream>
#include<cmath>
#include <algorithm>

using namespace std;

ifstream fin(".in");
ofstream fout(".out");

int a,b,c,nr;


int main()
{
    while(fin >> a >> b >>c)
    {
        if((a<b+c)&&(b<a+c)&&(c<a+b))
            ++nr;
    }

    fout << nr;

    return 0;
}
