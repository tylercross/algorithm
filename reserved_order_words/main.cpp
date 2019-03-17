#include <iostream>
#include <vector>

using namespace std;
void Reverse(string& str,int left,int right)
{
    int i=left,j=right;
    if(j==0) return;
    while(i<j)
    {
        swap(str[i++],str[j--]);
    }

}
int myIsspace(char c)
 {
     if(c =='\t'|| c =='\n'|| c ==' ')
         return 1;
     else
         return 0;
 }
void reserved_words(string& str)
{
    reserved(str);
    vector<string> temp;
    int i=0;
    while(i<str.size())
    {
        int start=i,end;

        while(myIsspace(str[i]))
        {

            i++;
            int end=i;

        }
        string sub_str=str.substr(start,end-start);
        reserved(sub_str);
        cout<<sub_str<<endl;
        temp.push_back(sub_str);
        i++;

    }
    str="";
    for(int i=0;i<temp.size();++i)
    {
       // cout<<temp[i]<<endl;
        str+=temp[i]+" ";

   }



}
int main()
{
    string str="abcd";
    //cin>>str;
    cout<<str<<endl;


   // reserved(str);
   // cout<<str<<endl;
    string str2="abcd efg";
    //cout<<str2<<endl;
    reserved_words(str2);
    cout<<str2<<endl;
    //cout << "Hello world!" << endl;return 0;
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//将指针p,q之间的单词反转
void ReverseWord(char *p, char *q)
{
	//中间变量
	char temp;
	while(p<q)
	{
		temp=*p;
		*p=*q;
		*q=temp;
		p++;
		q--;
	}
}
int myIsspace(char c)
 {
     if(c =='\t'|| c =='\n'|| c ==' ')
         return 1;
     else
         return 0;
 }

/*功能函数
void ReverseSent(char *s, char *sOut)
{
	char *p=NULL;
	char *q=NULL;
	memcpy(sOut,s,strlen(s)+1);
	p=q=sOut;
	while(*q++!=NULL)
	{
		if (myIsspace(*q))
		{
			ReverseWord(p,q-1);
			q++;
			p=q;
		}
	}
	//最后一个单词
	ReverseWord(p,q-2);
	//整个句子
	ReverseWord(sOut,q-2);

}


int main()
{
	char *buf="I am a boy";
	char p[20];
	ReverseSent(buf,p);
	printf("%s\n%s\n",buf,p);
	return 0;
}*/
