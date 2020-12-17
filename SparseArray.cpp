//
// Created by feng on 2020/12/16.
//

#include "SparseArray.h"

using namespace std;
void testSparseArray(){
    SparseArray<int ,20> array(8,6,0);
    for(int i = 0;i < 20;++i){
        array.setValue(i,i+2,i,(i+1)*(i+1));
    }
    cout << array << endl;
}