#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

#include "src/themes/theme.h"
#include "src/input/input.h"
#include "src/interfaces/interfaces.h"

int main(){ 

    int usuario = -1;
    
    char message[32] = ""; 

    do {
        system("clear");

        printf(OUTPUT "\n <--- LOGIN ---> \n");

        if(strcmp(message, "") != 0){
            printf(ERROR "\n %s ", message);
        }
        
        printf(OUTPUT);

        printf("\n (1) ADMIN");
        printf("\n (2) USUÁRIO COMUM");
        printf("\n");
    
        printf(SUCCESS "\n Digite 0 para SAIR!");
    
        printf("\n");
    
        printf(HELP "\n Insira o TIPO DE USUÁRIO >> ");
        usuario = input();

        switch(usuario){
            case 0:
                strcpy(message, "");
                break;

            case 1:
                interfaceInicialAdmin();
                strcpy(message, "");
                break;

            case 2:
                interfaceInicialUsuario();
                strcpy(message, "");
                break;

            default:
                strcpy(message, "Insira uma opção válida!\n");
                break;
        }
    
    } while(usuario != 0);

    printf("\n");

    printf(RESET);

    return 0;
}