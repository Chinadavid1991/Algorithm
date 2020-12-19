//
// Created by feng on 2020/12/19.
//

#include "MaxPriorityQue.h"
using namespace std;
void testMaxPriorityQue(){
    MaxPriorityQue<int> que(128);
    for(auto ix : {1,2,3,4,5,6,7,8,9,0}){
        que.add(ix);
    }
    for(int ix = 0;ix < 10;++ix){
        int v = que.pop();
        cout << v << endl;
    }
}