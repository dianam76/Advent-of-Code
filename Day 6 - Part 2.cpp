#include <fstream>
#include<cmath>
#include <algorithm>

using namespace std;

ifstream fin(".in");
ofstream fout(".out");

int i,j,k,g,h;
string s,sf;
bool ok;
pair<char,int> v[10001];

bool comp(pair<char,int>a, pair<char,int>b)
{
    return a.second>b.second;
}

int main()
{
    while(fin>>sf)
        s+=sf;

    h = sf.size();

    for(g = 0; g < h; ++g)
    {
        for(i = g; i < s.size(); i+=8)
        {
            for(j = 1; j <= k; ++j)
                if(s[i]==v[j].first)
                    {
                        ok = 1;
                        ++v[j].second;
                    }
            if(!ok)
            {
                ++k;
                v[k] = make_pair(s[i],1);
            }
            ok = 0;

        }
        sort(v+1,v+k+1,comp);
        fout <<v[k].first;
        for(i = 1; i <= k; ++i)
            v[i]=make_pair('0',0);
        k = 0;
    }


    return 0;
}
