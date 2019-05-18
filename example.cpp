#include "ThreadPool.h"
#include<string>
using namespace std;
class Task
{
public:
	void process()
	{
		cout << "run........." << endl;
	}
};
int main(void)
{
	threadPool<Task> pool(6);
	for(int i=0;i<50;++i)
	{
		Task *tt = new Task();
		//使用智能指针
		pool.append(tt);
		delete tt;
	}
	system("pause");
}
