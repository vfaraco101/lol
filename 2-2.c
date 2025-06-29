#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QTD_NOMES 5
#define TAM_NOME 100

void removeQuebraLinha(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

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

    printf("Digite %d nomes completos:\n", QTD_NOMES);
    for (int i = 0; i < QTD_NOMES; i++) {
        printf("Nome %d: ", i + 1);
        fgets(nomes[i], TAM_NOME, stdin);
        removeQuebraLinha(nomes[i]);
    }

    FILE *arquivo = fopen("nomes.txt", "w");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo nomes.txt");
        return 1;
    }
    for (int i = 0; i < QTD_NOMES; i++) {
        fprintf(arquivo, "%s\n", nomes[i]);
    }
    fclose(arquivo);

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

    printf("\nComparando os nomes digitados e lidos do arquivo:\n");
    for (int i = 0; i < QTD_NOMES; i++) {
        printf("Original: %-30s | Lido: %s\n", nomes[i], nomes_lidos[i]);
    }

    for (int i = 0; i < QTD_NOMES; i++) {
        inverteString(nomes_lidos[i]);
    }

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

    printf("\nNomes invertidos:\n");
    arquivo = fopen("nomes_invertidos.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo nomes_invertidos.txt\n");
        return 1;
    }
    char linha[100];
    while (fgets(linha, 100, arquivo))
    {
        printf("%s", linha);
    }
    fclose(arquivo);

    printf("\n\nNomes invertidos foram gravados no arquivo nomes_invertidos.txt\n");

    return 0;
}
