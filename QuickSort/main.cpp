#include <iostream>
#include <ctime>
#include "sorttesthelper.h"
#include "mergesort.h"
#include "quicksort.h"

using namespace std;

// 对arr[l...r]部分进行partition操作
// 返回p，使得arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template<typename T>
int __partition2(T arr[], int l, int r) {
    //随机化选择一个标定
    swap(arr[l], arr[rand()%(r-l+1)+l]);

    T v = arr[l];

    //arr[l+1...i) <= v ; arr(j...r] >= v
    int i = l+1, j = r;
    while (true) {
        while (i <= r && arr[i] < v)
            i++;
        while (j >= l+1 && arr[j] > v)
            j++;
        if (i > j) break;
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    swap(arr[l], arr[j]);
    return j;
}

//对arr[l...r]部分进行快速排序
template<typename T>
void __quickSort2(T arr[], int l, int r) {
//    if( l >= r)
//        return;
    if(r-l <= 15){
        insertionSort(arr, l, r);
        return;
    }

    int p = __partition2(arr, l, r);
    __quickSort2(arr, l, p-1);
    __quickSort2(arr, p+1, r);
}

//优化2： 两路快速排序算法
template<typename T>
void quickSort2(T arr[], int n) {
    srand(time(NULL));
    __quickSort2(arr, 0, n-1);
}


// 比较Merge Sort和Quick Sort两种排序算法的性能效率
// 两种排序算法虽然都是O(nlogn)级别的, 但是Quick Sort算法有常数级的优势
// Quick Sort要比Merge Sort快, 即使我们对Merge Sort进行了优化
int main()
{
    int n = 1000;

    //测试1：一般性测试
    cout <<"Test for Random Array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);
    int *arr3 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort 2", quickSort2, arr3, n);

    delete [] arr1;
    delete [] arr2;
    delete [] arr3;


    //测试2：测试近乎有序的数组
    int swaptimes = 10;
    cout <<"Test Random for Nearly Ordered Array, size = "<<n<<", swaptimes = "<<swaptimes<<endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n, swaptimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort 2", quickSort2, arr3, n);

    delete [] arr1;
    delete [] arr2;
    delete [] arr3;

    return 0;
}
