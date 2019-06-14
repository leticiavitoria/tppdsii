#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "BUSCADOR.h"
#include "doctest.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>


class Teste
{
public:

static string nomeArquivo(Arquivo &c)
    {
        return c.nomeArquivo;
    }
};

TEST_SUITE("Arquivo") {

  TEST_CASE("Arquivo(string nomeArquivo)")
    {
        Arquivo arquivo = Arquivo(Teste::nomeArquivo);
        CHECK_FALSE if(arquivo.nullFile == 1);
    }

  TEST_CASE("buscaPalavra(vector<string>& resultado, const string& palavra)")
    {
        Arquivo arquivo = Arquivo(Teste::nomeArquivo);
        CHECK(palavraPesquisada[quem] = "quem");
    }

  TESTE_CASE("contaPalavra(string palavra, string nomeArquivo)")
    {
        Arquivo arquivo = Arquivo(Teste::nomeArquivo);
        CHECK( arquivo.contaPalavra("quem", Teste::nomeArquivo) >= 1);
    }

  TESTE_CASE("map<string, vector<string>>")
    {
        map<string, vector<string>> m;
        m[teste] = "A"
        m[teste2] = "B"
        CHECK(m[teste] = "A");
        CHECK(m[teste2] = "B");
    }

  TESTE_CASE("cosineRanking(int argc, int num, char *argv[], string *palavraPesquisada, Arquivo arquivo);")
    {
        Arquivo arquivo = Arquivo(Teste::nomeArquivo);
        string palavraPesquisada[A];
        cosineRanking(int argc, int num, char *argv[], string *palavraPesquisada, Arquivo arquivo)
        CHECK(mostraResultado = (Documento onde possui mais palavras A, isso vai depender dos arquivos escolhidos));
    }
}
