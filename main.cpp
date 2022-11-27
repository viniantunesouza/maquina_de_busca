#include <iostream>
#include <sstream>
#include <string>

#include "maquina.h"

using namespace std;

int main() {
    Maquina m("./Documentos"); // Cria um objeto na classe Maquina, para o diretório onde estão os documentos.
    string input;
    cout << "O quê você deseja buscar hoje?" << endl;
    getline(cin, input);
    set<string> documentos = m.Buscar(input);
    for(auto it = documentos.begin(); it != documentos.end(); it++){ // Itera na lista de documentos já filtrada.
        cout << *it << endl;
    }
    return 0;
}