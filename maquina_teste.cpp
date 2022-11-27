#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>

#include "maquina.h"

TEST_CASE("Testa Maquina::Buscar(string input)"){
    Maquina m("./Teste");

    string input = "guardachuva";
    set<string> certo;
    certo.insert("teste1.txt");

    CHECK(m.Buscar(input) == certo);
}

TEST_CASE("Testa Maquina::Selecionar(buscadas, numero_de_palavras)"){
    Maquina m("./Teste");
    set<string> certo;
    certo.insert("teste1.txt");

    set<string> buscadas;
    buscadas.insert("peixe");
    buscadas.insert("guardachuva");
    int numero_de_palavras = 2;

    CHECK(m.Selecionar(buscadas, numero_de_palavras) == certo);
}

TEST_CASE("Testa Maquina::Letra(str)"){
    Maquina m("./Teste");
    
    string str1 = "A";
    string str2 = "á";

    CHECK(m.Letra(str1) == true);
    CHECK(m.Letra(str2) == false);
}

TEST_CASE("Testa Maquina::Normalizar(texto)"){
    Maquina m("./Teste");

    string errada = "GIrá--ssöl";
    string certa = "girassol";

    CHECK(m.Normalizar(errada) == certa);
}