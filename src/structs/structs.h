#ifndef STRUCTS_H
#define STRUCTS_H

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

// Estrutura Fone de Ouvido
struct Fone_Ouvido {
    int id;
    char modelo[16];
    char marca[16];
};

// Estrutura Sala de Estudos
struct Sala {
    char sala[4];
    int max_pessoas;
};

// Estrutura de Empréstimo
struct Emprestimo {
    int id;
    int id_recurso;
    char nome_recurso[32];

    char data_devolucao[8];
    int tempo_afastado;
};

// Estrutura de Reserva de Sala
struct Reserva_Sala {
    int id;
    int id_sala;
    char data_reserva[8];
    char horario_reserva[5];
    float duracao;
    int qntd_pessoas;
};


#endif