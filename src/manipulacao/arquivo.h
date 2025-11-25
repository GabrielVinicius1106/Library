#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "../structs/structs.h"

int numeroLivros(char arquivo[]);

void lerLivros(char arquivo[],  struct Livro *livro);

void salvarLivros(char arquivo[], struct Livro *livros);

#endif