//
// Created by feng on 2020/12/18.
//

#ifndef ALGORITHM___HEAPSORT_H
#define ALGORITHM___HEAPSORT_H
#include "ArrayHeap.h"
#include <iostream>


template <typename T>
class HeapSort {
    ArrayHeap<T> _heap;
public:
    HeapSort(T* items,size_t length,size_t capacity):_heap(items,length,capacity){};
    void creatHeap(){
        for(size_t ix = 0;ix < _heap.size()/2;++ix){
            _heap.sink(ix);
        }
    }
    void print(){
        std::cout << _heap << std::endl;
    }
};


#endif //ALGORITHM___HEAPSORT_H
