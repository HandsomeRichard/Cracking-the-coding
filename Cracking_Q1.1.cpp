#include <iostream>
#include <cstring>
#include <string>
using namespace std;

bool isUnique(string s)
{

    //256個ASCII 字元符號
    bool a[256];
    memset(a, 0, sizeof(a)); //將A array裡面值填入0 flase
    int len = s.length();
    for (int i = 0; i < len; i++)
    {

        int v = (int)s[i];
        a[v] = true;

        if (a[v])
        {

            return false;
        }
    }
}
//Implement an algorithm to determine if a string has all unique characters.
//What if you can not use additional data structures?
int main(void)
{

    string s = "abcde";

    cout << isUnique(s);
    system("PAUSE");
    return 0;
}