#include <iostream>
#include <sstream>
#include <string>

#include "maquina.h"

using namespace std;

int main() {
    Maquina m; // Cria um objeto na classe Maquina.
    cout << "O quê você deseja buscar hoje?" << endl;
    m.Buscar(); // Realiza a busca da palavra e dá "cout" nos documentos requeridos.
    return 0;
}