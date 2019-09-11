#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <iostream>

using namespace std;

//对arr[0...n)范围内的元素进行插入排序
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

//对arr[r...l]范围内的元素进行插入排序
template <typename T>
void insertionSort(T arr[], int l, int r) {
    for (int i = l+1 ; i <= r ; i++) {
        //寻找元素arr[i]合适的插入位置
        T e = arr[i];
        int j; //j保存元素e应该插入的位置
        for ( j = i ; j > l && arr[j-1] > e ; j--) {
                arr[j] = arr[j-1];
        }
        arr[j] = e;
    }
}

#endif // INSERTIONSORT_H
