//
// Created by feng on 2020/12/23.
//
#include "SelectSort.h"
#include <iostream>
#include <chrono>

using namespace std;

void testSelectSort() {
    constexpr int N = 20;
    int arr[N];
    for (int &ix : arr) {
        ix = (int) random() % N;
    }
    SelectSort<int, N> sort(arr);
    auto start = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    sort.sort();
    auto end = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    cout << "SelectSort cost time:" << end - start << endl;
    cout << "[";
    for (size_t ix = 0; ix < N; ++ix) {
        if (ix == N - 1) {
            cout << arr[ix] << "]";
        }
        else {
            cout << arr[ix] << ",";
        }

    }
    cout << endl;
}