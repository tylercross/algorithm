#ifndef _THREADPOOL_H
#define _THREADPOOL_H
#include <vector>
#include <queue>
#include <thread>
#include <iostream>
#include <stdexcept>
#include <condition_variable>
#include <memory> //unique_ptr

const int MAX_THREADS = 100; //最大线程数目


template <typename T>
class threadPool {
public:
	threadPool(int number =1 );
	~threadPool();
	bool append(T *request);
	
private:
	static void * worker(void *arg);
	void  run();

private:
	std::vector<std::thread> work_threads;
	std::queue<T *> tasks_queue;
	std::mutex queue_mutex;
	std::condition_variable condition;
	bool stop;
};


template <typename T>
threadPool<T>::threadPool(int number) : stop(false)
{
	if (number <= 0 || number > MAX_THREADS)
		throw std::exception();
	for (int i = 0; i < number; i++)
	{
		std::cout << "创建第" << i << "个线程 " << std::endl;
		/*
		std::thread temp(worker, this);
		不能先构造再插入
		*/
		work_threads.emplace_back(worker, this);//啥意思，初始化work,使用this 指针。
	}
}
template <typename T>
void *threadPool<T>::worker(void *arg)//work是一个中间体，作为静态成员函数必须通过对象来访问成员函数
									  //这么做的意义是？如果不使用这个中间体会怎样？为啥是静态的
{
	threadPool *pool = (threadPool *)arg; //thread_pool的this对象转换成pool指针	
	pool->run(); //用成员访问run。
	return pool;
}

template <typename T>
void threadPool<T>::run()
{
	while (!stop)
	{
		std::unique_lock<std::mutex> lk(this->queue_mutex);
		this->condition.wait(lk, [this] { return !this->tasks_queue.empty(); });
		if (this->tasks_queue.empty())
		{
			continue;
		}
		else
		{
			T *request = tasks_queue.front();
			tasks_queue.pop();
			if (request)
				request->process();//这个 T*对象的precess是执行一次的意思吗？是传入要进行的动作
		}
	}
}

template <typename T>
inline threadPool<T>::~threadPool() {
	{
		std::unique_lock<std::mutex> lk(queue_mutex);
		stop = true;
	}
	condition.notify_all();
	for (auto& ii : work_threads)
	{
		ii.join();
	}

}



template <typename T>
bool threadPool<T>::append(T *request) {
	{
		std::unique_lock<std::mutex> ul(queue_mutex);
		tasks_queue.push(request);
	}
	condition.notify_one();
	return true;
}

#endif
