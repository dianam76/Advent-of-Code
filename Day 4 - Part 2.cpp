#include <fstream>
#include<cmath>
#include <algorithm>

using namespace std;

ifstream fin(".in");
ofstream fout(".out");

int i,j,nr,nr1,k,sum;
string s,st="north pole objects ";
bool ok, okr;

int main()
{
    while(fin >> s)
    {
        nr = 0;
        for(i = 0; i < s.size(); ++i)
            if(s[i]=='-')
                s[i] = ' ';
            else if((s[i]<='9')&&(s[i]>='0'))
            {
                nr*=10;
                nr+=s[i]-'0';
            }
        for(i = 0; i <= s.size(); ++i)
            if((s[i]>='a')&&(s[i]<='z'))
                {
                    s[i]-=97;
                    s[i]+=nr%26;
                    s[i]%=26;
                    s[i]+=97;
                }


        if(s[0]=='n')
            fout << s;

        ok = 0;

    }

    return 0;
}
