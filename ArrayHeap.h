//
// Created by feng on 2020/12/18.
//

#ifndef ALGORITHM___ArrayHeap_H
#define ALGORITHM___ArrayHeap_H


#include <iostream>

template<class T>
class ArrayHeap {
public:
    explicit ArrayHeap(const size_t capacity) :
            _capacity(capacity), _store(true), _items(new T[capacity]) {}

    ArrayHeap(T *items, const size_t length ,const size_t capacity, const bool store = false) :
            N(length),_capacity(capacity), _store(store), _items(items) {}

    //堆中现有元素个数
    size_t size() const { return N; }

    //堆中现有元素最大值
    T &max() const {
        return _items[0];
    }

    //向堆中插入元素
    void insert(T elem) {
        if (N >= _capacity - 1) {
            std::cout << "heap is full" << std::endl;
            return;
        }
        _items[N++] = elem;
        //上浮元素使堆重新有序
        swim(N - 1);
    }

    //删除堆内最大元素，并返回该元素
    T delMax() {
        T maxElem = _items[0];
        _items[0] = _items[N];
        N--;
        //下沉堆开始元素，使得堆依然有序
        sink(0);
        return maxElem;
    }

    T &at(size_t ix) const { return _items[ix]; }

    T &operator[](size_t ix) {
        return _items[ix];
    }

    //上浮操作：元素k处的元素上浮至堆正确的位置
    void swim(size_t k) {
        k = k + 1;//坐标向右平移1
        while (k >= 2 && _items[k - 1] > _items[k / 2 - 1]) {
            exchange(k - 1, k / 2 - 1);
            k = k / 2;
        }
    }

    //下沉操作：元素k处的元素下沉至堆正确的位置
    void sink(size_t k) {
        k = k + 1;
        while (k * 2 <= N)//k*2-1 <= N-1
        {
            //查找当前节点的左右子节点最大的元素索引
            size_t ix = 2 * k <= N - 1 && _items[2 * k] > _items[2 * k - 1] ? 2 * k : 2 * k - 1;
            //比较元素ix和当前元素
            if (_items[k - 1] > _items[ix]) {
                break;
            }
            exchange(k - 1, ix);
            k = ix + 1;//向右平移1
        }
    }

    //下沉操作：元素k处的元素下沉至堆正确的位置,范围在[0,range]
    void sink(size_t k, size_t range) {
        k = k + 1;
        while (k * 2 - 1 <= range)//k*2-1 <= N-1
        {
            //查找当前节点的左右子节点最大的元素索引
            size_t ix = 2 * k <= range && _items[2 * k] > _items[2 * k - 1] ? 2 * k : 2 * k - 1;
            //比较元素ix和当前元素
            if (_items[k - 1] > _items[ix]) {
                break;
            }
            exchange(k - 1, ix);
            k = ix + 1;//向右平移1
        }
    }

    //交换两个位置的元素
    void exchange(size_t i, size_t j) {
        T temp = _items[i];
        _items[i] = _items[j];
        _items[j] = temp;
    }


    friend std::ostream &operator<<(std::ostream &os, const ArrayHeap &heap) {
        os << "[";
        for (size_t ix = 0; ix < heap.N; ++ix) {
            if (ix == heap.N - 1) {
                os << heap.at(ix) << "]";
            }
            else {
                os << heap.at(ix) << ",";
            }

        }
        return os;
    }

    ~ArrayHeap() {
        if (_store) {
            delete[] _items;
        }
    }

private:
    const bool _store = false;
    size_t _capacity;
    size_t N = 0;
    T *_items;
};

void testArrayHeap();

#endif //ALGORITHM___ArrayHeap_H
