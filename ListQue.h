//
// Created by feng on 2020/12/17.
//

#ifndef ALGORITHM___LISTQUE_H
#define ALGORITHM___LISTQUE_H
#include <iostream>
template <typename T>
class ListQue {
    struct Node{
        Node* next = nullptr;
        T Value;
        Node(Node *next, T value) : next(next), Value(value) {}
        Node() = default;
    };
    using v_ptr = Node*;
public:
    ListQue():_front(nullptr),_rear(nullptr),_size(0){}

    void push(const T& v){
        auto next = new Node(nullptr,v);
        if(isEmpty()){
            _rear = next;
            _front = _rear;
        }
        else{
            _rear->next = next;
            _rear = next;
        }
        _size++;
    }
    void pop(){
        if(isEmpty()) return;
        v_ptr next = _front->next;
        delete _front;
        _front = next;
        --_size;
        if(isEmpty()){
            _rear = nullptr;
        }
    }
    std::size_t size() const {
        return _size;
    }
    bool isEmpty() const {
        return _size <= 0;
    }
    friend std::ostream &operator<<(std::ostream &os, const ListQue &que) {
        v_ptr cur = que._front;
        while(cur){
            if(cur == que._front)
            {
                os << "[" << cur->Value << ",";
            } else
            {
                if(cur == que._rear){
                    os << cur->Value << "]";
                }
                else{
                    os << cur->Value << ",";
                }
            }
            cur = cur->next;
        }

        return os;
    }

    virtual ~ListQue() {
        v_ptr cur = _front;
        while (cur){
            v_ptr next = cur->next;
            delete cur;
            cur = next;
        }
    }

private:
    v_ptr _front;
    v_ptr _rear;
    std::size_t _size;
};


#endif //ALGORITHM___LISTQUE_H
