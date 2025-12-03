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
            
        int qntd = (livros + i)->qntd;

        if(qntd > 0){
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

                int qntd = (livros + i)->qntd;

                if(qntd){
                    printf(SUCCESS);
                    printf("\n (%02d) %-32.32s - %-24.24s    %04d    %02dº Volume | %02d disponíveis", (i + 1), (livros + i)->nome, (livros + i)->autor, (livros + i)->ano, (livros + i)->volume, (livros + i)->qntd);
                } else {
                    printf(ERROR);
                    printf("\n (--) %-32.32s - %-24.24s    %04d    %02dº Volume | 00 disponíveis", (livros + i)->nome, (livros + i)->autor, (livros + i)->ano, (livros + i)->volume);
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
            
        int qntd = (calculadoras + i)->qntd;

        if(qntd > 0){
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

                int qntd = (calculadoras + i)->qntd;

                if(qntd > 0){
                    printf(SUCCESS);
                    printf("\n (%02d) %-8.8s - %-8.8s | %02d disponíveis", (i + 1), (calculadoras + i)->modelo, (calculadoras + i)->marca, (calculadoras + i)->qntd);
                } else {
                    printf(ERROR);
                    printf("\n (--) %-8.8s - %-8.8s | 00 disponíveis", (calculadoras + i)->modelo, (calculadoras + i)->marca);
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
            
        int qntd = (fones_ouvido + i)->qntd;

        if(qntd > 0){
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

                int qntd = (fones_ouvido + i)->qntd;

                if(qntd > 0){
                    printf(SUCCESS);
                    printf("\n (%02d) %-16.16s - %-16.16s | %02d disponíveis", (i + 1), (fones_ouvido + i)->modelo, (fones_ouvido + i)->marca, (fones_ouvido + i)->qntd);
                } else {
                    printf(ERROR);
                    printf("\n (--) %-16.16s - %-16.16s | 00 disponíveis", (fones_ouvido + i)->modelo, (fones_ouvido + i)->marca);
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

// ============================================================

void listarEmprestimos(){
    
    int opcao = -1;
    
    char arquivo_emprestimos[] = "src/bd/emprestimos.txt";
    
    // ===================================================
            
    char message[64] = "";
    
    do {
        int num_emprestimos = numeroRecursos(arquivo_emprestimos);
        
        struct Emprestimo *emprestimos = malloc(sizeof(struct Emprestimo) * num_emprestimos);
        
        lerEmprestimos(arquivo_emprestimos, emprestimos);

        system("clear");
    
        printf(OUTPUT "\n <--- EMPRÉSTIMOS EM ANDAMENTO ---> \n");
        
        if(strcmp(message, "") != 0){
            printf(ERROR "\n %s ", message);
        }

        printf(ERROR "\n Atrasados");
        printf(SUCCESS "\n Pendentes");

        printf(OUTPUT "\n\n ================================ \n");

        int *nao_concluidos = malloc(sizeof(int) * num_emprestimos);

        int indice = 0, atrasados = 0;
        
        for(int i = 0; i < num_emprestimos; i++){

            if(emprestimos[i].concluido == 0){

                int atrasado = emprestimoAtrasado(emprestimos[i]);

                if(atrasado){
                    atrasados++;
                    printf(ERROR "\n (%02d) %03d %-32.32s %s Atrasado", (indice + 1), emprestimos[i].id, emprestimos[i].nome_recurso, emprestimos[i].data_devolucao);        
                } else {
                    printf(SUCCESS "\n (%02d) %03d %-32.32s %s", (indice + 1), emprestimos[i].id, emprestimos[i].nome_recurso, emprestimos[i].data_devolucao);        
                }
               
                nao_concluidos[indice] = i;
                indice++;
            }
        }

        if(!indice){
            printf(ERROR "\n Não há empréstimos realizados!");
        }

        printf(OUTPUT "\n\n ================================ ");    

        printf("\n Empréstimos atrasados: %d", atrasados);
        printf("\n Empréstimos pendentes: %d", indice);
        
        printf(SUCCESS "\n\n Digite %d para RETORNAR! ", (indice + 1));

        printf(HELP "\n\n Insira o EMPRÉSTIMO p/ CONCLUIR >> ");
        opcao = input();

        if(opcao == (indice + 1)){
            free(emprestimos);
            free(nao_concluidos);
            break;
        }

        if((opcao < 1 || opcao > (indice + 1))){
            sprintf(message, "Opção INVÁLIDA!\n");
        } else {
            strcpy(message, "");

            int indice_concluir = nao_concluidos[opcao - 1];

            emprestimos[indice_concluir].concluido = 1;

            concluirEmprestimo(emprestimos[indice_concluir].tipo_recurso, emprestimos[indice_concluir].id_recurso);

            salvarEmprestimos(arquivo_emprestimos, emprestimos, num_emprestimos);
        }

        free(nao_concluidos);
        free(emprestimos);
        
    } while(1);
}

void listarReservas(){

    int opcao = -1;
    
    char arquivo_reservas[] = "src/bd/reservas.txt";
    
    // ===================================================
    
    char message[32] = "";
    
    do {
        
        int num_reservas = numeroRecursos(arquivo_reservas);
        
        struct Reserva_Sala *reservas = malloc(sizeof(struct Reserva_Sala) * num_reservas);
        
        lerReservas(arquivo_reservas, reservas);
        
        system("clear");
    
        printf(OUTPUT "\n <--- RESERVAS REALIZADAS ---> \n");
        
        if(strcmp(message, "") != 0){
            printf(ERROR "\n %s ", message);
        }

        printf(ERROR "\n Atrasadas");
        printf(SUCCESS "\n Pendentes");

        printf(OUTPUT "\n\n ================================ \n");

        int *nao_concluidos = malloc(sizeof(int) * num_reservas);

        int indice = 0, atrasadas = 0;
        
        for(int i = 0; i < num_reservas; i++){

            if(reservas[i].concluido == 0){
                int atrasada = reservaAtrasada(reservas[i]);

                if(atrasada){
                    atrasadas++;
                    printf(ERROR "\n (%d) %s  ( %s ) Atrasada", (indice + 1), (reservas + i)->sala, (reservas + i)->data_reserva);
                } else {
                    printf(SUCCESS "\n (%d) %s  ( %s )", (indice + 1), (reservas + i)->sala, (reservas + i)->data_reserva);
                }
                
                nao_concluidos[indice] = i;
                indice++;
            }
            
        }

        if(!indice){
            printf(ERROR "\n Não há reservas realizadas!");
        }

        printf(OUTPUT "\n\n ================================ ");

        printf("\n Reservas atrasadas: %d", atrasadas);
        printf("\n Reservas pendentes: %d", indice);
        
        printf(SUCCESS "\n\n Digite %d para RETORNAR! ", (indice + 1));

        printf(HELP "\n\n Insira a RESERVA p/ CONCLUIR >> ");
        opcao = input();

        if(opcao == (indice + 1)){
            free(nao_concluidos);
            free(reservas);
            break;
        }
        
        if((opcao < 1 || opcao > (indice + 1))){
            sprintf(message, "Opção INVÁLIDA!\n");
        } else {
            strcpy(message, "");

            int indice_concluir = nao_concluidos[opcao - 1];

            reservas[indice_concluir].concluido = 1;

            concluirReserva(reservas[indice_concluir].sala);

            salvarReservas(arquivo_reservas, reservas, num_reservas);
        }

        free(nao_concluidos);
        free(reservas);
    
    } while(opcao != 0);
    
}

void emprestimoRecurso(int id_recurso, char nome_recurso[], char tipo_recurso[]){
    // Criação de um Empréstimo
    
    struct Emprestimo novo_emprestimo;
    struct Data data_emprestimo = dataAtual();
    struct Data data_devolucao;

    char arquivo_emprestimos[] = "src/bd/emprestimos.txt"; 
    
    data_devolucao = dataDevolucao();

    // Novo Empréstimo
    novo_emprestimo.id = randomID();
    novo_emprestimo.id_recurso = id_recurso;
    strcpy(novo_emprestimo.tipo_recurso, tipo_recurso);
    strcpy(novo_emprestimo.nome_recurso, nome_recurso);
    sprintf(novo_emprestimo.data_emprestimo, "%02d/%02d/%02d %02d:%02d", data_emprestimo.dia, data_emprestimo.mes, data_emprestimo.ano, data_emprestimo.hora, data_emprestimo.minuto);
    sprintf(novo_emprestimo.data_devolucao, "%02d/%02d/%02d %02d:%02d", data_devolucao.dia, data_devolucao.mes, data_devolucao.ano, data_devolucao.hora, data_devolucao.minuto);
    novo_emprestimo.concluido = 0;
    novo_emprestimo.atrasado = 0;

    // Lógica para Alterar Disponibilidade de Recurso
    if(strcmp(tipo_recurso, "livro") == 0){
        char arquivo[] = "src/bd/livros.txt";
        
        int num_livros = numeroRecursos(arquivo);

        struct Livro *livros = malloc(sizeof(struct Livro) * num_livros);

        lerLivros(arquivo, livros);

        for(int i = 0; i < num_livros; i++){
            if((livros + i)->id == id_recurso){
                (livros + i)->qntd -= 1;
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
                (calculadoras + i)->qntd -= 1;
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
                (fones_ouvido + i)->qntd -= 1;
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

    struct Reserva_Sala nova_reserva;

    char arquivo_reservas[] = "src/bd/reservas.txt"; 
    
    // ===================================================
    
    int horas, minutos, dia, mes, ano, horario_valido = 0, data_valida = 0, qntd_pessoas = 0, duracao = 0;
    
    char message[64] = "";
               
    while(!data_valida){
        system("clear");

        printf(OUTPUT "\n <--- (%s) DATA ---> \n", sala);

        if(strcmp(message, "") != 0){
            printf(ERROR "\n %s ", message);
        }

        data_valida = inputData(&dia, &mes, &ano, message);
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
    
    // Nova Reserva de Sala
    nova_reserva.id = randomID();
    strcpy(nova_reserva.sala, sala);
    sprintf(nova_reserva.data_reserva, "%02d/%02d/%02d %02d:%02d", dia, mes, ano, horas, minutos);
    nova_reserva.duracao = duracao;
    nova_reserva.qntd_pessoas = qntd_pessoas;
    nova_reserva.concluido = 0;
    nova_reserva.atrasado = 0;

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
    printf(RESET "\n Data: %s", nova_reserva.data_reserva);
    printf(RESET "\n Duração: %dmin", duracao);
    printf(RESET "\n Qntd de Pessoas: %d", qntd_pessoas);

    printf(SUCCESS "\n\n Pressione ENTER para retornar ");  
    int opcao = input();
};

// ============================================================

void acessarRecursos(){
    
    int opcao = -1;
    char message[32] = "";

    do {

        system("clear");

        printf(OUTPUT);
    
        printf("\n <--- RECURSOS DISPONÍVEIS ---> \n");
        
        if(strcmp(message, "") != 0){
            printf(ERROR "\n %s ", message);
        }

        printf(OUTPUT);

        printf("\n (1) LIVROS");
        printf("\n (2) CALCULADORAS");
        printf("\n (3) FONES DE OUVIDO");
        printf("\n (4) RESERVAR SALA");
        printf("\n");
        printf("\n (0) RETORNAR");
    
        printf(HELP "\n\n Insira uma opção >> ");
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

void interfaceInicialUsuario(){

    int opcao = -1;
    char message[32] = "";

    do {
        
        printf(OUTPUT);

        system("clear");

        printf(OUTPUT  "\n <--- BEM-VINDO A BIBLIOTECA ---> ");
        printf(SUCCESS "\n            (USUÁRIO) \n");


        if(strcmp(message, "") != 0){
            printf(ERROR "\n %s ", message);
        }

        printf(OUTPUT);

        printf("\n (1) ACESSAR RECURSOS DISPONÍVEIS");
        printf("\n (2) MEUS EMPRÉSTIMOS");
        printf("\n (3) MINHAS RESERVAS");
        printf("\n");
        printf("\n (0) SAIR");
        
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

}

void adicionarLivro(){

    char arquivo[] = "src/bd/livros.txt";

    struct Data data_atual = dataAtual();
    
    int num_livros = numeroRecursos(arquivo);
    
    struct Livro *livros = malloc(sizeof(struct Livro) * num_livros);

    lerLivros(arquivo, livros);

    // ========================================================

    char nome_livro[32], autor[32], categoria[16];

    int qntd = 0, ano = 0, volume = 0;

    system("clear");

    printf(OUTPUT "\n <-- ADICIONAR LIVRO --> \n");

    printf(HELP "\n Insira o NOME do LIVRO >> ");
    inputString(nome_livro, 32);

    printf(HELP "\n Insira o AUTOR >> ");
    inputString(autor, 32);

    printf(HELP "\n Insira a CATEGORIA >> ");
    inputString(categoria, 16);

    printf(HELP "\n Insira a QUANTIDADE >> ");
    qntd = input();

    while(qntd < 1){
        printf(ERROR " Insira uma QUANTIDADE VÁLIDA >> ");
        qntd = input(); 
    }

    printf(HELP "\n Insira o ANO >> ");
    ano = input();

    while(ano < 1400 || ano > data_atual.ano){
        printf(ERROR " Insira um ANO VÁLIDO >> ");
        ano = input(); 
    }

    printf(HELP "\n Insira o VOLUME >> ");
    volume = input();

    while(volume < 1){
        printf(ERROR " Insira um VOLUME VÁLIDO >> ");
        volume = input(); 
    }

    num_livros++;
    livros = realloc(livros, sizeof(struct Livro) * num_livros);
    
    livros[num_livros - 1].id = randomID();
    strcpy(livros[num_livros - 1].nome, nome_livro);
    strcpy(livros[num_livros - 1].autor, autor);
    strcpy(livros[num_livros - 1].categoria, categoria);
    livros[num_livros - 1].qntd = qntd;
    livros[num_livros - 1].ano = ano;
    livros[num_livros - 1].volume = volume;
    
    salvarLivros(arquivo, livros, num_livros);

    free(livros);
}

void adicionarCalculadora(){

    int opcao = 0;

    char arquivo[] = "src/bd/calculadoras.txt";
    
    int num_calculadoras = numeroRecursos(arquivo);
    
    struct Calculadora *calculadoras = malloc(sizeof(struct Calculadora) * num_calculadoras);

    lerCalculadoras(arquivo, calculadoras);

    // ========================================================

    char modelo[8], marca[8];

    int qntd = 0;

    system("clear");

    printf(OUTPUT "\n <-- ADICIONAR CALCULADORA --> \n");

    printf(HELP "\n Insira o MODELO >> ");
    inputString(modelo, 8);

    printf(HELP "\n Insira a MARCA >> ");
    inputString(marca, 8);

    printf(HELP "\n Insira a QUANTIDADE >> ");
    qntd = input();

    while(qntd < 1){
        printf(ERROR " Insira uma QUANTIDADE VÁLIDA >> ");
        qntd = input(); 
    }

    num_calculadoras++;
    calculadoras = realloc(calculadoras, sizeof(struct Calculadora) * num_calculadoras);
    
    calculadoras[num_calculadoras - 1].id = randomID();
    strcpy(calculadoras[num_calculadoras - 1].modelo, modelo);
    strcpy(calculadoras[num_calculadoras - 1].marca, marca);
    calculadoras[num_calculadoras - 1].qntd = 1;
    
    salvarCalculadoras(arquivo, calculadoras, num_calculadoras);

    free(calculadoras);
}

void adicionarFoneOuvido(){

    int opcao = 0;

    char arquivo[] = "src/bd/fones_ouvido.txt";
    
    int num_fones = numeroRecursos(arquivo);
    
    struct Fone_Ouvido *fones_ouvido = malloc(sizeof(struct Fone_Ouvido) * num_fones);

    lerFonesOuvido(arquivo, fones_ouvido);

    // ========================================================

    char modelo[8], marca[8];

    int qntd = 0;

    system("clear");

    printf(OUTPUT "\n <-- ADICIONAR FONE DE OUVIDO --> \n");

    printf(HELP "\n Insira o MODELO >> ");
    inputString(modelo, 8);

    printf(HELP "\n Insira a MARCA >> ");
    inputString(marca, 8);

    printf(HELP "\n Insira a QUANTIDADE >> ");
    qntd = input();

    while(qntd < 1){
        printf(ERROR " Insira uma QUANTIDADE VÁLIDA >> ");
        qntd = input(); 
    }

    num_fones++;
    fones_ouvido = realloc(fones_ouvido, sizeof(struct Fone_Ouvido) * num_fones);
    
    fones_ouvido[num_fones - 1].id = randomID();
    strcpy(fones_ouvido[num_fones - 1].modelo, modelo);
    strcpy(fones_ouvido[num_fones - 1].marca, marca);
    fones_ouvido[num_fones - 1].qntd = 1;
    
    salvarFonesOuvido(arquivo, fones_ouvido, num_fones);

    free(fones_ouvido);
}

void adicionarSala(){

    int opcao = 0;

    char arquivo[] = "src/bd/salas.txt";
    
    int num_salas = numeroRecursos(arquivo);
    
    struct Sala *salas = malloc(sizeof(struct Sala) * num_salas);

    lerSalas(arquivo, salas);

    // ========================================================

    char sala[8];
    int max_pessoas;

    system("clear");

    printf(OUTPUT "\n <-- ADICIONAR SALA --> \n");

    printf(HELP "\n Insira a SALA >> ");
    inputString(sala, 8);

    printf(HELP "\n Insira a CAPACIDADE (pessoas) >> ");
    max_pessoas = input();

    while(max_pessoas < 1){
        printf(ERROR " Insira uma quantidade válida ( >= 1) >> ");
        max_pessoas = input();
    }

    num_salas++;
    salas = realloc(salas, sizeof(struct Sala) * num_salas);
    
    salas[num_salas - 1].id = randomID();
    strcpy(salas[num_salas - 1].sala, sala);
    salas[num_salas - 1].max_pessoas = max_pessoas;
    salas[num_salas - 1].disponivel = 1;
    
    salvarSalas(arquivo, salas, num_salas);

    free(salas);
}

void adicionarRecurso(){

    int opcao = -1;
    char message[32] = "";

    do {

        system("clear");

        printf(OUTPUT);
    
        printf("\n <--- ADICIONAR RECURSO ---> \n");
        
        if(strcmp(message, "") != 0){
            printf(ERROR "\n %s ", message);
        }

        printf(OUTPUT);

        printf("\n (1) LIVRO");
        printf("\n (2) CALCULADORA");
        printf("\n (3) FONE DE OUVIDO");
        printf("\n (4) SALA");
        printf("\n");
        printf("\n (0) RETORNAR");
    
        printf(HELP "\n\n Insira uma opção >> ");
        opcao = input();

        switch (opcao){
            case 0:
                strcpy(message, "");
                break;
            
            case 1:
                adicionarLivro();
                strcpy(message, "");
                break;
            
            case 2:
                adicionarCalculadora();
                strcpy(message, "");
                break;

            case 3:
                adicionarFoneOuvido();
                strcpy(message, "");
                break;

            case 4:
                adicionarSala();
                strcpy(message, "");
                break;
            
            default:
                strcpy(message, "Insira uma opção válida!\n");
                break;
        }
    
    } while(opcao != 0);

}

// ============================================================

void removerLivro(){

    int opcao = 0;

    char arquivo[] = "src/bd/livros.txt";
    
    // ========================================================
    
    char message[32] = "";
    
    do {

        int num_recursos = numeroRecursos(arquivo);
        
        struct Livro *livros = malloc(sizeof(struct Livro) * num_recursos);
        
        lerLivros(arquivo, livros);
        
        system("clear");
    
        printf(OUTPUT "\n <-- LIVROS (REMOVER) --> \n");

        if(strcmp(message, "") != 0){
            printf(ERROR "\n %s ", message);
        }

        if(num_recursos == 0){
            printf(ERROR "\n Não há LIVROS!");
        }

        for(int i = 0; i < num_recursos; i++){
    
            printf(OUTPUT "\n (%02d) %03d %-32.32s %-32.32s %-16.16s | %02d livros", (i + 1), livros[i].id, livros[i].nome, livros[i].autor, livros[i].categoria, livros[i].qntd);
    
        }
    
        printf(OUTPUT "\n\n ================================ ");
    
        printf("\n");

        printf(SUCCESS "\n Digite 0 para RETORNAR! \n");
    
        printf(HELP "\n Insira o LIVRO a EXCLUIR >> ");
        opcao = input();

        if(opcao == 0){
            free(livros);
            break;
        }

        if(opcao < 0 || opcao > (num_recursos)){
            strcpy(message, "Insira uma OPÇÃO VÁLIDA!\n");
        } else {

            printf(HELP "\n Insira a QUANTIDADE a EXCLUIR >> ");
            int qntd = input();

            while(qntd < 1){
                printf(ERROR " Insira uma QUANTIDADE VÁLIDA >> ");
                qntd = input();
            }

            if(qntd >= livros[opcao - 1].qntd){
                struct Livro *temp = malloc(sizeof(struct Livro) * (num_recursos - 1));
                
                int ii = 0;
                for(int i = 0; i < num_recursos; i++){
                    if(i != (opcao - 1)){
                        temp[ii] = livros[i];   
                        ii++;
                    }
                }
                
                num_recursos--;
                salvarLivros(arquivo, temp, num_recursos);
            
                free(temp);
                
            } else {
                livros[opcao - 1].qntd -= qntd;
                salvarLivros(arquivo, livros, num_recursos);
            }
            
            free(livros);
        }   

    } while(opcao != 0);
}

void removerCalculadora(){
    
    int opcao = 0;

    char arquivo[] = "src/bd/calculadoras.txt";
    
    // ========================================================
    
    char message[32] = "";
    
    do {

        int num_recursos = numeroRecursos(arquivo);
        
        struct Calculadora *calculadoras = malloc(sizeof(struct Calculadora) * num_recursos);
        
        lerCalculadoras(arquivo, calculadoras);
        
        system("clear");
    
        printf(OUTPUT "\n <-- CALCULADORAS (REMOVER) --> \n");

        if(strcmp(message, "") != 0){
            printf(ERROR "\n %s ", message);
        }

        if(num_recursos == 0){
            printf(ERROR "\n Não há CALCULADORAS!");
        }

        for(int i = 0; i < num_recursos; i++){
    
            printf(OUTPUT "\n (%02d) %03d %-8.8s - %-8.8s | %02d calculadoras", (i + 1), calculadoras[i].id, calculadoras[i].modelo, calculadoras[i].marca, calculadoras[i].qntd);
    
        }
    
        printf(OUTPUT "\n\n ================================ ");
    
        printf("\n");

        printf(SUCCESS "\n Digite 0 para RETORNAR! \n");
    
        printf(HELP "\n Insira a CALCULADORA a EXCLUIR >> ");
        opcao = input();

        if(opcao == 0){
            free(calculadoras);
            break;
        }

        if(opcao < 0 || opcao > (num_recursos)){
            strcpy(message, "Insira uma OPÇÃO VÁLIDA!\n");
        } else {

            printf(HELP "\n Insira a QUANTIDADE a EXCLUIR >> ");
            int qntd = input();

            while(qntd < 1){
                printf(ERROR " Insira uma QUANTIDADE VÁLIDA >> ");
                qntd = input();
            }

            if(qntd >= calculadoras[opcao - 1].qntd){
                struct Calculadora *temp = malloc(sizeof(struct Calculadora) * (num_recursos - 1));
            
                int ii = 0;
                for(int i = 0; i < num_recursos; i++){
                    if(i != (opcao - 1)){
                        temp[ii] = calculadoras[i];   
                        ii++;
                    }
                }
                
                num_recursos--;
                salvarCalculadoras(arquivo, temp, num_recursos);
            
                free(temp);

            } else {
                calculadoras[opcao - 1].qntd -= qntd;
                salvarCalculadoras(arquivo, calculadoras, num_recursos);
            }
            
            free(calculadoras);
        }   

    } while(opcao != 0);
}

void removerFoneOuvido(){
    
    int opcao = 0;

    char arquivo[] = "src/bd/fones_ouvido.txt";
    
    // ========================================================
    
    char message[32] = "";
    
    do {

        int num_recursos = numeroRecursos(arquivo);
        
        struct Fone_Ouvido *fones_ouvido = malloc(sizeof(struct Fone_Ouvido) * num_recursos);
        
        lerFonesOuvido(arquivo, fones_ouvido);
        
        system("clear");
    
        printf(OUTPUT "\n <-- FONES DE OUVIDO (REMOVER) --> \n");

        if(strcmp(message, "") != 0){
            printf(ERROR "\n %s ", message);
        }

        if(num_recursos == 0){
            printf(ERROR "\n Não há FONES DE OUVIDO!");
        }

        for(int i = 0; i < num_recursos; i++){
    
            printf(OUTPUT "\n (%02d) %03d %-8.8s - %-16.16s | %02d fones de ouvido", (i + 1), fones_ouvido[i].id, fones_ouvido[i].modelo, fones_ouvido[i].marca, fones_ouvido[i].qntd);
    
        }
    
        printf(OUTPUT "\n\n ================================ ");
    
        printf("\n");

        printf(SUCCESS "\n Digite 0 para RETORNAR! \n");
    
        printf(HELP "\n Insira o FONE DE OUVIDO a EXCLUIR >> ");
        opcao = input();

        if(opcao == 0){
            free(fones_ouvido);
            break;
        }

        if(opcao < 0 || opcao > (num_recursos)){
            strcpy(message, "Insira uma OPÇÃO VÁLIDA!\n");
        } else {

            printf(HELP "\n Insira a QUANTIDADE a EXCLUIR >> ");
            int qntd = input();

            while(qntd < 1){
                printf(ERROR " Insira uma QUANTIDADE VÁLIDA >> ");
                qntd = input();
            }   

            if(qntd >= fones_ouvido[opcao - 1].qntd){
                
                struct Fone_Ouvido *temp = malloc(sizeof(struct Fone_Ouvido) * (num_recursos - 1));
            
                int ii = 0;
                for(int i = 0; i < num_recursos; i++){
                    if(i != (opcao - 1)){
                        temp[ii] = fones_ouvido[i];   
                        ii++;
                    }
                }
                
                num_recursos--;
                salvarFonesOuvido(arquivo, temp, num_recursos);
            
                free(temp);
                
            } else {
                fones_ouvido[opcao - 1].qntd -= qntd;
                salvarFonesOuvido(arquivo, fones_ouvido, num_recursos);
            }
            
            free(fones_ouvido);

        }   

    } while(opcao != 0);
}

void removerSala(){

    int opcao = 0;

    char arquivo[] = "src/bd/salas.txt";
    
    // ========================================================
    
    char message[32] = "";
    
    do {

        int num_recursos = numeroRecursos(arquivo);
        
        struct Sala *salas = malloc(sizeof(struct Sala) * num_recursos);
        
        lerSalas(arquivo, salas);
        
        system("clear");
    
        printf(OUTPUT "\n <-- SALAS (REMOVER) --> \n");

        if(strcmp(message, "") != 0){
            printf(ERROR "\n %s ", message);
        }

        if(num_recursos == 0){
            printf(ERROR "\n Não há SALAS!");
        }

        for(int i = 0; i < num_recursos; i++){
    
            printf(OUTPUT "\n (%02d) %03d %-8.8s  %02d pessoas", (i + 1), salas[i].id, salas[i].sala, salas[i].max_pessoas);
    
        }
    
        printf(OUTPUT "\n\n ================================ ");
    
        printf("\n");

        printf(SUCCESS "\n Digite 0 para RETORNAR! \n");
    
        printf(HELP "\n Insira a SALA a EXCLUIR >> ");
        opcao = input();

        if(opcao == 0){
            free(salas);
            break;
        }

        if(opcao < 0 || opcao > (num_recursos)){
            strcpy(message, "Insira uma OPÇÃO VÁLIDA!\n");
        } else {

            struct Sala *temp = malloc(sizeof(struct Sala) * (num_recursos - 1));
        
            int ii = 0;
            for(int i = 0; i < num_recursos; i++){
                if(i != (opcao - 1)){
                    temp[ii] = salas[i];   
                    ii++;
                }
            }
            
            num_recursos--;
            salvarSalas(arquivo, temp, num_recursos);
        
            free(temp);
            free(salas);
        }   

    } while(opcao != 0);
}

void removerRecurso(){

    int opcao = -1;
    char message[32] = "";

    do {

        system("clear");

        printf(OUTPUT);
    
        printf("\n <--- REMOVER RECURSO ---> \n");
        
        if(strcmp(message, "") != 0){
            printf(ERROR "\n %s ", message);
        }

        printf(OUTPUT);

        printf("\n (1) LIVRO");
        printf("\n (2) CALCULADORA");
        printf("\n (3) FONE DE OUVIDO");
        printf("\n (4) SALA");
        printf("\n");
        printf("\n (0) RETORNAR");
    
        printf(HELP "\n\n Insira uma opção >> ");
        opcao = input();

        switch (opcao){
            case 0:
                strcpy(message, "");
                break;
            
            case 1:
                removerLivro();
                strcpy(message, "");
                break;
            
            case 2:
                removerCalculadora();
                strcpy(message, "");
                break;

            case 3:
                removerFoneOuvido();
                strcpy(message, "");
                break;

            case 4:
                removerSala();
                strcpy(message, "");
                break;
            
            default:
                strcpy(message, "Insira uma opção válida!\n");
                break;
        }
    
    } while(opcao != 0);
}

// ============================================================

void editarLivro(){

    int opcao = 0;

    char arquivo[] = "src/bd/livros.txt";
    
    // ========================================================
    
    char message[32] = "";
    
    do {

        int num_recursos = numeroRecursos(arquivo);
        
        struct Livro *livros = malloc(sizeof(struct Livro) * num_recursos);
        
        lerLivros(arquivo, livros);
        
        system("clear");
    
        printf(OUTPUT "\n <-- LIVROS (EDITAR) --> \n");

        if(strcmp(message, "") != 0){
            printf(ERROR "\n %s ", message);
        }

        if(num_recursos == 0){
            printf(ERROR "\n Não há LIVROS!");
        }

        for(int i = 0; i < num_recursos; i++){
    
            printf(OUTPUT "\n (%02d) %03d %-32.32s %-32.32s %-16.16s | %02d livros", (i + 1), livros[i].id, livros[i].nome, livros[i].autor, livros[i].categoria, livros[i].qntd);
    
        }
    
        printf(OUTPUT "\n\n ================================ ");
    
        printf("\n");

        printf(SUCCESS "\n Digite 0 para RETORNAR! \n");
    
        printf(HELP "\n Insira o LIVRO a EDITAR >> ");
        opcao = input();

        if(opcao == 0){
            free(livros);
            break;
        }

        if(opcao < 0 || opcao > (num_recursos)){
            strcpy(message, "Insira uma OPÇÃO VÁLIDA!\n");
        } else {

            printf("\n Insira NOVO NOME >> ");
            inputString(livros[opcao - 1].nome, 32);

            printf("\n Insira NOVO AUTOR >> ");
            inputString(livros[opcao - 1].autor, 32);

            printf("\n Insira NOVA CATEGORIA >> ");
            inputString(livros[opcao - 1].categoria, 16);

            printf("\n Insira a QUANTIDADE >> ");
            livros[opcao - 1].qntd = input();

            while(livros[opcao - 1].qntd < 1){
                printf(ERROR " Insira uma QUANTIDADE VÁLIDA >> ");
                livros[opcao - 1].qntd = input();
            }

            salvarLivros(arquivo, livros, num_recursos);

            free(livros);
        }   

    } while(opcao != 0);

}

void editarCalculadora(){

    int opcao = 0;

    char arquivo[] = "src/bd/calculadoras.txt";
    
    // ========================================================
    
    char message[32] = "";
    
    do {

        int num_recursos = numeroRecursos(arquivo);
        
        struct Calculadora *calculadoras = malloc(sizeof(struct Calculadora) * num_recursos);
        
        lerCalculadoras(arquivo, calculadoras);
        
        system("clear");
    
        printf(OUTPUT "\n <-- CALCULADORAS (EDITAR) --> \n");

        if(strcmp(message, "") != 0){
            printf(ERROR "\n %s ", message);
        }

        if(num_recursos == 0){
            printf(ERROR "\n Não há CALCULADORAS!");
        }

        for(int i = 0; i < num_recursos; i++){
    
            printf(OUTPUT "\n (%02d) %03d %-8.8s - %s", (i + 1), calculadoras[i].id, calculadoras[i].modelo, calculadoras[i].marca);
    
        }
    
        printf(OUTPUT "\n\n ================================ ");
    
        printf("\n");

        printf(SUCCESS "\n Digite 0 para RETORNAR! \n");
    
        printf(HELP "\n Insira a CALCULADORA a EDITAR >> ");
        opcao = input();

        if(opcao == 0){
            free(calculadoras);
            break;
        }

        if(opcao < 0 || opcao > (num_recursos)){
            strcpy(message, "Insira uma OPÇÃO VÁLIDA!\n");
        } else {

            printf(HELP "\n Insira NOVO MODELO >> ");
            inputString(calculadoras[opcao - 1].modelo, 8);

            printf(HELP "\n Insira NOVA MARCA >> ");
            inputString(calculadoras[opcao - 1].marca, 8);

            printf("\n Insira a QUANTIDADE >> ");
            calculadoras[opcao - 1].qntd = input();

            while(calculadoras[opcao - 1].qntd < 1){
                printf(ERROR " Insira uma QUANTIDADE VÁLIDA >> ");
                calculadoras[opcao - 1].qntd = input();
            }

            salvarCalculadoras(arquivo, calculadoras, num_recursos);

            free(calculadoras);
        }   

    } while(opcao != 0);

}

void editarFoneOuvido(){

    int opcao = 0;

    char arquivo[] = "src/bd/fones_ouvido.txt";
    
    // ========================================================
    
    char message[32] = "";
    
    do {

        int num_recursos = numeroRecursos(arquivo);
        
        struct Fone_Ouvido *fones_ouvido = malloc(sizeof(struct Fone_Ouvido) * num_recursos);
        
        lerFonesOuvido(arquivo, fones_ouvido);
        
        system("clear");
    
        printf(OUTPUT "\n <-- FONES DE OUVIDO (EDITAR) --> \n");

        if(strcmp(message, "") != 0){
            printf(ERROR "\n %s ", message);
        }

        if(num_recursos == 0){
            printf(ERROR "\n Não há FONES DE OUVIDO!");
        }

        for(int i = 0; i < num_recursos; i++){
    
            printf(OUTPUT "\n (%02d) %03d %-8.8s - %s", (i + 1), fones_ouvido[i].id, fones_ouvido[i].modelo, fones_ouvido[i].marca);
    
        }
    
        printf(OUTPUT "\n\n ================================ ");
    
        printf("\n");

        printf(SUCCESS "\n Digite 0 para RETORNAR! \n");
    
        printf(HELP "\n Insira o FONE DE OUVIDO a EDITAR >> ");
        opcao = input();

        if(opcao == 0){
            free(fones_ouvido);
            break;
        }

        if(opcao < 0 || opcao > (num_recursos)){
            strcpy(message, "Insira uma OPÇÃO VÁLIDA!\n");
        } else {

            printf(HELP "\n Insira NOVO MODELO >> ");
            inputString(fones_ouvido[opcao - 1].modelo, 16);

            printf(HELP "\n Insira NOVA MARCA >> ");
            inputString(fones_ouvido[opcao - 1].marca, 16);

            printf("\n Insira a QUANTIDADE >> ");
            fones_ouvido[opcao - 1].qntd = input();

            while(fones_ouvido[opcao - 1].qntd < 1){
                printf(ERROR " Insira uma QUANTIDADE VÁLIDA >> ");
                fones_ouvido[opcao - 1].qntd = input();
            }

            salvarFonesOuvido(arquivo, fones_ouvido, num_recursos);

            free(fones_ouvido);
        }   

    } while(opcao != 0);

}

void editarSala(){

    int opcao = 0;

    char arquivo[] = "src/bd/salas.txt";
    
    // ========================================================
    
    char message[32] = "";
    
    do {

        int num_recursos = numeroRecursos(arquivo);
        
        struct Sala *salas = malloc(sizeof(struct Sala) * num_recursos);
        
        lerSalas(arquivo, salas);
        
        system("clear");
    
        printf(OUTPUT "\n <-- SALAS (EDITAR) --> \n");

        if(strcmp(message, "") != 0){
            printf(ERROR "\n %s ", message);
        }

        if(num_recursos == 0){
            printf(ERROR "\n Não há SALAS!");
        }

        for(int i = 0; i < num_recursos; i++){
    
            printf(OUTPUT "\n (%02d) %03d %-8.8s  %02d pessoas", (i + 1), salas[i].id, salas[i].sala, salas[i].max_pessoas);
    
        }
    
        printf(OUTPUT "\n\n ================================ ");
    
        printf("\n");

        printf(SUCCESS "\n Digite 0 para RETORNAR! \n");
    
        printf(HELP "\n Insira a SALA a EDITAR >> ");
        opcao = input();

        if(opcao == 0){
            free(salas);
            break;
        }

        if(opcao < 0 || opcao > (num_recursos)){
            strcpy(message, "Insira uma OPÇÃO VÁLIDA!\n");
        } else {

            printf(HELP "\n Insira NOVA SALA >> ");
            inputString(salas[opcao - 1].sala, 8);

            printf(HELP "\n Insira NOVA CAPACIDADE (pessoas) >> ");
            salas[opcao - 1].max_pessoas = input();
            
            do {             
                printf(ERROR " Insira NOVA CAPACIDADE (pessoas) >> ");
                salas[opcao - 1].max_pessoas = input();
            } while(salas[opcao - 1].max_pessoas <= 0);

            salvarSalas(arquivo, salas, num_recursos);
            
            free(salas);
        }   

    } while(opcao != 0);

}


void editarRecurso(){

    int opcao = -1;
    char message[32] = "";

    do {

        system("clear");

        printf(OUTPUT);
    
        printf("\n <--- EDITAR RECURSO ---> \n");
        
        if(strcmp(message, "") != 0){
            printf(ERROR "\n %s ", message);
        }

        printf(OUTPUT);

        printf("\n (1) LIVRO");
        printf("\n (2) CALCULADORA");
        printf("\n (3) FONE DE OUVIDO");
        printf("\n (4) SALA");
        printf("\n");
        printf("\n (0) RETORNAR");
    
        printf(HELP "\n\n Insira uma opção >> ");
        opcao = input();

        switch (opcao){
            case 0:
                strcpy(message, "");
                break;
            
            case 1:
                editarLivro();
                strcpy(message, "");
                break;
            
            case 2:
                editarCalculadora();
                strcpy(message, "");
                break;

            case 3:
                editarFoneOuvido();
                strcpy(message, "");
                break;

            case 4:
                editarSala();
                strcpy(message, "");
                break;
            
            default:
                strcpy(message, "Insira uma opção válida!\n");
                break;
        }
    
    } while(opcao != 0);

}

void interfaceInicialAdmin(){
    int opcao = -1;
    char message[32] = "";

    do {
        
        printf(OUTPUT);

        system("clear");

        printf(OUTPUT  "\n <--- BEM-VINDO A BIBLIOTECA ---> ");
        printf(SUCCESS "\n             (ADMIN) \n");

        if(strcmp(message, "") != 0){
            printf(ERROR "\n %s ", message);
        }

        printf(OUTPUT);

        printf("\n (1) ADICIONAR RECURSO");
        printf("\n (2) REMOVER RECURSO");
        printf("\n (3) EDITAR RECURSO");
        printf("\n");
        printf("\n (0) SAIR");
        
        printf(HELP "\n\n Insira uma opção >> ");
        opcao = input();

        switch (opcao){

            case 0: 
                strcpy(message, "");
                break;
        
            case 1:
                adicionarRecurso();
                strcpy(message, "");
                break;
            
            case 2:
                removerRecurso();
                strcpy(message, "");
                break;

            case 3:
                editarRecurso();
                strcpy(message, "");
                break;
        
            default:
                strcpy(message, "Insira uma opção válida!\n");
                break;
        
        }

    } while(opcao != 0);
}