//
// Created by feng on 2020/12/22.
//

#ifndef ALGORITHM___INSERTSORT_H
#define ALGORITHM___INSERTSORT_H

#include <iostream>

template<typename T>
class InsertSort {
    using v_ptr = T *;
public:
    explicit InsertSort(v_ptr data, const size_t length) : _data(data), N(length) {}

    void sort() {
        for (int ix = 0; ix < N; ++ix) {
            insert(ix);
        }
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
    void insert(int ix) {
        for (int iy = ix; iy > 0; --iy) {
            if (_data[iy] >= _data[iy - 1]) {
                break;
            }
            else {
                swap(iy, iy - 1);
            }
        }
    }

    void swap(int i, int j) {
        T temp = _data[i];
        _data[i] = _data[j];
        _data[j] = temp;
    }

private:
    v_ptr _data;
    const size_t N;
};

void testInsertSort(int size);

#endif //ALGORITHM___INSERTSORT_H
