#include <iostream>
#include <cstring>
#include <string>
using namespace std;

string removeDuplicated(string s)
{

    int len = s.length();
    if (len < 2)
    {
        return s ;
    }

    bool c[256];
    memset(c, 0, sizeof(c));
    int p = 0;

    for (int i = 0; i < len; i++)
    {

        if (!c[s[i]])
        {

            s[p++] = s[i];
            c[s[i]] = true;
        }
    }

    s[p] = '\0';
    return s;
    
}

int main(void)
{

    string s = "abbbccccddd";
    cout << removeDuplicated(s);
   

    system("PAUSE");
    return 0;
}