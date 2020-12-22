//
// Created by feng on 2020/12/22.
//

#include "InsertSort.h"
#include <chrono>
using namespace std;
void testInsertSort(){
    constexpr int N = 20;
    int arr[N];
    for(int & ix : arr){
        ix = (int)random()% N;
    }
    InsertSort<int,N> sort(arr);
    auto start = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    sort.sort();
    auto end = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());;
    cout << "InsertSort cost time:" << end-start << endl;
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