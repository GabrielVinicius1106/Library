#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "interfaces.h"
#include "../datas/datas.h"
#include "../manipulacao/arquivo.h"
#include "../structs/structs.h"
#include "../themes/theme.h"
#include "../utils/utils.h"
#include "../input/input.h"

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
            printf(ERROR "\n Não há livros disponíveis!");
        } else {
            for(int i = 0; i < num_livros; i++){
                printf(OUTPUT "\n (%d) %s", (i + 1), (livros + i)->nome);
            }
        }

        printf(OUTPUT "\n\n ================================ ");
        
        printf(SUCCESS "\n\n Digite %d para sair! \n", (num_livros + 1));

        printf(HELP "\n Insira o livro desejado >> ");
        opcao = input();
    
        
        if(opcao == (num_livros + 1)){
            break;
        } else if(opcao >= 1 && opcao <= num_livros){
            emprestimoRecurso((livros + opcao - 1)->id, (livros + opcao - 1)->nome);
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
            printf(ERROR "\n Não há calculadoras disponíveis!");
        } else {
            for(int i = 0; i < num_calculadoras; i++){
                printf(OUTPUT "\n (%d) %s", (i + 1), (calculadoras + i)->modelo);
            }
        }

        printf(OUTPUT "\n\n ================================ ");
        
        printf(SUCCESS "\n\n Digite %d para sair! \n", (num_calculadoras + 1));

        printf(HELP "\n Insira a calculadora desejada >> ");
        opcao = input();
    
        
        if(opcao == (num_calculadoras + 1)){
            break;
        } else {
            emprestimoRecurso((calculadoras + opcao - 1)->id, (calculadoras + opcao - 1)->modelo);
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
        opcao = input();
    
        
        if(opcao == (num_fones + 1)){
            break;
        } else {
            emprestimoRecurso((fones_ouvido + opcao - 1)->id, (fones_ouvido + opcao - 1)->modelo);
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
        opcao = input();
    
        
        if(opcao == (num_salas + 1)){
            break;
        } else if(opcao >= 1 && opcao <= num_salas){
            reservaSala((salas + opcao - 1)->sala, (salas + opcao - 1)->max_pessoas);
        }
        
    } while(opcao < 1 || opcao > num_salas);
    
    free(salas);
}

void listarEmprestimos(){
    
    int opcao = -1;
    
    char arquivo_emprestimos[] = "src/bd/emprestimos.txt";
    
    int num_emprestimos = numeroRecursos(arquivo_emprestimos);
    
    struct Emprestimo *emprestimos = malloc(sizeof(struct Emprestimo) * num_emprestimos);

    lerEmprestimos(arquivo_emprestimos, emprestimos);

    // ===================================================

    do {
        system("clear");
    
        printf(OUTPUT "\n <--- EMPRÉSTIMOS REALIZADOS ---> \n");
        
        if(!num_emprestimos){
            printf(ERROR "\n Não há empréstimos realizados!");
        } else {
            for(int i = 0; i < num_emprestimos; i++){
                printf(OUTPUT "\n (%d) %d   %s  %s", (i + 1), (emprestimos + i)->id, (emprestimos + i)->nome_recurso, (emprestimos + i)->data_devolucao);
            }
        }

        printf(OUTPUT "\n\n ================================ ");
        
        printf(SUCCESS "\n\n Pressione ENTER para retornar! \n");
        opcao = input();
        
    } while(opcao != 0);
    
    free(emprestimos);
}

void listarReservas(){
    
}

void emprestimoRecurso(int id_recurso, char nome_recurso[]){
    // Criação de um Empréstimo
    
    struct Emprestimo novo_emprestimo;
    struct Data data_devolucao;

    char arquivo_emprestimos[] = "src/bd/emprestimos.txt"; 
    
    data_devolucao = dataDevolucao();

    // Novo Empréstimo
    novo_emprestimo.id = randomID();
    novo_emprestimo.id_recurso = id_recurso;
    strcpy(novo_emprestimo.nome_recurso, nome_recurso);
    sprintf(novo_emprestimo.data_devolucao, "%d/%d/%d %d:%d", data_devolucao.dia, data_devolucao.mes, data_devolucao.ano, data_devolucao.hora, data_devolucao.minuto);
    novo_emprestimo.tempo_afastado = 0;

    salvarEmprestimos(arquivo_emprestimos, &novo_emprestimo, 1);

    printf(SUCCESS "\n\n Pressione ENTER para retornar ");  
    int opcao = input();
}

void reservaSala(char sala[], int max_pessoas){

    printf(SUCCESS "\n Sala: %s", sala);
    printf(SUCCESS "\n Max Pessoas: %d pessoas", max_pessoas);

    printf(SUCCESS "\n\n Pressione ENTER para retornar ");  
    int opcao = input();

    printf("\n");
};

void acessarRecursos(){
    
    int opcao = -1;
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
        printf("\n 0 - RETORNAR");
    
        printf(HELP "\n\n Insira uma opção > ");
        opcao = input();

        switch (opcao){
            case 0:
                strcpy(message, "");
                break;

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
    
    } while(opcao != 0);
}

void interfaceInicial(){

    int opcao = -1;
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
        printf("\n 2 - LISTAR EMPRÉSTIMOS");
        printf("\n 3 - LISTAR RESERVAS");
        printf("\n");
        printf("\n 0 - SAIR");
        
        printf(HELP "\n\n Insira uma opção >> ");
        opcao = input();

        switch (opcao){

            case 0: 
                strcpy(message, "");
                break;
        
            case 1:
                strcpy(message, "");
                acessarRecursos();

                break;
            
            case 2:
                strcpy(message, "");
                listarEmprestimos();

                break;

            case 3:
                strcpy(message, "");
                listarReservas();

                break;
        
            default:
                strcpy(message, "Insira uma opção válida!\n");
                break;
        
        }

    } while(opcao != 0);

    system("clear");

    printf(SUCCESS "\n Obrigado por utilizar! \n\n\n");

    printf(RESET);

}