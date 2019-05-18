// smart_ptr.cpp : 定义控制台应用程序的入口点。
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
	SmartPtr(const SmartPtr<T> &orig);                // 浅拷贝
	SmartPtr<T>& operator=(const SmartPtr<T> &rhs);    // 浅拷贝
private:
	T *ptr;
	// 将use_count声明成指针是为了方便对其的递增或递减操作
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
	// 只在最后一个对象引用ptr时才释放内存
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


// 重载等号函数不同于复制构造函数，即等号左边的对象可能已经指向某块内存。
// 这样，我们就得先判断左边对象指向的内存已经被引用的次数。如果次数为1，
// 表明我们可以释放这块内存；反之则不释放，由其他对象来释放。
/*
template<class T>
SmartPtr<T>& SmartPtr<T>::operator=(const SmartPtr<T> &rhs)
{
	// 《C++ primer》：“这个赋值操作符在减少左操作数的使用计数之前使rhs的使用计数加1，
	// 从而防止自身赋值”而导致的提早释放内存
	++(*rhs.use_count);

	// 将左操作数对象的使用计数减1，若该对象的使用计数减至0，则删除该对象
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
