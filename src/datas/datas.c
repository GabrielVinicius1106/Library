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