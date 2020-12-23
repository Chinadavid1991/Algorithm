//
// Created by feng on 2020/12/23.
//

#include <chrono>
#include "ShellSort.h"
#include "InsertSort.h"
#include "SelectSort.h"
#include "QuickSort.h"
#include "HeapSort.h"
#include "MergeSort.h"

using namespace std;

long now() {
    std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch());
    return ms.count();
}

void testSortAlgorithmTimeCost() {
    const int size = 100000;
    testInsertSort(size);
    testSelectSort(size);

    testShellSort(size);
    testQuickSort(size);
    testHeapSort(size);
    testMergeSort(size);
}