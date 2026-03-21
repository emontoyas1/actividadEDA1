//
// Created by monto on 20/03/2026.
//

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
#include <string>


class quickSort {

public:
    void sort(std::vector<std::string>& vector);

private:
    void recursividadQS(std::vector<std::string>& arr, int low, int high);

    void dividir(std::vector<std::string>& arr, int low, int high);


};



#endif //QUICKSORT_H
