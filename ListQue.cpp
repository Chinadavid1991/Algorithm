//
// Created by feng on 2020/12/17.
//

#include "ListQue.h"
using namespace std;
void testListQue(){
    ListQue<int> que;
    for(int i = 0;i < 20;++i){
        que.push(i);
        if(i % 2 == 0){
            que.pop();
        }
    }
    cout << "size:" << que.size() << "\n" << "data:"<< que  << endl;
}