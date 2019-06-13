#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include "BUSCADOR.h"
#include "BUSCADOR.cpp"

using std::map;
using std::string;
using std::vector;
using Maquina_de_busca::Arquivo;



int main(int argc, char *argv[])
{

    Arquivo arquivo = Arquivo();

	int i, num=1;
	for(i = 1; i < argc; i++)
	{
        std::cout << "Aguarde " << i << std::endl;
		arquivo = Arquivo(argv[i]);
            if(arquivo.nullFile == 1)
            {
                std::cout << "Terminando a leitura do arquivo"<<std::endl;
                return 0;
            }

    }

while(num!=0)
    {
        std::cout<<std::endl<<"Digite a quantidade de palavras a ser pesquisada ou zero caso não queiraa realizar uma pesquisa: ";
        std::cin>> num;
        string palavraPesquisada[num];
        vector<string> resultado;

        if(num == 0)
        {
            return 0;
        }

for(i=0; i<num; i++)
    {
        std::cout << "Insira a palavra "<< i+1 << std::endl;
		std::cin >> palavraPesquisada[i];

bool existe = Arquivo::buscaPalavra(resultado, palavraPesquisada[i]);
    if(existe)
		{
			std::cout << "Palavra existe nos seguintes arquivos: " << std::endl;
			Maquina_de_busca::mostraResultado(resultado);
		} else {
			std::cout << "Palavra pesquisada NAO EXISTE" << std::endl << std::endl;
                }

    }
        cosineRanking(argc, num, argv, palavraPesquisada, arquivo);
    }

}

