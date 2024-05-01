# ThreadSafeQueue

## Overview
ThreadSafeQueue encapsulates a standard std::queue to ensure thread-safe operations. It uses a std::mutex to synchronize access to the queue.

## Methods

### ThreadSafeQueue(std::queue<int> initialQueue)
Constructor that initializes the queue with a given set of integers.

### int retrieveAndDeleteFront()
Retrieves and removes the front element of the queue. If the queue is empty, it returns 0. This method locks the queue for the duration of the operation to ensure thread safety.

### void printQueue()
Prints the current elements in the queue to the standard output. This method also locks the queue during the operation to prevent concurrent modification.

### void pushValue(int value)
Adds a new integer value to the back of the queue. The queue is locked during this operation to maintain thread safety.
