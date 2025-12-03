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

void inputString(char string[], int tamanho){

    fgets(string, tamanho, stdin);

    for(int i = 0; i < tamanho; i++){
        if(string[i] == '\n') string[i] = '\0';
    }

}

int inputData(int *dia, int *mes, int *ano, char message[]){
    
    // Resolver VALIDAÇÃO de DATAS (inserção de datas passadas)

    int meses[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // 1 - Janeiro
    // 2 - Fevereiro
    // 3 - Março
    // 4 - Abril
    // 5 - Maio
    // 6 - Junho
    // 7 - Julho
    // 8 - Agosto
    // 9 - Setembro
    // 10 - Outubro
    // 11 - Novembro
    // 12 - Dezembro

    struct Data data_atual = dataAtual();

    char buffer[16]; 
      
    printf(HELP "\n Insira a DATA da RESERVA (dd/mm/yyyy) >> ");

    fgets(buffer, sizeof(buffer), stdin);
    int num_leituras = sscanf(buffer, "%d/%d/%d", dia, mes, ano);

    // Implementar validação de mês e ano bisexto  
    
    int num_dias = 0;

    if(*ano < data_atual.ano){
        sprintf(message, "Insira um ano válido!\n");
        return 0;
    }

    if(*mes < 1 || *mes > 12){        
        sprintf(message, "Insira um mês válido!\n");
        return 0;
    } else {

        // Fevereiro
        if(*mes == 2){
            if(*ano % 4 == 0){
                if(*ano % 100 == 0){
                    if(*ano % 400 == 0){
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
            num_dias = meses[*mes - 1];
        }   
    }

    if(*dia < 1 || *dia > num_dias){
        sprintf(message, "Insira um dia válido!\n");
        return 0;
    }

    if(num_leituras == 3){
        return 1;
    }

    return 0;

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