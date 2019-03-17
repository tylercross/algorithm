#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int fun(string str)
{
    map<char,int> dict;
    int counter =0;
    for(auto i:str)
    {
       // cout<<i<<endl;
        if(dict.find(i)==dict.end())
        {
           // cout<<i<<endl;
            dict[i] = 1;
            counter ++;
            if(counter>2) return 0;
        }
        else
            dict[i]++;

    }
    if(counter==1 ) return 1;
    else if(counter ==0) return 0;
    else return 2;

}
string fun2(int n,vector<int> nums)
{
    if(n<=0) return "Impossible";
    if(n==1) return "Possible";
    sort(nums.begin(),nums.end());
    int diff;
    for(int i=1;i<n;i++)
    {
        if(i==1)
        {
            diff = nums[1]-nums[0];
        }
        else if(nums[i]-nums[i-1]!=diff)
            return "Impossible";

    }
    return "Possible";
}
void helper_fun3(int n,int k,int &counter,int last);
int fun3(int n,int k)
{
    int counter=0;
    if(n<1||k<1) return -1;
    for(int i=1;i<=k;i++)
    helper_fun3(n-1,k,counter,i);

    return counter;

}
void helper_fun3(int n,int k,int &counter,int last)
{
    if(n==0) {counter++;return ;}

        for(int j=1;j<=k;j++)
        {
            if(last<=j||last%j!=0)
                helper_fun3(n-1,k,counter,j);
            //else return;
        }





}



int main()
{

   /*1
    string str;
    cin>>str;
    cout<<fun(str)<<endl;
*/
  /*
    int n;
    cin>>n;
    vector<int> nums(n,0);
    int num;
    for(int i=0;i<n;i++)
        cin>>nums[i];

    cout<<fun2(n,nums)<<endl;
*/

    int n;
    cin>>n;
    int k;
    cin>>k;
    int  tr = 1000000007;
    cout<<fun3(n,k)%tr<<endl;


    return 0;
}
