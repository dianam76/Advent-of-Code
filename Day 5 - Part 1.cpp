#include <fstream>
#include "md5.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

ifstream fin(".in");
ofstream fout(".out");

string s,h;
int index,nr,i;
bool ok;
pair<char,bool> v[10];

string to_string(int i)
{
    stringstream ss;
    ss << i;
    return ss.str();
}

int main(int argc, char *argv[])
{
    fin >> s;
    while(nr<8)
    {
        h = md5(s+to_string(index));
        for(i = 0; i < 5; ++i)
            if(h[i]!='0')
                ok = 1;
        if(!ok)
            {
                ++nr;
                fout << h[5];    
            }
        ok = 0;
        ++index;
    }

    return 0;
}
