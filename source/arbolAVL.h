//
// Created by monto on 21/03/2026.
//

#ifndef ARBOLAVL_H
#define ARBOLAVL_H

#include <string>
#include <vector>

namespace avl {

    struct Nodo {
        std::string palabra;
        Nodo *izq, *der;
        int altura;
        Nodo(const std::string& p) : palabra(p), izq(nullptr), der(nullptr), altura(1) {}
    };

    class arbolAVL {
    public:
        static int h(Nodo* n);
        static Nodo* rotarDerecha(Nodo* y);
        static Nodo* rotarIzquierda(Nodo* x);
        static Nodo* insertarAVL(Nodo* nodo, const std::string& palabra);
        static void inorden(Nodo* nodo, std::vector<std::string>& resultado);
    };

}

#endif //ARBOLAVL_H
