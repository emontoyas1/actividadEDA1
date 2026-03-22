//
// Created by monto on 22/03/2026.
//

#include "heapSort.h"
using namespace std;
namespace hS {
    void heapSort::heapify(std::vector<string>& arr, int n, int i) {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < n && arr[left] > arr[largest])
            largest = left;

        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapSort::heapify(arr, n, largest);
        }
    }

    void heapSort::heapSortfun(vector<string>& arr) {
        int n = arr.size();


        for (int i = n/2 - 1; i >= 0; i--)
            heapSort::heapify(arr, n, i);

        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapSort::heapify(arr, i, 0);
        }
    }
}