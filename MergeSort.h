//
// Created by feng on 2020/12/23.
//

#ifndef ALGORITHM___MERGESORT_H
#define ALGORITHM___MERGESORT_H

#include <iostream>

template<typename T>
class MergeSort {
    using v_ptr = T *;
public:
    explicit MergeSort(v_ptr data, const size_t length) : _data(data), N(length) {}

    void sort() {
        T *assist = new T[N];
        int lo = 0;
        int hi = N - 1;
        sort(assist, lo, hi);
        delete[] assist;
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
    void sort(T *assist, int lo, int hi) {
        if (lo >= hi) {//不可分割，组元素个数1
            return;
        }
        int mid = (hi + lo) / 2;
        sort(assist, lo, mid);
        sort(assist, mid + 1, hi);
        merge(assist, lo, mid, hi);
    }

    void merge(T *assist, int lo, int mid, int hi) {
        int ix = lo;
        int p1 = lo;
        int p2 = mid + 1;
        //排序
        while (p1 <= mid && p2 <= hi) {
            if (_data[p1] < _data[p2]) {
                assist[ix++] = _data[p1++];
            }
            else {
                assist[ix++] = _data[p2++];
            }
        }
        while (p1 <= mid) {
            assist[ix++] = _data[p1++];
        }
        while (p2 <= hi) {
            assist[ix++] = _data[p2++];
        }
        //复制辅助数组对应元素到原数组
        for (ix = lo; ix <= hi; ++ix) {
            _data[ix] = assist[ix];
        }
    }

private:
    v_ptr _data;
    const size_t N;
};

void testMergeSort(int size);

#endif //ALGORITHM___MERGESORT_H
