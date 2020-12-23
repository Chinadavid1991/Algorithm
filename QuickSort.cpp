//
// Created by feng on 2020/12/23.
//

#include "QuickSort.h"
using namespace std;
void testQuickSort() {
    constexpr int N = 20;
    int arr[N];
    for (int &ix : arr) {
        ix = (int) random() % N;
    }
    QuickSort<int, N> sort(arr);
    sort.sort();
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