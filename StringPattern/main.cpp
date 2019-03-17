#include <iostream>
#include <string>
#include <vector>
using namespace std;


int search0(const string& str,const string& pat)
{
  int M=pat.size();
  int N=str.size();
  for(int i=0;i<N-M;++i)
  {
      int j;
      for(j=0;j<M;++j)
        if(str[i+j]!=pat[j]) break;
      if(j==M) return i;
  }
  return N;
}

int search1(const string& str,const string &pat)
{
    int j,M=pat.size();
    int i,N=str.size();
    for( i=0,j=0;i<N&&j<M;i++)
    {
        if(str[i]==pat[j]) j++;
        else {i-=j;j=0;}

    }
    if (j==M) return i-M;
    else return N;
}

int search2(const string& str,const string &pat)
{
    int str_len=str.size(),pat_len=pat.size();
    int str_index=0,pat_index=0;
    while(str_index<str_len&&pat_index<pat_len)
    {
        if(str[str_index]==pat[pat_index])
        {
            ++str_index;
            ++pat_index;
        }
        else
        {
            str_index-=(pat_index-1);
            pat_index=0;

        }

    }

    if(pat_index==pat_len)
    {
        return str_index-pat_len;

    }
    else
        return -1;

}

int kmp_search(const string& str,const string& pat)
{
    const int pat_len=pat.size(),str_len=str.size();
    int *overlay_function=new int[pat_len];//存放overlay值的数组
    int index;//存放k值
    overlay_function[0]=-1;//初始化首位置
    for(int i=1;i<pat_len;++i)
    {
        index=overlay_function[i-1];//i指向新添加的字符位置
        while(index>=0 && pat[i]!=pat[index+1])//i=j+1
        {
            index=overlay_function[index];//index=k
        }
        if(pat[index+1]==pat[i]) overlay_function[i]=index+1;
        else overlay_function[i]=-1;
    }

    int str_index=0,pat_index=0;
    while(str_index<str_len&&pat_index<pat_len)
    {
        if(str[str_index]==pat[pat_index])
        {
            ++str_index;
            ++pat_index;
        }
        else if(pat_index==0)
        {
            ++str_index;
        }
        else
        {
            pat_index=overlay_function[pat_index-1]+1;
        }
    }
    delete []overlay_function;
    if(pat_index==pat_len)
    {
        return str_index-pat_len;

    }
    else
        return -1;

}





void overlay(const string & pat)
{
    const int pat_len=pat.size();
    int *overlay_function=new int[pat_len];//存放overlay值的数组
    int index;//存放k值
    overlay_function[0]=-1;//初始化首位置
    for(int i=1;i<pat_len;++i)
    {
        index=overlay_function[i-1];//i指向新添加的字符位置
        while(index>=0 && pat[i]!=pat[index+1])//i=j+1
        {
            index=overlay_function[index];//index=k
        }
        if(pat[index+1]==pat[i]) overlay_function[i]=index+1;
        else overlay_function[i]=-1;

    }
    for(int i=0;i<pat_len;++i)
    {
        cout<<overlay_function[i]<<endl;

    }
   delete []overlay_function;

}





int main()
{
    //cout<<search2("banananobano","nano")<<endl;
    overlay("annacanna");
   // cout<<search1("banananobano","nano")<<endl;
   cout<<kmp_search("banananobano","no")<<endl;
return 0;
}
