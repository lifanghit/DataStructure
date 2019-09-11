#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <iostream>
#include <algorithm>

using namespace std;

//冒泡排序
template<typename T>
void bubbleSort(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = n-1; j > i; j--) {
            if (arr[j-1] > arr[j])
                swap(arr[j], arr[j-1]);
        }
    }
}


//优化1：冒泡排序
template<typename T>
void bubbleSort1(T arr[], int n) {
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

//优化2：冒泡排序
template<typename T>
void bubbleSort2(T arr[], int n) {
    int newn;  //使用newn进行优化

    do {
        newn = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i-1] > arr[i]) {
                swap(arr[i], arr[i-1]);

                // 记录最后一次的交换位置,在此之后的元素在下一轮扫描中均不考虑
                newn = i;
            }

        }
        n = newn;
    } while (newn > 0);
}

#endif // BUBBLESORT_H
