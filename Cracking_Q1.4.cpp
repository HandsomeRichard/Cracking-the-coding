#include <iostream>
#include <cstring>
#include <string>
using namespace std;

/*原文：

Write a method to decide if two strings are anagrams or not.
译文：
写一个函数判断两个字符串是否是变位词。
变位词(anagrams)指的是组成两个单词的字符相同，但位置不同的单词。
比如说， abbcd和abcdb就是一对变位词。该题目有两种做法*/

bool isAnagramsCharArray(char *, char *);

int main(void)
{

    //1.放在char array
    char s1[] = "ASQEE";
    char s2[] = "QSBEE";
    if (isAnagramsCharArray(s1, s2))
    {
        cout << "same";
    }
    else
    {

        cout << "NOT same";
    }

    system("PAUSE");
    return 0;
}

bool isAnagramsCharArray(char *a, char *b)
{

    //
    //int a_len = sizeof(a)/sizeof(a[0]);

    int a_len = strlen(a);
    int b_len = strlen(b);
    bool retunparam = true;
    

    //new bool array
    bool *check = new bool[a_len]();
    memset(check, false, sizeof(check)); //將A array裡面值填入0 flase

    for (int i = 0; i < a_len; i++)
        cout << "old:"<< check[i] << endl;

    for (int i = 0; i < a_len; i++)
    {

        char nowchar = a[i];
        for (int j = 0; j < b_len; j++)
        {
            if (nowchar == b[j])
            {
                check[i] = true; //相同填入 true
            }
        }
    }

    for (int i = 0; i < a_len; i++)
        cout  << "new:"<< check[i]  << endl;

    for (int i = 0; i < a_len; i++)
    {

        if (check[i] == false )
        {
            retunparam =  false;
            break;
        }
    }

    return retunparam;
    
}
