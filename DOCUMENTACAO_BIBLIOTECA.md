### Sistema de Biblioteca

- Gerenciador de Biblioteca, com funcionalidades de:
    > Empréstimo
    > Listagem de Itens Disponíveis
    > Listagem de Empréstimos
    > Fitro de Itens (livros, tablets, fones de ouvido, calculadora)
    > Controle de Devoluções

### Structs:

-   struct Usuario {
        codigo,
        nome,
        email
    }

-   struct Livro {
        codigo,
        nome,
        categoria,
        autor
    }

-   struct Calculadora {
        codigo,
        modelo,
        marca
    }

-   struct Tablet {
        codigo,
        modelo,
        marca
    }

-   struct Fone_Ouvido {
        codigo,
        modelo,
        marca
    }

-   struct Emprestimo {
        codigo_emprestimo,
        codigo_item,
        nome_item,
        codigo_usuario,
        nome_usuario,
        data_devolução,
        valor_multa **caso atrase**
    }

### Funcionalidades:

- **Administrador:**
    
    > Cadastrar / Remover Livros, Calculadoras, Tablets, Fones de Ouvido

    > Gerenciar Emprestimos

- **Usuário:**

    > Listar Livros, Calculadora, Tablets, Fones de Ouvido

    > Aplicar Filtros (categoria de livros, modelo de fone, etc.)

    > Realizar Emprestimos

### Construção:

- Para ***leitura e escrita*** no arquivo:
    > Ler o arquivo inteiro e salvar na memória (alocação dinâmica)
    > Realizar modificações
    > Salvar novamente no arquivo quando necessário