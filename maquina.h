#ifndef _MAQUINA_H_
#define _MAQUINA_H_

#include <map>
#include <set>
#include <string>

using namespace std;

// Implementa uma máquina de busca que mapeia uma string
// a um set de files.
class Maquina{
    private:
        map<string,set<string>> Maquina_; // índice invertido
        set<string> input; // entrada do usuário
    
    public:
        // Cria um índice invertido com os documentos do diretório "./documentos/"
        Maquina();

        // Recebe uma lista de palavras
        set<string> Buscar();

        // Normaliza o texto de entrada
        void Normalizar(string input); 

        // Retorna os valores da máquina de busca
        void Recuperar(string input);
};


#endif