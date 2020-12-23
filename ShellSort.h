//
// Created by feng on 2020/12/22.
//

#ifndef ALGORITHM___SHELLSORT_H
#define ALGORITHM___SHELLSORT_H

#include <iostream>

template<typename T>
class ShellSort {
    using v_ptr = T *;
public:
    explicit ShellSort(v_ptr data, const size_t length) : _data(data), N(length) {}

    void sort() {
        int h = growth();
        while (h > 0) {
            for (int ix = 0; ix < N; ++ix) {
                insert(ix, h);
            }
            h /= 2;
        }
    }

    void print() {
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
    int growth() {
        int h = 1;
        while (h < N / 2) {
            h = 2 * h + 1;
        }
        return h;
    }

    void insert(int ix, int h) {
        for (int iy = ix; iy >= h; iy = iy - h) {
            if (_data[iy] >= _data[iy - h]) {
                break;
            }
            swap(iy, iy - h);
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

void testShellSort(int size);

#endif //ALGORITHM___SHELLSORT_H
