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
        map<string, set<string>> Maquina_; // Índice invertido
    
    public:
        // Cria um índice invertido com os documentos do diretório "./documentos/"
        Maquina();

        // Recebe uma lista de palavras
        void Buscar();

        // Seleciona os documentos que possuem as palavras buscadas, e os organiza
        set<string> Selecionar(set<string> buscadas, int numero_de_palavras);

        // Normaliza o texto de entrada
        string Normalizar(string input); 

        // Retorna os valores da máquina de busca
        void Recuperar(set<string> documentos);
};


#endif