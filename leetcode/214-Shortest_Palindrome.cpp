#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool isPalindrome(const string &s,int left,int right)
{
    while(left<=right)
    {
        if(s[left++]!=s[right--]) return false;

    }
    return true;
}
string shortestPalindrome(string s) {
        if(!s.size()||isPalindrome(s,0,s.size()-1)) return s;
        int symcenter=s.size()/2-1;
         int counter=1,temp=symcenter;

         while(temp>0){

            if(s[temp]==s[temp-1]) {counter++; temp--;}
            else break;
         }
         cout<<counter<<endl;

            for(int i=1;symcenter-i>=0&&symcenter>0;++i)
            {
                if(s[symcenter-i]!=s[symcenter+i])
                {
                    symcenter--;
                    break;
                }
            }
            string right=s.substr(symcenter+1,s.size()-1-symcenter);
           // cout<<right;
           reverse(right.begin(),right.end());
           string res =counter%2?(right+s[symcenter]+s.substr(symcenter+1,s.size()-1-symcenter))\
           :( right+s.substr(symcenter+1,s.size()-1-symcenter));
            return res;
       }

int main()
{
    string s;
    cin>>s;
    cout<<shortestPalindrome(s)<<endl;


 //   cout<<firstUniqChar(s)<<endl;
     return 0;
}
