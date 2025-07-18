#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 8
float calculaMedia(float vetor1[], float vetor2[]) {
    float soma = 0.0;
    for (int i = 0; i < TAM; i++) {
        soma += vetor1[i];
        soma += vetor2[i];
    }
    return soma / (2 * TAM);
}
void calculaTaxaAprovacao(int totalAlunos, int aprovados, float *taxa) {
    if (totalAlunos == 0) {
        *taxa = 0.0;
    } else {
        *taxa = (aprovados * 100.0) / totalAlunos;
    }
}
float encontraMaior(float vetor1[], float vetor2[]) {
    float maior = vetor1[0];
    for (int i = 1; i < TAM; i++) {
        if (vetor1[i] > maior) maior = vetor1[i];
    }
    for (int i = 0; i < TAM; i++) {
        if (vetor2[i] > maior) maior = vetor2[i];
    }
    return maior;
}
int main() {
    float turmaA[TAM], turmaB[TAM];
    int aprovadosA = 0, aprovadosB = 0;
    float media, taxaA, taxaB;
    float maiorNota;
    srand(time(NULL));
    printf("Digite as notas da Turma A:\n");
    for (int i = 0; i < TAM; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%f", &turmaA[i]);
    }
    printf("\nNotas da Turma B (geradas aleatoriamente):\n");
    for (int i = 0; i < TAM; i++) {
        turmaB[i] = (rand() % 1001) / 100.0;
        printf("Nota %d: %.2f\n", i + 1, turmaB[i]);
    }
    media = calculaMedia(turmaA, turmaB);
    printf("\nMédia geral das notas: %.2f\n", media);
    maiorNota = encontraMaior(turmaA, turmaB);
    printf("\nMaior nota entre as duas turmas: %.2f\n", maiorNota);
    printf("\nNotas menores que a metade do maior valor (%.2f):\n", maiorNota / 2);
    for (int i = 0; i < TAM; i++) {
        if (turmaA[i] < maiorNota / 2)
            printf("Turma A - Nota %d: %.2f\n", i + 1, turmaA[i]);
        if (turmaB[i] < maiorNota / 2)
            printf("Turma B - Nota %d: %.2f\n", i + 1, turmaB[i]);
    }
    for (int i = 0; i < TAM; i++) {
        if (turmaA[i] >= 6.0) aprovadosA++;
        if (turmaB[i] >= 6.0) aprovadosB++;
    }
    calculaTaxaAprovacao(TAM, aprovadosA, &taxaA);
    calculaTaxaAprovacao(TAM, aprovadosB, &taxaB);
    printf("\nTaxa de aprovação Turma A: %.2f%% (%d de %d)\n", taxaA, aprovadosA, TAM);
    printf("Taxa de aprovação Turma B: %.2f%% (%d de %d)\n", taxaB, aprovadosB, TAM);
    return 0;
}
