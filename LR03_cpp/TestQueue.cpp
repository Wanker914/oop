#include <cassert>
#include "Queue.h"

void testIntSet() {
    Queue<int> intQueue;
    intQueue.enqueue(144);
    intQueue.enqueue(914);
    intQueue.enqueue(999);
    intQueue.dequeue();
    assert(intQueue.isQueue(999));
    assert(intQueue.isQueue(914));
    assert(!intQueue.isQueue(144));
}

void testDoubleSet() {
    Queue<double> doubleQueue;
    doubleQueue.enqueue(9.12);
    doubleQueue.enqueue(31.32);
    doubleQueue.enqueue(50.33);
    doubleQueue.dequeue();
    assert(doubleQueue.isQueue(50.33));
    assert(doubleQueue.isQueue(31.32));
    assert(!doubleQueue.isQueue(9.12));
}

void testStringSet() {
    Queue<std::string> stringQueue;
    stringQueue.enqueue("TestName");
    stringQueue.enqueue("TN");
    stringQueue.enqueue("WWW");
    stringQueue.dequeue();
    assert(stringQueue.isQueue("WWW"));
    assert(stringQueue.isQueue("TN"));
    assert(!stringQueue.isQueue("TestName"));
}

void testQueue() {
    testIntSet();
    testDoubleSet();
    testStringSet();
}