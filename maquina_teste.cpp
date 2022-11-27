#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>

#include "maquina.h"

TEST_CASE("Testa Maquina::Buscar(string input)"){
    Maquina m("./Documentos");

    string input = "guardachuva";
    set<string> certo;
    certo.insert("teste1.txt");
    certo.insert("teste2.txt");

    CHECK(m.Buscar(input) == certo); // O método buscar deve retornar um set com os documentos que possuem a string "guardachuva".
}

TEST_CASE("Testa Maquina::Selecionar(buscadas, numero_de_palavras)"){
    Maquina m("./Documentos");
    set<string> certo;
    certo.insert("teste1.txt");

    set<string> buscadas;
    buscadas.insert("peixe");
    buscadas.insert("guardachuva");
    int numero_de_palavras = 2;

    CHECK(m.Selecionar(buscadas, numero_de_palavras) == certo); // O método buscar deve retornar um set com os documentos que possuem as strings "guardachuva" e "peixe".
}

TEST_CASE("Testa Maquina::Letra(str)"){
    Maquina m("./Documentos");
    
    string str1 = "A";
    string str2 = "á";

    CHECK(m.Letra(str1) == true); // O método deve retornar se a letra "A" está normalizada.
    CHECK(m.Letra(str2) == false); // O método deve retornar se a letra "á" está normalizada.
}

TEST_CASE("Testa Maquina::Normalizar(texto)"){
    Maquina m("./Documentos");

    string errada = "GIrá--ssöl";
    string certa = "girassol";

    CHECK(m.Normalizar(errada) == certa); // O método deve normalizar a string "girassol".
}