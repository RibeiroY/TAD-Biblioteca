#include <stdio.h>
#include <stdlib.h>
#include "emprestimo.h"



void leitura_emprestimo (TEmprestimo *emprestimo){
	printf("Digite o CPF do usuario que requisitou o emprestimo.\n");
	fflush(stdin);
	fgets(emprestimo->CPF, 15, stdin);
	printf("Digite o ISBN do livro a ser emprestado.\n");
	fflush(stdin);
	fgets(emprestimo->ISBN, 20, stdin);
	printf("Digite a data de emprestimo. Dia:");
	scanf("%d", &emprestimo->emprestar.dia);
	printf("\nMes:");
	scanf("%d", &emprestimo->emprestar.mes);
	printf("\nAno:");
	scanf("%d", &emprestimo->emprestar.ano);
}


void IniciarEmpresta(TModuloEmprestimo *empresta){
	empresta->indice=0;

}

void CadastraEmprestimo(TModuloEmprestimo *emprestimos,TEmprestimo emprestimo1){
		emprestimos->vetor[emprestimos->indice]=emprestimo1;
		emprestimos->indice++;
	
}
void  Imprimir2Emprestimo(TModuloEmprestimo modulo2){
	int i;
	for(i=0;i<modulo2.indice;i++){
		modulo2.vetor[i].devolucao_max= CalcularEntrega(modulo2.vetor[i].emprestar);
		Press(modulo2.vetor[i]);
	}
}
void Press(TEmprestimo emprestimo){
	printf("CPF: %s\n", emprestimo.CPF);
	printf("ISBN : %s\n", emprestimo.ISBN);
	printf("Data de emprestimo. %d/%d/%d", emprestimo.emprestar.dia,emprestimo.emprestar.mes, emprestimo.emprestar.ano);
	printf("Data maxima de devolucao.%d/%d/%d:", emprestimo.devolucao_max.dia,emprestimo.devolucao_max.mes, emprestimo.devolucao_max.ano);
	
}

int VerificarLivro (TModuloLivro modulo, int indice){
	int porcentagem;

	porcentagem = modulo.vetor[indice].quantidade_total * 0.1;
	modulo.vetor[indice].quantidade= modulo.vetor[indice].quantidade_total - modulo.vetor[indice].quant_emprestados;
	if(modulo.vetor[indice].quantidade<= porcentagem || modulo.vetor[indice].quantidade == 1){
		return 1;
	}
	return 0;

}

int VerificarUsuario(TModuloUsuario modulo1, int indice){
	if(modulo1.vetor[indice].tipo_usuario == 1){
		if(modulo1.vetor[indice].quant_borrow >=3 && modulo1.vetor[indice].multa >0){
			return 1;
		}
	}else{
		if(modulo1.vetor[indice].quant_borrow>=5 && modulo1.vetor[indice].multa >0){
			return 1;
		}
	}
	return 0;
}

TData CalcularEntrega(TData d_emprestimo){
	TData d_entrega;

	d_entrega=d_emprestimo;
	d_entrega.dia=d_emprestimo.dia + 7;

	if(d_emprestimo.mes==2){
		if (d_entrega.dia>28){
			d_entrega.mes++;
			d_entrega.dia = d_entrega.dia - 28;
		}
	}else if(d_emprestimo.mes==4 ||d_emprestimo.mes == 6 || d_emprestimo.mes==9 ||d_emprestimo.mes==11){
		if (d_entrega.dia>30){
			d_entrega.mes++;
			d_entrega.dia = d_entrega.dia - 30;
		}
		
	}else{
		if (d_entrega.dia > 31){
			if(d_emprestimo.mes==12){
				d_entrega.dia=d_entrega.dia - 31;
				d_entrega.mes=1;
				d_entrega.ano++;
			}else{
			d_entrega.mes++;
			d_entrega.dia=d_entrega.dia - 31;
			}
		}
	}
	return d_entrega;
}

int PesquisarEmprestimo(TModuloEmprestimo modulo2, TEmprestimo borrow){
	int i;
	for(i=0;i<modulo2.indice;i++){
		if(strcmp(modulo2.vetor[i].CPF, borrow.CPF) == 0){
			if(strcmp(modulo2.vetor[i].ISBN, borrow.ISBN)==0){
				return i;
			}
		}
	}
	return -1;
}
float CalculaMulta(TModuloEmprestimo *modulo2, TModuloUsuario *user, int indice, int indice2){
	TData devolver;
	int dias_atraso;
	printf("\t CALCULAR MULTA: DIGITE A DATA DE DEVOLUCAO.\nDIA:");
	fflush(stdin);
	scanf("%d", &devolver.dia);
	printf("\tMES:\n");
	fflush(stdin);
	scanf("%d", &devolver.mes);
	printf("\tANO:\n");
	scanf("%d", &devolver.ano);

	if(modulo2->vetor[indice].devolucao_max.mes<devolver.mes){
		if(modulo2->vetor[indice].devolucao_max.mes == 2){
			devolver.dia = devolver.dia + 28;
		}
		if(modulo2->vetor[indice].devolucao_max.mes == 4|| modulo2->vetor[indice].devolucao_max.mes == 6|| modulo2->vetor[indice].devolucao_max.mes ==9|| modulo2->vetor[indice].devolucao_max.mes == 11){
			devolver.dia = devolver.dia + 30;
		}
		if(modulo2->vetor[indice].devolucao_max.mes == 1 ||modulo2->vetor[indice].devolucao_max.mes == 3 ||modulo2->vetor[indice].devolucao_max.mes == 5 ||modulo2->vetor[indice].devolucao_max.mes == 7 ||modulo2->vetor[indice].devolucao_max.mes == 8 ||modulo2->vetor[indice].devolucao_max.mes == 10 ||modulo2->vetor[indice].devolucao_max.mes == 12){
			devolver.dia=devolver.dia+31;
		}
	}
	dias_atraso=devolver.dia - modulo2->vetor[indice].devolucao_max.dia;
	if (dias_atraso>0){
		user->vetor[indice2].multa = 2.00 * dias_atraso;
		return user->vetor[indice2].multa;
	}
	return 0;
}

void ExcluirEmprestimo(TModuloEmprestimo modulo2, int indice){
	int i;
	for(i=indice;i<modulo2.indice;i++){
		modulo2.vetor[i] = modulo2.vetor[i+1];
	}
}
void AlterarEmprestimo(TModuloEmprestimo *modulo2,TEmprestimo borrow, int indice){
	modulo2->vetor[modulo2->indice]=borrow;
}
float PagarMulta(float k){
	int i;
	float m, troco;
	printf("\tDeseja pagar a multa agora? DIGITE '1' PARA 'SIM' OU '2' PARA 'NÃO'\n");
	scanf("%d", &i);
	while (i!=1 && i!=2){
		printf("\tDIGITE UMA OPCAO VALIDA!!!!!!!!\n");
		scanf("%d", &i);
	}
	if (i==1){
		printf("Valor total a ser pago: %.2f", k);
		printf("\tDigite o valor a ser pago.\n");
		scanf("%f",&m);
		if(m>k){
			troco=m-k;
			printf("\tMULTA PAGA! TROCO:%.2f\n",troco);
			return 0;
		}else if(m<k){
			printf("\tA MULTA NAO FOI TOTALMENTE PAGA!\n");
			return k-m;
		}else{
			printf("\tMULTA PAGA!\n");
			return 0;
		}
	}else{
		printf("\tA MULTA NAO FOI PAGA!\n");
		return k;
	}
}
