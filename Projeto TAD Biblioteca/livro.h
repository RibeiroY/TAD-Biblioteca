#ifndef LIVRO_H_INCLUDED
#define LIVRO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data{
	int dia;
	int mes;
	int ano;
}TData;

typedef struct livro{
	char ISBN[20];
	char titulo[100];
	char editora[100];
	char local[100];
	TData data_pub;
	char prim_autor[100];
	char seg_autor[100];
	int quantidade;
	int quantidade_total;
	int quant_emprestados;
}TLivro;

typedef struct biblioteca{
	TLivro vetor[100];
	int indice;
	
}TModuloLivro;
/*
Leitura dos dados do livro que o usuário quer cadastrar
*/
void Ler(TLivro *book);
/*
Função responsável pela impressão de livros cadastrados. Ela será chamada dentro de outra função.
*/
void ImprimirLivro(TLivro book);
/*
Inicia o módulo de livro
*/
void Iniciar(TModuloLivro *biblioteca);
/*
Realiza o cadastro do livro estabelecido pelo usuário
*/
void CadastraLivro(TModuloLivro *modulo1,TLivro book);
/*
Impressão de todos os livros cadastrados.
Utiliza a função ImprimirLivro citada anteriormente.
*/
void Imprimir2Livro(TModuloLivro modulo);
/*
Realiza a pesquisa do livro com base no título que o usuário introduzir.
*/
int PesquisarLivro(TModuloLivro modulo, TLivro book);
/*
Mesma função citada anteriormente, com a diferença de que a pesquisa se dá com base no ISBN.
*/
int Pesquisar2Livro(TModuloLivro modulo, TLivro book);
/*
Alteração de livros que ocupam determinado endereço de memória.
*/
void AlterarLivro(TModuloLivro *modulo1,TLivro book, int indice);
/*
O livro que ocupa o espaço do indice seguinte do vetor haverá de ocupar o espaço do vetor em questão.
Com todos os livros seguintes acontecerá a mesma coisa. Ou seja: exclusão do livro em questão.
*/
void Excluir(TModuloLivro modulo, int i);


#endif
