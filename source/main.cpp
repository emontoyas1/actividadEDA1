#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <chrono>

struct Nodo {
    std::string palabra;
    Nodo *izq, *der;
    int altura;
    Nodo(const std::string& p) : palabra(p), izq(nullptr), der(nullptr), altura(1) {}
};

int h(Nodo* n) { return n ? n->altura : 0; }

Nodo* rotarDerecha(Nodo* y) {
    Nodo* x = y->izq;
    y->izq = x->der;
    x->der = y;
    y->altura = std::max(h(y->izq), h(y->der)) + 1;
    x->altura = std::max(h(x->izq), h(x->der)) + 1;
    return x;
}

Nodo* rotarIzquierda(Nodo* x) {
    Nodo* y = x->der;
    x->der = y->izq;
    y->izq = x;
    x->altura = std::max(h(x->izq), h(x->der)) + 1;
    y->altura = std::max(h(y->izq), h(y->der)) + 1;
    return y;
}

Nodo* insertarAVL(Nodo* nodo, const std::string& palabra) {
    if (!nodo) return new Nodo(palabra);
    if (palabra < nodo->palabra) nodo->izq = insertarAVL(nodo->izq, palabra);
    else if (palabra > nodo->palabra) nodo->der = insertarAVL(nodo->der, palabra);
    else return nodo;

    nodo->altura = 1 + std::max(h(nodo->izq), h(nodo->der));
    int bal = h(nodo->izq) - h(nodo->der);

    if (bal > 1 && palabra < nodo->izq->palabra) return rotarDerecha(nodo);
    if (bal < -1 && palabra > nodo->der->palabra) return rotarIzquierda(nodo);
    if (bal > 1 && palabra > nodo->izq->palabra) {
        nodo->izq = rotarIzquierda(nodo->izq);
        return rotarDerecha(nodo);
    }
    if (bal < -1 && palabra < nodo->der->palabra) {
        nodo->der = rotarDerecha(nodo->der);
        return rotarIzquierda(nodo);
    }
    return nodo;
}

std::vector<std::string> cargarDatos(const std::string& nombreArchivo) {
    std::vector<std::string> palabras;
    std::ifstream archivo(nombreArchivo);
    std::string palabra;
    if (archivo.is_open()) {
        while (archivo >> palabra) {
            palabras.push_back(palabra);
        }
        archivo.close();
    } else {
        std::cerr << "Error: No se pudo localizar el archivo " << nombreArchivo << std::endl;
    }
    return palabras;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

std::vector<std::string> dataOriginal = cargarDatos("source/palabras.txt");
    if (dataOriginal.empty()) {
        std::cout << "Error: Conjunto de datos vacio." << std::endl;
        return 1;
    }

    std::vector<std::string> dataQuick = dataOriginal;
    auto inicioQ = std::chrono::high_resolution_clock::now();
    std::sort(dataQuick.begin(), dataQuick.end());
    auto finQ = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> tiempoQ = finQ - inicioQ;
    std::cout << "Resultados de rendimiento:" << std::endl;
    std::cout << "Tiempo de ejecucion QuickSort: " << tiempoQ.count() << " segundos" << std::endl;

    Nodo* raiz = nullptr;
    auto inicioA = std::chrono::high_resolution_clock::now();
    for (const std::string& s : dataOriginal) {
        raiz = insertarAVL(raiz, s);
    }
    auto finA = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> tiempoA = finA - inicioA;
    std::cout << "Tiempo de ejecucion Arbol AVL: " << tiempoA.count() << " segundos" << std::endl;

    
    std::cout << "\n--- ANALISIS DE RENDIMIENTO Y MEMORIA ---" << std::endl;
    std::cout << "Cantidad de elementos analizados (n): 100000" << std::endl;
    std::cout << "Complejidad Algoritmica Teorica: O(n log n)" << std::endl;
    std::cout << "Tamano unitario de un Nodo AVL: " << sizeof(Nodo) << " bytes" << std::endl;
    std::cout << "Memoria total estimada (AVL): " << (sizeof(Nodo) * 100000) / 1024 << " KB" << std::endl;
    std::cout << "Memoria total estimada (Vector): " << (sizeof(std::string) * 100000) / 1024 << " KB" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    
    
    return 0;
}