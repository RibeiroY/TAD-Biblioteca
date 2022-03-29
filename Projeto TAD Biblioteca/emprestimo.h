#ifndef EMPRESTIMO_H_INCLUDED
#define EMPRESTIMO_H_INCLUDED



#include <stdio.h>
#include <stdlib.h>
#include "livro.h"
#include "usuario.h"
#include <string.h>

typedef struct emprestimo{
	char CPF[15];
	char ISBN[20];
	TData emprestar;
	TData devolucao;
	TData devolucao_max;
	int quant_disponivel;
	int quant_emprestados;
}TEmprestimo;

typedef struct emprestimos{
	TEmprestimo vetor[100];
	int indice;
	
}TModuloEmprestimo;
/*
Leitura de novos emprestimos.
Coletarao dados de CPF e ISBN e haverá a conferencia de disponibilidade de cada um.
*/
void leitura_emprestimo (TEmprestimo *emprestimo);
/*
Impressão de um unico emprestimo. 
Sera utilizada na impressao 
*/
void Press(TEmprestimo emprestimo);
/*
Inicialização do módulo de empréstimo. 
*/
void IniciarEmpresta(TModuloEmprestimo *empresta);
/*
Cadastro de novos empréstimos.
Será feito mediante condições como: ausencia de multa, disponibilidade de livros e etc. 
*/
void CadastraEmprestimo(TModuloEmprestimo *emprestimos,TEmprestimo emprestimo1);
/*
Impressao de todos os empréstimos
*/
void  Imprimir2Emprestimo(TModuloEmprestimo modulo2);
/*
Verificação de disponibilidade de livros. 
*/
int VerificarLivro (TModuloLivro modulo, int indice);
/*
Verificação de habilitação de usuário para novos emprestimos.
Caso haja multa, não será possível fazer o serviço que pede a verificação 
*/
int VerificarUsuario(TModuloUsuario modulo1, int indice);
/*
Calculo da data de entrega dos livros emprestados. 
A data de empréstimo é lida e os cálculos são feitos. Existem todas as restrições relacionadas a mes e ano. 
*/
TData CalcularEntrega(TData d_emprestimo);
/*
Pesquisa de existencia de emprestimos através de laço de repetição. 
*/
int PesquisarEmprestimo(TModuloEmprestimo modulo2, TEmprestimo borrow);
/*
Cálculo da multa em relação aos dias de atraso.  
*/
float CalculaMulta(TModuloEmprestimo *modulo2, TModuloUsuario *modulo1, int indice, int indice2);
/*
O espaço ocupado pelo emprestimo excluído será ocupado pelo espaço sucessor.
Todos os outros sucessores passarão pelo mesmo processo.  
*/
void ExcluirEmprestimo(TModuloEmprestimo modulo2, int indice);
/*Mediante as condições estabelecidas (multa e etc), essa função altera os dados estabelecidos naquele endereço de memória */
void AlterarEmprestimo(TModuloEmprestimo *modulo2,TEmprestimo borrow, int indice);
/*Função de pagamento de multas pendentes, caso tenha.*/
float PagarMulta(float k);

#endif
