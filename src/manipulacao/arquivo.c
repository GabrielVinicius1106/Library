#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../datas/datas.h"
#include "../input/input.h"
#include "../themes/theme.h"
#include "arquivo.h"

// Retorna o número de recursos de um arquivo
// numeroRecursos(<diretorio_arquivo>)
int numeroRecursos(char arquivo[]){
    
    FILE *fp = fopen(arquivo, "r");

    int qntd = 0;
    char c;

    while((c = getc(fp)) != EOF){
        if(c == '\n'){
            qntd++;
        }
    }

    return qntd;
}

// lerLivros(<diretorio_arquivo>, <ponteiro_de_struct>)
void lerLivros(char arquivo[], struct Livro *livros){

    FILE *fp = fopen(arquivo, "r+");

    if(fp == NULL){
        printf(ERROR "\n ERRO: Falha ao ler arquivo! \n\n");
    } else {

        int num_livros = numeroRecursos(arquivo);

        int id;
        char nome[32];
        char autor[32];
        char categoria[16];
        int disponivel;
        
        rewind(fp);
        for(int i = 0; i < num_livros; i++){
            
            fscanf(fp, " %d;", &id);
            fscanf(fp, " %[^;];", nome);
            fscanf(fp, " %[^;];", autor);
            fscanf(fp, " %[^;];", categoria);
            fscanf(fp, " %d;\n", &disponivel);

            (livros + i)->id = id;
            strcpy((livros + i)->nome, nome);
            strcpy((livros + i)->autor, autor);
            strcpy((livros + i)->categoria, categoria);
            (livros + i)->disponivel = disponivel;
        }
    }

    fclose(fp);
}

// lerCalculadoras(<diretorio_arquivo>, <ponteiro_de_struct>)
void lerCalculadoras(char arquivo[], struct Calculadora *calculadoras){
    FILE *fp = fopen(arquivo, "r+");

    if(fp == NULL){
        printf(ERROR "\n ERRO: Falha ao ler arquivo! \n\n");
    } else {

        int num_calculadoras = numeroRecursos(arquivo);

        int id;
        char modelo[8];
        char marca[8];
        int disponivel;
        
        rewind(fp);
        for(int i = 0; i < num_calculadoras; i++){
            
            fscanf(fp, " %d;", &id);
            fscanf(fp, " %[^;];", modelo);
            fscanf(fp, " %[^;];", marca);
            fscanf(fp, " %d;\n", &disponivel);

            (calculadoras + i)->id = id;
            strcpy((calculadoras + i)->modelo, modelo);
            strcpy((calculadoras + i)->marca, marca);
            (calculadoras + i)->disponivel = disponivel;
        }
    }

    fclose(fp);
}   

// lerFonesOuvido(<diretorio_arquivo>, <ponteiro_de_struct>)
void lerFonesOuvido(char arquivo[], struct Fone_Ouvido *fones_ouvido){
    FILE *fp = fopen(arquivo, "r+");

    if(fp == NULL){
        printf(ERROR "\n ERRO: Falha ao ler arquivo! \n\n");
    } else {

        int num_fones = numeroRecursos(arquivo);

        int id;
        char modelo[16];
        char marca[16];
        int disponivel;

        rewind(fp);
        for(int i = 0; i < num_fones; i++){
            
            fscanf(fp, " %d;", &id);
            fscanf(fp, " %[^;];", modelo);
            fscanf(fp, " %[^;];", marca);
            fscanf(fp, " %d;\n", &disponivel);

            (fones_ouvido + i)->id = id;
            strcpy((fones_ouvido + i)->modelo, modelo);
            strcpy((fones_ouvido + i)->marca, marca);
            (fones_ouvido + i)->disponivel = disponivel;
        }
    }

    fclose(fp);
}

// lerSalas(<diretorio_arquivo>, <ponteiro_de_struct>)
void lerSalas(char arquivo[], struct Sala *salas){
    FILE *fp = fopen(arquivo, "r+");

    if(fp == NULL){
        printf(ERROR "\n ERRO: Falha ao ler arquivo! \n\n");
    } else {

        int num_salas = numeroRecursos(arquivo);

        int id;
        char sala[8];
        int max_pessoas;
        int disponivel;
        
        rewind(fp);
        for(int i = 0; i < num_salas; i++){
            
            fscanf(fp, " %d;", &id);
            fscanf(fp, " %[^;];", sala);
            fscanf(fp, " %d;", &max_pessoas);
            fscanf(fp, " %d;\n", &disponivel);

            (salas + i)->id = id;
            strcpy((salas + i)->sala, sala);
            (salas + i)->max_pessoas = max_pessoas;
            (salas + i)->disponivel = disponivel;
        }
    }

    fclose(fp);
}

// lerEmprestimos(<diretorio_arquivo>, <ponteiro_de_struct>)
void lerEmprestimos(char arquivo[], struct Emprestimo *emprestimos){
    
    FILE *fp = fopen(arquivo, "r+");

    if(fp == NULL){
        printf(ERROR "\n ERRO: Falha ao ler arquivo! \n\n");
    } else {

        int num_emprestimos = numeroRecursos(arquivo);

        int id_emprestimo;
        int id_recurso;
        char nome_recurso[32];
        char tipo_recurso[12];

        char data_emprestimo[24];
        char data_devolucao[24];
        int concluido;
        int atrasado;
        
        rewind(fp);
        for(int i = 0; i < num_emprestimos; i++){
            
            fscanf(fp, " %d;", &id_emprestimo);
            fscanf(fp, " %d;", &id_recurso);
            fscanf(fp, " %[^;];", tipo_recurso);
            fscanf(fp, " %[^;];", nome_recurso);
            fscanf(fp, " %[^;];", data_emprestimo);
            fscanf(fp, " %[^;];", data_devolucao);
            fscanf(fp, " %d;", &concluido);
            fscanf(fp, " %d;\n", &atrasado);

            (emprestimos + i)->id = id_emprestimo; 
            (emprestimos + i)->id_recurso = id_recurso; 
            strcpy((emprestimos + i)->tipo_recurso, tipo_recurso);
            strcpy((emprestimos + i)->nome_recurso, nome_recurso);
            strcpy((emprestimos + i)->data_emprestimo, data_emprestimo);
            strcpy((emprestimos + i)->data_devolucao, data_devolucao);
            (emprestimos + i)->concluido = concluido;
            (emprestimos + i)->atrasado = atrasado;
        }
    }

    fclose(fp);
}

// lerReservas(<diretorio_arquivo>, <ponteiro_de_struct>)
void lerReservas(char arquivo[], struct Reserva_Sala *reservas){
    
    FILE *fp = fopen(arquivo, "r+");

    if(fp == NULL){
        printf(ERROR "\n ERRO: Falha ao ler arquivo! \n\n");
    } else {

        int num_reservas = numeroRecursos(arquivo);

        int id_reserva;
        char sala[8];
        char data_reserva[32];
        int duracao;
        int qntd_pessoas;
        int concluido;
        int atrasado;
        
        rewind(fp);
        for(int i = 0; i < num_reservas; i++){
            
            fscanf(fp, " %d;", &id_reserva);
            fscanf(fp, " %[^;];", sala);
            fscanf(fp, " %[^;];", data_reserva);
            fscanf(fp, " %d;", &duracao);
            fscanf(fp, " %d;", &qntd_pessoas);
            fscanf(fp, " %d;", &concluido);
            fscanf(fp, " %d;\n", &atrasado);

            (reservas + i)->id = id_reserva; 
            strcpy((reservas + i)->sala, sala);
            strcpy((reservas + i)->data_reserva, data_reserva);
            (reservas + i)->duracao = duracao; 
            (reservas + i)->qntd_pessoas = qntd_pessoas; 
            (reservas + i)->concluido = concluido; 
            (reservas + i)->atrasado = atrasado;
        }
    }

    fclose(fp);
}

// salvarLivros(<diretorio_arquivo>, <ponteiro_de_struct>, <numero_structs>)
void salvarLivros(char arquivo[], struct Livro *livros, int num_livros){

    FILE *fp = fopen(arquivo, "w");

    if(fp == NULL){
        printf(ERROR "\n ERRO: Falha ao ler arquivo! \n\n");
    } else {

        for(int i = 0; i < num_livros; i++){
            fprintf(fp, "%d;%s;%s;%s;%d;\n", (livros + i)->id, (livros + i)->nome, (livros + i)->autor, (livros + i)->categoria, (livros + i)->disponivel);
            fflush(fp);
        }

        system("clear");

        printf(SUCCESS "\n Livro(s) salvos com sucesso! \n");
    
    }
    
    fclose(fp);
}

// salvarCalculadoras(<diretorio_arquivo>, <ponteiro_de_struct>, <numero_structs>)
void salvarCalculadoras(char arquivo[], struct Calculadora *calculadoras, int num_calculadoras){
    FILE *fp = fopen(arquivo, "w");

    if(fp == NULL){
        printf(ERROR "\n ERRO: Falha ao ler arquivo! \n\n");
    } else {

        for(int i = 0; i < num_calculadoras; i++){
            fprintf(fp, "%d;%s;%s;%d;\n", (calculadoras + i)->id, (calculadoras + i)->modelo, (calculadoras + i)->marca, (calculadoras + i)->disponivel);
            fflush(fp);
        }

        system("clear");

        printf(SUCCESS "\n Calculadora(s) salvas com sucesso! \n");
    
    }
    
    fclose(fp);
}

// salvarFonesOuvido(<diretorio_arquivo>, <ponteiro_de_struct>, <numero_structs>)
void salvarFonesOuvido(char arquivo[], struct Fone_Ouvido *fones_ouvido, int num_fones){
    FILE *fp = fopen(arquivo, "w");

    if(fp == NULL){
        printf(ERROR "\n ERRO: Falha ao ler arquivo! \n\n");
    } else {

        for(int i = 0; i < num_fones; i++){
            fprintf(fp, "%d;%s;%s;%d;\n", (fones_ouvido + i)->id, (fones_ouvido + i)->modelo, (fones_ouvido + i)->marca, (fones_ouvido + i)->disponivel);
            fflush(fp);
        }

        system("clear");

        printf(SUCCESS "\n Fone(s) de Ouvido salvos com sucesso! \n");
    
    }
    
    fclose(fp);
}

// salvarSalas(<diretorio_arquivo>, <ponteiro_de_struct>, <numero_structs>)
void salvarSalas(char arquivo[], struct Sala *salas, int num_salas){
    FILE *fp = fopen(arquivo, "w");

    if(fp == NULL){
        printf(ERROR "\n ERRO: Falha ao ler arquivo! \n\n");
    } else {

        for(int i = 0; i < num_salas; i++){
            fprintf(fp, "%d;%s;%d;%d;\n", (salas + i)->id, (salas + i)->sala, (salas + i)->max_pessoas, (salas + i)->disponivel);
            fflush(fp);
        }

        system("clear");    
    }
    
    fclose(fp);
}

// salvarEmprestimo(<diretorio_arquivo>, <ponteiro_de_struct>)
void salvarEmprestimo(char arquivo[], struct Emprestimo *emprestimo){

    FILE *fp = fopen(arquivo, "a+");

    if(fp == NULL){
        printf(ERROR "\n ERRO: Falha ao ler arquivo! \n\n");
    } else {

        fprintf(fp, "%03d;%02d;%s;%s;%s;%s;%d;%d;\n", emprestimo->id, emprestimo->id_recurso, emprestimo->tipo_recurso, emprestimo->nome_recurso, emprestimo->data_emprestimo, emprestimo->data_devolucao, emprestimo->concluido, emprestimo->atrasado);
        fflush(fp);

        system("clear");

        printf(SUCCESS "\n %s salvo com sucesso! ", emprestimo->nome_recurso);
    
    }
    
    fclose(fp);
}

// concluirEmprestimo(<tipo_recurso>, <id_recurso>)
void concluirEmprestimo(char tipo_recurso[], int id_recurso){

    if(strcmp(tipo_recurso, "livro") == 0){

        char arquivo[] = "src/bd/livros.txt";
        int num_livros = numeroRecursos(arquivo);
        struct Livro *livros = malloc(sizeof(struct Livro) * num_livros);

        lerLivros(arquivo, livros);

        for(int i = 0; i < num_livros; i++){
            if(livros[i].id == id_recurso){
                livros[i].disponivel = 1;
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
            if(calculadoras[i].id == id_recurso){
                calculadoras[i].disponivel = 1;
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
            if(fones_ouvido[i].id == id_recurso){
                fones_ouvido[i].disponivel = 1;
            }
        }

        salvarFonesOuvido(arquivo, fones_ouvido, num_fones);

        free(fones_ouvido);
    }

}

void concluirReserva(char sala[]){

        char arquivo[] = "src/bd/salas.txt";
        int num_salas = numeroRecursos(arquivo);
        struct Sala *salas = malloc(sizeof(struct Livro) * num_salas);

        lerSalas(arquivo, salas);

        for(int i = 0; i < num_salas; i++){

            if(strcmp(salas[i].sala, sala) == 0){
                salas[i].disponivel = 1;
            }

        }

        salvarSalas(arquivo, salas, num_salas);

        free(salas);
}

// salvarReserva(<diretorio_arquivo>, <ponteiro_de_struct>)
void salvarReserva(char arquivo[], struct Reserva_Sala *sala){
    
    FILE *fp = fopen(arquivo, "a+");

    if(fp == NULL){
        printf(ERROR "\n ERRO: Falha ao ler arquivo! \n\n");
    } else {

        fprintf(fp, "%d;%s;%s;%d;%d;%d;%d;\n", sala->id, sala->sala, sala->data_reserva, sala->duracao, sala->qntd_pessoas, sala->concluido, sala->atrasado);
        fflush(fp);

        system("clear");

        printf(SUCCESS "\n Sala %s reservada com sucesso! ", sala->sala);
    
    }
    
    fclose(fp);
}

// salvarEmprestimos(<diretorio_arquivo>, <ponteiro_de_struct>)
void salvarEmprestimos(char arquivo[], struct Emprestimo *emprestimos, int num_emprestimos){
    FILE *fp = fopen(arquivo, "w");

    if(fp == NULL){
        printf(ERROR "\n ERRO: Falha ao ler arquivo! \n\n");
    } else {

        for(int i = 0; i < num_emprestimos; i++){
            fprintf(fp, "%03d;%02d;%s;%s;%s;%s;%d;%d;\n", (emprestimos + i)->id, (emprestimos + i)->id_recurso, (emprestimos + i)->tipo_recurso,(emprestimos + i)->nome_recurso, (emprestimos + i)->data_emprestimo, (emprestimos + i)->data_devolucao, (emprestimos + i)->concluido, (emprestimos + i)->atrasado);
            fflush(fp);
        }

        system("clear");    
    }
    
    fclose(fp);
}

// salvarReservas(<diretorio_arquivo>, <ponteiro_de_struct>, <numero_structs>)
void salvarReservas(char arquivo[], struct Reserva_Sala *salas, int num_reservas){
    FILE *fp = fopen(arquivo, "w");

    if(fp == NULL){
        printf(ERROR "\n ERRO: Falha ao ler arquivo! \n\n");
    } else {

        for(int i = 0; i < num_reservas; i++){
            fprintf(fp, "%d;%s;%s;%d;%d;%d;%d;\n", salas[i].id, salas[i].sala, salas[i].data_reserva, salas[i].duracao, salas[i].qntd_pessoas, salas[i].concluido, salas[i].atrasado);
            fflush(fp);
        }

        system("clear");
    }
    
    fclose(fp);
}
