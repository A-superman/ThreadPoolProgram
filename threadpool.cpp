#include "threadpool.h"
#include <functional>
#include <thread>
#include <iostream>

const int TASK_MAX_THRESHOLD = 1024;

// 线程池构造
ThreadPool::ThreadPool()
    : initThreadSize_(0)
    , taskSize_(0)
    , taskQueMaxThreshold_(TASK_MAX_THRESHOLD)
    , poolMode_(PoolMode::MODE_FIXED)
{}

// 线程池析构
ThreadPool::~ThreadPool()
{}

// 设置线程池的工作模式
void ThreadPool::setMode(PoolMode mode)
{
    poolMode_ = mode;
}

// 设置task任务队列上线阈值
void ThreadPool::setTaskQueMaxThreadHold(int threshold)
{
    taskQueMaxThreshold_ = threshold;
}

// 给线程池提交任务
void ThreadPool::submitTask(std::shared_ptr<Task> sp)
{

}

// 开启线程池
void ThreadPool::start(int initThreadSize)
{  
    // 记录初始线程个数
    initThreadSize_ = initThreadSize;

    // 创建线程对象
    for(int i = 0; i < initThreadSize_; i++) {
        // 创建thread线程对象的时候，把线程函数给到thread线程对象
        threads_.emplace_back(new Thread(std::bind(&ThreadPool::threadFunc, this)));
    }

    // 启动所有线程     std::vector<Thread*> threads_;
    for(int i = 0; i < initThreadSize_; i++) {
        threads_[i]->start();   // 执行一个线程函数
    }
}

// 定义线程函数
void ThreadPool::threadFunc()
{
    std::cout << "begin threadFunc tid:" << std::this_thread::get_id()
        << std::endl;
    std::cout << "end threadFunc tid:"<< std::this_thread::get_id() 
        << std::endl;
}

////////////////线程方法实现/////////////////

// 线程构造
Thread::Thread(ThreadFunc func)
    :func_(func)
{}
// 线程析构
Thread::~Thread()
{}
// 启动线程
void Thread::start()
{
    // 执行一个线程函数
    std::thread t(func_);   // c++11来说 线程对象t 和线程函数func_
    t.detach(); // 设置分离线程
}