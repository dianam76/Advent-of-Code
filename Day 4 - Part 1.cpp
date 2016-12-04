#include <fstream>
#include<cmath>
#include <algorithm>

using namespace std;

ifstream fin(".in");
ofstream fout(".out");

pair<int, char> v[10001];

int i,j,nr,k,sum;
string s;
bool ok, okr;

bool comp(pair<int,char> a, pair<int,char> b)
{
    if(a.first!=b.first)
        return a.first>b.first;
    return a.second<b.second;
}

int main()
{
    while(fin >> s)
    {
        nr = 0;
        k = 0;
        for(i = 0; i < s.size(); ++i)
            if(s[i]=='[')
                {
                    sort(v + 1, v + k + 1,comp);
                    for(j = 1; j <= 5; ++j)
                        if(v[j].second!=s[i+j])
                            okr = 1;
                    if(!okr)
                        sum += nr;
                    okr = 0;
                    break;

                }
            else if((s[i]<='z')&&(s[i]>='a'))
            {
                for(j = 1; j <= k; ++j)
                    {
                        if(s[i]==v[j].second)
                            {++v[j].first;
                            ok = 1;}
                    }
                if(!ok)
                    {
                        ++k;
                        v[k] = make_pair(1,s[i]);
                    }
                ok = 0;
            }
            else if((s[i]<='9')&&(s[i]>='0'))
            {
                nr*=10;
                nr+=s[i]-'0';
            }
    }


    fout << sum;


    return 0;
}
