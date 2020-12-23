//
// Created by feng on 2020/11/25.
//

#ifndef ALGORITHM___SELECTSORT_H
#define ALGORITHM___SELECTSORT_H

#include <iostream>

template<typename T>
class SelectSort {
    using v_ptr = T *;
public:
    explicit SelectSort(v_ptr data, size_t length) : _data(data), N(length) {}

    void sort() {
        for (int ix = 0; ix < N; ++ix) {
            swap(_data[argMin(ix, N)], _data[ix]);
        }
    }

    v_ptr getData() const {
        return _data;
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
    size_t argMin(size_t _items, size_t end) {
        for (size_t ix = _items; ix < end; ++ix) {
            if (_data[_items] > _data[ix]) {
                _items = ix;
            }
        }
        return _items;
    }

    void swap(T &x, T &y) {
        if (&x == &y)
            return;
        T temp = x;
        x = y;
        y = temp;
    }


private:
    v_ptr _data;
    const size_t N;

};

void testSelectSort(int size);


#endif //ALGORITHM___SELECTSORT_H
