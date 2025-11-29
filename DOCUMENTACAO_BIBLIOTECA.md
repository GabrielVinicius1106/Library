### Sistema de Biblioteca

- Gerenciador de Biblioteca, com funcionalidades de:
    > Empréstimo de Recursos
    > Reserva de Sala

    > Listagem de Itens Disponíveis
    > Listagem de Empréstimos
    > Listagem de Reservas
    > Listagem de Empréstimos / Reservas Atrasadas

    > Persistência de dados em arquivos .txt

### Structs:

-   struct Livro {
        id,
        nome,
        autor,
        categoria,
        disponivel
    }

-   struct Calculadora {
        id,
        modelo,
        marca,
        disponivel
    }

-   struct Fone_Ouvido {
        id,
        modelo,
        marca,
        disponivel
    }

-   struct Sala {
        id,
        sala,
        max_pessoas,
        disponivel
    }

-   struct Emprestimo {
        id,
        id_recurso,
        tipo_recurso,
        nome_recurso,
        data_emprestimo,
        data_devolução,
        concluido,
        atrasado
    }

-   struct Reserva_Sala {
        id,
        sala,
        data_reserva,
        duracao,
        qntd_pessoas,
        concluido,
        atrasado
    }

-   struct Data {
        dia,
        mes,
        ano,
        hora,
        minuto
    }

### Funcionalidades:

- **Administrador:**
    
    > Cadastrar, Remover e Editar Recursos (livros, calculadoras, fones de ouvido e salas)

- **Usuário:**

    > Listar Livros, Calculadora, Fones de Ouvido

    > Realizar Emprestimos

    > Realizar Reservas

### Funcionalidades NÃO IMPLEMENTADAS:

- Aplicar FILTRO na LISTAGEM de Recursos
- Aplicar MULTA nos EMPRÉSTIMOS ATRASADOS
- BLOQUEIO de Usuário com ATRASOS
- Pagamento de MULTAS