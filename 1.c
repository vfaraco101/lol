resultado:
#include <stdio.h>

#define PRIMEIRA 21
#define ULTIMA 6

int main() {
    int quantidade_1, quantidade_2;
    float valor;

    printf("digite a quantia\n");
    scanf("%d", &quantidade_1);

    printf("digite a quantia\n");
    scanf("%d", &quantidade_2);

    valor = (quantidade_1 + quantidade_2) * (ULTIMA - PRIMEIRA) / 2.0;

    if (valor > quantidade_1) {
        printf("o resuldado é %f e as quantidades são %d e %d\n", valor, quantidade_1, quantidade_2);
    } else {
        printf("o resultado é %f e as quantdades são %d e %d\n", valor * 0.8, quantidade_1, quantidade_2);
    }

    return 0;
}
