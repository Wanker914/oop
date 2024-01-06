#include <list>
#include <iostream>
#include <algorithm>
#include <stdexcept>

template <typename T>
class Queue {
private:
    std::list<T> elements_;

public:


    void enqueue(const T& element) {
        elements_.push_back(element);
    }

    void dequeue(){
        if (isEmpty()) {
            throw std::out_of_range("out_of_range");
        }
        elements_.pop_front();
    };

    void print() const {
        for (const T& element: elements_) {
            std::wcout << element << L" ";
        }
        std::wcout << std::endl;
    }

    const T& front() const{
        if (isEmpty()) {
            throw std::out_of_range("out_of_range");
        }
        return elements_.front();
    };

    bool isEmpty() const{
        return elements_.empty();
    };


    bool isQueue(const T& element) const{
        return std::binary_search(elements_.begin(), elements_.end(), element);
    };

};

