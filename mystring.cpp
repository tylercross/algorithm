// mystring.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"



#include <string.h> 

#include <stdio.h>
#include <iostream>

using namespace std;

class String {

	friend ostream & operator << (ostream& os, String &str);
	friend istream & operator >> (istream& is, String &str);
public:
	String(const char* str = "");
	String(const String& rhs);
	~String();
	String& operator=(const String& rhs);
	size_t size ()const;
	const char* c_str ()const;
	
private:
	char* data;
};

/* 不简洁版本
String::String(const char* str) {
if (str == NULL) {
data = new char[1];
*data = '\0';
} else {
int len = strlen(str);
data = new char[len + 1];
strcpy(data, str);
}
}
*/



String::String(const char* str)
{
	
	int size = strlen(str) ;
	data = new char[size+1];
	strcpy_s(data,size+1,str);//strcpy
}


String::~String() {
	delete[] data;
}

String::String(const String& rhs) /*{
	int size = rhs.size();
	data = new char[size+ 1];
	strcpy_s(data, size+1, rhs.c_str());
}*/
{
	int size = rhs.size();
	if(data != nullptr)
		delete[] data;
	data = new char[size + 1];
	strcpy_s(data, size + 1, rhs.data);
}


// bad version
String& String::operator=(const String& rhs) /*{
	if (this != &rhs) {
		delete[] data;
		int size = rhs.size();
		data = new char[size+1];
		strcpy_s(data,size+1,rhs.c_str());
	}
	return *this;
}*/
{
	if (this != &rhs)
	{
		if (data != nullptr)
			delete[] data;
		int r_size = rhs.size();
		data = new char[r_size + 1];
		strcpy_s(data, r_size + 1, rhs.c_str());
	}
	return *this;
}


size_t String::size() const {
	return strlen(data);
}

const char* String::c_str () const{
	return data;
}
ostream & operator <<(ostream &os, String &str)
{
	os << str.c_str();
	return os;
}
istream & operator >> (istream &is, String &str)
{
	char *tmp = new char[1000];
	is >> tmp;	
	str.data = new char[strlen(tmp) + 1];
	strcpy_s(str.data,strlen(tmp)+1,tmp);
	return is;
}

int main() {
	String s = "abcd";
	String s1;
	cin >> s1;
	cout << s1<<endl;
	String s2(s);
	cout << s2<< endl;
	system("pause");
	return 0;
}