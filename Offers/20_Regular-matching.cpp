#include <iostream>
#include <string>
using namespace std;


bool matchCore(char* str, char* pat)
{
    if(*str=='\0' && *pat=='\0') return true;
    if(*str!='\0' && *pat=='\0') return false;
    if(*(pat+1)=='*')
    {
        if(*pat==*str||(*pat=='.'&&*str!='\0'))
            return matchCore(str+1,pat+2)||\
            matchCore(str+1,pat)||\
            matchCore(str,pat+2);
        else
            return matchCore(str,pat+2);//ºöÂÔµôÕâ¸ö²»Æ¥ÅäµÄ×Ö·û

    }

    if((*str==*pat)||(*pat=='.'&&*str!='\0'))
        return matchCore(str+1,pat+1);
    return false;

}
bool match(char* str,char* pat)
{
    if(pat==nullptr||str==nullptr) return false;


    return matchCore(str,pat);
}




int main()
{
    char pat[]="abcde";
    char str[]="aabcef";

    if(match(str,pat)) cout<<"true";
    else
        cout<<"false";
    return 0;
}
