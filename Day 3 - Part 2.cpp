#include <fstream>
#include<cmath>
#include <algorithm>

using namespace std;

ifstream fin(".in");
ofstream fout(".out");

int a,b,c,nr,i,v[101];


int main()
{
    while(fin >> v[1])
    {
        for(i = 2; i <= 9; ++i)
            fin >> v[i];
        if((v[2]< v[5]+v[8])&&(v[5]<v[2]+v[8])&&(v[8]<v[2]+v[5]))
            ++nr;
        if((v[3]< v[6]+v[9])&&(v[6]<v[3]+v[9])&&(v[9]<v[3]+v[6]))
            ++nr;
        if((v[1]< v[4]+v[7])&&(v[4]<v[1]+v[7])&&(v[7]<v[1]+v[4]))
            ++nr;

    }

    fout << nr;

    return 0;
}
