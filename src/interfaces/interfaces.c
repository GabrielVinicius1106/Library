#include <stdio.h>
#include <string.h>
#include "interfaces.h"
#include "../themes/theme.h"

// Usuário Comum
void interfaceInicialUsuario(){

    int opcao = 0;
    char message[32];

    printf(OUTPUT);

    do {
        
        system("clear");

        printf("\n <--- BEM VINDO A BIBLIOTECA ---> \n");
        
        printf("\n %s ", message);

        printf("\n 1 - REALIZAR EMPRÉSTIMO");
        printf("\n 2 - LISTAR EMPRÉSTIMOS");
        printf("\n 3 - SAIR");
    
        printf("\n\n Insira uma opção >> ");
        scanf("%d", &opcao);

        switch (opcao){
        
            case 1:
                strcpy(message, "Realizar Empréstimo!\n");
                break;
            
            case 2:
                strcpy(message, "Listar Empréstimos!\n");
                break;
        
            default:
                strcpy(message, "Insira uma opção válida!\n");
                break;
        
        }

    } while(opcao != 3);

    printf("\n Até mais! \n");

    printf(RESET);

}