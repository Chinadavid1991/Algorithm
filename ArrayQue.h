//
// Created by feng on 2020/12/17.
//

#ifndef ALGORITHM___ARRAYQUE_H
#define ALGORITHM___ARRAYQUE_H
#include <iostream>
#include <cassert>
#include <algorithm>
#include <memory.h>
template <typename T>
class ArrayQue {
    using v_ptr = T*;
public:
    explicit ArrayQue(const std::size_t capacity) :
                      _capacity(capacity),_data(new T[_capacity]), _front(-1), _rear(-1) {}

    virtual ~ArrayQue() {
        delete[] _data;
    }
    void push(const T& v){
        if(_rear == _capacity - 1  ){
            if(_front*4 < _capacity){
                auto data = new T[2*_capacity];
                memcpy(data,_data, sizeof(T)*_capacity);
                _capacity = _capacity*2;
                delete[] _data;
                _data = data;
            }
            else{
                for(std::size_t ix = 0;ix < (_rear - _front);++ix){
                    _data[ix] = _data[ix+_front+1];
                }
                _rear = _rear - (_front + 1);
                _front = -1;
            }
        }

        _data[++_rear] = v;

    }
    void pop(){
        if(_rear <= _front) return;
        ++_front;
    }
    std::size_t size() const { return _capacity;}
    friend std::ostream &operator<<(std::ostream &os, const ArrayQue &array) {

        for(size_t i = array._front + 1;i <= array._rear;++i){
            if(i == array._front + 1 && i == array._rear){
                os << "[" << array._data[i] << "]";
            }
            else if(i == array._front + 1 && i != array._rear){
                os << "[" << array._data[i] << ",";
            }

            else if(i > array._front + 1 && i < array._rear){
                os << array._data[i] << ",";
            }
            else{
                os << array._data[i] << "]";
            }
        }
        return os;
    }

private:
    std::size_t _capacity;
    v_ptr _data;
    int _front;
    int _rear;

};
void testArrayQue();

#endif //ALGORITHM___ARRAYQUE_H
