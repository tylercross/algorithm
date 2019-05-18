#ifndef _THREADPOOL_H
#define _THREADPOOL_H
#include <vector>
#include <queue>
#include <thread>
#include <iostream>
#include <stdexcept>
#include <condition_variable>
#include <memory> //unique_ptr

const int MAX_THREADS = 100; //����߳���Ŀ


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
		std::cout << "������" << i << "���߳� " << std::endl;
		/*
		std::thread temp(worker, this);
		�����ȹ����ٲ���
		*/
		work_threads.emplace_back(worker, this);//ɶ��˼����ʼ��work,ʹ��this ָ�롣
	}
}
template <typename T>
void *threadPool<T>::worker(void *arg)//work��һ���м��壬��Ϊ��̬��Ա��������ͨ�����������ʳ�Ա����
									  //��ô���������ǣ������ʹ������м����������Ϊɶ�Ǿ�̬��
{
	threadPool *pool = (threadPool *)arg; //thread_pool��this����ת����poolָ��	
	pool->run(); //�ó�Ա����run��
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
				request->process();//��� T*�����precess��ִ��һ�ε���˼���Ǵ���Ҫ���еĶ���
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
