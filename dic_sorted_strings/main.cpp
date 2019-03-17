#include <iostream>
#include <vector>
using namespace std;

string Dic_sort(vector<string> &strs )
{
    string big_string="";
    int strs_num=strs.size();
    for(int i=0;i<strs_num;++i)
    {
        for(int j=i+1;j<strs_num;j++)
            if(strs[i]+strs[j]>strs[j]+strs[i]) swap(strs[i],strs[j]);
    }
    for(int i=0;i<strs_num;++i)
    {
        big_string+=strs[i];
    }
    return big_string;
}
int main()
{
    vector<string> strs={"ab","c","aa","b"};
     cout<<Dic_sort(strs );

    return 0;
}
