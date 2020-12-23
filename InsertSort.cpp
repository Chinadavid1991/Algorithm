//
// Created by feng on 2020/12/22.
//

#include "InsertSort.h"
#include "Common.h"

using namespace std;


void testInsertSort(const int size) {
    const int N = size;
    int *arr = new int[N];
    for (int ix = 0; ix < N; ++ix) {
        arr[ix] = (int) random() % N;
    }

    InsertSort<int> sort(arr, N);
    long start = now();
    sort.sort();
    auto end = now();
    cout << "InsertSort cost time:" << end - start << endl;
    delete[] arr;
}