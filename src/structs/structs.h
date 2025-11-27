#ifndef STRUCTS_H
#define STRUCTS_H

// Estrutura Livro
struct Livro {
    int id;
    char nome[32];
    char autor[32];
    char categoria[16];
    int disponivel;
};

// Estrutura Calculadora
struct Calculadora {
    int id;
    char modelo[8];
    char marca[8];
    int disponivel;
};

// Estrutura Fone de Ouvido
struct Fone_Ouvido {
    int id;
    char modelo[16];
    char marca[16];
    int disponivel;
};

// Estrutura Sala de Estudos
struct Sala {
    int id;
    char sala[8];
    int max_pessoas;
    int disponivel;
};

// calculadora

// Estrutura de Empréstimo
struct Emprestimo {
    int id;
    int id_recurso;
    char tipo_recurso[12];

    char nome_recurso[32];
    char data_devolucao[32];
    int concluido;
};

// Estrutura de Reserva de Sala
struct Reserva_Sala {
    int id;
    char sala[8];
    char data_reserva[16];
    char horario_reserva[16];
    int duracao;
    int qntd_pessoas;
    int concluido;
};

// Estrutura de Data
struct Data {
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
};


#endif