#include <fstream>
#include<cmath>
#include <algorithm>

using namespace std;

ifstream fin(".in");
ofstream fout(".out");

int m[6][6],i,x,y,j,k;
string s;


int main()
{
    m[1][3] = 1;
    m[2][2] = 2;
    m[2][3] = 3;
    m[2][4] = 4;
    m[3][1] = 5;
    m[3][2] = 6;
    m[3][3] = 7;
    m[3][4] = 8;
    m[3][5] = 9;
    m[4][2] = 10;
    m[4][3] = 11;
    m[4][4] = 12;
    m[5][3] = 13;

    x = 3;
    y = 1;

   while(fin>>s)
   {
       for(i = 0; i < s.size(); ++i)
        if(s[i]=='U')
            {
                if((x>1)&&(m[x-1][y]))
                    --x;
            }
        else if(s[i]=='D')
            {
                if((x<5)&&(m[x+1][y]))
                    ++x;
            }
        else if(s[i]=='L')
            {
                if((y>1)&&(m[x][y-1]))
                    --y;
            }
        else if(s[i]=='R')
            {
                if((y<5)&&(m[x][y+1]))
                    ++y;
            }

        if(m[x][y]<10)
            fout << m[x][y];
        else if(m[x][y]==10)
                fout << 'A';
        else if(m[x][y]==11)
                fout << 'B';
        else if(m[x][y]==12)
                fout << 'C';
        else if(m[x][y]==13)
                fout << 'D';

   }

    return 0;
}
