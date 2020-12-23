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
    void sort(){
        creatHeap();
        for(int ix = _heap.size() - 1;ix >= 0;--ix){
            _heap.exchange(0,ix);
            _heap.sink(0,ix-1);
        }

    }
    void print(){
        std::cout << _heap << std::endl;
    }

private:
    void creatHeap(){
        for(int ix = _heap.size()/2 -1 ;ix >= 0;--ix){
            _heap.sink(ix);
        }
    }
};
void testHeapSort(int size);

#endif //ALGORITHM___HEAPSORT_H
