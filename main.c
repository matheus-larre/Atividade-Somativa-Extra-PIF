#include <stdio.h>
#include <stdlib.h>

/**
 * ATIVIDADE 3: Ponteiros para Structs
 * Definição da estrutura Produto contendo ID e Preço.
 */
typedef struct {
    int id;
    float preco;
} Produto;

/**
 * ATIVIDADE 2 e 3: Passagem por Referência
 * Função que aplica um desconto percentual diretamente na memória.
 * 
 * @param p_produto Ponteiro para a struct Produto (Atividade 3)
 * @param percentual Valor do desconto (float)
 */
void aplicar_desconto(Produto *p_produto, float percentual) {
    if (p_produto != NULL) {
        // Uso do operador seta (->) conforme Atividade 3
        float valor_desconto = p_produto->preco * (percentual / 100.0f);
        p_produto->preco -= valor_desconto;
    }
}

/**
 * ATIVIDADE 4: Aritmética de Ponteiros em Arrays
 * Função que percorre o array e imprime os dados usando aritmética de ponteiros.
 * 
 * @param ptr Ponteiro para o início do array de Produtos
 * @param quantidade Número de itens no array
 */
void imprimir_produtos(Produto *ptr, int quantidade) {
    printf("\n--- Relatorio de Estoque (Aritmetica de Ponteiros) ---\n");
    for (int i = 0; i < quantidade; i++) {
        // Obrigatório: (ptr + i)->campo sem usar colchetes []
        printf("ID: %d | Preco: R$ %.2f\n", 
               (ptr + i)->id, 
               (ptr + i)->preco);
    }
    printf("------------------------------------------------------\n");
}

int main() {
    // --- ATIVIDADE 1: Fundamentos de Ponteiros e Modificacao Direta ---
    float preco_base = 100.0f;
    float *ponteiro_float = &preco_base;
    
    // Aplicando aumento de 10% exclusivamente via ponteiro
    *ponteiro_float = *ponteiro_float * 1.10f;
    
    printf("Atividade 1 - Valor original alterado via ponteiro: R$ %.2f\n", preco_base);

    // --- ATIVIDADE 4 (Contexto): Array Estático de 3 Produtos ---
    // (O enunciado da Atividade 5 expande isso para dinamico, mas mantemos o conceito)
    printf("\n--- Demonstracao de Array Estatico (Atividade 4) ---\n");
    Produto estoque_estatico[3] = {
        {101, 50.0f},
        {102, 75.0f},
        {103, 120.0f}
    };
    imprimir_produtos(estoque_estatico, 3);

    // --- ATIVIDADE 5: Alocacao Dinamica de Memoria (malloc e free) ---
    int num_produtos;
    printf("\n--- Cadastro Dinamico (Atividade 5) ---\n");
    printf("Quantos produtos deseja cadastrar? ");
    scanf("%d", &num_produtos);

    // Verificacao de seguranca para quantidade
    if (num_produtos <= 0) {
        printf("Quantidade invalida. Encerrando programa.\n");
        return 0;
    }

    // Alocacao dinamica usando malloc
    Produto *estoque_dinamico = (Produto *) malloc(num_produtos * sizeof(Produto));

    // Tratamento de Erros: Verificar retorno do malloc
    if (estoque_dinamico == NULL) {
        fprintf(stderr, "Erro critico: Falha ao alocar memoria.\n");
        return 1;
    }

    // Preenchendo o array iterando com ponteiros
    for (int i = 0; i < num_produtos; i++) {
        Produto *p_item = (estoque_dinamico + i); // Aritmetica de ponteiros
        
        printf("\nProduto %d:\n", i + 1);
        printf("Digite o ID: ");
        scanf("%d", &(p_item->id));
        printf("Digite o Preco: ");
        scanf("%f", &(p_item->preco));

        // Chamada da Atividade 2/3: Passagem por referencia
        aplicar_desconto(p_item, 10.0f); // Aplicando 10% de desconto
        printf("Nota: Desconto de 10%% aplicado via ponteiro.\n");
    }

    // Imprimindo o array dinamico usando a funcao da Atividade 4
    imprimir_produtos(estoque_dinamico, num_produtos);

    // Liberação de memória (free) para evitar memory leaks
    free(estoque_dinamico);
    estoque_dinamico = NULL; // Evita ponteiro solto (dangling pointer)

    printf("\nMemoria liberada com sucesso. Fim da atividade.\n");

    return 0;
}
