//
// Created by feng on 2020/12/18.
//

#include "ArrayHeap.h"
#include <iostream>
using namespace std;
void testArrayHeap(){
    ArrayHeap<int> heap(1000);
    for(int ix = 0;ix < 50; ++ix){
        heap.insert(ix);
    }
    heap.delMax();
    cout << heap << endl;
    cout << heap.size() << endl;
    cout << heap[20] << endl;
}