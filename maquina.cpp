#include "maquina.h"
#include <fstream>
#include <filesystem>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

namespace fs = std::filesystem;
using namespace std;

// Cria um índice invertido com os documentos do diretório "./documentos/".
Maquina::Maquina(string path){
    for (const auto & entry : fs::directory_iterator(path)){ // Iterador para os documentos da pasta.
        string palavra;
        ifstream in;
        in.open(entry.path());
        while(in >> palavra){ // Insere cada palavra e o documento em que se encontra no map Maquina_.
            string entryPath = entry.path();
            string nome = entryPath.substr((path.length() + 1), (entryPath.length() - path.length())); // Retira o nome da pasta do nome do documento.
            Maquina_[Normalizar(palavra)].insert(nome);
        }

        in.close();
    }
}

// Recebe uma lista de palavras e separa elas.
set<string> Maquina::Buscar(string input){
    int numero_de_palavras = 0;
    set<string> buscadas;
    string palavras;
    stringstream stream(input);
    while(getline(stream, palavras, ' ')){ // Separa cada palavra da busca e insere no set "buscadas".
        buscadas.insert(Normalizar(palavras));
        numero_de_palavras++;
    }
    return Selecionar(buscadas, numero_de_palavras); // "Printa" as palavras depois de tirar os documentos em que nem todas aparecem.   
}

// Seleciona os documentos que possuem todas as palavras buscadas, e os organiza.
set<string> Maquina::Selecionar(set<string> buscadas, int numero_de_palavras){
    map<string, int> documentosAntes;
    set<string> documentosDepois;
    for(auto it1 = buscadas.begin(); it1 != buscadas.end(); it1++){ // Seleciona cada palavra da busca.
        if(Maquina_.find(*it1) != Maquina_.end()){ // Checa se a palavra existe no map dos documentos.
            for(auto it2 = (Maquina_.find(*it1)->second).begin(); it2 != (Maquina_.find(*it1)->second).end(); it2++){ // Itera todos os documentos em que a palavra aparece no map.
                documentosAntes[*it2]++; // Adiciona todos os documentos (mesmo os que não possuem todas as palavras buscadas).
            }
        }
    }
    for(auto it3 = documentosAntes.begin(); it3 != documentosAntes.end(); it3++){ // Itera na lista dos documentos sem filtragem.
        if (documentosAntes[it3->first] == numero_de_palavras){ // Checa se o número de vezes que cada documento aparece é igual ao número de palavras buscadas.
            documentosDepois.insert(it3->first); // Passa os documentos em que todas as palavras aparecem para um set.
        }
    }
    return documentosDepois;
}

vector<string> letras = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p",
    "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K",
    "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"}; // Conjunto das letras que podem aparecer após normalizar.

bool Maquina::Letra(string str) { // Checa se o caracter do parâmetro é uma letra do vector acima.
    for(int i = 0; i < letras.size(); i++) {
        if (letras[i] == str) {
            return true;
        }
    }
    
    return false;
}

// Normaliza o texto do parâmetro.
string Maquina::Normalizar(string texto) {
    string output = "";
    
    for (int i = 0; i < texto.length(); i++) { // Percorre cada letra da palavra do parâmetro.
        string buffer = "";

        for (int j = 0; j < texto.length() - i; j++) {
            buffer += texto[i + j]; // Acumula os caracteres para comparar.
            
            if (Letra(buffer)) { // Compara o buffer com os caracteres e substitui pela letra correspondente.
                output += tolower(buffer[0]);
            } else if (buffer == "á" || buffer == "ã" || buffer == "à" || buffer == "â" || buffer == "ä" || buffer == "Á" || buffer == "Ã" || buffer == "À" || buffer == "Â" || buffer == "Ä") {
                output += 'a';
            } else if (buffer == "é" || buffer == "è" || buffer == "ê" || buffer == "ë" || buffer == "É" || buffer == "È" || buffer == "Ê" || buffer == "Ë") {
                output += 'e';
            } else if (buffer == "í" || buffer == "ì" || buffer == "î" || buffer == "ï" || buffer == "Í" || buffer == "Ì" || buffer == "Î" || buffer == "Ï") {
                output += 'i';
            } else if (buffer == "ó" || buffer == "õ" || buffer == "ò" || buffer == "ö" || buffer == "ô" || buffer == "Ó" || buffer == "Õ" || buffer == "Ö" || buffer == "Ò" || buffer == "Ô") {
                output += 'o';
            } else if (buffer == "ú" || buffer == "ù" || buffer == "û" || buffer == "ü" || buffer == "Ú" || buffer == "Ù" || buffer == "Û" || buffer == "Ü") {
                output += 'u';
            } else if (buffer == "ç" || buffer == "Ç") {
                output += 'c';
            }
        }
        
        buffer = "";
    }
    
    return output;
}



