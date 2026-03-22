#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <chrono>
#include "heapSort.h"
#include "quickSort.h"
#include "arbolAVL.h"



std::vector<std::string> cargarDatos(const std::string& data){
     std::vector<std::string> palabras;
     std::ifstream archivo(data);
     std::string palabra;
    while (archivo>>palabra) {
        palabras.push_back(palabra);
    }

    archivo.close();
return palabras;



}


int main() {
    std::vector<std::string> dataOriginal = cargarDatos("palabras.txt"); // aca las palabras se convierten en vector
    //quickSort
    std::vector<std::string> dataQuick = dataOriginal;

    auto start_qs = std::chrono::high_resolution_clock::now();
    qS::quickSort::organizarQS(dataQuick);
    auto end_qs = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duracion_qs = end_qs - start_qs;

    std::cout<< "--------------------------------------------------" << std::endl;
    std::cout << "primeros 10 palabras ordenadas quickSort:   " << std::endl;

    for (int i = 0; i < 10 && i < (int)dataQuick.size(); i++) {
        std::cout << dataQuick[i] << " | ";
    }
    std::cout << "tiempo de quicksort: " << duracion_qs.count() << " seg" << std::endl;


    //heapSort
    std::vector<std::string> dataHeap = dataOriginal;

    auto start_hs = std::chrono::high_resolution_clock::now();
    hS::heapSort::heapSortfun(dataHeap);
    auto end_hs = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duracion_hs = end_hs - start_hs;

    std::cout<< "--------------------------------------------------" << std::endl;

    std::cout<<"primeros 10 palabras ordenadas heapsort:     "<<std::endl;

    for (int i = 0; i < 10 && i < (int)dataHeap.size(); i++) {
        std::cout << dataHeap[i] << " | ";
    }
    std::cout << "tiempo de heapsort: " << duracion_hs.count() << " seg" << std::endl;


    //arbolAVL
    std::vector<std::string> dataAVL = dataOriginal;

    avl::Nodo* raiz = nullptr;
    auto start_avl = std::chrono::high_resolution_clock::now();
    for (const std::string& palabra : dataAVL) {
        raiz = avl::arbolAVL::insertarAVL(raiz, palabra);
    }
    auto end_avl = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duracion_avl = end_avl - start_avl;

    std::cout<< "--------------------------------------------------" << std::endl;
    std::cout << "primeros 10 palabras ordenadas arbolAVL:" << std::endl;

    std::vector<std::string> ordenadoAVL;
    avl::arbolAVL::inorden(raiz, ordenadoAVL);
    for (int i = 0; i < 10 && i < (int)ordenadoAVL.size(); i++) {
        std::cout << ordenadoAVL[i] << " | ";
    }
    std::cout << "tiempo de arbolAVL: " << duracion_avl.count() << " seg" << std::endl;

    std::cout<< "--------------------------------------------------" << std::endl;


    }


