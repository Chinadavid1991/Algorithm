//
// Created by feng on 2020/12/23.
//
#include "SelectSort.h"
#include <iostream>
#include "Common.h"

using namespace std;

void testSelectSort(const int size) {
    const int N = size;
    int *arr = new int[N];
    for (int ix = 0; ix < N; ++ix) {
        arr[ix] = (int) random() % N;
    }

    SelectSort<int> sort(arr, N);
    long start = now();
    sort.sort();
    long end = now();
    cout << "SelectSort cost time:" << end - start << endl;
    delete[] arr;
}