#include <iostream>


using namespace std;
    bool isPalindrome(const string&s,int left,int right)
    {
        while(left<=right)
        {
            if(s[left++]!=s[right--]) return false;
        }
        return true;
    }
    string longestPalindrome(string s) {
         string res;
         int pace=s.size();
         while(pace>0)
         {
             for(int i=0;i<=s.size()-pace;++i)
           {
               if(isPalindrome(s,i,i+pace-1)) {res=s.substr(i,pace); return res;}
           }
           pace--;
         }

    }

int main()
{
    int k;
    string str;
  //  cin>>str;
  //  reversesubstr(str,0,2);
   // cout<<str<<endl;
   cin>>str;
    cout<<longestPalindrome(str)<<endl;
    return 0;
}
