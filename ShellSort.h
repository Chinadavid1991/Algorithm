//
// Created by feng on 2020/12/22.
//

#ifndef ALGORITHM___SHELLSORT_H
#define ALGORITHM___SHELLSORT_H

#include <iostream>

template<typename T, size_t N>
class ShellSort {
    using v_ref = T(&)[N];
    using v_ptr = T(*)[N];
public:
    explicit ShellSort(v_ref data) : _data(data) {}

    int growth() {
        int h = 1;
        while (h < N/2) {
            h = 2 * h + 1;
        }
        return h;
    }

    void sort() {
        int h = growth();
        while (h > 0){
            for(int ix = 0;ix < N;++ix){
                insert(ix,h);
            }
            h /= 2;
        }
    }

    void insert(int ix,int h){
        for(int iy = ix;iy >= h;iy = iy -h){
            if(_data[iy] >= _data[iy-h]){
                break;
            }
            swap(iy,iy-h);
        }
    }
    void swap(int i,int j){
        T temp = _data[i];
        _data[i] = _data[j];
        _data[j] = temp;
    }

private:
    v_ref _data;
};
void testShellSort();

#endif //ALGORITHM___SHELLSORT_H
