#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "interfaces.h"
#include "../themes/theme.h"

int validarUsuario(char *nome_usuario, char *senha){

    if(strcmp(nome_usuario, "admin\n") == 0 && strcmp(senha, "admin\n") == 0){
        // Admin
        return 1;
    } else if(strcmp(nome_usuario, "usuario\n") == 0 && strcmp(senha, "usuario\n") == 0){
        // Usuario 
        return 2;
    } else {
        return 0;
    }

}

void interfaceLogin(){

    char nome_usuario[32], senha[8], message[32] = "";

    printf(OUTPUT);

    do {

        system("clear");
    
        printf(OUTPUT "\n <--- BEM-VINDO A BIBLIOTECA ---> \n");

        if(strcmp(message, "") != 0){
            printf(ERROR "\n %s \n", message);
        }
    
        printf(OUTPUT "\n Faça seu login para entrar \n");
    
        printf(HELP "\n Nome de Usuario > ");
        fgets(nome_usuario, 32, stdin);
    
        printf(HELP "\n Senha > ");
        fgets(senha, 8, stdin);

    
        if(validarUsuario(nome_usuario, senha) == 1){
            // Permissão de Administrador
            interfaceInicial(1);
        }
    
        if(validarUsuario(nome_usuario, senha) == 2){
            // Permissão de Usuário
            interfaceInicial(0);
        }

        strcpy(message, "Usuario e/ou Senha Inválidos! ");

    } while(!validarUsuario(nome_usuario, senha));


    printf("\n strlen(%s) >> %ld ", nome_usuario, strlen(nome_usuario));
    printf("\n strlen(%s) >> %ld ", senha, strlen(senha));

}

void interfaceRealizarEmprestimo(){
    FILE *file;

    int opcao = 0;

    do {

        system("clear");

        printf(OUTPUT);
    
        printf("<--- RECURSOS DISPONÍVEIS ---> \n");
    
        printf("\n 1 - LIVROS");
        printf("\n 2 - CALCULADORAS");
        printf("\n 3 - FONES DE OUVIDO");
        printf("\n 4 - TABLETS");
        printf("\n");
        printf("\n 5 - RESERVAR SALA");
        printf("\n");
        printf("\n 6 - SAIR");
    
        printf(HELP "\n\n Insira uma opção > ");
        scanf("%d", &opcao);
    
    } while(opcao != 6);
}

void interfaceInicial(int codigo_permissao){

    int opcao = 0;
    char message[32] = "";

    do {
        
        printf(OUTPUT);

        system("clear");

        printf("\n <--- BEM-VINDO A BIBLIOTECA ---> \n");

        if(strcmp(message, "") != 0){
            printf(ERROR "\n %s ", message);
        }

        printf(OUTPUT);

        printf("\n 1 - ACESSAR RECURSOS");
        printf("\n 2 - LISTAR EMPRÉSTIMOS / RESERVAS");
        printf("\n 3 - SAIR");
    
        printf(HELP "\n\n Insira uma opção >> ");
        scanf("%d", &opcao);

        switch (opcao){
        
            case 1:
                strcpy(message, "");
                interfaceRealizarEmprestimo();

                break;
            
            case 2:
                strcpy(message, "");
                // listarEmprestimos();

                break;
        
            default:
                strcpy(message, "Insira uma opção válida!\n");
                break;
        
        }

    } while(opcao != 3);

    printf(OUTPUT "\n Até mais! \n\n");

    printf(RESET);

}