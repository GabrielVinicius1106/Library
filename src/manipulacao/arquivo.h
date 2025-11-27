#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "../structs/structs.h"

int numeroRecursos(char arquivo[]);

void lerLivros(char arquivo[],  struct Livro *livros);

void lerCalculadoras(char arquivo[],  struct Calculadora *calculadoras);

void lerFonesOuvido(char arquivo[],  struct Fone_Ouvido *fones_ouvido);

void lerSalas(char arquivo[], struct Sala *salas);

void lerEmprestimos(char arquivo[], struct Emprestimo *emprestimos);

void lerReservas(char arquivo[], struct Reserva_Sala *reservas);

void salvarLivros(char arquivo[], struct Livro *livros, int num_livros);

void salvarCalculadoras(char arquivo[], struct Calculadora *calculadoras, int num_calculadoras);

void salvarFonesOuvido(char arquivo[], struct Fone_Ouvido *fones_ouvido, int num_fones);

void salvarSalas(char arquivo[], struct Sala *salas, int num_salas);

void salvarEmprestimo(char arquivo[], struct Emprestimo *emprestimo);

void salvarReserva(char arquivo[], struct Reserva_Sala *sala);

#endif