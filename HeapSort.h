//
// Created by feng on 2020/12/18.
//

#ifndef ALGORITHM___HEAPSORT_H
#define ALGORITHM___HEAPSORT_H
#include "ArrayHeap.h"

template <typename T>
class HeapSort {
    ArrayHeap<T> _heap;
public:
    HeapSort(T* items,size_t length):_heap(items,length){};
};


#endif //ALGORITHM___HEAPSORT_H
