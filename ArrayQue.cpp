//
// Created by feng on 2020/12/17.
//

#include "ArrayQue.h"
using namespace std;
void testArrayQue(){
    ArrayQue<int> que(10);
    for(int ix = 0;ix < 1000;++ix){
        que.push(ix);
        if(ix % 2 == 0){
            que.pop();
        }
    }
    cout << que.size() << endl;
}