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

    int opcao;

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

    printf("\n===== MENU DE COMPARAÇÃO =====\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("6 - PIB per Capita\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    printf("\nComparando %s (%s) x %s (%s)\n", cidade1, estado1, cidade2, estado2);

    switch (opcao) {
        case 1:
            printf("População:\n");
            printf("%s: %d | %s: %d\n", cidade1, populacao1, cidade2, populacao2);
            if (populacao1 > populacao2)
                printf("Resultado: %s venceu!\n", cidade1);
            else if (populacao2 > populacao1)
                printf("Resultado: %s venceu!\n", cidade2);
            else
                printf("Resultado: Empate!\n");
            break;

        case 2:
            printf("Área:\n");
            printf("%s: %.2f km² | %s: %.2f km²\n", cidade1, area1, cidade2, area2);
            if (area1 > area2)
                printf("Resultado: %s venceu!\n", cidade1);
            else if (area2 > area1)
                printf("Resultado: %s venceu!\n", cidade2);
            else
                printf("Resultado: Empate!\n");
            break;

        case 3:
            printf("PIB:\n");
            printf("%s: %.2f bilhões | %s: %.2f bilhões\n", cidade1, pib1, cidade2, pib2);
            if (pib1 > pib2)
                printf("Resultado: %s venceu!\n", cidade1);
            else if (pib2 > pib1)
                printf("Resultado: %s venceu!\n", cidade2);
            else
                printf("Resultado: Empate!\n");
            break;

        case 4:
            printf("Pontos Turísticos:\n");
            printf("%s: %d | %s: %d\n", cidade1, pontosTuristicos1, cidade2, pontosTuristicos2);
            if (pontosTuristicos1 > pontosTuristicos2)
                printf("Resultado: %s venceu!\n", cidade1);
            else if (pontosTuristicos2 > pontosTuristicos1)
                printf("Resultado: %s venceu!\n", cidade2);
            else
                printf("Resultado: Empate!\n");
            break;

        case 5:
            printf("Densidade Demográfica (quanto menor, melhor):\n");
            printf("%s: %.2f hab/km² | %s: %.2f hab/km²\n", cidade1, densidade1, cidade2, densidade2);
            if (densidade1 < densidade2)
                printf("Resultado: %s venceu!\n", cidade1);
            else if (densidade2 < densidade1)
                printf("Resultado: %s venceu!\n", cidade2);
            else
                printf("Resultado: Empate!\n");
            break;

        case 6:
            printf("PIB per Capita:\n");
            printf("%s: %.2f | %s: %.2f\n", cidade1, pibPerCapita1, cidade2, pibPerCapita2);
            if (pibPerCapita1 > pibPerCapita2)
                printf("Resultado: %s venceu!\n", cidade1);
            else if (pibPerCapita2 > pibPerCapita1)
                printf("Resultado: %s venceu!\n", cidade2);
            else
                printf("Resultado: Empate!\n");
            break;

        default:
            printf("Opção inválida. Escolha um número de 1 a 6.\n");
    }

    return 0;
}
