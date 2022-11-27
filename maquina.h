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
        Maquina(string path);

        // Recebe uma lista de palavras e retorna os documentos buscados.
        set<string> Buscar(string input);

        // Seleciona os documentos que possuem todas as palavras buscadas, e os organiza.
        set<string> Selecionar(set<string> buscadas, int numero_de_palavras);

        // Checa se o caracter do parâmetro é uma letra normalizada ou não.
        bool Letra(string str);

        // Normaliza o texto do parâmetro.
        string Normalizar(string input); 

};


#endif