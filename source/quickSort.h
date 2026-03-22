//
// Created by monto on 20/03/2026.
//
//interfaz
#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
#include <string>
#include <iostream>


namespace qS{
class quickSort {
public:
    static void organizarQS(std::vector<std::string>&dataQuick);

    static void recursividadQS(std::vector<std::string>&dataQuick, int low, int high);

    static int dividir(std::vector<std::string>&dataQuick, int low, int high);
};
};



#endif //QUICKSORT_H
