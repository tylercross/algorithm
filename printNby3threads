#include <iostream>
#include <vector>
#include <thread>
#include <condition_variable>
#include <mutex>
 
constexpr int THREADS = 3;
constexpr int MAX = 100;
 
std::mutex m;
std::condition_variable cv[THREADS];
bool flags[THREADS];
 
int n = 0;
 
void f(int i)
{
    const int next = (i + 1) % THREADS;
    for (;;)
    {
        std::unique_lock<std::mutex> lock(m);
        cv[i].wait(lock, [=](){return flags[i];});
        if (n <= MAX)
            std::cout << "thread " << i << ": " << n++ << std::endl;
        flags[i] = false;
        flags[next] = true;
        lock.unlock();
        cv[next].notify_one();
        if (n > MAX)
            break;
    }
}
 
int main()
{
    flags[0] = true;
    std::vector<std::thread> vec;
    for (int i = 0; i < THREADS; ++i)
        vec.emplace_back(f, i);
    for (auto &t: vec)
        t.join();
    return 0;
}
