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
                begin=mymap[s[j]];//����ظ������������i;
            mymap[s[j]]=j;//����mymap
            len=max(len,(j-begin));//�Ƚ�len�����ַ��ĳ���

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
