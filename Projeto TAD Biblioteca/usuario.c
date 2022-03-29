


#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"


void Read(TUsuario *user){
	int option;
	printf("\nDigite o nome do usuario:");
	fflush(stdin);
	fgets(user->nome, 50, stdin);
	
	printf("\nSobrenome:");
	fflush(stdin);
	fgets(user->sobrenome, 100, stdin);

	printf("\nIdentidade:");
	fflush(stdin);
	fgets(user->identidade, 14, stdin);
	
	printf("\nCPF:");
	fflush(stdin);
	fgets(user->CPF, 15, stdin);
	printf("Digite  1 para aluno ou 2 para funcionario.") ;
	scanf("%d", &user->tipo_usuario);
	while(user->tipo_usuario !=1 && user->tipo_usuario !=2){
		printf("\nInvalido. Tente de novo");
		scanf("%d", &user->tipo_usuario);
	}
	
	switch (user->tipo_usuario){
		case 1:
			printf("\nCurso:");
			fflush(stdin);
			fgets(user->curso, 100, stdin);
			break;
		case 2:
			printf("\nDepartamento:");
			fflush(stdin);
			fgets(user->departamento, 100, stdin);
			break;
	}
		
	printf("\nEndereco: ");
	printf("Logradouro:");
	fflush(stdin);
	fgets(user->address_user.logradouro, 100, stdin);
	printf("\nNumero:");
	scanf("%d", &user->address_user.numero);
	printf("\nBairro:");
	fflush(stdin);
	fgets(user->address_user.bairro, 100, stdin);
	printf("\nCEP:");
	fflush(stdin);
	fgets(user->address_user.CEP, 11, stdin);
	printf("\nCidade:");
	fflush(stdin);
	fgets(user->address_user.cidade, 100, stdin);
	printf("\nData de Nascimento: ");
	printf("Dia:");
	scanf("%d", &user->birth.dia);
	printf("Mes:");
	scanf("%d", &user->birth.mes);
	printf("Ano:");
	scanf("%d", &user->birth.ano);
	user->quant_borrow=0;
}

void Print(TUsuario user){
	printf("\nNome e sobrenome:%s %s", user.nome, user.sobrenome);
	
	
	printf("\nIdentidade: %s",user.identidade);
	printf("\nCPF:%s", user.CPF);
	
	if(user.curso != NULL){
		printf("\nCurso:%s", user.curso);
	}
	if(user.departamento != NULL){
		printf("\nDepartamento:%s", user.departamento);
	}
	
	printf("\nEndereco: ");
	printf("%s Numero: %d",user.address_user.logradouro, user.address_user.numero);
	printf(" Bairro:%s\n CEP:%s\n Cidade: %s", user.address_user.bairro, user.address_user.CEP,user.address_user.cidade);
	printf("\nData de Nascimento:%d/%d/%d", user.birth.dia, user.birth.mes, user.birth.ano);
	
}
void IniciarUser(TModuloUsuario *usu){
	usu->indice=0;
}

void CadastrarUsuario(TModuloUsuario *usuarios, TUsuario usuario1){
		usuarios->vetor[usuarios->indice]=usuario1;
		usuarios->indice++;
}
void  Imprimir2Usuario(TModuloUsuario modulo1){
	int i;
	
	for(i=0;i<modulo1.indice;i++){
		Print(modulo1.vetor[i]);
	}
}
int PesquisarUsuario(TModuloUsuario modulo1, TUsuario user){
	int i;
	for(i=0;i<modulo1.indice;i++){
		if(strcmp(modulo1.vetor[i].CPF, user.CPF) == 0){
 		return i;
		}
	}
	return -1;
}

void AlterarUsuario(TModuloUsuario *modulo1,TUsuario user, int indice){
	modulo1->vetor[modulo1->indice]=user;
}
void ExcluirUsuario(TModuloUsuario modulo1, int indice){
	int i;
	for(i=indice;i<modulo1.indice;i++){
		modulo1.vetor[i] = modulo1.vetor[i+1];
	}
}
