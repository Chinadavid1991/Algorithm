//
// Created by feng on 2020/12/16.
//

#ifndef ALGORITHM___SPARSEARRAY_H
#define ALGORITHM___SPARSEARRAY_H
#include <iostream>
template <typename T,std::size_t N>
class SparseArray {
    struct Value{
        int _x = 0 ;
        int _y = 0;
        T _v;
        Value()= default;
        Value(int x, int y, const T& v) : _x(x), _y(y), _v(v) {}
    };
public:
    SparseArray(int row,int col, const T& other) : _data(new Value[N]),_row(row),_col(col),_other(other){}
    virtual ~SparseArray() {
        delete[] _data;
    }
    void setValue(std::size_t index,int x,int y, const T& v){
        _data[index]._x = x;
        _data[index]._y = y;
        _data[index]._v = v;
    }

    friend std::ostream &operator<<(std::ostream &os, const SparseArray &array) {
        for(size_t i = 0;i < N;++i){
            if(i == 0 && i == N - 1){
                os << "[" << array._data[i]._v << "]";
            }
            else if(i == 0 && i != N - 1){
                os << "[" << array._data[i]._v << ",";
            }

            else if(i > 0 && i < N - 1){
                os << array._data[i]._v << ",";
            }
            else{
                os << array._data[i]._v << "]";
            }
        }
        return os;
    }

private:
    Value* _data;
    const int _row;
    const int _col;
    T _other;
};
void testSparseArray();

#endif //ALGORITHM___SPARSEARRAY_H
