#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "interfaces.h"
#include "../manipulacao/arquivo.h"
#include "../structs/structs.h"
#include "../themes/theme.h"

void listarLivros(){

    int opcao = 0;

    char arquivo_livros[] = "src/bd/livros.txt";
    
    int num_livros = numeroRecursos(arquivo_livros);
    
    struct Livro *livros = malloc(sizeof(struct Livro) * num_livros);

    lerLivros(arquivo_livros, livros);

    // ===================================================

    do {
        system("clear");
    
        printf(OUTPUT "\n <--- LIVROS DISPONÍVEIS ---> \n");
    
        if(!num_livros){
            printf(ERROR "\n Não salas disponíveis!");
        } else {
            for(int i = 0; i < num_livros; i++){
                printf(OUTPUT "\n (%d) %s", (i + 1), (livros + i)->nome);
            }
        }

        printf(OUTPUT "\n\n ================================ ");
        
        printf(SUCCESS "\n\n Digite %d para sair! \n", (num_livros + 1));

        printf(HELP "\n Insira o livro desejado >> ");
        scanf("%d", &opcao);
    
        
        if(opcao == (num_livros + 1)){
            break;
        }
        
    } while(opcao < 1 || opcao > num_livros);
    
    free(livros);
}

void listarCalculadoras(){

    int opcao = 0;
    
    char arquivo_calculadoras[] = "src/bd/calculadoras.txt";
    
    int num_calculadoras = numeroRecursos(arquivo_calculadoras);
    
    struct Calculadora *calculadoras = malloc(sizeof(struct Calculadora) * num_calculadoras);

    lerCalculadoras(arquivo_calculadoras, calculadoras);

    // ===================================================

    do {
        system("clear");
    
        printf(OUTPUT "\n <--- CALCULADORAS DISPONÍVEIS ---> \n");
        
        if(!num_calculadoras){
            printf(ERROR "\n Não calculadoras disponíveis!");
        } else {
            for(int i = 0; i < num_calculadoras; i++){
                printf(OUTPUT "\n (%d) %s", (i + 1), (calculadoras + i)->modelo);
            }
        }

        printf(OUTPUT "\n\n ================================ ");
        
        printf(SUCCESS "\n\n Digite %d para sair! \n", (num_calculadoras + 1));

        printf(HELP "\n Insira a calculadora desejada >> ");
        scanf("%d", &opcao);
    
        
        if(opcao == (num_calculadoras + 1)){
            break;
        }
        
    } while(opcao < 1 || opcao > num_calculadoras);
    
    free(calculadoras);

}

void listarFonesOuvido(){
    
    int opcao = 0;
    
    char arquivo_fones[] = "src/bd/fones_ouvido.txt";
    
    int num_fones = numeroRecursos(arquivo_fones);
    
    struct Fone_Ouvido *fones_ouvido = malloc(sizeof(struct Fone_Ouvido) * num_fones);

    lerFonesOuvido(arquivo_fones, fones_ouvido);

    // ===================================================

    do {
        system("clear");
    
        printf(OUTPUT "\n <--- FONES DE OUVIDO DISPONÍVEIS ---> \n");
        
        if(!num_fones){
            printf(ERROR "\n Não há fones de ouvido disponíveis!");
        } else {
            for(int i = 0; i < num_fones; i++){
                printf(OUTPUT "\n (%d) %s", (i + 1), (fones_ouvido + i)->modelo);
            }
        }

        printf(OUTPUT "\n\n ================================ ");
        
        printf(SUCCESS "\n\n Digite %d para sair! \n", (num_fones + 1));

        printf(HELP "\n Insira o fone de ouvido desejado >> ");
        scanf("%d", &opcao);
    
        
        if(opcao == (num_fones + 1)){
            break;
        }
        
    } while(opcao < 1 || opcao > num_fones);
    
    free(fones_ouvido);
}

void listarSalas(){
    
    int opcao = 0;
    
    char arquivo_salas[] = "src/bd/salas.txt";
    
    int num_salas = numeroRecursos(arquivo_salas);
    
    struct Sala *salas = malloc(sizeof(struct Sala) * num_salas);

    lerSalas(arquivo_salas, salas);

    // ===================================================

    do {
        system("clear");
    
        printf(OUTPUT "\n <--- SALAS DISPONÍVEIS ---> \n");
        
        if(!num_salas){
            printf(ERROR "\n Não há salas disponíveis!");
        } else {
            for(int i = 0; i < num_salas; i++){
                printf(OUTPUT "\n (%d) Sala: %s | Capacidade: %d ", (i + 1), (salas + i)->sala, (salas + i)->max_pessoas);
            }
        }

        printf(OUTPUT "\n\n ================================ ");
        
        printf(SUCCESS "\n\n Digite %d para sair! \n", (num_salas + 1));

        printf(HELP "\n Insira a sala desejada >> ");
        scanf("%d", &opcao);
    
        
        if(opcao == (num_salas + 1)){
            break;
        }
        
    } while(opcao < 1 || opcao > num_salas);
    
    free(salas);
}

void realizarEmprestimo(){
    
    int opcao = 0;
    char message[32] = "";

    do {

        system("clear");

        printf(OUTPUT);
    
        printf("<--- RECURSOS DISPONÍVEIS ---> \n");
        
        if(strcmp(message, "") != 0){
            printf(ERROR "\n %s ", message);
        }

        printf(OUTPUT);

        printf("\n 1 - LIVROS");
        printf("\n 2 - CALCULADORAS");
        printf("\n 3 - FONES DE OUVIDO");
        printf("\n 4 - RESERVAR SALA");
        printf("\n");
        printf("\n 5 - SAIR");
    
        printf(HELP "\n\n Insira uma opção > ");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                strcpy(message, "");
                listarLivros();
                break;

            case 2:
                strcpy(message, "");
                listarCalculadoras();
                break;

            case 3:
                strcpy(message, "");
                listarFonesOuvido();
                break;

            case 4:
                strcpy(message, "");
                listarSalas();
                break;

            case 5:
                strcpy(message, "");
                break;
            
            default:
                strcpy(message, "Insira uma opção válida!\n");
                break;
        }
    
    } while(opcao != 5);
}

void listarEmprestimos(){
    int opcao = 0;

    struct Emprestimos *emprestimos = NULL;

    do {
        system("clear");

        printf(OUTPUT);
    
        printf("<--- EMPRÉSTIMOS REALIZADOS ---> \n");
        
        if(!emprestimos){
            printf(ERROR "\n Não há empréstimos realizados! \n");
        }

        printf(HELP "\n Digite 6 para RETORNAR > ");
        scanf("%d", &opcao);
    
    } while(opcao != 6);
}

void interfaceInicial(){

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
                realizarEmprestimo();

                break;
            
            case 2:
                strcpy(message, "");
                listarEmprestimos();

                break;
        
            default:
                strcpy(message, "Insira uma opção válida!\n");
                break;
        
        }

    } while(opcao != 3);

    system("clear");

    printf(RESET);

}