//
// Created by feng on 2020/12/23.
//

#include "QuickSort.h"
#include "Common.h"

using namespace std;

void testQuickSort(const int size) {
    const int N = size;
    int *arr = new int[N];
    for (int ix = 0; ix < N; ++ix) {
        arr[ix] = (int) random() % N;
    }

    QuickSort<int> sort(arr, N);
    long start = now();
    sort.sort();
    long end = now();
    cout << "QuickSort cost time:" << end - start << endl;
    delete[] arr;
}