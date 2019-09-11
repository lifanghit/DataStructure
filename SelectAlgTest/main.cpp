#include <iostream>
#include <string>
#include "student.h"
#include "sorttesthelper.h"
#include "selectionsort.h"
#include "insertionsort.h"
#include "bubblesort.h"

using namespace std;

int main()
{
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    selectionSort(arr, 10);
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    float arr1[5] = {10.0, 9.3, 8.5, 7.6, 5.0};
    selectionSort(arr1, 5);
    for (int i = 0; i < 5; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    string arr2[4] = {"D", "E", "C", "A"};
    selectionSort(arr2, 4);
    for (int i = 0; i < 4; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    Student stu[4] = {{"D", 90}, {"C", 95}, {"E", 100}, {"B", 95}};
    selectionSort(stu, 4);
    for (int i = 0; i < 4; i++) {
        cout << stu[i] << " ";
    }
    cout << endl;

    int n = 10000;

    //测试1：一般性测试

    int *array1 = SortTestHelper::generateRandomArray(n, 0, n);
    int *array2 = SortTestHelper::copyIntArray(array1, n);
    int *array3 = SortTestHelper::copyIntArray(array1, n);
    int *array4 = SortTestHelper::copyIntArray(array1, n);
    int *array5 = SortTestHelper::copyIntArray(array1, n);

//    selectionSort(array3, n);
//    SortTestHelper::printArray(array3, n);

    SortTestHelper::testSort("Selection Sort", selectionSort, array1, n);
    SortTestHelper::testSort("Insertion sort", insertionSort, array2, n);
    SortTestHelper::testSort("Bubble sort", bubbleSort, array3, n);
    SortTestHelper::testSort("Bubble sort 1", bubbleSort1, array4, n);
    SortTestHelper::testSort("Bubble sort 2", bubbleSort2, array5, n);

    delete[] array1;
    delete[] array2;
    delete[] array3;
    delete[] array4;
    delete[] array5;

    cout << endl;



    //测试2：测试近乎有序的数组
    int swaptimes = 10;

    cout << "Test for Random Nearly Ordered Array, size = " << n << ", swap time = " << swaptimes << endl;

    array1 = SortTestHelper::generateNearlyOrderedArray(n, swaptimes);
    array2 = SortTestHelper::copyIntArray(array1, n);
    array3 = SortTestHelper::copyIntArray(array1, n);
    array4 = SortTestHelper::copyIntArray(array1, n);
    array5 = SortTestHelper::copyIntArray(array1, n);

    SortTestHelper::testSort("Selection Sort", selectionSort, array1, n);
    SortTestHelper::testSort("Insertion sort", insertionSort, array2, n);
    SortTestHelper::testSort("Bubble sort", bubbleSort, array3, n);
    SortTestHelper::testSort("Bubble sort 1", bubbleSort1, array4, n);
    SortTestHelper::testSort("Bubble sort 2", bubbleSort2, array5, n);

    delete[] array1;
    delete[] array2;
    delete[] array3;
    delete[] array4;
    delete[] array5;


    //测试3：测试完全有序的数组
    n = 100000;
    swaptimes = 0;

    cout << "Test for Ordered Array, size = " << n << ", swap time = " << swaptimes << endl;

    array1 = SortTestHelper::generateNearlyOrderedArray(n, swaptimes);
    array2 = SortTestHelper::copyIntArray(array1, n);
    array3 = SortTestHelper::copyIntArray(array1, n);
    array4 = SortTestHelper::copyIntArray(array1, n);
    array5 = SortTestHelper::copyIntArray(array1, n);

    // 在这种情况下，不再测试选择排序算法
//    SortTestHelper::testSort("Selection Sort", selectionSort, array1, n);
    SortTestHelper::testSort("Insertion sort", insertionSort, array2, n);
    SortTestHelper::testSort("Bubble sort", bubbleSort, array3, n);
    SortTestHelper::testSort("Bubble sort 1", bubbleSort1, array4, n);
    SortTestHelper::testSort("Bubble sort 2", bubbleSort2, array5, n);

    delete[] array1;
    delete[] array2;
    delete[] array3;
    delete[] array4;
    delete[] array5;

    return 0;
}
