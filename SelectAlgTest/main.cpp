#include <iostream>
#include <string>
#include "student.h"
#include "sorttesthelper.h"

using namespace std;

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
    int *array = SortTestHelper::generateNearlyOrderedArray(n, 10);
    int *array2 = SortTestHelper::copyIntArray(array, n);

//    selectionSort(array, n);
//    SortTestHelper::printArray(array, n);

    SortTestHelper::testSort("Selection Sort", selectionSort, array, n);
    SortTestHelper::testSort("Insertion sort", insertionSort, array2, n);

    delete[] array;
    delete[] array2;

    return 0;
}
