// smart_ptr.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;
/*
template<class T>
class SmartPtr
{
public:
	SmartPtr(T *p);
	~SmartPtr();
	SmartPtr(const SmartPtr<T> &orig);                // ǳ����
	SmartPtr<T>& operator=(const SmartPtr<T> &rhs);    // ǳ����
private:
	T *ptr;
	// ��use_count������ָ����Ϊ�˷������ĵ�����ݼ�����
	int *use_count;
};*/
template<typename T>
class SmartPtr {
	public:
		SmartPtr(T *p);
		SmartPtr(const SmartPtr<T> & target);
		~SmartPtr();
		SmartPtr<T>& operator=(const SmartPtr<T> & target);
private:
	T * _ptr;
	int * _count;
};

/*
template<class T>
SmartPtr<T>::SmartPtr(T *p) : ptr(p)
{
	try
	{
		use_count = new int(1);
	}
	catch (...)
	{
		delete ptr;
		ptr = nullptr;
		use_count = nullptr;
		cout << "Allocate memory for use_count fails." << endl;
		exit(1);
	}

	cout << "Constructor is called!" << endl;
}
*/
template<class T>
SmartPtr<T>::SmartPtr(T *p): _ptr(p) {
	try
	{
		_count = new int(1);
	}
	catch (...)
	{
		delete _ptr;
		_ptr = nullptr;
		_count = nullptr;
		exit(1);
	}
  }
/*
template<class T>
SmartPtr<T>::~SmartPtr()
{
	// ֻ�����һ����������ptrʱ���ͷ��ڴ�
	if (--(*use_count) == 0)
	{
		delete ptr;
		delete use_count;
		ptr = nullptr;
		use_count = nullptr;
		cout << "Destructor is called!" << endl;
	}
}*/
template<class T>
SmartPtr<T>::~SmartPtr()
{
	if (--(*_count) == 0)
	{
		delete _ptr;
		delete _count;
		_ptr = nullptr;
		_count = nullptr;

	}
}
/*
template<class T>
SmartPtr<T>::SmartPtr(const SmartPtr<T> &orig)
{
	ptr = orig.ptr;
	use_count = orig.use_count;
	++(*use_count);
	cout << "Copy constructor is called!" << endl;
}
*/
template<class T>
SmartPtr<T>::SmartPtr(const SmartPtr<T> &target) {
	_ptr = target._ptr;
	_count = target._count;
	++(*_count);0

}


// ���صȺź�����ͬ�ڸ��ƹ��캯�������Ⱥ���ߵĶ�������Ѿ�ָ��ĳ���ڴ档
// ���������Ǿ͵����ж���߶���ָ����ڴ��Ѿ������õĴ������������Ϊ1��
// �������ǿ����ͷ�����ڴ棻��֮���ͷţ��������������ͷš�
/*
template<class T>
SmartPtr<T>& SmartPtr<T>::operator=(const SmartPtr<T> &rhs)
{
	// ��C++ primer�����������ֵ�������ڼ������������ʹ�ü���֮ǰʹrhs��ʹ�ü�����1��
	// �Ӷ���ֹ����ֵ�������µ������ͷ��ڴ�
	++(*rhs.use_count);

	// ��������������ʹ�ü�����1�����ö����ʹ�ü�������0����ɾ���ö���
	if (--(*use_count) == 0)
	{
		delete ptr;
		delete use_count;
		cout << "Left side object is deleted!" << endl;
	}

	ptr = rhs.ptr;
	use_count = rhs.use_count;

	cout << "Assignment operator overloaded is called!" << endl;
	return *this;
}
*/
template <typename T>
SmartPtr<T>& SmartPtr<T>::operator=(const SmartPtr<T> &rhs) {
	++(*(rhs._count));
	if (--(*_count) == 0) {
		delete _ptr;
		delete _count;
		
	}
	_ptr = rhs._ptr;
	_count = rhs._ptr;
	return *this;
}


#include <iostream>
using namespace std;

int main()
{
	// Test Constructor and Assignment Operator Overloaded
	SmartPtr<int> p1(new int(0));
	p1 = p1;
	// Test Copy Constructor
	SmartPtr<int> p2(p1);
	// Test Assignment Operator Overloaded
	SmartPtr<int> p3(new int(1));
	p3 = p1;
	system("pause");
	return 0;
}
