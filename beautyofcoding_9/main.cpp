#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

bool isDeformation(string str1, string str2);
bool isDeformation_hash(string str1, string str2);

int main()
{
    string str1, str2;
    cin>>str1>>str2;

    if(isDeformation_hash(str1, str2))
        cout<<str1<<"和"<<str2<<"互为变形词"<<endl;
    else
        cout<<str1<<"和"<<str2<<"不互为变形词"<<endl;
    return 0;
}

bool isDeformation(string str1, string str2)
{
   int str1_len=str1.size();
   int str2_len=str2.size();
   if(str1_len!=str2_len) return false;
   sort(str1.begin(),str1.end());
   sort(str2.begin(),str2.end());
   for(int i=0;i<str1_len;++i)
   {
       if(str1[i]!=str2[i]) return false;

   }
   return true;
}
bool isDeformation_hash(string str1, string str2)
{
     int str1_len=str1.size();
    int str2_len=str2.size();
    if(str1_len!=str2_len) return false;
    int *hash_table1=new int[256] ();

    //int *hash_table2=new int[256] ();

    for(int i=0;i<str1_len;++i)
    {
        hash_table1[str1[i]]++;

    }
    for(int j=0;j<str2_len;++j)
    {
        hash_table1[str2[j]]--;
        if(hash_table1[str2[j]]<0) return false;

    }

    delete []hash_table1;
    //delete []hash_table2;
    return true;
}
