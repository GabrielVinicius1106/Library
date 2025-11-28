#include <stdio.h>
#include <time.h>

#include "datas.h"
#include "../structs/structs.h"
#include "../input/input.h"

struct Data dataAtual(){

    struct tm *data_hora_atual;

    time_t segundos;

    time(&segundos);

    data_hora_atual = localtime(&segundos);

    struct Data data_atual;

    data_atual.dia = data_hora_atual->tm_mday;
    data_atual.mes = data_hora_atual->tm_mon + 1;
    data_atual.ano = data_hora_atual->tm_year + 1900;

    data_atual.hora = data_hora_atual->tm_hour;
    data_atual.minuto = data_hora_atual->tm_min;

    return data_atual;
}

struct Data dataDevolucao(){
    // Cada empréstimo terá uma duração de 7 dias
    // LIMITAÇÃO: Todos os meses possuem 31 DIAS

    struct Data data_devolucao = dataAtual();

    data_devolucao.dia = data_devolucao.dia + 7;

    if(data_devolucao.dia > 31){
        data_devolucao.dia = data_devolucao.dia - 31;
        data_devolucao.mes += 1;

        if (data_devolucao.mes > 12){
            data_devolucao.mes = 1;
            data_devolucao.ano += 1;
        }
    }

    return data_devolucao;


}

int emprestimoAtrasado(struct Emprestimo emprestimo){
 
    struct Data data_atual = dataAtual();
    struct Data data_emprestimo;
    struct Data data_devolucao;

    sscanf(emprestimo.data_emprestimo, "%d/%d/%d %d:%d", &data_emprestimo.dia, &data_emprestimo.mes, &data_emprestimo.ano, &data_emprestimo.hora, &data_emprestimo.minuto);
    sscanf(emprestimo.data_devolucao, "%d/%d/%d %d:%d", &data_devolucao.dia, &data_devolucao.mes, &data_devolucao.ano, &data_devolucao.hora, &data_devolucao.minuto);
        
    // Calcular a QUANTIDADE de dias entre DATA_DEVOLUCAO - DATA_EMPRESTIMO | DATA_ATUAL - DATA_EMPRESTIMO

    int emprestimo_devolucao = (((data_devolucao.ano - 2000) * 365) + (data_devolucao.mes * 31) + data_devolucao.dia) - (((data_emprestimo.ano - 2000) * 365) + (data_emprestimo.mes * 31) + data_emprestimo.dia);
    int emprestimo_hoje = (((data_atual.ano - 2000) * 365) + (data_atual.mes * 31) + data_atual.dia) - (((data_emprestimo.ano - 2000) * 365) + (data_emprestimo.mes * 31) + data_emprestimo.dia);
    
    if(emprestimo_devolucao < emprestimo_hoje){
        return 1;
    }

    return 0;
}

int reservaAtrasada(struct Reserva_Sala reserva){


    struct Data data_reserva, data_atual = dataAtual();

    sscanf(reserva.data_reserva, "%d/%d/%d %d:%d", &data_reserva.dia, &data_reserva.mes, &data_reserva.ano, &data_reserva.hora, &data_reserva.minuto);

    int ate_reserva = ((data_reserva.ano - 2000) * 365) + (data_reserva.mes * 31) + data_reserva.dia;
    int ate_hoje = ((data_atual.ano - 2000) * 365) + (data_atual.mes * 31) + data_atual.dia;

    if(ate_reserva < ate_hoje){
        return 1;
    }

    return 0;


}