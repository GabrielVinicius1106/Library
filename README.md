# Biblioteca de Empréstimos e Reservas

Este projeto é um sistema de gerenciamento de biblioteca para empréstimo e reserva de recursos como livros, calculadoras, fones de ouvido e salas. O sistema é implementado em C e utiliza arquivos texto para persistência dos dados.

## Objetivo

O objetivo do projeto é fornecer uma aplicação de linha de comando para gerenciar:
- Empréstimos e devoluções de livros, calculadoras e fones de ouvido
- Reservas de salas
- Controle de disponibilidade dos recursos
- Listagem de recursos, empréstimos e reservas

## Funcionalidades Disponíveis

- **Listagem de Recursos**: Visualize todos os livros, calculadoras, fones de ouvido e salas disponíveis para empréstimo ou reserva.
- **Empréstimo de Recursos**: Realize empréstimos de livros, calculadoras e fones de ouvido, com controle de disponibilidade e data de devolução.
- **Reserva de Salas**: Permite reservar salas, informando data, horário, duração e quantidade de pessoas.
- **Listagem de Empréstimos e Reservas**: Consulte todos os empréstimos e reservas realizados.
- **Conclusão de Empréstimos e Reservas**: Marque recursos como devolvidos ou reservas como concluídas, tornando-os novamente disponíveis.
- **Validação de Disponibilidade**: O sistema impede empréstimos ou reservas de itens indisponíveis.

## Estrutura do Projeto

```
Library/
├── compile.bat / compile.sh         # Scripts de compilação (Windows/Linux)
├── run.bat / run.sh                 # Scripts de execução (Windows/Linux)
├── main.c                           # Arquivo principal
├── src/                             # Código-fonte
│   ├── bd/                          # Arquivos de dados (txt)
│   ├── datas/                       # Manipulação de datas
│   ├── input/                       # Funções de entrada
│   ├── interfaces/                  # Interfaces do usuário
│   ├── manipulacao/                 # Leitura e escrita de arquivos
│   ├── structs/                     # Definição de structs
│   ├── themes/                      # Temas e cores para terminal
│   └── utils/                       # Funções utilitárias
└── DOCUMENTACAO_BIBLIOTECA.md       # Documentação detalhada
```

## Como Compilar e Executar

### No Linux

1. **Compilar:**
   ```bash
   ./compile.sh
   ```
   ou
   ```bash
   bash compile.sh
   ```

2. **Executar:**
   ```bash
   ./run.sh
   ```
   ou
   ```bash
   bash run.sh
   ```

### No Windows

1. **Compilar:**
   Clique duas vezes em `compile.bat` ou execute no Prompt de Comando:
   ```bat
   compile.bat
   ```

2. **Executar:**
   Clique duas vezes em `run.bat` ou execute no Prompt de Comando:
   ```bat
   run.bat
   ```

## Observações
- Os arquivos de dados ficam em `src/bd/` e são essenciais para o funcionamento do sistema.
- O sistema utiliza apenas a linha de comando e não possui interface gráfica.
- Para mais detalhes sobre as funções e estrutura, consulte o arquivo `DOCUMENTACAO_BIBLIOTECA.md`.

---
Desenvolvido para fins acadêmicos na disciplina de Linguagem de Programação.
