#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "../structs/structs.h"

int numeroRecursos(char arquivo[]);

void lerLivros(char arquivo[],  struct Livro *livros);

void lerCalculadoras(char arquivo[],  struct Calculadora *calculadoras);

void lerFonesOuvido(char arquivo[],  struct Fone_Ouvido *fones_ouvido);

void lerSalas(char arquivo[], struct Sala *salas);

void salvarLivros(char arquivo[], struct Livro *livros, int num_livros);

#endif