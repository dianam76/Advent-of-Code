#include <fstream>
#include <string>

using namespace std;

ifstream fin(".in");
ofstream fout(".out");

int nr1,nr2,i;
long long int l,k,nr,nrf,f;
string s;
pair<int,int> x;

pair<int,int> decompress(int i)
{
    k=i;
    int nr1 = 0;
    int nr2 = 0;
    bool ok = 0;
    int nr = 0;
    ++i;
    ++k;
    while((s[i]<='9')&&(s[i]>='0'))
        {
            nr1*=10;
            nr1+=s[i]-'0';
            ++i;
            ++k;
        }
    ++i;
    ++k;
    while((s[i]<='9')&&(s[i]>='0'))
        {
            nr2*=10;
            nr2+=s[i]-'0';
            ++i;
            ++k;
        }
    ++k;

    for(int j = i+1; j < i+nr1; ++j)
        if(s[j]=='(')
            {
                pair<int,int> a = decompress(j);
                nrf+=nr2*a.second;
                j = a.first;
                ok = 1;
            }
    if(!ok)
    {
        nr += nr1*nr2;
        k+=nr1;
        return make_pair(k,nr);
    }

    return make_pair(k,nrf);
}

int main()
{
    fin >> s;

        for(i = 0; i < s.size(); ++i)
            {
                if(s[i] =='(')
                   {
                       x = decompress(i);
                       i = x.first;
                       l+=x.second;
                       nr = 0;
                   }
                else ++l;
            }

    fout << l;

    return 0;
}
