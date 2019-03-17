#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
using namespace std;
bool isPalindrome(const string &s,int left,int right);
void dfs(int index,string& s,vector<string>& path,vector<vector<string>>& res);
vector<vector<string>> partition(string s)
{
    vector<vector<string>> res;
    if(s.empty()) return res;
    vector<string> path;
    dfs(0,s,path,res);
    return res;

}
void dfs(int index,string& s,vector<string>& path,vector<vector<string>>& res)
{
    if(index==s.size()) {
        res.push_back(path);
      return;}
    for(int i=index;i<s.size();++i)
    {
        if(isPalindrome(s,index,i)){
            path.push_back(s.substr(index,i-index+1));
            dfs(i+1,s,path,res);
             path.pop_back();
        }

    }

}
bool isPalindrome(const string &s,int left,int right)
{
    while(left<=right)
    {
        if(s[left++]!=s[right--]) return false;

    }
    return true;
}





int main()
{
    string s;
    cin>>s;
    vector<vector<string> >res;
    res=partition(s);
    for(int i=0;i<res.size();++i)
      {

        for(int j=0;j<res[i].size();++j)
        cout<<res[i][j]<<" ";
        cout<<endl;
      }


 //   cout<<firstUniqChar(s)<<endl;
     return 0;
}
