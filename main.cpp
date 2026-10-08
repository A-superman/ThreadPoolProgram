#include <iostream> 
#include "threadpool.h"

int main()
{
    ThreadPool threadpool;
    threadpool.start(6);
    return 0;
}