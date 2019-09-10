#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <queue>

using namespace std;
class ThreadPool {
public:
    ThreadPool(size_t);
    template <class F, class ... Args>
    auto enqueue(F&& f,Args&&... args)
        ->future<decltype(f(args...))>;
    ~ThreadPool() ;
private:
    vector<thread> workers;
    queue<function<void()> >tasks;

    mutex queue_mutex;
    condition_variable condition;
    bool stop;
};

inline ThreadPool::ThreadPool (size_t threads) :stop(false) {
    for(size_t i = 0;i<threads;++i) {
        workers.emplace_back(
                [this](){
                    for(;;){
                        function<void()> task;
                        {
                            unique_lock<mutex> lock(this->queue_mutex);
                            this->condition.wait(lock,[this]{return this->stop || !this->tasks.empty();});
                            if(this->stop && this->tasks.empty())
                                return;
                            task = std::move(this->tasks.front());
                            this->tasks.pop();
                        }
                        task();
                        }
                     }
                );
    }
}
template <class F,class... Args>
auto ThreadPool::enqueue(F &&f, Args &&... args) ->future<decltype(f(args...))> {
    auto task = make_shared< packaged_task<decltype(f(args...))()>> (//packaged_task<R(Args...)>
               bind(forward<F>(f),forward<Args>(args)...)
            );
    {
        unique_lock<mutex> lock(queue_mutex);
        if(stop) {
            throw runtime_error("threadpool is stopped!");
        }
        tasks.emplace([task](){(*task)();});
    }
    condition.notify_one();
    return task->get_future();
}
inline ThreadPool::~ThreadPool() {
    {
        unique_lock<mutex> lock(queue_mutex);
        stop = true;
    }
    condition.notify_all();
    for(auto &worker:workers) {
        worker.join();
    }

}



int main() {
    ThreadPool pool(4);
    vector<future<int>> res;
    for(int i=0;i<10;++i) {
        res.emplace_back(pool.enqueue([i](){
            return i*i;
        }) );
    }
    for(auto &&i: res) {
        cout<<i.get()<<endl;
    }

    return 0;
}
