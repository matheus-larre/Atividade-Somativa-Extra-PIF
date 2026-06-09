# Atividade Somativa Extra - Programação Imperativa e Funcional (PIF)

**Aluno:** Matheus Larré  
**Curso:** Análise e Desenvolvimento de Sistemas (ADS) - CESAR School  
**Professor:** Renan Costa Alencar  

## 📌 Visão Geral
Este projeto contempla a resolução de cinco atividades práticas focadas em fundamentos de baixo nível utilizando a linguagem C. O objetivo é demonstrar o domínio sobre ponteiros, estruturas de dados (structs) e o gerenciamento manual de memória RAM.

## 🛠️ Atividades Implementadas

### 1. Fundamentos de Ponteiros e Modificação Direta
- Manipulação de uma variável `float` exclusivamente através de um ponteiro.
- Aplicação de um aumento de 10% no valor original acessando o endereço de memória.

### 2. Passagem por Referência
- Encapsulamento da lógica em uma função `aplicar_desconto`.
- Modificação do valor original na memória sem a necessidade de retorno da função (`void`).

### 3. Ponteiros para Structs
- Agrupamento de dados em uma `struct Produto` (ID e Preço).
- Uso do operador seta (`->`) para acesso e modificação de membros da estrutura via ponteiro.

### 4. Aritmética de Ponteiros em Arrays
- Implementação de função para percorrer vetores utilizando estritamente aritmética de ponteiros.
- Restrição técnica: Proibição do uso de índices de colchetes `[]` na iteração do array, utilizando `(ptr + i)`.

### 5. Alocação Dinâmica de Memória (malloc e free)
- Transição do limite estático para o dinâmico.
- Uso de `malloc` para alocação no **Heap**.
- Tratamento de erros para garantir a integridade do sistema em caso de falha de memória.
- Uso de `free` para prevenir *memory leaks*.

## 🧠 Explicação Técnica: Stack vs Heap

Durante a execução deste programa, dois segmentos de memória são utilizados:
- **Stack (Pilha):** Utilizada para variáveis locais e chamadas de funções. É automática e rápida, mas de tamanho fixo.
- **Heap (Monte):** Utilizada na Atividade 5 para alocação em tempo de execução. Permite flexibilidade de tamanho, mas exige que o desenvolvedor gerencie o ciclo de vida dos dados manualmente (`free`).

## ⚙️ Como Compilar e Executar

Para compilar o projeto utilizando o GCC:
```bash
gcc -o atividade_pif main.c
```

Para executar:
```bash
./atividade_pif
```

---
*Projeto desenvolvido para fins acadêmicos na CESAR School.*
