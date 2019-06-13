#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "BUSCADOR.h"


using std::vector;
using std::string;
using std::map;

namespace Maquina_de_busca
{
	map<string, vector<string>> Arquivo::indiceInvertido;

	Arquivo::Arquivo()
	{

	}

    Arquivo::Arquivo(string nomeArquivo)
	{
		this-> nomeArquivo = nomeArquivo;
		nullFile = 0;

		std::ifstream arquivoOpen;// Abre arquivo
			arquivoOpen.open(this->nomeArquivo);
                if(arquivoOpen.fail())
                {
                    nullFile = 1;
                }
                for(string linha; getline(arquivoOpen, linha);)
                {
                    vector<string> palavras = this->NormalizaTexto(linha);

                        for(vector<string>::iterator palavra = palavras.begin(); palavra != palavras.end(); ++palavra)
                        {
                            map<string, vector<string>>::iterator eBook = Arquivo::indiceInvertido.find(*palavra);
                                if(eBook != Arquivo::indiceInvertido.end())
                                {
                                    if(std::find(eBook->second.begin(), eBook->second.end(), this->nomeArquivo) == eBook->second.end())
                                    {
                                        vector<string>::iterator caminhoArquivo = eBook->second.end();
                                        eBook->second.insert(caminhoArquivo, this->nomeArquivo);
                                    }
                                } else {
                                        vector<string> novoValor {this->nomeArquivo};
                                        Arquivo::indiceInvertido.insert(std::pair<string, vector<string>>(*palavra, novoValor));
                                        }
                        }
                    }

    arquivoOpen.close();
	}

        vector<string> Arquivo::NormalizaTexto(string linha)
            {
                for(int i = 0; linha[i]; i++)
                {
                    linha[i] = tolower(linha[i]);
                }

                for(int i = 0; linha[i]; i++)
                {
                    if(!((linha[i] >= 97 && linha[i] <= 122) || (linha[i] >= 30 && linha[i] <= 39) || linha[i] == 32))
                        linha.erase(i,1);
                }

		string Separar; // Separa em palavras
		std::stringstream ss(linha);
		vector<string> palavras;
            while (ss >> Separar)
            {
                palavras.push_back(Separar);
            }
            return palavras;
	}

bool Arquivo::buscaPalavra(vector<string>& resultado, const string& palavra)
	{
	    std::map<string, vector<string>>::iterator busca;
		busca = Arquivo::indiceInvertido.find(palavra);
		std::cout << "Buscando por: '" << palavra << "'" << std::endl;
            if(busca != Arquivo::indiceInvertido.end())
            {
                resultado = busca->second;
                return true;
            } else {
                return false;
                    }
    }

    int Arquivo::contaPalavra(string palavra, string nomeArquivo)
	{
        int i, cont=0;
	    vector<string> palavras;
	    std::ifstream arquivoOpen;
        arquivoOpen.open(nomeArquivo);
            if(arquivoOpen.fail())
            {
                std::cout<<"FALHA na leitura do arquivo!"<<std::endl;
                nullFile = 1;
                return 0;
            }

		for(string linha; getline(arquivoOpen, linha);)
		{
			vector<string> palavras = this->NormalizaTexto(linha);
                for(i=0; i<palavras.size(); i++)
                    {
                        if(palavra.compare(palavras[i])==0)
                        {
                            cont++;
                        }
                    }
		}
    arquivoOpen.close();
    return cont;
}

int Arquivo::indiceInvertidosize()
	{
	    return indiceInvertido.size();
	}
    map<string, vector<string>>  Arquivo::getindiceInvertido()
    {
        return indiceInvertido;
    }

void mostraResultado(vector<string> resultado)
	{
        for (vector<string>::iterator res = resultado.begin() ; res != resultado.end(); ++res)
        {
            std::cout << *res << std::endl;
        }
    std::cout << std::endl;
	}

void cosineRanking(int argc, int num, char *argv[], string *palavraPesquisada, Arquivo arquivo) //Importancia das palavras
	{
        float vetorDocumento[argc-1][arquivo.indiceInvertidosize()] = {{0}};

        float vetorPalavrasPesquisadas[num][arquivo.indiceInvertidosize()] = {{0}};

        float similaridade[argc], idf=0;

        float aux1=0, aux2=0, aux3=0, id=0, n=0;

        int i, j=0, k;

    string auxstring;
    map<string, vector<string>> auxmap = arquivo.getindiceInvertido();
    vector<string> auxvetor;
    map<string, vector<string>>::iterator it;


for(i=1; i<argc; i++)
    {
        for(it = auxmap.begin(); it != auxmap.end(); it++)
        {
            auxvetor = it->second;
            n = auxvetor.size();
            id = arquivo.contaPalavra(it->first, argv[i]);
            idf = log((argc-1)/n);
            vetorDocumento[i-1][j] = id*idf;
            j++;
        }
        j=0;
    }


    n=0, j=0;

for(i=0; i<num; i++)
    {
        for(it = auxmap.begin(); it != auxmap.end(); it++)
            {
                if(palavraPesquisada[i].compare(it->first)==0)
                    {
                        auxvetor = it->second;
                        n = auxvetor.size();
                        idf = log((argc-1)/n);
                        vetorPalavrasPesquisadas[i][j] = idf*1;
                    } else {
                    vetorPalavrasPesquisadas[i][j] = 0;
                    }
                j++;
            }

            j=0;
    }

for(k=0; k<num; k++)
    {
        for(j=0; j<arquivo.indiceInvertidosize();j++)
            {
                aux2 = aux2 + pow(vetorPalavrasPesquisadas[k][j],2);
            }
    }

        for(i=0; i<argc-1; i++)
            {
                for(j=0;j<arquivo.indiceInvertidosize();j++)
                    {
                        aux1 = aux1 + pow(vetorDocumento[i][j], 2);
                    }

        for(k=0;k<num;k++)
            {
                for(j=0; j<arquivo.indiceInvertidosize();j++)
                    {
                        aux3 = aux3 + vetorDocumento[i][j]*vetorPalavrasPesquisadas[k][j];
                    }
            }


        similaridade[i] = aux3/(sqrt(aux1) * sqrt(aux2)); // equação da similaridade
        aux1 = 0;
        aux3 = 0;
    }

    std::cout<<"Ranking Consine: "<< std::endl;
    map<float, string> ranking;

for(i=0; i<argc-1; i++)
    {
        ranking.insert(std::pair<float,string>(similaridade[i]*-1, argv[i+1]));
    }

        i=1;
        map<float, string>::iterator it2;

    for(it2 = ranking.begin(); it2 != ranking.end(); it2++)
        {
            std::cout<<i<<". "<<it2->second<<std::endl;
            i++;
        }

	}
}
