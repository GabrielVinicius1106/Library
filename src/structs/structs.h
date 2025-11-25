#ifndef STRUCTS_H
#define STRUCTS_H

// permissao = 0 => Usuário Comum
// permissao = 1 => Usuário Administrador

// Estrutura Usuário
struct Usuario {
    int id;
    char nome[32];
    char senha[8];
    int permissao;
};

// Estrutura Livro
struct Livro {
    int id;
    char nome[32];
    char autor[32];
    char categoria[16];
};

// Estrutura Calculadora
struct Calculadora {
    int id;
    char modelo[8];
    char marca[8];
};

// Estrutura Tablet
struct Tablet {
    int id;
    char modelo[8];
    char marca[8];
};

// Estrutura Fone de Ouvido
struct Fone_Ouvido {
    int id;
    char modelo[8];
    char marca[8];
};

// Estrutura de Empréstimo
struct Emprestimo {
    int id;
    int id_recurso;
    char nome_recurso[32];

    int id_usuario;
    char nome_usuario[32];

    char data_devolucao[8];
    float valor_multa;
};

#endif