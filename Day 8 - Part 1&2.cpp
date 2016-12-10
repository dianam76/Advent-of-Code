#include <fstream>
#include <string>

using namespace std;

ifstream fin(".in");
ofstream fout(".out");

string s;
int nr1, nr2,nr,i,j;
bool m[10][60], r[10][60];

int main()
{
    while(getline(fin,s))
    {
        nr1 = nr2 = 0;
        i = 0;
        if(s[1]=='e')
        {
            while((s[i]<'0')||(s[i]>'9'))
                ++i;
            while((s[i]>= '0')&&(s[i]<='9'))
                {
                    nr1*=10;
                    nr1+= s[i]-'0';
                    ++i;
                }
            ++i;
            while((s[i]>= '0')&&(s[i]<='9'))
                {
                    nr2*=10;
                    nr2+= s[i]-'0';
                    ++i;
                }
            for(i = 0; i < nr2; ++i)
                for(j = 0; j < nr1; ++j)
                    m[i][j] = 1;

        }
        else if (s[7]=='c')
        {
            while((s[i]<'0')||(s[i]>'9'))
                ++i;
            while((s[i]>= '0')&&(s[i]<='9'))
                {
                    nr1*=10;
                    nr1+= s[i]-'0';
                    ++i;
                }
            i+=4;
            while((s[i]>= '0')&&(s[i]<='9'))
                {
                    nr2*=10;
                    nr2+= s[i]-'0';
                    ++i;
                }
            for(i = 0; i < 6; ++i)
                if(m[i][nr1])
                    r[(i+nr2)%6][nr1] = 1;
            for(i = 0; i < 6; ++i)
                {
                    m[i][nr1] = r[i][nr1];
                    r[i][nr1] = 0;
                }
        }
        else
        {
            while((s[i]<'0')||(s[i]>'9'))
                ++i;
            while((s[i]>= '0')&&(s[i]<='9'))
                {
                    nr1*=10;
                    nr1+= s[i]-'0';
                    ++i;
                }
            i+=4;
            while((s[i]>= '0')&&(s[i]<='9'))
                {
                    nr2*=10;
                    nr2 += s[i]-'0';
                    ++i;
                }
            for(i = 0; i < 50; ++i)
                if(m[nr1][i])
                    r[nr1][(i+nr2)%50] = 1;
            for(i = 0; i < 50; ++i)
                {
                    m[nr1][i] = r[nr1][i];
                    r[nr1][i] = 0;
                }
        }
    }
    for(i = 0; i < 6; ++i,fout << endl)
            for(j = 0; j < 50; ++j)
            fout << m[i][j] << " ";
        fout << endl;
    for(i = 0; i < 6; ++i)
        for(j = 0; j < 50; ++j)
            if(m[i][j])
                ++nr;
    fout << nr;
    return 0;
}
