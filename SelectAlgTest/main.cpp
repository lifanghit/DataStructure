#include <iostream>
#include <string>
#include "student.h"
#include "sorttesthelper.h"

using namespace std;

//冒泡排序
template<typename T>
void bubbleSort(T arr[], int n) {
    bool bchange = false;  //交换标志
    for (int i = 0; i < n; i++) {
        for (int j = n-1; j > i; j--) {
            if (arr[j-1] > arr[j]) {
                swap(arr[j], arr[j-1]);
                bchange = true;
            }
        }
        // 如果标志为false，说明本轮遍历没有交换，已经是有序数列，可以结束排序
        if (!bchange)
            break;
    }
}


//插入排序
template <typename T>
void insertionSort(T arr[], int n) {
    for (int i = 1 ; i < n ; i++) {
        //寻找元素arr[i]合适的插入位置
        T e = arr[i];
        int j; //j保存元素e应该插入的位置
        for ( j = i ; j > 0 && arr[j-1] > e ; j--) {
                arr[j] = arr[j-1];
        }
        arr[j] = e;
    }
}



//选择排序
template<typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n; i++) {
      int minIndex = i;
      for (int j = i+1; j < n ; j++) {
          if(arr[j] < arr[minIndex])
              minIndex = j;    
      }
      swap(arr[i], arr[minIndex]);
    }
}

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

//    selectionSort(array3, n);
//    SortTestHelper::printArray(array3, n);

    SortTestHelper::testSort("Selection Sort", selectionSort, array1, n);
    SortTestHelper::testSort("Insertion sort", insertionSort, array2, n);
    SortTestHelper::testSort("Bubble sort", bubbleSort, array3, n);

    delete[] array1;
    delete[] array2;
    delete[] array3;

    cout << endl;



    //测试2：测试近乎有序的数组
    int swaptimes = 10;

    cout << "Test for Random Nearly Ordered Array, size = " << n << ", swap time = " << swaptimes << endl;

    array1 = SortTestHelper::generateNearlyOrderedArray(n, swaptimes);
    array2 = SortTestHelper::copyIntArray(array1, n);
    array3 = SortTestHelper::copyIntArray(array1, n);

    SortTestHelper::testSort("Selection Sort", selectionSort, array1, n);
    SortTestHelper::testSort("Insertion sort", insertionSort, array2, n);
    SortTestHelper::testSort("Bubble sort", bubbleSort, array3, n);

    delete[] array1;
    delete[] array2;
    delete[] array3;

    return 0;
}
