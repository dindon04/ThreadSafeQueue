#include <iostream>
#include <thread>
#include "ThreadSafeQueue.h"

int main() {
    std::queue<int> initialNumbers;

    for (int i = 1; i <= 10; i++) {
        initialNumbers.push(i);
    }

    ThreadSafeQueue safeQueue(initialNumbers);

    std::thread threadRetrieve(&ThreadSafeQueue::retrieveAndDeleteFront, &safeQueue);
    std::thread threadPush(&ThreadSafeQueue::pushValue, &safeQueue, 13);

    if (threadRetrieve.joinable()) {
        threadRetrieve.join();
    }

    if (threadPush.joinable()) {
        threadPush.join();
    }

    safeQueue.printQueue();
    return 0;
}