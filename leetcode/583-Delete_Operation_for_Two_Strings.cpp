#include <iostream>
#include <vector>

using namespace std;
/*int lcs(const string& s1,const string& s2,int m,int n,vector<vector<int> >& mem)
{
    if(m==0||n==0) {for(int i=0;i<mem.size();++i)
    for(int j=0;j<mem[i].size();++j)
        cout<<mem[i][j]<<endl;
    return 0;}
    if(mem[m][n]>0) return mem[m][n];
    if(s1[m-1]==s2[n-1]) mem[m][n]=1+lcs(s1,s2,m-1,n-1,mem);
    else
        mem[m][n]=max(lcs(s1,s2,m,n-1,mem),lcs(s1,s2,m-1,n,mem));
    return mem[m][n];
}*/
int minDistance(string word1, string word2) {
    int len1=word1.size();
    int len2=word2.size();
   // vector<vector<int> > mem(len1,vector<int> (len2,0));
    //return len1+len2-2*lcs(word1,word2,len1,len2,mem);
    vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
    for(int i=1;i<=len1;++i)
    for(int j=1;j<=len2;++j){
        if(word1[i-1]==word2[j-1])
            dp[i][j]=dp[i-1][j-1] + 1;
        else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
    return len1+len2-2*dp[len1][len2];

     }

int main()
{
    string s1,s2;
    cin>>s1>>s2;

    cout<<minDistance(s1,s2)<<endl;
    return 0;
}
