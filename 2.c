#include <stdio.h>

int main() {
    int quantidade, i;
    float preco, total = 0.0, media;
    float chute;

    // Solicita a quantidade de frutas vendidas
    printf("Informe quantas frutas foram vendidas: ");
    scanf("%d", &quantidade);

    // Loop determinado para ler os preços
    for (i = 1; i <= quantidade; i++) {
        printf("digite o preço da fruta %d: ", i);
        scanf("%f", &preco);
        total += preco;
    }

    // Calcula a média
    media = total / quantidade;

    // Loop indeterminado para os chutes do usuário
    while (1) {
        printf("Informe um valor em reais (0 ou negativo para sair): ");
        scanf("%f", &chute);

        if (chute <= 0) {
            break;
        }

        if (chute > media) {
            printf("errou pra mais!\n");
        } else if (chute == media) {
            printf("acertou a media\n");
        } else {
            printf("errou pra menos\n");
        }
    }

    return 0;
}
