#include <iostream>
#include <string>
#include <vector>
#include <fstream>

std::vector<std::string> cargarDatos(const std::string& data){
     std::vector<std::string> palabras;
     std::ifstream archivo(data);
     std::string palabra;
    while (archivo>>palabra) {
        palabras.push_back(palabra);
    }
return palabras;
    data.close();


}

int main() {
    std::vector<std::string> dataOriginal = cargarDatos("palabras.txt");

    std::vector<std::string> dataQuick = dataOriginal;

    std::vector<std::string> dataHeap = dataOriginal;

    std::vector<std::string> dataAVL= dataOriginal;

}