//
// Created by monto on 22/03/2026.
//

#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <vector>
#include <string>
namespace hS{
    class heapSort {


    public:
        static void heapify(std::vector<std::string>& arr, int n, int i);
        static void heapSortfun(std::vector<std::string>& palbras);

    };
}


#endif //HEAPSORT_H
