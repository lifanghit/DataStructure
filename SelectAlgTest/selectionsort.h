#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <iostream>
#include <algorithm>

using namespace std;

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


#endif // SELECTIONSORT_H
