#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../themes/theme.h"
#include "arquivo.h"

int numeroLivros(char arquivo[]){
    FILE *fp = fopen(arquivo, "r");

    int num_livros = 0;
    char c;

    while((c = getc(fp)) != EOF){
        if(c == '\n'){
            num_livros++;
        }
    }

    return num_livros;
}

void lerLivros(char arquivo[], struct Livro *livros){

    FILE *fp = fopen(arquivo, "r");

    if(fp == NULL){
        printf(ERROR "\n ERRO: Falha ao ler arquivo! \n\n");
    } else {

        int num_livros = numeroLivros(arquivo);

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

        printf("\n Numero de Livros: %d \n", num_livros);

        printf("\n Numero de Bytes do Arquivo: %d bytes \n", num_bytes);

    }

    fclose(fp);
}

void salvarLivros(char arquivo[], struct Livro *livro){

    FILE *fp = fopen(arquivo, "a+");

    if(fp == NULL){
        printf(ERROR "\n ERRO: Falha ao ler arquivo! \n\n");
    } else {
        fprintf(fp, "%d;%s;%s;%s;\n", livro->id, livro->nome, livro->autor, livro->categoria);
        fflush(fp);
    }
    
    fclose(fp);
}