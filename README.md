# ACTIVIDAD 1 - EDA
### Miguel Angel Alvarez
### Samuel Quintero
### Emmanuel Montoya Salazar

## Algoritmos usados
### 1. QuickSort
Analisis BigO

Mejor caso y Caso promedio
O(n log n) -> cuando el pivote divide la lista en 2 mitades mas o menos iguales

Peor caso
(n^2) -> cuando el pivote que se elige resulta ser el numero mayor o el numero menor de el arreglo

Tiempo de ejecucion: 0.321877 seg

### 2. HeapSort

Peor caso, caso promedio y mejor caso
O(n log n) -> son iguales ya que no importa si la lista esta ordenada o no, el algoritmo hace las mismas comparaciones en cualquier caso

Este algoritmo antes de ordenar siempre debe agrupar los datos en un arbol valido. En el primer ciclo for de el archivo "heapSort.cpp" revisa la estructura completa
Esto toma un tiempo de O(n)

-heapsort toma el elemento mas grande y lo manda al final. El ultimo elemento lo pone en la raiz, esto provoca que la funcion debe hundirlo, comparandolo con sus hijos nivel por nivel, eso es 
para restaurar el orden.

-Como el elemento es tan peque;o, en la inmensa mayoria de la iteraciones tendra que caer a alguna hoja del arbol, la distancia desde la raiz hasta las hojas en un arbol binario es de *O(log n)*
al repetir el proceso de extraccion y hundimiento  para n elementos nos da que la complejidad algoritmica es de _O(n log n)_

Tiempo de ejecucion: 0.322367 seg

### 3, Arbol AVL
- Insercion -> O(log n)
- Insertar n palabras O(n log n)
- Recorrido Inorder O(n)
- Total =O (n log n)

-AVL mantiene la propiedad de balance: la diferencia de alturas entre subárboles izquierdo y derecho es máximo 1 en todo nodo, por lo tanto, cada insercion recorre como maximo la altura O(log n)
Tiempo de ejecucion: 0.199938 seg

## Estructura del proyecto 

actividadEDA_1/
├── source/
│   ├── main.cpp
│   ├── quickSort.h / quickSort.cpp   (namespace qS) se usa interfaz en las clases para lograr un codigo mas limpio!
│   ├── heapSort.h  / heapSort.cpp    (namespace hS)
│   ├── arbolAVL.h  / arbolAVL.cpp   (namespace avl)
│   └── palabras.txt
└── CMakeLists.txt


