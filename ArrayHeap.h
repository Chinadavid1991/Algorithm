//
// Created by feng on 2020/12/18.
//

#ifndef ALGORITHM___ArrayHeap_H
#define ALGORITHM___ArrayHeap_H


#include <iostream>

template<class T>
class ArrayHeap {
public:
    explicit ArrayHeap(const size_t capacity) : _items(new T[capacity + 1]) {}

    //堆中现有元素个数
    size_t size() const { return N; }

    //堆中现有元素最大值
    T &max() const {
        return _items[1];
    }

    //向堆中插入元素
    void insert(T elem) {
        _items[++N] = elem;
        //上浮元素使堆重新有序
        swim(N);
    }

    //删除堆内最大元素，并返回该元素
    T delMax() {
        T maxElem = _items[1];
        _items[1] = _items[N];
        N--;
        //下沉堆开始元素，使得堆依然有序
        sink(1);
        return maxElem;
    }

    T& at(size_t ix) const { return _items[ix]; }

    ~ArrayHeap() {
        delete[] _items;
    }

private:
    //上浮操作：元素k处的元素上浮至堆正确的位置
    void swim(size_t k) {
        while (k >= 2 && _items[k] > _items[k / 2])
        {
            exchange(k, k / 2);
            k = k / 2;
        }
    }

    //下沉操作：元素k处的元素下沉至堆正确的位置
    void sink(size_t k) {
        while (k * 2 <= N)
        {
            //查找当前节点的左右子节点最大的元素索引
            size_t ix = 2 * k + 1 <= N && _items[2 * k + 1] > _items[2 * k] ? 2 * k + 1 : 2 * k;
            //比较元素ix和当前元素
            if (_items[k] > _items[ix]) {
                break;
            }
            exchange(k, ix);
            k = ix;
        }
    }

    //交换两个位置的元素
    void exchange(size_t i, size_t j) {
        T temp = _items[i];
        _items[i] = _items[j];
        _items[j] = temp;
    }

private:
    size_t N = 0;
    T *_items;
};


#endif //ALGORITHM___ArrayHeap_H
