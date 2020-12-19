//
// Created by feng on 2020/12/19.
//

#ifndef ALGORITHM___MAXPRIORITYQUE_H
#define ALGORITHM___MAXPRIORITYQUE_H
#include "ArrayHeap.h"

template <typename T>
class MaxPriorityQue {
    ArrayHeap<T> _heap;
public:
    explicit MaxPriorityQue(const int capacity) : _heap(capacity){}
    T pop(){
        return _heap.delMax();
    }
    void add(const T& elem){
        _heap.insert(elem);
    }
};


#endif //ALGORITHM___MAXPRIORITYQUE_H
