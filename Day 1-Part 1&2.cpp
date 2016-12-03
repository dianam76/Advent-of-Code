#include <fstream>
#include<cmath>
#include <algorithm>

using namespace std;

ifstream fin(".in");
ofstream fout(".out");

string s;
int sum, i,x,nr[10001],y,j,g,l,k;
char v[10001];
pair<int,int> coord[1001];

int main()
{
    getline(fin,s);
    ++j;
    if(s[0]== 'L')
        v[1] = 'V';
    else v[1] = 'E';

    for(i = 1; i < s.size(); ++i)
        if(s[i]=='L')
            {
                ++j;
                if(v[j-1]=='E')
                    v[j]='N';
                else if(v[j-1]=='V')
                    v[j] = 'S';
                else if(v[j-1]=='S')
                    v[j] = 'E';
                else v[j] = 'V';
            }
        else if(s[i]=='R')
            {
                ++j;
                if(v[j-1]=='E')
                    v[j]='S';
                else if(v[j-1]=='V')
                    v[j] = 'N';
                else if(v[j-1]=='S')
                    v[j] = 'V';
                else v[j] = 'E';
            }


    for(i = 0; i < s.size(); ++i)
        if((s[i]=='L')||(s[i]=='R'))
        {
            ++k;
            while((s[i+1]>='0')&&(s[i+1]<='9'))
            {
                nr[k]*=10;
                nr[k]+=s[i+1]-'0';
                ++i;
            }
        }


    for(i = 1; i <= k;++i)
        if(v[i]=='S')
        {
            for(g = 1; g <= nr[i]; ++g)

                coord[++l] = make_pair(--x,y);


            for(j = 1; j <= l; ++j)
                    for(g = j+1; g <= l; ++g)
                    if(coord[j]==coord[g])
                  {
                      fout <<abs(coord[j].first)+abs(coord[j].second);
                      return 0;
                  }
        }
        else if(v[i]=='N')
            {
                for(g = 1; g <= nr[i]; ++g)

                    coord[++l] = make_pair(++x,y);

                for(j = 1; j <= l; ++j)
                    for(g = j+1; g <= l; ++g)
                    if(coord[j]==coord[g])
                      {
                          fout <<abs(coord[j].first)+abs(coord[j].second);
                          return 0;
                      }
            }
        else if(v[i]=='E')
            {
             for(g = 1; g <= nr[i]; ++g)

                    coord[++l] = make_pair(x,++y);

            for(j = 1; j <= l; ++j)
                    for(g = j+1; g <= l; ++g)
                    if(coord[j]==coord[g])
                  {
                      fout <<abs(coord[j].first)+abs(coord[j].second);
                      return 0;
                  }
            }
        else {
                for(g = 1; g <= nr[i]; ++g)

                    coord[++l] = make_pair(x,--y);

                for(j = 1; j <= l; ++j)
                    for(g = j+1; g <= l; ++g)
                    if(coord[j]==coord[g])
                      {
                          fout <<abs(coord[j].first)+abs(coord[j].second);
                          return 0;
                      }
        }

    sum = abs(x)+abs(y);
    fout << '\n';
    fout << sum;

    return 0;
}
