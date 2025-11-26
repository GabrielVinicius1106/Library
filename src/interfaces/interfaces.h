#include "../structs/structs.h"

#ifndef INTERFACES_H
#define INTERFACES_H


void listarLivros();

void listarCalculadoras();

void listarFonesOuvido();

void listarSalas();

// ===================================================

void emprestimoRecurso(int id_recurso, char nome_recurso[]);

void reservaSala(char sala[], int max_pessoas);

void acessarRecursos();

void listarEmprestimos();

void listarReservas();

void interfaceInicial();

#endif 