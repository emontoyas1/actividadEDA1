//
// Created by monto on 20/03/2026.
//

#include "quickSort.h"
namespace qS {
    void quickSort::organizarQS(std::vector<std::string>& arrQuick) {
        if (arrQuick.empty() || arrQuick.size() <= 1) return;
        recursividadQS(arrQuick, 0, arrQuick.size() -1);
    }

    void quickSort::recursividadQS(std::vector<std::string> &dataQuick, int low, int high) {
        if (low < high) {
            int piv = dividir(dataQuick, low, high);
            recursividadQS(dataQuick, low, piv -1);//izquierda menores al pivpte
            recursividadQS(dataQuick, piv +1, high);// mitad derecha (mayores al pivote)
        }
    }

    int quickSort::dividir(std::vector<std::string>&dataQuick, int low, int high) {

        std::string pivote = dataQuick[high];
        int i = low -1;
        for (int j=low; j<high; j++) {
            if (dataQuick[j] <= pivote) {
                i++;
                std::string temp = dataQuick[i]; //swap
                dataQuick[i] = dataQuick[j];
                dataQuick[j] = temp;
            }
        }

        std::string tempFinal = dataQuick[i+1];
        dataQuick[i+1] = dataQuick[high];
        dataQuick[high] = tempFinal;

        return i+1;
    }
}










