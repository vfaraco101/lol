#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QTD_NOMES 5
#define TAM_NOME 100

// Função para remover a quebra de linha do final da string, se existir
void removeQuebraLinha(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// Função para inverter uma string (exceto se tiver 1 caractere ou menos)
void inverteString(char *str) {
    int len = strlen(str);
    if (len <= 1) return;

    for (int i = 0; i < len / 2; i++) {
        char aux = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = aux;
    }
}

int main() {
    char nomes[QTD_NOMES][TAM_NOME];
    char nomes_lidos[QTD_NOMES][TAM_NOME];

    // 1. Ler os nomes
    printf("Digite %d nomes completos:\n", QTD_NOMES);
    for (int i = 0; i < QTD_NOMES; i++) {
        printf("Nome %d: ", i + 1);
        fgets(nomes[i], TAM_NOME, stdin);
        removeQuebraLinha(nomes[i]);
    }

    // 2. Gravar no arquivo "nomes.txt"
    FILE *arquivo = fopen("nomes.txt", "w");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo nomes.txt");
        return 1;
    }
    for (int i = 0; i < QTD_NOMES; i++) {
        fprintf(arquivo, "%s\n", nomes[i]);
    }
    fclose(arquivo);

    // 3. Ler do arquivo para a segunda matriz
    arquivo = fopen("nomes.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo nomes.txt para leitura");
        return 1;
    }
    for (int i = 0; i < QTD_NOMES; i++) {
        if (fgets(nomes_lidos[i], TAM_NOME, arquivo) != NULL) {
            removeQuebraLinha(nomes_lidos[i]);
        }
    }
    fclose(arquivo);

    // 4. Exibir as duas matrizes
    printf("\nComparando os nomes digitados e lidos do arquivo:\n");
    for (int i = 0; i < QTD_NOMES; i++) {
        printf("Original: %-30s | Lido: %s\n", nomes[i], nomes_lidos[i]);
    }

    // 5. Inverter os nomes da segunda matriz
    for (int i = 0; i < QTD_NOMES; i++) {
        inverteString(nomes_lidos[i]);
    }

    // 6. Gravar os nomes invertidos em "nomes_invertidos.txt"
    arquivo = fopen("nomes_invertidos.txt", "w");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo nomes_invertidos.txt");
        return 1;
    }
    for (int i = 0; i < QTD_NOMES; i++) {
        fprintf(arquivo, "%s\n", nomes_lidos[i]);
    }
    fclose(arquivo);

    printf("\nNomes invertidos foram gravados em 'nomes_invertidos.txt'.\n");

    return 0;
}
