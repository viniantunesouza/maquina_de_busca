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

Maquina::Maquina(){
    string path = "./Documentos";
    for (const auto & entry : fs::directory_iterator(path)){
        string palavra;
        ifstream in;
        in.open(entry.path());
        while(in >> palavra){
            string entryPath = entry.path();
            string nome = entryPath.substr((path.length() + 1), (nome.length() - path.length()));
            Maquina_[Normalizar(palavra)].insert(nome);
        }

        in.close();
    }
}

void Maquina::Buscar(){
    int numero_de_palavras = 0;
    set<string> buscadas;
    string input, palavras;
    getline(cin, input);
    stringstream stream(input);
    while(getline(stream, palavras, ' ')){
        buscadas.insert(Normalizar(palavras));
        numero_de_palavras++;
    }
    Recuperar(Selecionar(buscadas, numero_de_palavras));   
}

set<string> Maquina::Selecionar(set<string> buscadas, int numero_de_palavras){
    map<string, int> documentosAntes;
    set<string> documentosDepois;
    for(auto it1 = buscadas.begin(); it1 != buscadas.end(); it1++){
        if(Maquina_.find(*it1) != Maquina_.end()){
            for(auto it2 = (Maquina_.find(*it1)->second).begin(); it2 != (Maquina_.find(*it1)->second).end(); it2++){
                documentosAntes[*it2]++;
            }
        }
    }
    for(auto it3 = documentosAntes.begin(); it3 != documentosAntes.end(); it3++){
        if (documentosAntes[it3->first] == numero_de_palavras){
            documentosDepois.insert(it3->first);
        }
    }
    return documentosDepois;
}

void Maquina::Recuperar(set<string> documentos){
    for(auto it = documentos.begin(); it != documentos.end(); it++){
        cout << *it << endl;
    }
}

vector<string> letras = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p",
    "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K",
    "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

bool Letra(string str) {
    for(int i = 0; i < letras.size(); i++) {
        if (letras[i] == str) {
            return true;
        }
    }
    
    return false;
}

string Maquina::Normalizar(string texto) {
    string output = "";
    
    for (int i = 0; i < texto.length(); i++) {
        string buffer = "";
        bool mudou = false;

        for (int j = 0; j < texto.length() - i; j++) {
            buffer += texto[i + j];
            
            if (Letra(buffer)) {
                output += tolower(buffer[0]);
            } else if (buffer == "á" || buffer == "ã" || buffer == "à" || buffer == "â" || buffer == "Á" || buffer == "Ã" || buffer == "À" || buffer == "Â") {
                output += 'a';
                mudou = true;
            } else if (buffer == "é" || buffer == "è" || buffer == "ê" || buffer == "É" || buffer == "È" || buffer == "Ê") {
                output += 'e';
                mudou = true;
            } else if (buffer == "í" || buffer == "ì" || buffer == "î" || buffer == "Í" || buffer == "Ì" || buffer == "Î") {
                output += 'i';
                mudou = true;
            } else if (buffer == "ó" || buffer == "õ" || buffer == "ò" || buffer == "ô" || buffer == "Ó" || buffer == "Õ" || buffer == "Ò" || buffer == "Ô") {
                output += 'o';
                mudou = true;
            } else if (buffer == "ú" || buffer == "ù" || buffer == "û" || buffer == "Ú" || buffer == "Ù" || buffer == "Û") {
                output += 'u';
                mudou = true;
            } else if (buffer == "ç" || buffer == "Ç") {
                output += 'c';
                mudou = true;
            }
        }
        
        mudou = false;
        buffer = "";
    }
    
    return output;
}



