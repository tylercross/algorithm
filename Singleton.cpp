// Singleton.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
/*
#include <iostream>


class Singleton {
public:
	static Singleton * GetInstance() {

		return instance_;
	}
	static void DestroyInstance() {
		if (instance_ != nullptr)
		{
			delete instance_;

		}
	}
private:
	static Singleton * instance_;
	Singleton() = default;
	Singleton(const Singleton &) = delete;
	Singleton& operator=(const Singleton &) = delete;

};
Singleton * Singleton::instance_ = new Singleton;

int main() {
	Singleton* s1 = Singleton::GetInstance();
	std::cout << s1 << std::endl;

	Singleton* s2 = Singleton::GetInstance();
	std::cout << s2 << std::endl;

	Singleton::DestroyInstance();
	system("pause");
	return 0;
}*/


#include <iostream>
#include <mutex>
/*
class Singleton {
public:
	static Singleton* GetInstance() {
		if (instance_ == nullptr) {
			std::unique_lock<std::mutex> lock(mutex_);//
			if (instance_ == nullptr) {
				instance_ = new Singleton;
			}
		}

		return instance_;
	}

	~Singleton() = default;

	// 释放资源。
	void Destroy() {
		if (instance_ != nullptr) {
			delete instance_;
			instance_ = nullptr;
		}
	}

	void PrintAddress() const {
		std::cout << this << std::endl;
	}

private:
	Singleton() = default;

	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

private:
	static Singleton* instance_;
	static std::mutex mutex_;
};*/

class Singleton {
public:
	static Singleton *GetInstance() {
		if (instance_ == nullptr)
		{
			std::unique_lock<std::mutex> ul(mutex_);
			if (instance_ == nullptr)
			{
				instance_ = new Singleton;
			}
		}
		return instance_;
	}
	static void Destroy() {
		if (instance_ != nullptr)
		{
			delete instance_;
			instance_ = nullptr;
		}
	}
	~Singleton() = default;

private:
	Singleton() = default;
	Singleton(const Singleton &) = delete;
	Singleton& operator=(const Singleton &) = delete;
	static std::mutex mutex_;
	static Singleton * instance_;
};
std::mutex Singleton::mutex_ ;
Singleton * Singleton::instance_ = nullptr;



int main() {
	Singleton* s1 = Singleton::GetInstance();
	//s1->PrintAddress();
	std::cout << s1 << std::endl;
	Singleton* s2 = Singleton::GetInstance();
	//s2->PrintAddress();
	std::cout << s2 << std::endl;
	system("pause");
	return 0;
}

