#include "../structs/structs.h"

#ifndef INTERFACES_H
#define INTERFACES_H

void listarLivros();

void listarCalculadoras();

void listarFonesOuvido();

void listarSalas();

// ============================================================

void listarEmprestimos();

void listarReservas();

void emprestimoRecurso(int id_recurso, char nome_recurso[], char tipo_recurso[]);

void reservaSala(int id_sala, char sala[], int max_pessoas);

// ============================================================

void acessarRecursos();

void interfaceInicialUsuario();

void adicionarLivro();

void adicionarCalculadora();

void adicionarFoneOuvido();

void adicionarSala();

void adicionarRecurso();

// ============================================================

void removerLivro();

void removerCalculadora();

void removerFoneOuvido();

void removerSala();

void removerRecurso();

// ============================================================

void editarRecurso();

void interfaceInicialAdmin();

#endif 