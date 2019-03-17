#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
using namespace std;
int firstUniqChar(string s) {
        vector<int> mymap(255,-1);
        for(int i=0;i<s.size();i++)
        {
            if(mymap[s[i]]<0) mymap[s[i]]=i;
            else mymap[s[i]]=INT_MAX;
        }

        int min=INT_MAX;
        for(int j=0;j<mymap.size();j++)
        {
            if(mymap[j]>-1&&mymap[j]<min) min=mymap[j];
          // cout<<mymap[j]<<" ";
        }
        return min;
}
int main()
{
    string s;
    cin>>s;
    cout<<firstUniqChar(s)<<endl;

}
