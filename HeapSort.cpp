//
// Created by feng on 2020/12/18.
//

#include "HeapSort.h"
void testHeapSort(){
    int arr[101] = {0};
    for(int ix = 0;ix <= 10;++ix){
        if(ix % 10 == 0){
            arr[ix] = 10;
        }
        else{
            arr[ix] = ix;
        }
    }
    HeapSort<int> sort(arr,11,1000);
    sort.sort();
    sort.print();
}