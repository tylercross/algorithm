#include <iostream>
#include <vector>
#include<string>

using namespace std;


int get_substring(const string &s )
{

        int len=0,begin=-1;
        vector<int> mymap(255,-1);
        for(int j=0;j<s.length();j++)
        {
           // tmp=mymap[s[j]];
           // i=max(tmp,1);
           // mymap[s[j]]=j;
            if(mymap[s[j]]>begin)
                begin=mymap[s[j]];//如果重复重新设置起点i;
            mymap[s[j]]=j;//更新mymap
            len=max(len,(j-begin));//比较len和子字符的长度

        }
        return len;
        }



int main()
{
    string str;
    cin>>str;
    cout<<get_substring(str);


    return 0;
}
