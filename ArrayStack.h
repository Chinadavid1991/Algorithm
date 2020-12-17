//
// Created by feng on 2020/12/17.
//

#ifndef ALGORITHM___ARRAYSTACK_H
#define ALGORITHM___ARRAYSTACK_H
#include <iostream>
template <typename T>
class ArrayStack {
    using v_ptr = T*;
public:
    explicit ArrayStack(int capacity) : _capacity(capacity),_data(new T[_capacity]),_top(-1) {}
    bool isEmpty(){
        return _top <= -1;
    }
    void push(const T& v){
        if(_top >= _capacity - 1)
            return;
        _data[++_top] = v;
    }
    void pop(){
        if(isEmpty()) return;
        --_top;
    }

    friend std::ostream &operator<<(std::ostream &os, const ArrayStack &stack) {
        for(size_t i = 0;i <= stack._top;++i){
            if(i == 0 && i == stack._top){
                os << "[" << stack._data[i] << "]";
            }
            else if(i == 0 && i != stack._top){
                os << "[" << stack._data[i] << ",";
            }

            else if(i > 0 && i < stack._top){
                os << stack._data[i] << ",";
            }
            else{
                os << stack._data[i] << "]";
            }
        }
        return os;
    }

    virtual ~ArrayStack() {
        delete[] _data;
    }

private:
    int _capacity;
    v_ptr _data;
    int _top;
};


#endif //ALGORITHM___ARRAYSTACK_H
