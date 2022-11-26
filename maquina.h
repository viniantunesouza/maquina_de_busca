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
        map<string, set<string>> Maquina_; // Índice invertido.
    
    public:
        // Cria um índice invertido com os documentos do diretório "./documentos/".
        Maquina();

        // Recebe uma lista de palavras e separa elas.
        void Buscar();

        // Seleciona os documentos que possuem todas as palavras buscadas, e os organiza.
        set<string> Selecionar(set<string> buscadas, int numero_de_palavras);

        // Normaliza o texto do parâmetro.
        string Normalizar(string input); 

        // "Printa" na tela os documentos que possuem todas as palavras buscadas.
        void Recuperar(set<string> documentos);
};


#endif