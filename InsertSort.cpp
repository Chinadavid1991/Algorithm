//
// Created by feng on 2020/12/22.
//

#include "InsertSort.h"
using namespace std;
void testInsertSort(){
    constexpr int N = 20;
    int arr[N];
    for(int & ix : arr){
        ix = (int)random()% N;
    }
    InsertSort<int,N> sort(arr);
    sort.sort();
    cout << "[";
    for (size_t ix = 0; ix < N; ++ix) {
        if (ix == N-1) {
            cout << arr[ix] << "]";
        }
        else {
            cout << arr[ix] << ",";
        }

    }
    cout << endl;

}