//
// Created by monto on 20/03/2026.
//
//interfaz
#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
#include <string>


class quickSort {

public:
    void sort(std::vector<std::string>&dataQuick);

    void recursividadQS(std::vector<std::string>&dataQuick, int low, int high);

    int dividir(std::vector<std::string>&dataQuick, int low, int high);


};



#endif //QUICKSORT_H
