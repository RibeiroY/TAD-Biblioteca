
#include <stdio.h>
#include <stdlib.h>
#include "livro.h"


void Ler(TLivro *book){
	printf("\nDigite o titulo do livro:");
	fflush(stdin);
	fgets(book->titulo, 100, stdin);
	
	printf("\nISBN:");
	fflush(stdin);
	fgets(book->ISBN, 20, stdin);

	printf("\nEditora:");
	fflush(stdin);
	fgets(book->editora, 100, stdin);
	
	printf("\nLocal:");
	fflush(stdin);
	fgets(book->local, 100, stdin);
	
	printf("\nData de publicacao: ");
	printf("Dia:");
	scanf("%d", &book->data_pub.dia);
	printf("\nMes:");
	scanf("%d", &book->data_pub.mes);
	printf("\nAno:");
	scanf("%d", &book->data_pub.ano);
	
	printf("\nPrimeiro autor:");
	fflush(stdin);
	fgets(book->prim_autor, 100, stdin);
	
	printf("\nSegundo autor:");
	fflush(stdin);
	fgets(book->seg_autor, 100, stdin);

	printf("\n Digite a quantidade total de livros no acervo.");
	fflush(stdin);
	scanf("%d", &book->quantidade_total);
	
	book->quant_emprestados =0;
	book->quantidade = book->quantidade_total;
}

void ImprimirLivro(TLivro book){
	printf("\nTitulo do livro:%s", book.titulo);
	
	
	printf("\nISBN:%s",book.ISBN);

	printf("\nEditora:%s", book.editora);
	
	printf("\nLocal:%s", book.local);
	
	
	printf("\nData de publicacao: ");
	printf("%d/%d/%d", book.data_pub.dia,book.data_pub.mes,book.data_pub.ano);

	printf("\nPrimeiro autor:%s", book.prim_autor);

	
	printf("\nSegundo autor:%s", book.seg_autor);
	printf("\nQuantidade Total: %d", book.quantidade_total);
	printf("\nQuantidade atual: %d",book.quantidade);
	printf("\nQuantidade de emprestados: %d", book.quant_emprestados);

	
}
void Iniciar(TModuloLivro *biblioteca){
	biblioteca->indice=0;
}
void CadastraLivro(TModuloLivro *modulo1,TLivro book){
	modulo1->vetor[modulo1->indice]=book;
	modulo1->indice++;
}
void Imprimir2Livro(TModuloLivro modulo){
	int i;
	for(i=0;i<modulo.indice;i++){
		ImprimirLivro(modulo.vetor[i]);
	}
}

int PesquisarLivro(TModuloLivro modulo, TLivro book){
int i;
	for(i=0;i<modulo.indice;i++){
		if(strcmp(modulo.vetor[i].titulo, book.titulo) == 0){
 		return i;
		}
	}
	return -1;
}

int Pesquisar2Livro(TModuloLivro modulo, TLivro book){
int i;
	for(i=0;i<modulo.indice;i++){
		if(strcmp(modulo.vetor[i].ISBN, book.ISBN) == 0){
 		return i;
		}
	}
	return -1;
}
void AlterarLivro(TModuloLivro *modulo,TLivro book, int indice){
	modulo->vetor[modulo->indice]=book;
}
void Excluir(TModuloLivro modulo, int indice){
	int i;
	for(i=indice;i<modulo.indice;i++){
		modulo.vetor[i] = modulo.vetor[i+1];
	}
}
