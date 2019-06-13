#ifndef BUSCADOR_H_INCLUDED
#define BUSCADOR_H_INCLUDED
#include <iostream>
#include <vector>
#include <map>
#include <string>

using std::vector;
using std::string;
using std::map;

namespace Maquina_de_busca
{
	class Arquivo
	{
		public:

            Arquivo();
			Arquivo(string nomeArquivo);
			static bool buscaPalavra(vector<string>& resultado, const string& palavra);
			bool nullFile;
			int contaPalavra(string palavra, string nomeArquivo);//retorna a quantidade de vezes que uma palavra aparece dentro de um determinado documento
			map<string, vector<string>>  getindiceInvertido();
			int indiceInvertidosize();
			void mostraResultado(vector<string> resultado);
			void cosineRanking(int argc, int num, char *argv[], string *palavraPesquisada, Arquivo arquivo);

		private:

			static map<string, vector<string>> indiceInvertido;
			static vector<string> NormalizaTexto(string linha);
			string nomeArquivo;
			friend class Teste;

	};
}
#endif // BUSCADOR_H_INCLUDED
