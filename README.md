
# Sistema de Gerenciamento de Biblioteca

> **Projeto desenvolvido por Gabriel Vinícius**

Este projeto é um sistema completo de gerenciamento de biblioteca, desenvolvido em C, que permite o controle de empréstimos e reservas de recursos como livros, calculadoras, fones de ouvido e salas. Todos os dados são persistidos em arquivos texto, garantindo fácil manutenção e portabilidade.

---

## Funcionalidades Principais

- **Listagem de Recursos**: Visualize todos os livros, calculadoras, fones de ouvido e salas disponíveis.
- **Empréstimo de Livros, Calculadoras e Fones de Ouvido**: Controle de disponibilidade, registro de empréstimos e devoluções.
- **Reserva de Salas**: Permite reservar salas informando data, horário, duração e quantidade de pessoas.
- **Listagem de Empréstimos e Reservas**: Consulte todos os empréstimos e reservas realizados.
- **Conclusão de Empréstimos e Reservas**: Marque recursos como devolvidos ou reservas como concluídas, tornando-os novamente disponíveis.
- **Validação de Disponibilidade**: O sistema impede empréstimos ou reservas de itens indisponíveis.
- **Controle de Usuários**: Acesso diferenciado para administradores e usuários comuns.
- **Interface de Linha de Comando**: Navegação simples e intuitiva pelo terminal.

---

## Estrutura da Aplicação

```
Library/
├── compile.bat / compile.sh         # Scripts de compilação (Windows/Linux)
├── run.bat / run.sh                 # Scripts de execução (Windows/Linux)
├── main.c                           # Arquivo principal
├── src/
│   ├── bd/                          # Arquivos de dados (txt)
│   ├── datas/                       # Manipulação de datas
│   ├── input/                       # Funções de entrada
│   ├── interfaces/                  # Interfaces do usuário
│   ├── manipulacao/                 # Leitura e escrita de arquivos
│   ├── structs/                     # Definição de structs
│   ├── themes/                      # Temas e cores para terminal
│   └── utils/                       # Funções utilitárias
├── DOCUMENTACAO_BIBLIOTECA.md       # Documentação detalhada
└── BANCO_DADOS.txt                  # Exemplo de dados para popular o sistema
```

---

## Como Funciona

O sistema é executado via terminal e apresenta um menu inicial para seleção do tipo de usuário (Administrador ou Usuário Comum). Cada perfil possui permissões específicas:

- **Administrador**: Acesso total a todas as funcionalidades, incluindo cadastro, remoção e edição de recursos.
- **Usuário Comum**: Pode visualizar, reservar e devolver recursos, conforme disponibilidade.

Todas as operações são registradas em arquivos texto localizados em `src/bd/`, facilitando a consulta e manutenção dos dados.

---

## Como Executar

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

---

## Como Utilizar

1. **Selecione o tipo de usuário** ao iniciar o sistema.
2. **Navegue pelos menus** para listar, emprestar, reservar ou devolver recursos.
3. **Siga as instruções** exibidas no terminal para cada operação.
4. **Consulte a documentação** (`DOCUMENTACAO_BIBLIOTECA.md`) para detalhes sobre cada funcionalidade.

---


## Observações

- Os arquivos de dados ficam em `src/bd/` e são essenciais para o funcionamento do sistema.
- O sistema utiliza apenas a linha de comando e não possui interface gráfica.
- Para mais detalhes sobre as funções e estrutura, consulte o arquivo `DOCUMENTACAO_BIBLIOTECA.md`.

### ⚠️ Permissão de Execução no Linux

Ao compilar o projeto, o executável `compile.sh` e `run.sh` podem precisar de permissão de execução. Caso ocorra erro de permissão ao executar, utilize o comando abaixo no terminal:

```bash
chmod +x compile.sh
```

```bash
chmod +x run.sh
```

---

**Projeto desenvolvido por Gabriel Vinícius. Todos os direitos reservados.**

---
Desenvolvido para fins acadêmicos na disciplina de Linguagem de Programação.
