#include <iostream>
#include "ShellSort.h"
#include "InsertSort.h"
#include "SelectSort.h"
#include "QuickSort.h"
#include "HeapSort.h"
#include "MergeSort.h"
using namespace std;

int main() {
    const int size = 200000;
    cout << "测试各种排序算法时间复杂度" << endl;
    testInsertSort(size);
    testSelectSort(size);

    testShellSort(size);
    testQuickSort(size);
    testHeapSort(size);
    testMergeSort(size);
    return 0;
}
