#include <stdio.h>
#include <string.h>

void removerQuebraDeLinha(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

int main() {
    char estado1[3], codigo1[5], cidade1[100];
    int populacao1, pontosTuristicos1;
    float area1, pib1;
    float densidade1, pibPerCapita1;

    char estado2[3], codigo2[5], cidade2[100];
    int populacao2, pontosTuristicos2;
    float area2, pib2;
    float densidade2, pibPerCapita2;

    printf("== Cadastro da Carta 1 ==\n");
    printf("Estado: ");
    fgets(estado1, sizeof(estado1), stdin);
    removerQuebraDeLinha(estado1);

    printf("Código: ");
    fgets(codigo1, sizeof(codigo1), stdin);
    removerQuebraDeLinha(codigo1);

    printf("Nome da cidade: ");
    fgets(cidade1, sizeof(cidade1), stdin);
    removerQuebraDeLinha(cidade1);

    printf("População: ");
    scanf("%d", &populacao1);

    printf("Área (km²): ");
    scanf("%f", &area1);

    printf("PIB (em bilhões): ");
    scanf("%f", &pib1);

    printf("Pontos turísticos: ");
    scanf("%d", &pontosTuristicos1);

    getchar();

    printf("\n== Cadastro da Carta 2 ==\n");
    printf("Estado: ");
    fgets(estado2, sizeof(estado2), stdin);
    removerQuebraDeLinha(estado2);

    printf("Código: ");
    fgets(codigo2, sizeof(codigo2), stdin);
    removerQuebraDeLinha(codigo2);

    printf("Nome da cidade: ");
    fgets(cidade2, sizeof(cidade2), stdin);
    removerQuebraDeLinha(cidade2);

    printf("População: ");
    scanf("%d", &populacao2);

    printf("Área (km²): ");
    scanf("%f", &area2);

    printf("PIB (em bilhões): ");
    scanf("%f", &pib2);

    printf("Pontos turísticos: ");
    scanf("%d", &pontosTuristicos2);

    densidade1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000) / populacao1;

    densidade2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2;

    printf("\n=== Comparação de Cartas (Atributo: População) ===\n");
    printf("Carta 1 - %s (%s): %d habitantes\n", cidade1, estado1, populacao1);
    printf("Carta 2 - %s (%s): %d habitantes\n", cidade2, estado2, populacao2);

    if (populacao1 > populacao2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
    } else if (populacao2 > populacao1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
