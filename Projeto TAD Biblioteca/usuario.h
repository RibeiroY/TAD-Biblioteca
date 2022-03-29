#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "livro.h"


typedef struct endereco{
	char logradouro[100];
	int numero;
	char bairro[100];
	char cidade[100];
	char CEP[11];	
	
}TEndereco;

typedef struct usuario{
	char nome[50];
	char sobrenome[100];
	char identidade[14];
	char CPF[15];
	char curso[100];
	char departamento[100];
	TEndereco address_user;
	TData birth;
	int quant_borrow;
	int tipo_usuario;
	float multa;
}TUsuario;

typedef struct usuarios{
	TUsuario vetor[100];
	int indice;
	
}TModuloUsuario;
/*
Leitura de dados de usuário
*/

void Read(TUsuario *user);
/*
Impressao de dados de usuário
*/
void Print(TUsuario user);
/*
Inicialização do módulo de usuário
*/
void IniciarUser(TModuloUsuario *usuario);
/*
Cadastro de usuários nos respectivos indices do vetor.
*/
void CadastrarUsuario(TModuloUsuario *usuarios, TUsuario usuario1);
/*
Impressão de todos os dados de usuário
*/
void  Imprimir2Usuario(TModuloUsuario modulo1 );
/*
Pesquisa de existência de dados de usuários digitados 
*/
int PesquisarUsuario(TModuloUsuario modulo1, TUsuario user);
/*
Alteração de usuários no vetor.
*/
void AlterarUsuario(TModuloUsuario *modulo1,TUsuario user, int indice);
/*
O usuario que ocupa o espaço do indice seguinte do vetor haverá de ocupar o espaço do vetor em questão.
Com todos os usuarios seguintes acontecerá a mesma coisa. Ou seja: exclusão do usuario em questão.
*/
void ExcluirUsuario(TModuloUsuario modulo1, int indice);

#endif 
