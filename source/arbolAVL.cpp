//
// Created by monto on 21/03/2026.
//

#include "arbolAVL.h"
#include <algorithm>

namespace avl {

    int arbolAVL::h(Nodo* n) {
        return n ? n->altura : 0;
    }

    Nodo* arbolAVL::rotarDerecha(Nodo* y) {
        Nodo* x = y->izq;
        y->izq = x->der;
        x->der = y;
        y->altura = std::max(h(y->izq), h(y->der)) + 1;
        x->altura = std::max(h(x->izq), h(x->der)) + 1;
        return x;
    }

    Nodo* arbolAVL::rotarIzquierda(Nodo* x) {
        Nodo* y = x->der;
        x->der = y->izq;
        y->izq = x;
        x->altura = std::max(h(x->izq), h(x->der)) + 1;
        y->altura = std::max(h(y->izq), h(y->der)) + 1;
        return y;
    }

    Nodo* arbolAVL::insertarAVL(Nodo* nodo, const std::string& palabra) {
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

    void arbolAVL::inorden(Nodo* nodo, std::vector<std::string>& resultado) {
        if (!nodo) return;
        inorden(nodo->izq, resultado);
        resultado.push_back(nodo->palabra);
        inorden(nodo->der, resultado);
    }

}
