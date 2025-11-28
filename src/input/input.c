#include <stdio.h>
#include <string.h>

#include "input.h"
#include "../structs/structs.h"
#include "../datas/datas.h"
#include "../themes/theme.h"

int input(){
    char buffer[8];
    int valor;
    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            
            // Tenta converter string para inteiro
            if (sscanf(buffer, "%d", &valor) == 1) {
                return valor;
            } else {
                return 0;
            }
        }
    }
}

int inputData(int *dia, int *mes, char message[]){
    
    // Resolver VALIDAÇÃO de DATAS (inserção de datas passadas)

    struct Data data_atual = dataAtual();

    char buffer[16]; 
      
    printf(HELP "\n Insira a DATA da RESERVA (dd/mm) >> ");

    fgets(buffer, sizeof(buffer), stdin);
    int num_leituras = sscanf(buffer, "%d/%d", dia, mes);

    if(*mes < data_atual.mes){
        sprintf(message, "Insira uma data válida! ( > %d/%d)\n", data_atual.dia, data_atual.mes);
        return 0;
    }

    if(*mes == data_atual.mes && *dia <= data_atual.dia){
        sprintf(message, "Insira uma data válida! ( > %d/%d)\n", data_atual.dia, data_atual.mes);
        return 0;
    }

    if(num_leituras != 2){
        strcpy(message, "Insira o formato válido (dd/mm)!\n");
        return 0;
    } else if((*dia < 1) || (*dia > 31) || (*mes < 1) || (*mes > 12)){
        strcpy(message, "Insira uma data válida!\n");
        return 0;
    } else {
        strcpy(message, "");
        return 1;
    }   
}

int inputHorario(int *horas, int *minutos, char message[]){
    
    char buffer[16]; 
      
    printf(HELP "\n Insira o HORÁRIO da RESERVA (7h - 20h) >> ");

    fgets(buffer, sizeof(buffer), stdin);
    int num_leituras = sscanf(buffer, "%d:%d", horas, minutos);

    if(num_leituras != 2){
        strcpy(message, "Insira o formato válido (HH:mm)!\n");
        return 0;
    } else if((*horas < 7) || (*horas > 20) || (*minutos < 0) || (*minutos > 59) || (*horas == 20 && *minutos > 0)){
        strcpy(message, "Insira um horário válido (7h - 20h)!\n");
        return 0;
    } else {
        strcpy(message, "");
        return 1;
    }

}