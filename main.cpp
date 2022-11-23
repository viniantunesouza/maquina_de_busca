#include <iostream>
#include <sstream>
#include <string>

#include "maquina.h"

using namespace std;

int main() {
    Maquina m;
    cout << "O quê você deseja buscar hoje?" << endl;
    Maquina.Buscar();
    Maquina.Recuperar();
    return 0;
}