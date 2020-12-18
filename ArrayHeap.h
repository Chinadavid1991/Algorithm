//
// Created by feng on 2020/12/18.
//

#ifndef ALGORITHM___ArrayHeap_H
#define ALGORITHM___ArrayHeap_H


#include <iostream>

template<class T>
class ArrayHeap {
public:
    explicit ArrayHeap(const size_t capacity) : start(new T[capacity + 1]) {}

    //堆中现有元素个数
    size_t size() const { return N; }

    //堆中现有元素最大值
    T &max() const {
        return start[1];
    }

    //向堆中插入元素
    void insert(T elem) {
        start[++N] = elem;
        //上浮元素使堆重新有序
        swim(N);
    }

    //删除堆内最大元素，并返回该元素
    T delMax() {
        T maxElem = start[1];
        start[1] = start[N];
        N--;
        //下沉堆开始元素，使得堆依然有序
        sink(1);
        return maxElem;
    }

    T &at(size_t ix) const { return start[ix]; }

    ~ArrayHeap() {
        delete[] start;
    }

private:
    //上浮操作：元素k处的元素上浮至堆正确的位置
    void swim(size_t k) {
        while (k >= 2 && start[k] > start[k / 2])
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
            size_t ix = 2 * k + 1 <= N && start[2 * k + 1] > start[2 * k] ? 2 * k + 1 : 2 * k;
            //比较元素ix和当前元素
            if (start[k] > start[ix])
            {
                break;
            }
            exchange(k, ix);
            k = ix;
        }
    }

    //交换两个位置的元素
    void exchange(size_t i, size_t j) {
        T temp = start[i];
        start[i] = start[j];
        start[j] = temp;
    }

private:
    size_t N = 0;
    T *start;
};


#endif //ALGORITHM___ArrayHeap_H
