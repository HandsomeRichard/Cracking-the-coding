#include <iostream>
#include <cstring>
#include <string>
using namespace std;


char* ReverseString(char *s){

    //因為單strlen算 s的長度會有error故在main function加入相同的~
    //compiler關係???? 不知道
    int len = strlen(s);

    //cout << len;
    int lastPos = len-1;

    for(int i=0 ; i<(lastPos)/2 ; i++ ){
        
        char tmp = s[i];
        s[i] = s[lastPos-1-i];
        s[lastPos-1-i] = tmp;


        

    } 
    return s ;

}



//Write code to reverse a C-Style String.
// (C-String means that “abcd” is represented as five characters, including the null character.)
int main(void)
{

    char s[4] = {'a','b','c','d'};

    //必須有這段程式碼
    int len = strlen(s);

    cout << ReverseString(s);

    

    system("PAUSE");
    return 0;
}