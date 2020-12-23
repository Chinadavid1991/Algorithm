//
// Created by feng on 2020/12/23.
//

#ifndef ALGORITHM___QUICKSORT_H
#define ALGORITHM___QUICKSORT_H
#include <iostream>
template <typename T,size_t N>
class QuickSort {
    using v_ref = T(&)[N];
public:
    explicit QuickSort(v_ref data) : _data(data) {}
    void sort(){
        int lo = 0;
        int hi = N - 1;
        sort(lo,hi);
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
    v_ref _data;
};

void testQuickSort();
#endif //ALGORITHM___QUICKSORT_H
