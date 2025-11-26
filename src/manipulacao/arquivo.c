#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../themes/theme.h"
#include "arquivo.h"

// Retorna o número de recursos de um arquivo
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
        
        int num_bytes = 0;
        
        char c;

        rewind(fp);
        while((c = getc(fp)) != EOF){
            num_bytes++;
        }

        
        rewind(fp);
        for(int i = 0; i < num_livros; i++){
            
            fscanf(fp, " %d;", &id);
            fscanf(fp, " %[^;];", nome);
            fscanf(fp, " %[^;];", autor);
            fscanf(fp, " %[^;];\n", categoria);

            (livros + i)->id = id;
            strcpy((livros + i)->nome, nome);
            strcpy((livros + i)->autor, autor);
            strcpy((livros + i)->categoria, categoria);
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
        
        int num_bytes = 0;
        
        char c;

        rewind(fp);
        while((c = getc(fp)) != EOF){
            num_bytes++;
        }

        
        rewind(fp);
        for(int i = 0; i < num_calculadoras; i++){
            
            fscanf(fp, " %d;", &id);
            fscanf(fp, " %[^;];", modelo);
            fscanf(fp, " %[^;];", marca);

            (calculadoras + i)->id = id;
            strcpy((calculadoras + i)->modelo, modelo);
            strcpy((calculadoras + i)->marca, marca);
        }
    }

    fclose(fp);
}   

void lerFonesOuvido(char arquivo[], struct Fone_Ouvido *fones_ouvido){
    FILE *fp = fopen(arquivo, "r+");

    if(fp == NULL){
        printf(ERROR "\n ERRO: Falha ao ler arquivo! \n\n");
    } else {

        int num_fones = numeroRecursos(arquivo);

        int id;
        char modelo[16];
        char marca[16];
        
        int num_bytes = 0;
        
        char c;

        rewind(fp);
        while((c = getc(fp)) != EOF){
            num_bytes++;
        }

        
        rewind(fp);
        for(int i = 0; i < num_fones; i++){
            
            fscanf(fp, " %d;", &id);
            fscanf(fp, " %[^;];", modelo);
            fscanf(fp, " %[^;];", marca);

            (fones_ouvido + i)->id = id;
            strcpy((fones_ouvido + i)->modelo, modelo);
            strcpy((fones_ouvido + i)->marca, marca);
        }
    }

    fclose(fp);
}

void lerSalas(char arquivo[], struct Sala *salas){
    FILE *fp = fopen(arquivo, "r+");

    if(fp == NULL){
        printf(ERROR "\n ERRO: Falha ao ler arquivo! \n\n");
    } else {

        int num_salas = numeroRecursos(arquivo);

        char sala[4];
        int max_pessoas;
        
        int num_bytes = 0;
        
        char c;

        rewind(fp);
        while((c = getc(fp)) != EOF){
            num_bytes++;
        }

        
        rewind(fp);
        for(int i = 0; i < num_salas; i++){
            
            fscanf(fp, " %[^;];", sala);
            fscanf(fp, " %d;", &max_pessoas);

            strcpy((salas + i)->sala, sala);
            (salas + i)->max_pessoas = max_pessoas;
        }
    }

    fclose(fp);
}

void lerEmprestimos(char arquivo[], struct Emprestimo *emprestimos){
    FILE *fp = fopen(arquivo, "r+");

    if(fp == NULL){
        printf(ERROR "\n ERRO: Falha ao ler arquivo! \n\n");
    } else {

        int num_emprestimos = numeroRecursos(arquivo);

        int id_emprestimo;
        int id_recurso;
        char nome_recurso[32];

        char data_devolucao[24];
        int tempo_afastado;
        
        int num_bytes = 0;
        
        char c;

        rewind(fp);
        while((c = getc(fp)) != EOF){
            num_bytes++;
        }

        
        rewind(fp);
        for(int i = 0; i < num_emprestimos; i++){
            
            fscanf(fp, " %d;", &id_emprestimo);
            fscanf(fp, " %d;", &id_recurso);
            fscanf(fp, " %[^;];", nome_recurso);
            fscanf(fp, " %[^;];", data_devolucao);
            fscanf(fp, " %d;", &tempo_afastado);

            (emprestimos + i)->id = id_emprestimo; 
            (emprestimos + i)->id_recurso = id_recurso; 
            strcpy((emprestimos + i)->nome_recurso, nome_recurso);
            strcpy((emprestimos + i)->data_devolucao, data_devolucao);
            (emprestimos + i)->tempo_afastado = tempo_afastado;
        }
    }

    fclose(fp);
}

// salvarLivros(<diretorio_arquivo>, <ponteiro_de_struct>, <numero_structs>)
void salvarLivros(char arquivo[], struct Livro *livros, int num_livros){

    FILE *fp = fopen(arquivo, "r+");

    if(fp == NULL){
        printf(ERROR "\n ERRO: Falha ao ler arquivo! \n\n");
    } else {

        for(int i = 0; i < num_livros; i++){
            fprintf(fp, "%d;%s;%s;%s;\n", (livros + i)->id, (livros + i)->nome, (livros + i)->autor, (livros + i)->categoria);
            fflush(fp);
        }

        system("clear");

        printf(SUCCESS "\n Livros salvos com sucesso! \n");
    
    }
    
    fclose(fp);
}

void salvarEmprestimos(char arquivo[], struct Emprestimo *emprestimo, int num_emprestimos){
    
    FILE *fp = fopen(arquivo, "a+");

    if(fp == NULL){
        printf(ERROR "\n ERRO: Falha ao ler arquivo! \n\n");
    } else {

        fprintf(fp, "%d;%d;%s;%s;%d\n", emprestimo->id, emprestimo->id_recurso, emprestimo->nome_recurso, emprestimo->data_devolucao, emprestimo->tempo_afastado);
        fflush(fp);

        system("clear");

        printf(SUCCESS "\n %s salvo com sucesso! \n", emprestimo->nome_recurso);
    
    }
    
    fclose(fp);
}