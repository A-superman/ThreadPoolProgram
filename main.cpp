#include <iostream>
#include <chrono>
#include <thread>
#include "threadpool.h"

class MyTask : public Task
{
public:
    void run()
    {
        int sum  = 10;
        std::cout << "tid : " << std::this_thread::get_id() << " begin " << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(5));
        std::cout << "tid : " << std::this_thread::get_id() << " end "
            << std::endl;
    }
};

int main()
{
    ThreadPool threadpool;
    threadpool.start(4);
    threadpool.submitTask(std::make_shared<MyTask>());
    threadpool.submitTask(std::make_shared<MyTask>());
    threadpool.submitTask(std::make_shared<MyTask>());
    threadpool.submitTask(std::make_shared<MyTask>());
    threadpool.submitTask(std::make_shared<MyTask>());
    threadpool.submitTask(std::make_shared<MyTask>());
    threadpool.submitTask(std::make_shared<MyTask>());
    threadpool.submitTask(std::make_shared<MyTask>());
    threadpool.submitTask(std::make_shared<MyTask>());
    threadpool.submitTask(std::make_shared<MyTask>());
    threadpool.submitTask(std::make_shared<MyTask>());
    threadpool.submitTask(std::make_shared<MyTask>());
    threadpool.submitTask(std::make_shared<MyTask>());
    threadpool.submitTask(std::make_shared<MyTask>());
    threadpool.submitTask(std::make_shared<MyTask>());
    getchar();
    return 0;
}