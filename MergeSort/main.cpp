#include <iostream>
#include <algorithm>
#include "sorttesthelper.h"
#include "insertionsort.h"
#include "mergesort.h"

using namespace std;

//自底向上的归并排序算法
template<typename T>
void mergeSortBU(T arr[], int n) {
    for (int size = 1; size <= n; size += size) {
        for (int i = 0; i+size < n; i += size + size) {
            //对arr[i..i+size-1]和arr[i+size...i+2*size-1]进行归并
            __merge(arr, i, i+size-1, min(i+size+size-1, n-1));
        }
    }

}

int main()
{

    int n = 10000;

    //测试1：一般性测试
    int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);
    int *arr3 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
    SortTestHelper::testSort("Merge Sort",     mergeSort,     arr2, n);
    SortTestHelper::testSort("Merge Sort BU",  mergeSortBU,   arr3, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    cout << endl;



    //测试2：测试近乎有序的数组
    int swaptimes = 100;

    cout << "Test for Random Nearly Ordered Array, size = " << n << ", swap time = " << swaptimes << endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n, swaptimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
    SortTestHelper::testSort("Merge Sort",     mergeSort,     arr2, n);
    SortTestHelper::testSort("Merge Sort BU",  mergeSortBU,   arr3, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    return 0;
}
