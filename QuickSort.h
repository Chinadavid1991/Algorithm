//
// Created by feng on 2020/12/23.
//

#ifndef ALGORITHM___QUICKSORT_H
#define ALGORITHM___QUICKSORT_H
#include <iostream>
template <typename T>
class QuickSort {
    using v_ptr = T*;
public:
    explicit QuickSort(v_ptr data,size_t length) : _data(data),N(length) {}
    void sort(){
        int lo = 0;
        int hi = N - 1;
        sort(lo,hi);
    }
    void print(){
        std::cout << "[";
        for (size_t ix = 0; ix < N; ++ix) {
            if (ix == N - 1) {
                std::cout << _data[ix] << "]";
            }
            else {
                std::cout << _data[ix] << ",";
            }

        }
        std::cout << std::endl;
    }
private:
    void sort(int lo,int hi){
        if(lo >= hi){
            return;
        }
        int pos = partition(lo,hi);
        sort(lo,pos-1);
        sort(pos+1,hi);
    }
    void swap(int i,int j){
        T temp = _data[i];
        _data[i] = _data[j];
        _data[j] = temp;
    }
    int partition(int lo,int hi){
        T key = _data[lo];
        int left = lo;
        int right = hi+1;
        while (true){
            while (left < right && _data[--right] > key);
            while (left < right && _data[++left] < key);
            if(left >= right){
                swap(lo,right);
                break;
            }
            else{
                swap(left,right);
            }
        }
        return right;
    }
private:
    v_ptr _data;
    const size_t N;
};

void testQuickSort(int size);
#endif //ALGORITHM___QUICKSORT_H
