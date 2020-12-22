//
// Created by feng on 2020/12/22.
//

#ifndef ALGORITHM___INSERTSORT_H
#define ALGORITHM___INSERTSORT_H

#include <iostream>

template <typename T,size_t N>
class InsertSort {
    using v_ref = T(&)[N];
    using v_ptr = T(*)[N];
public:
    explicit InsertSort(v_ref data) : _data(data) {}
    void sort(){
        for(int ix = 0;ix < N;++ix){
            insert(ix);
        }
    }
    void insert(int ix){
        for(int iy = ix;iy > 0;--iy){
            if(_data[iy] >= _data[iy-1]){
                break;
            }
            else{
                swap(iy,iy-1);
            }
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
void testInsertSort();

#endif //ALGORITHM___INSERTSORT_H
