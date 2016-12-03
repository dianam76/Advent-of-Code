#include <fstream>
#include<cmath>
#include <algorithm>

using namespace std;

ifstream fin(".in");
ofstream fout(".out");

int m[4][4],i,x,y,j,k;
string s;


int main()
{
    for(i = 1; i <= 3; ++i)
        for(j = 1; j <= 3; ++j)
            m[i][j]= ++k;

    x = y = 2;

   while(fin>>s)
   {
       for(i = 0; i < s.size(); ++i)
        if(s[i]=='U')
            {
                if(x>1)
                    --x;
            }
        else if(s[i]=='D')
            {
                if(x<3)
                    ++x;
            }
        else if(s[i]=='L')
            {
                if(y>1)
                    --y;
            }
        else if(s[i]=='R')
            {
                if(y<3)
                    ++y;
            }

        fout << m[x][y];

   }

    return 0;
}
