#include "ThreadSafeQueue.h"
#include <iostream>

ThreadSafeQueue::ThreadSafeQueue(std::queue<int> initialQueue) : queue(initialQueue) {}

int ThreadSafeQueue::retrieveAndDeleteFront() {
    int frontValue = 0;
    mutex.lock();
    if (!queue.empty()) {
        frontValue = queue.front();
        queue.pop();
    }
    mutex.unlock();
    return frontValue;
}

void ThreadSafeQueue::printQueue() {
    std::queue<int> tempQueue = queue;
    mutex.lock();
    while (!tempQueue.empty()) {
        std::cout << tempQueue.front() << " ";
        tempQueue.pop();
    }
    std::cout << "\n";
    mutex.unlock();
}

void ThreadSafeQueue::pushValue(int value) {
    mutex.lock();
    queue.push(value);
    mutex.unlock();
}