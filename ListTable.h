//
// Created by feng on 2020/12/17.
//

#ifndef ALGORITHM___LISTTABLE_H
#define ALGORITHM___LISTTABLE_H
#include <string>
#include <utility>
class ListTable {
    struct Node{
        Node* next;
        std::string name;
        int id;
        Node(Node *next, std::string name,int id) : next(next), name(std::move(name)),id(id) {}
        Node():next(nullptr),id(-1){}
        bool isEqual(int id_,const std::string& name_){
            return id == id_ && name == name_;
        }
    };
    using v_ptr = Node*;
public:
    explicit ListTable(int capacity) : _capacity(capacity), _data(new v_ptr[_capacity]) {
        for(int ix = 0;ix < _capacity;++ix){
            _data[ix] = nullptr;
        }
    }

    void add(int id,const std::string& name){
        int ix = id % _capacity;
        v_ptr cur = _data[ix];
        if(nullptr == cur){
            _data[ix] = new Node(nullptr,name,id);
        }
        else{
            while (cur){
                if(cur->isEqual(id,name)){
                    return;
                }
                if(nullptr == cur->next){
                    cur->next = new Node(nullptr,name,id);
                    break;
                }
                cur = cur->next;
            }
        }
        ++_size;
    }
    void remove(int id,const std::string& name){
        int ix = id % _capacity;
        v_ptr cur = _data[ix];
        if(nullptr == cur){
            return;
        }
        else{
            v_ptr last = nullptr;
            while (cur){
                if(cur->isEqual(id,name)){
                    if(last){
                        last->next = cur->next;
                        delete cur;
                        --_size;
                    }
                    break;
                }
                last = cur;
                cur = cur->next;
            }
        }
    }

    std::string get(int id){
        int ix = id % _capacity;
        v_ptr cur = _data[ix];
        while (cur){
            if(cur->id == id){
                return cur->name;
            }
            cur = cur->next;
        }
        return "";
    }
    int size() const { return _size;}
    virtual ~ListTable() {
        for(size_t ix = 0;ix < _capacity;++ix){
            v_ptr cur = _data[ix];
            while(cur){
                v_ptr next = cur->next;
                delete cur;
                cur = next;
            }
        }
        delete[] _data;
    }

private:
    int _capacity;
    int _size = 0;
    v_ptr* _data;


};


#endif //ALGORITHM___LISTTABLE_H
