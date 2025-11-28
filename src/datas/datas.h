#ifndef DATAS_H
#define DATAS_H

#include <time.h>

#include "../structs/structs.h"

struct Data dataAtual();

struct Data dataDevolucao();

int emprestimoAtrasado(struct Emprestimo emprestimo);

int reservaAtrasada(struct Reserva_Sala reserva);

#endif