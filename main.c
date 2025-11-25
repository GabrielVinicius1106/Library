#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "src/structs/structs.h"
#include "src/themes/theme.h"
#include "src/interfaces/interfaces.h"
#include "src/manipulacao/arquivo.h"

int main(){ 

    struct Livro livros[3] = {
        {1, "Teste Nome", "Teste Autor", "Teste Categoria"},
        {3, "Teste Nome", "Teste Autor", "Teste Categoria"},
        {4, "Teste Nome", "Teste Autor", "Teste Categoria"}
    };

    // struct Livro livro = {2, "nome teste", "autor denovo", "categoriaa"};

    char arquivo_livros[] = "src/bd/livros.txt";
    
    struct Livro *livros_bd = malloc(sizeof(struct Livro) * 3);
    
    int num_livros = numeroLivros(arquivo_livros);
        
    // salvarLivros(arquivo_livros, livros, numeroLivros(arquivo_livros));


    livros_bd = realloc(livros_bd, sizeof(struct Livro) * num_livros);

    lerLivros(arquivo_livros, livros_bd);

    for(int i = 0; i < num_livros; i++){
        printf("\n ID: %d ", (livros_bd + i)->id);
        printf("\n Nome: %s ", (livros_bd + i)->nome);
        printf("\n Autor: %s ", (livros_bd + i)->autor);
        printf("\n Categoria: %s \n", (livros_bd + i)->categoria);
    }

    return 0;
}