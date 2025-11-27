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

    int livros_disponiveis = 0, indice = 0;
    int *vetor_disponiveis = malloc(sizeof(int));

    char message[32] = "";
 
    for(int i = 0; i < num_livros; i++){
            
        int disponivel = (livros + i)->disponivel;

        if(disponivel){
            livros_disponiveis += 1;

            vetor_disponiveis = realloc(vetor_disponiveis, sizeof(int) * livros_disponiveis);
            *(vetor_disponiveis + indice) = (livros + i)->id;
            indice++;
        }
            
    }

    do {
        
        system("clear");
    
        printf(OUTPUT "\n <--- LIVROS DISPONÍVEIS ---> \n");

        if(strcmp(message, "") != 0){
            printf(ERROR "\n %s ", message);
        }

        if(!num_livros){
            printf(ERROR "\n Não há livros disponíveis!");
        } else {

            printf(ERROR "\n Indisponível");
            printf(SUCCESS "\n Disponível");

            printf("\n");

            for(int i = 0; i < num_livros; i++){

                int disponivel = (livros + i)->disponivel;

                if(disponivel){
                    printf(SUCCESS);
                    printf("\n (%02d) %-32.32s - %s", (i + 1), (livros + i)->nome, (livros + i)->autor);
                } else {
                    printf(ERROR);
                    printf("\n (--) %-32.32s - %s", (livros + i)->nome, (livros + i)->autor);
                }

            }
        }

        printf(OUTPUT "\n\n ================================ ");

        printf(OUTPUT "\n Livros Disponíveis: %d", livros_disponiveis);
        
        printf(SUCCESS "\n\n Digite %d para sair! \n", (num_livros + 1));

        printf(HELP "\n Insira o LIVRO desejado >> ");
        opcao = input();

        if(opcao == (num_livros + 1)){
            break;
        }

        if(opcao < 1 || opcao > (num_livros + 1)){
            strcpy(message, "Opção INVÁLIDA!\n");
        } else {
            int found = 0;
            for(int i = 0; i < livros_disponiveis; i++){
                if((livros + opcao - 1)->id == vetor_disponiveis[i]){
                    found = 1;
                }
            }
    
            if(found){
                emprestimoRecurso((livros + opcao - 1)->id, (livros + opcao - 1)->nome, "livro");
                break;
            } else {
                strcpy(message, "Livro INDISPONÍVEL!\n");
            }
        }

        
    } while(1);

    free(vetor_disponiveis);
    free(livros);
}

void listarCalculadoras(){

    int opcao = 0;
    
    char arquivo_calculadoras[] = "src/bd/calculadoras.txt";
    
    int num_calculadoras = numeroRecursos(arquivo_calculadoras);
    
    struct Calculadora *calculadoras = malloc(sizeof(struct Calculadora) * num_calculadoras);

    lerCalculadoras(arquivo_calculadoras, calculadoras);

    // ===================================================

    int calculadoras_disponiveis = 0, indice = 0;
    int *vetor_disponiveis = malloc(sizeof(int));

    char message[32] = "";

    for(int i = 0; i < num_calculadoras; i++){
            
        int disponivel = (calculadoras + i)->disponivel;

        if(disponivel){
            calculadoras_disponiveis += 1;

            vetor_disponiveis = realloc(vetor_disponiveis, sizeof(int) * calculadoras_disponiveis);
            *(vetor_disponiveis + indice) = (calculadoras + i)->id;
            indice++;
        }
            
    }

    do {
        system("clear");
    
        printf(OUTPUT "\n <--- CALCULADORAS DISPONÍVEIS ---> \n");
        
        if(strcmp(message, "") != 0){
            printf(ERROR "\n %s ", message);
        }

        if(!num_calculadoras){
            printf(ERROR "\n Não há calculadoras disponíveis!");
        } else {

            printf(ERROR "\n Indisponível");
            printf(SUCCESS "\n Disponível");

            printf("\n");

            for(int i = 0; i < num_calculadoras; i++){

                int disponivel = (calculadoras + i)->disponivel;

                if(disponivel){
                    printf(SUCCESS);
                    printf("\n (%02d) %-8.8s - %s", (i + 1), (calculadoras + i)->modelo, (calculadoras + i)->marca);
                } else {
                    printf(ERROR);
                    printf("\n (--) %-8.8s - %s", (calculadoras + i)->modelo, (calculadoras + i)->marca);
                }
            }
        }

        printf(OUTPUT "\n\n ================================ ");
        
        printf(OUTPUT "\n Calculadoras Disponíveis: %d", calculadoras_disponiveis);
        
        printf(SUCCESS "\n\n Digite %d para sair! \n", (num_calculadoras + 1));

        printf(HELP "\n Insira a CALCULADORA desejada >> ");
        opcao = input();

        if(opcao == (num_calculadoras + 1)){
            break;
        }

        if(opcao < 1 || opcao > (num_calculadoras + 1)){
            strcpy(message, "Opção INVÁLIDA!\n");
        } else {
            int found = 0;
            for(int i = 0; i < calculadoras_disponiveis; i++){
                if((calculadoras + opcao - 1)->id == vetor_disponiveis[i]){
                    found = 1;
                }
            }
    
            if(found){
                emprestimoRecurso((calculadoras + opcao - 1)->id, (calculadoras + opcao - 1)->modelo, "calculadora");
                break;
            } else {
                strcpy(message, "Calculadora INDISPONÍVEL!\n");
            }
        }
        
    } while(1);
    
    free(vetor_disponiveis);
    free(calculadoras);

}

void listarFonesOuvido(){
    
    int opcao = 0;
    
    char arquivo_fones[] = "src/bd/fones_ouvido.txt";
    
    int num_fones = numeroRecursos(arquivo_fones);
    
    struct Fone_Ouvido *fones_ouvido = malloc(sizeof(struct Fone_Ouvido) * num_fones);

    lerFonesOuvido(arquivo_fones, fones_ouvido);

    // ===================================================

    int fones_disponiveis = 0, indice = 0;
    int *vetor_disponiveis = malloc(sizeof(int));

    char message[32] = "";

    for(int i = 0; i < num_fones; i++){
            
        int disponivel = (fones_ouvido + i)->disponivel;

        if(disponivel){
            fones_disponiveis += 1;

            vetor_disponiveis = realloc(vetor_disponiveis, sizeof(int) * fones_disponiveis);
            *(vetor_disponiveis + indice) = (fones_ouvido + i)->id;
            indice++;
        }
            
    }

    do {
        system("clear");
    
        printf(OUTPUT "\n <--- FONES DE OUVIDO DISPONÍVEIS ---> \n");
        
        if(strcmp(message, "") != 0){
            printf(ERROR "\n %s ", message);
        }

        if(!num_fones){
            printf(ERROR "\n Não há fones de ouvido disponíveis!");
        } else {

            printf(ERROR "\n Indisponível");
            printf(SUCCESS "\n Disponível");

            printf("\n");

            for(int i = 0; i < num_fones; i++){

                int disponivel = (fones_ouvido + i)->disponivel;

                if(disponivel){
                    printf(SUCCESS);
                    printf("\n (%02d) %-16.16s - %s", (i + 1), (fones_ouvido + i)->modelo, (fones_ouvido + i)->marca);
                } else {
                    printf(ERROR);
                    printf("\n (--) %-16.16s - %s", (fones_ouvido + i)->modelo, (fones_ouvido + i)->marca);
                }
            }
        }

        printf(OUTPUT "\n\n ================================ ");
        
        printf(OUTPUT "\n Fones de Ouvido Disponíveis: %d", fones_disponiveis);
        
        printf(SUCCESS "\n\n Digite %d para sair! \n", (num_fones + 1));

        printf(HELP "\n Insira o FONE DE OUVIDO desejado >> ");
        opcao = input();

        if(opcao == (num_fones + 1)){
            break;
        }

        if(opcao < 1 || opcao > (num_fones + 1)){
            strcpy(message, "Opção INVÁLIDA!\n");
        } else {
            int found = 0;
            for(int i = 0; i < fones_disponiveis; i++){
                if((fones_ouvido + opcao - 1)->id == vetor_disponiveis[i]){
                    found = 1;
                }
            }
    
            if(found){
                emprestimoRecurso((fones_ouvido + opcao - 1)->id, (fones_ouvido + opcao - 1)->modelo, "fone_ouvido");
                break;
            } else {
                strcpy(message, "Fone de Ouvido INDISPONÍVEL!\n");
            }
        }
        
    } while(1);
    
    free(vetor_disponiveis);
    free(fones_ouvido);
}

void listarSalas(){
    
    int opcao = 0;
    
    char arquivo_salas[] = "src/bd/salas.txt";
    
    int num_salas = numeroRecursos(arquivo_salas);
    
    struct Sala *salas = malloc(sizeof(struct Sala) * num_salas);

    lerSalas(arquivo_salas, salas);

    // ===================================================

    int salas_disponiveis = 0, indice = 0;
    int *vetor_disponiveis = malloc(sizeof(int));

    char message[32] = "";

    for(int i = 0; i < num_salas; i++){
            
        int disponivel = (salas + i)->disponivel;

        if(disponivel){
            salas_disponiveis += 1;

            vetor_disponiveis = realloc(vetor_disponiveis, sizeof(int) * salas_disponiveis);
            *(vetor_disponiveis + indice) = (salas + i)->id;
            indice++;
        }
            
    }

    do {
        system("clear");
    
        printf(OUTPUT "\n <--- SALAS DISPONÍVEIS ---> \n");
        
        if(strcmp(message, "") != 0){
            printf(ERROR "\n %s ", message);
        }

        if(!num_salas){
            printf(ERROR "\n Não há salas disponíveis!");
        } else {

            printf(ERROR "\n Indisponível");
            printf(SUCCESS "\n Disponível");

            printf("\n");

            for(int i = 0; i < num_salas; i++){

                int disponivel = (salas + i)->disponivel;

                if(disponivel){
                    printf(SUCCESS);
                    printf("\n (%02d) %-8.8s | %02d pessoas ", (i + 1), (salas + i)->sala, (salas + i)->max_pessoas);
                } else {
                    printf(ERROR);
                    printf("\n (--) %-8.8s | %02d pessoas ", (salas + i)->sala, (salas + i)->max_pessoas);
                }
            }
        }

        printf(OUTPUT "\n\n ================================ ");
        
        printf(OUTPUT "\n Salas Disponíveis: %d", salas_disponiveis);
        
        printf(SUCCESS "\n\n Digite %d para sair! \n", (num_salas + 1));

        printf(HELP "\n Insira a SALA desejada >> ");
        opcao = input();

        if(opcao == (num_salas + 1)){
            break;
        }

        if(opcao < 1 || opcao > (num_salas + 1)){
            strcpy(message, "Opção INVÁLIDA!\n");
        } else {
            int found = 0;
            for(int i = 0; i < salas_disponiveis; i++){
                if((salas + opcao - 1)->id == vetor_disponiveis[i]){
                    found = 1;
                }
            }
    
            if(found){
                reservaSala((salas + opcao - 1)->id, (salas + opcao - 1)->sala, (salas + opcao - 1)->max_pessoas);
                break;
            } else {
                strcpy(message, "Sala INDISPONÍVEL!\n");
            }
        }
        
    } while(1);

    free(vetor_disponiveis);
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

                int concluido = (emprestimos + i)->concluido;

                if(concluido){
                    printf(SUCCESS);
                } else {
                    printf(OUTPUT);
                }

                printf("\n (%02d) %03d %-32.32s %s", (i + 1), (emprestimos + i)->id, (emprestimos + i)->nome_recurso, (emprestimos + i)->data_devolucao);
            }
        }

        printf(OUTPUT "\n\n ================================ ");
        
        printf(SUCCESS "\n\n Pressione ENTER para retornar! ");
        opcao = input();
        
    } while(opcao != 0);
    
    free(emprestimos);
}

void listarReservas(){

    int opcao = -1;
    
    char arquivo_reservas[] = "src/bd/reservas.txt";
    
    int num_reservas = numeroRecursos(arquivo_reservas);
    
    struct Reserva_Sala *reservas = malloc(sizeof(struct Reserva_Sala) * num_reservas);

    lerReservas(arquivo_reservas, reservas);

    // ===================================================

    do {
        system("clear");
    
        printf(OUTPUT "\n <--- RESERVAS REALIZADAS ---> \n");
        
        if(!num_reservas){
            printf(ERROR "\n Não há reservas realizadas!");
        } else {
            for(int i = 0; i < num_reservas; i++){

                int concluido = (reservas + i)->concluido;

                if(concluido){
                    printf(SUCCESS);
                } else {
                    printf(OUTPUT);
                }
                
                printf("\n (%d) %s  ( %-10s  %-5s)", (i + 1), (reservas + i)->sala, (reservas + i)->data_reserva, (reservas + i)->horario_reserva);
            }
        }

        printf(OUTPUT "\n\n ================================ ");
        
        printf(SUCCESS "\n\n Pressione ENTER para retornar! ");
        opcao = input();
        
    } while(opcao != 0);
    
    free(reservas);
}

void emprestimoRecurso(int id_recurso, char nome_recurso[], char tipo_recurso[]){
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
    novo_emprestimo.concluido = 0;

    // Lógica para Alterar Disponibilidade de Recurso
    if(strcmp(tipo_recurso, "livro") == 0){
        char arquivo[] = "src/bd/livros.txt";
        
        int num_livros = numeroRecursos(arquivo);

        struct Livro *livros = malloc(sizeof(struct Livro) * num_livros);

        lerLivros(arquivo, livros);

        for(int i = 0; i < num_livros; i++){
            if((livros + i)->id == id_recurso){
                (livros + i)->disponivel = 0;
            }
        }

        salvarLivros(arquivo, livros, num_livros);

        free(livros);
    }

    if(strcmp(tipo_recurso, "calculadora") == 0){
        char arquivo[] = "src/bd/calculadoras.txt";

        int num_calculadoras = numeroRecursos(arquivo);

        struct Calculadora *calculadoras = malloc(sizeof(struct Calculadora) * num_calculadoras);

        lerCalculadoras(arquivo, calculadoras);

        for(int i = 0; i < num_calculadoras; i++){
            if((calculadoras + i)->id == id_recurso){
                (calculadoras + i)->disponivel = 0;
            }
        }

        salvarCalculadoras(arquivo, calculadoras, num_calculadoras);

        free(calculadoras);
    }

    if(strcmp(tipo_recurso, "fone_ouvido") == 0){
        char arquivo[] = "src/bd/fones_ouvido.txt";

        int num_fones = numeroRecursos(arquivo);

        struct Fone_Ouvido *fones_ouvido = malloc(sizeof(struct Fone_Ouvido) * num_fones);

        lerFonesOuvido(arquivo, fones_ouvido);

        for(int i = 0; i < num_fones; i++){
            if((fones_ouvido + i)->id == id_recurso){
                (fones_ouvido + i)->disponivel = 0;
            }
        }

        salvarFonesOuvido(arquivo, fones_ouvido, num_fones);

        free(fones_ouvido);
    }

    salvarEmprestimo(arquivo_emprestimos, &novo_emprestimo);

    printf(OUTPUT "\n\n Pressione ENTER para retornar ");  
    int opcao = input();
}

void reservaSala(int id_sala, char sala[], int max_pessoas){
    // Criação de Reserva de Sala

    struct Data data_atual = dataAtual(); 
    struct Reserva_Sala nova_reserva;

    char arquivo_reservas[] = "src/bd/reservas.txt"; 
    
    // ===================================================
    
    int horas, minutos, dia, mes, horario_valido = 0, data_valida = 0, qntd_pessoas = 0, duracao = 0;
    
    char message[64] = "";
    
    do {                
        while(!data_valida){
            system("clear");

            printf(OUTPUT "\n <--- (%s) DATA ---> \n", sala);

            if(strcmp(message, "") != 0){
                printf(ERROR "\n %s ", message);
            }

            data_valida = inputData(&dia, &mes, message);
        }
        
        strcpy(message, "");

        while(!horario_valido){
            system("clear");

            printf(OUTPUT "\n <--- (%s) HORÁRIO ---> \n", sala);

            if(strcmp(message, "") != 0){
                printf(ERROR "\n %s ", message);
            }

            horario_valido = inputHorario(&horas, &minutos, message);        
        }

        strcpy(message, "");

        do {
            system("clear");

            printf(OUTPUT "\n <--- (%s) DURAÇÃO ---> \n", sala);

            if(strcmp(message, "") != 0){
                printf(ERROR "\n %s ", message);
            }

            printf(HELP "\n Insira o TEMPO DE DURAÇÃO (15min - 300min) >> ");
            duracao = input();

            if(duracao < 15 || duracao > 300){
                strcpy(message, "Insira uma duração válida (15min - 300min)!\n");
            }

        } while(duracao < 15 || duracao > 300);

        strcpy(message, "");

         do {
            system("clear");

            printf(OUTPUT "\n <--- (%s) No PESSOAS ---> \n", sala);

            if(strcmp(message, "") != 0){
                printf(ERROR "\n %s ", message);
            }

            printf(HELP "\n Insira a QUANTIDADE DE PESSOAS >> ");
            qntd_pessoas = input();

            if(qntd_pessoas < 1 || qntd_pessoas > max_pessoas){
                sprintf(message, "Insira uma quantidade válida (1 - %d)!\n", max_pessoas);
            }

        } while(qntd_pessoas < 1 || qntd_pessoas > max_pessoas);

        
    } while(!horario_valido || !data_valida);
    
    // Nova Reserva de Sala
    nova_reserva.id = randomID();
    strcpy(nova_reserva.sala, sala);
    sprintf(nova_reserva.data_reserva, "%d/%d/%d", dia, mes, data_atual.ano);
    sprintf(nova_reserva.horario_reserva, "%d:%d", horas, minutos);
    nova_reserva.duracao = duracao;
    nova_reserva.qntd_pessoas = qntd_pessoas;
    nova_reserva.concluido = 0;

    // Alterar Disponibilidade de Sala

    char arquivo[] = "src/bd/salas.txt";
        
    int num_salas = numeroRecursos(arquivo);

    struct Sala *salas = malloc(sizeof(struct Sala) * num_salas);

    lerSalas(arquivo, salas);

    for(int i = 0; i < num_salas; i++){
        if((salas + i)->id == id_sala){
            (salas + i)->disponivel = 0;
            break;
        }
    }

    salvarSalas(arquivo, salas, num_salas);

    free(salas);
    
    salvarReserva(arquivo_reservas, &nova_reserva);
    
    printf("\n");

    printf(RESET "\n Sala: %s", sala);
    printf(RESET "\n Data: %s %s", nova_reserva.data_reserva, nova_reserva.horario_reserva);
    printf(RESET "\n Duração: %dmin", duracao);
    printf(RESET "\n Qntd de Pessoas: %d", qntd_pessoas);

    printf(SUCCESS "\n\n Pressione ENTER para retornar ");  
    int opcao = input();
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

        printf("\n 1 - ACESSAR RECURSOS DISPONÍVEIS");
        printf("\n 2 - MEUS EMPRÉSTIMOS");
        printf("\n 3 - MINHAS RESERVAS");
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