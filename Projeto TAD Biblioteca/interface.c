#include <stdio.h>
#include <stdlib.h>


#include "interface.h"


void MSG_MENU(){
    printf("****************MENU PRINCIPAL****************\n");
    printf("\t1-GERENCIAMENTO DE LIVROS\n");
    printf("\t2-GERENCIAMENTO DE USUARIOS\n");
    printf("\t3-GERENCIAMENTO DE EMPRESTIMOS\n");
    printf("\t4-SAIR\n");
}

void MSG_SUBMENU(int n_modulo){
    system("cls");
    printf("****************MENU DO MODULO %d****************\n",n_modulo);
    printf("\t1:CADASTRAR\n");
    printf("\t2:PESQUISAR\n");
    printf("\t3:ALTERAR\n");
    printf("\t4:EXCLUIR\n");
    printf("\t5:IMPRIMIR TODOS\n");
    printf("\t6:SAIR\n");
}

void SubMenu1(TModuloLivro *modulo, TLivro book){
    int opcao=0;
    int i;
    do
    {
        MSG_SUBMENU(1);
        printf("\tDigite uma opcao:\n ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                Ler(&book);
                i=PesquisarLivro(*modulo, book);
                if(i==-1){
                    CadastraLivro(modulo, book);
                }else{
                    printf("\tNAO FOI POSSIVEL CADASTRAR\n");
                }
                system("PAUSE");
                break;
            case 2:
                system("cls");
                printf("\tDigite o livro que deseja pesquisar.\n");
                fflush(stdin);
                fgets(book.titulo, 100, stdin);
                i=PesquisarLivro(*modulo, book);
                if(i>=0){
                    printf("\tLIVRO ENCONTRADO!\n");
                    ImprimirLivro(modulo->vetor[i]);
                }else{
                    printf("\nLIVRO INEXISTENTE!");
                }
                system("PAUSE");
                break;
            case 3:
                system("cls");
                printf("\tDigite o livro que sera sujeito a alteracao.\n");
                fflush(stdin);
                fgets(book.titulo,100,stdin);

                i= PesquisarLivro(*modulo, book);
                if(i >=0 && book.quant_emprestados == 0){
                    printf("\tDigite os novos dados.\n");
                    Ler(&book);
                    AlterarLivro(modulo, book, i);
                    printf("\tLIVRO ALTERADO COM SUCESSO.\n");
                }else{
                    printf("\tNAO FOI POSSIVEL ALTERAR.\n");
                }
               system("PAUSE");
                break;
            case 4:
                system("cls");
                printf("\tQUAL LIVRO DESEJA EXCLUIR?\n");
                fflush(stdin);
                fgets(book.titulo,100,stdin);
                 i= PesquisarLivro(*modulo, book);
                 if(i >= 0){
                        Excluir(*modulo, i);
                        printf("Usuario excluído com sucesso!");
                  } else{
                         printf("Usuario não encontrado para exclusao!");
                 }
                    system("PAUSE");
                break;
            case 5:
                system("cls");
                if(modulo->indice>0){
                    Imprimir2Livro(*modulo);
                }else{
                    printf("NÃO HA LIVRO CADASTRADO.\n");
                }
                system("PAUSE");
                break;
            case 6:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<<");
                system("PAUSE");
                break;
            default:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
                system("PAUSE");
            } 
    } while(opcao != 6);

}

void SubMenu2(TModuloUsuario *modulo1, TUsuario usuario){
    int opcao=0;
    int i;
    do
    {
        MSG_SUBMENU(2);
        printf("\tDigite uma opcao:\n ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                Read(&usuario);
                i=PesquisarUsuario(*modulo1, usuario);
                if(i==-1){
                    CadastrarUsuario(modulo1, usuario);
                }else{
                    printf("\tNAO FOI POSSIVEL CADASTRAR\n");
                }
                system("PAUSE");
                break;
            case 2:
                system("cls");
                printf("\tDigite o usuario(CPF) que deseja pesquisar.\n");
                fflush(stdin);
                fgets(usuario.CPF, 15, stdin);
                i=PesquisarUsuario(*modulo1, usuario);
                if(i>=0){
                    printf("\tUSUARIO ENCONTRADO!\n");
                    Print(modulo1->vetor[i]);
                }else{
                    printf("\tUSUARIO INEXISTENTE\n");
                }
                system("PAUSE");
                break;
            case 3:
                system("cls");
                printf("\tDigite o usuario(CPF) que sera sujeito a alteracao.\n");
                fflush(stdin);
                fgets(usuario.CPF,15,stdin);

                i= PesquisarUsuario(*modulo1, usuario);
                if(i >=0 && usuario.quant_borrow == 0 && usuario.multa == 0){
                    printf("\tDigite os novos dados.\n");
                    Read(&usuario);
                    AlterarUsuario(modulo1, usuario, i);
                    printf("\tUSUARIO ALTERADO COM SUCESSO.\n");
                }else if (i >=0 && usuario.quant_borrow == 0 && usuario.multa>0){
                    printf("\tMULTA EXISTENTE. NAO FOI POSSIVEL ALTERAR.\n");
                }else if (i==0){
                    printf("\nNAO FOI POSSIVEL ALTERAR. USUARIO DIGITADO NAO EXISTE.\n");
                }else{
                    printf("\tNAO FOI POSSIVEL ALTERAR. USUARIO POSSUI EMPRESTIMOS ATIVOS.\n");
                }
                system("PAUSE");
                break;
            case 4:
                system("cls");
                printf("\tQUAL USUARIO(CPF) DESEJA EXCLUIR?\n");
                fflush(stdin);
                fgets(usuario.CPF,15,stdin);
                 i= PesquisarUsuario(*modulo1, usuario);
                 if(i >= 0){
                        ExcluirUsuario(*modulo1, i);
                        printf("Usuario excluído com sucesso!");
                } else{
                         printf("Usuario não encontrado para exclusão!");
                }
                system("PAUSE");
                break;
            case 5:
                system("cls");
                if(modulo1->indice>0){
                    Imprimir2Usuario(*modulo1);
                }else{
                    printf("NÃO HÁ USUARIO CADASTRADO.\n");
                }
                system("PAUSE");
                break;
            case 6:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<<");
                system("PAUSE");
                break;
            default:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
                system("PAUSE");
           } 
    } while(opcao != 6);
}

void SubMenu3(TModuloLivro *modulo, TLivro book, TModuloUsuario *modulo1, TUsuario user, TModuloEmprestimo *modulo2, TEmprestimo borrow){
    int opcao=0;
    int i;
    int j;
    float k;
    int x;
    int y;
    do
    {
        MSG_SUBMENU(3);
        printf("\tDigite uma opcao:\n ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                system("cls");
                leitura_emprestimo(&borrow);

                i=PesquisarUsuario(*modulo1, user);
                j=PesquisarLivro(*modulo,book);
                x=VerificarLivro(*modulo,x);
                y=VerificarUsuario(*modulo1,y);
                
                

                if(i>=0 && j>=0 && x==0 && y==0){
                    CadastraEmprestimo(modulo2, borrow);
                    modulo1->vetor[i].quant_borrow++;
                    modulo->vetor[j].quant_emprestados++;
                    modulo->vetor[j].quantidade--;
                    printf("\tEMPRESTIMO CADASTRADO COM SUCESSO\n");
                }else{
                    if (y==1){
                        printf("\tUSUARIO BLOQUEADO COM MAXIMO DE LIVROS EMPRESTADOS OU MULTA EM ABERTO.\n");
                    }else if(x==1){
                        printf("\tBAIXA OU NENHUMA DISPONIBILIDADE DE LIVROS.\n");
                    }
                    printf("\tNAO FOI POSSIVEL CADASTRAR\n");
                }
                system("PAUSE");
                break;
            case 2:
                system("cls");
                printf("\tPARA PESQUISAR EMPRESTIMO, DIGITE O CPF E O ISBN DESEJADOS.\n");
                fflush(stdin);
                fgets(borrow.CPF, 15, stdin);
                fflush(stdin);
                fgets(borrow.ISBN, 20, stdin);
                i=PesquisarEmprestimo(*modulo2, borrow);
                if(i>=0){
                    printf("\tEMPRESTIMO ENCONTRADO!\n");
                    modulo2->vetor[i].devolucao_max= CalcularEntrega(modulo2->vetor[i].emprestar);
                    Press(modulo2->vetor[i]);
                }else{
                    printf("\t EMPRESTIMO NAO ENCONTRADO!!\n");
                }
                system("PAUSE");
                break;
            case 3:
                system("cls");
                printf("\tDigite o CPF e  o ISBN do emprestimo que deseja ALTERAR.\n");
                fflush(stdin);
                fgets(borrow.CPF,15,stdin);
                fflush(stdin);
                fgets(borrow.ISBN,20,stdin);
                strcpy(user.CPF, borrow.CPF);
                i=PesquisarEmprestimo(*modulo2, borrow);
                y=PesquisarUsuario(*modulo1, user);
                k=CalculaMulta(modulo2, modulo1, i,y);
                if(i >=0 && k == 0){
                    printf("\tDigite os novos dados.\n");
                    leitura_emprestimo(&borrow);
                    AlterarEmprestimo(modulo2, borrow, i);
                    printf("\tEMPRESTIMO ALTERADO COM SUCESSO.\n");
                }else if(i>=0 && k>0){
                    PagarMulta(k);
                    if (k==0){
                        printf("\tDigite os novos dados.\n");
                        leitura_emprestimo(&borrow);
                        AlterarEmprestimo(modulo2, borrow, i);
                        printf("\tEMPRESTIMO ALTERADO COM SUCESSO.\n");
                    }
                }else{
                    printf("\tNAO FOI POSSIVEL ALTERAR.\n");
                }
                system("PAUSE");
                break;
            case 4:
                system("cls");
                printf("\tDIGITE O CPF E O ISBN DO EMPRESTIMO QUE DESEJA EXCLUIR.\n");
                fflush(stdin);
                fgets(borrow.CPF,15,stdin);
                fflush(stdin);
                fgets(borrow.ISBN,20,stdin);
                strcpy(user.CPF, borrow.CPF);
                strcpy(book.ISBN, borrow.ISBN);
                i= PesquisarEmprestimo(*modulo2, borrow);
                y=PesquisarUsuario(*modulo1, user);
                k=CalculaMulta(modulo2, modulo1, i, y);
                x=PesquisarLivro(*modulo,book);
                float u;
                if(i >= 0 && k==0){
                        ExcluirEmprestimo(*modulo2, i);
                        modulo1->vetor[y].quant_borrow--;
                        modulo->vetor[x].quant_emprestados--;
                        modulo->vetor[x].quantidade++;
                        printf("\tEmprestimo excluído com sucesso!\n");
                } else if(i>=0 && k>0){
                    printf("\tValor da multa: %.2f\n", k);
                    u = PagarMulta(k);
                    if (u>0)
                    {
                        printf("\tO livro sera devolvido com debito.\n");
                        ExcluirEmprestimo(*modulo2, i);
                        modulo1->vetor[y].quant_borrow--;
                        modulo->vetor[x].quant_emprestados--;
                        modulo->vetor[x].quantidade++;
                        modulo1->vetor[y].multa=u;
                        printf("\tEmprestimo excluído com sucesso!\n");
                    }else{
                        ExcluirEmprestimo(*modulo2, i);
                        modulo1->vetor[y].quant_borrow--;
                        modulo->vetor[x].quant_emprestados--;
                        modulo->vetor[x].quantidade++;
                        modulo1->vetor[y].multa=u;
                        printf("\tEmprestimo excluído com sucesso!\n");
                    }
                }else{
                    printf("\tEmprestimo nao pode ser excluido.\n");
                }
                system("PAUSE");
                break;
            case 5:
                system("cls");
                if(modulo2->indice>0){
                    Imprimir2Emprestimo(*modulo2);
                }else{
                    printf("NÃO HÁ EMPRESTIMO CADASTRADO.\n");
                }
                system("PAUSE");
                break;
            case 6:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<<");
                system("PAUSE");
                break;
            default:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
                system("PAUSE");
            } 
    } while(opcao != 6);
}