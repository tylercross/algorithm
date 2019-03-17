#include <iostream>

using namespace std;
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

void ReverseString(string& str,int left,int right)
{
    int i=left,j=right;
    if(j==0) return;
    while(i<j)
    {
        swap(str[i++],str[j--]);
    }

}
void Reverse_i(string& str,int i)
{
    ReverseString(str,0,i);
    cout << str << endl;
    ReverseString(str,i+1,str.size()-1);
    cout << str << endl;
    ReverseString(str,0,str.size()-1);


}

int main()
{
    string str="abcdef";
    //ReverseString(str,0,2);
    Reverse_i(str,2);
    cout << str << endl;
    return 0;
}
