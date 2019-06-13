Trabalho Prático: Máquina de Busca - Programação e Desenvolvimento de Software II - UFMG

Esse trabalho tem como objetivo implementar uma máquina de busca textual, a qual consiga abrir arquivos em .txt de um diretório, 
armazenar em formas de strings essas palavras juntamente com o número de vezes que elas aparecem e, ao final, 
gerar um índice contendo esses valores armazenados (ignorando sinais de pontuação e diferenças entre letras maiúsculas e minúsculas). 
O usuário deve informar a base de dados onde o buscador deverá consultar as palavras determinadas.

Índice invertido: relaciona a palavra do vocabulário com a lista de documentos

IDF: importância da palavra no documento, definida na expressão abaixo.

Classificação dos resultados: O peso de cada palavra é determinada pela quantidade vezes que ela aparece no documento, 
sendo a posição ocupada no vetor definida por: idf(t) = log(N/nt).
