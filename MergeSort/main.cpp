#include <iostream>
#include <algorithm>
#include "sorttesthelper.h"
#include "insertionsort.h"
#include "mergesort.h"

using namespace std;


int main()
{

    int n = 10000;

    //测试1：一般性测试
    int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort",     mergeSort,     arr1, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);

    delete[] arr1;
    delete[] arr2;

    cout << endl;



    //测试2：测试近乎有序的数组
    int swaptimes = 10;

    cout << "Test for Random Nearly Ordered Array, size = " << n << ", swap time = " << swaptimes << endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n, swaptimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort",     mergeSort,     arr1, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);

    delete[] arr1;
    delete[] arr2;

    return 0;
}
