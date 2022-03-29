#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include <string.h>




int main(){
    //Declarações de variáveis e inicialização de cada módulo
	TLivro book;
	TModuloLivro modulo;
	Iniciar(&modulo);
	TUsuario user;
	TModuloUsuario modulo1;
	IniciarUser(&modulo1);
	TEmprestimo emprestimo;
	TModuloEmprestimo modulo2;
	IniciarEmpresta(&modulo2);
	int opcao = 0;
    do{
        system("cls");
        MSG_MENU();
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
            case 1:
                // Chamada de Função para o submenu do Módulo 
                SubMenu1(&modulo, book);
                break;
            case 2:
                // Chamada de Função para o submenu do Módulo I
                SubMenu2(&modulo1, user);
                break;
            case 3:
                // Chamada de Função para o submenu do Módulo II
                SubMenu3(&modulo, book, &modulo1, user, &modulo2, emprestimo);
                break;
            case 4:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Saindo do programa...!!! <<<<<<");
				system("PAUSE");
                break;
            default:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
                system("PAUSE");
        }
    }while(opcao != 3);

	system("PAUSE");
	
	
	return 0;
}
