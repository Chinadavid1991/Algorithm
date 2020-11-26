//
// Created by feng on 2020/11/25.
//

#ifndef ALGORITHM___SELECTSORT_H
#define ALGORITHM___SELECTSORT_H

#include <iostream>

template<typename T, std::size_t N>
class SelectSort {
    using v_ref = T (&)[N];
public:
    explicit SelectSort(v_ref data) : _data(data) {}

    void sort() {
        for (int ix = 0; ix < N; ++ix) {
            swap(_data[argMin(ix,N)], _data[ix]);
        }
    }

    v_ref getData() const {
        return _data;
    }

private:
    size_t argMin(size_t start,size_t end) {
        for (size_t ix = start; ix < end; ++ix) {
            if (_data[start] > _data[ix]) {
                start = ix;
            }
        }
        return start;
    }

    void swap(T &x, T &y) {
        if (&x == &y)
            return;
        T temp = x;
        x = y;
        y = temp;
    }

private:
    v_ref _data;

};


#endif //ALGORITHM___SELECTSORT_H
