#include "../structs/structs.h"

#ifndef INTERFACES_H
#define INTERFACES_H


void listarLivros();

void listarCalculadoras();

void listarFonesOuvido();

void listarSalas();

// ===================================================

void emprestimoLivro(struct Livro *livro);

void realizarEmprestimo();

void listarEmprestimos();

void interfaceInicial();

#endif 