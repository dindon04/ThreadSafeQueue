#pragma once
#include <queue>
#include <mutex>

class ThreadSafeQueue {
public:
    ThreadSafeQueue(std::queue<int> initialQueue);
    int retrieveAndDeleteFront();
    void printQueue();
    void pushValue(int value);

private:
    std::queue<int> queue;
    std::mutex mutex;
};