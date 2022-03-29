#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "livro.h"
#include "usuario.h"
#include "emprestimo.h"
/*  
Menu principal
*/
void MSG_MENU();
/*  
"Esqueleto" de cada submenu. Menus de livro, usuário e empréstimo.
*/
void MSG_SUBMENU(int n_modulo);
/*  
SubMenu que presta serviços a respeito de cadastro, pesquisa, alteração e exclusão de livros.
*/
void SubMenu1(TModuloLivro *modulo, TLivro book);
/*  
SubMenu que presta serviços a respeito de cadastro, pesquisa, alteração e exclusão de usuário.
*/
void SubMenu2(TModuloUsuario *modulo2, TUsuario user);
/*  
SubMenu que presta serviços a respeito de cadastro, pesquisa, alteração e exclusão de empréstimo.
*/
void SubMenu3(TModuloLivro *modulo, TLivro book, TModuloUsuario *modulo1, TUsuario user, TModuloEmprestimo *modulo2, TEmprestimo borrow);

#endif