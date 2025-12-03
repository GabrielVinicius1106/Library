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

    int meses[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    struct Data data_atual = dataAtual();
    
    int num_dias = 0;

    // Fevereiro
    if(data_atual.mes == 2){
        if(data_atual.ano % 4 == 0){
            if(data_atual.ano % 100 == 0){
                if(data_atual.ano % 400 == 0){
                    num_dias = 29;
                } else {
                    num_dias = 28;
                }
            } else {
                num_dias = 29;
            }
        } else {
            num_dias = 28;
        }
    } else {

        // Outros Meses
        num_dias = meses[data_atual.mes - 1];
    }   

    int dia_devolucao = data_atual.dia + 7;
    int mes_devolucao = data_atual.mes; 
    int ano_devolucao = data_atual.ano; 

    if(dia_devolucao > num_dias){
        dia_devolucao = dia_devolucao - num_dias;
        mes_devolucao++;

        if(mes_devolucao > 12){
            mes_devolucao = 1;
            ano_devolucao += 1;
        }
    }

    data_atual.dia = dia_devolucao;
    data_atual.mes = mes_devolucao;
    data_atual.ano = ano_devolucao;

    return data_atual;

}

int emprestimoAtrasado(struct Emprestimo emprestimo){
 
    struct Data data_atual = dataAtual();
    struct Data data_emprestimo;
    struct Data data_devolucao;
    
    sscanf(emprestimo.data_emprestimo, "%d/%d/%d %d:%d", &data_emprestimo.dia, &data_emprestimo.mes, &data_emprestimo.ano, &data_emprestimo.hora, &data_emprestimo.minuto);
    sscanf(emprestimo.data_devolucao, "%d/%d/%d %d:%d", &data_devolucao.dia, &data_devolucao.mes, &data_devolucao.ano, &data_devolucao.hora, &data_devolucao.minuto);

    int meses[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int num_dias_atual = 0;
    int num_dias_emprestimo = 0;
    int num_dias_devolucao = 0;

    // Numero de Dias MÊS ATUAL
    if(data_atual.mes == 2){
        if(data_atual.ano % 4 == 0){
            if(data_atual.ano % 100 == 0){
                if(data_atual.ano % 400 == 0){
                    num_dias_atual = 29;
                } else {
                    num_dias_atual = 28;
                }
            } else {
                num_dias_atual = 29;
            }
        } else {
            num_dias_atual = 28;
        }
    } else {
        num_dias_atual = meses[data_atual.mes - 1];
    }

    // Numero de Dias MÊS DE EMPRÉSTIMO 
    if(data_emprestimo.mes == 2){
        if(data_emprestimo.ano % 4 == 0){
            if(data_emprestimo.ano % 100 == 0){
                if(data_emprestimo.ano % 400 == 0){
                    num_dias_emprestimo = 29;
                } else {
                    num_dias_emprestimo = 28;
                }
            } else {
                num_dias_emprestimo = 29;
            }
        } else {
            num_dias_emprestimo = 28;
        }
    } else {
        num_dias_emprestimo = meses[data_emprestimo.mes - 1];
    }

    // Numero de Dias MÊS DE DEVOLUÇÃO 
    if(data_devolucao.mes == 2){
        if(data_devolucao.ano % 4 == 0){
            if(data_devolucao.ano % 100 == 0){
                if(data_devolucao.ano % 400 == 0){
                    num_dias_devolucao = 29;
                } else {
                    num_dias_devolucao = 28;
                }
            } else {
                num_dias_devolucao = 29;
            }
        } else {
            num_dias_devolucao = 28;
        }
    } else {
        num_dias_devolucao = meses[data_devolucao.mes - 1];
    }

    // Calcular a QUANTIDADE de dias entre DATA_DEVOLUCAO - DATA_EMPRESTIMO | DATA_ATUAL - DATA_EMPRESTIMO

    int emprestimo_devolucao = (((data_devolucao.ano - 2000) * 365) + (data_devolucao.mes * num_dias_devolucao) + data_devolucao.dia) - (((data_emprestimo.ano - 2000) * 365) + (data_emprestimo.mes * num_dias_emprestimo) + data_emprestimo.dia);
    int emprestimo_hoje = (((data_atual.ano - 2000) * 365) + (data_atual.mes * num_dias_atual) + data_atual.dia) - (((data_emprestimo.ano - 2000) * 365) + (data_emprestimo.mes * num_dias_emprestimo) + data_emprestimo.dia);
    
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