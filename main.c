#include <stdio.h>
#include <string.h>
#include "src/structs/structs.h"
#include "src/themes/theme.h"
#include "src/interfaces/interfaces.h"

int main(){

    // interfaceLogin(); 

    // interfaceInicial(1);
    
    struct Livro novoLivro;

    novoLivro.id = 1;
    strcpy(novoLivro.autor, "Machado de Assis");
    strcpy(novoLivro.nome, "Dom Casmurro");
    strcpy(novoLivro.categoria, "Romance");


    // TESTE - LEITURA / ESCRITA DE ARQUIVO =====================================

    FILE *fp;

    char file[] = "src/banco_de_dados_biblioteca/biblioteca.txt";

    fp = fopen(file, "a+");

    if(fp == NULL){
        printf(ERROR "\n ERRO: Falha ao ler arquivo! \n\n");
    } else {
        printf(SUCCESS "\n SUCESSO: Leitura concluída! \n\n");

        // fwrite(&novoLivro, sizeof(struct Livro), 1, fp);
        
        fprintf(fp, "%d|", novoLivro.id);
        fprintf(fp, "%s|", novoLivro.autor);
        fprintf(fp, "%s|", novoLivro.nome);
        fprintf(fp, "%s|\n", novoLivro.categoria);
    }

    fclose(fp);


    return 0;
}