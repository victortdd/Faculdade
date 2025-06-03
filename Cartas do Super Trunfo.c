#include <stdio.h>
#include <string.h>

void removerQuebraDeLinha(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

float getValor(int attr, int carta, int pop1, int pop2, float area1, float area2, float pib1, float pib2,
               int pt1, int pt2, float dens1, float dens2, float ppc1, float ppc2) {
    switch (attr) {
        case 1: return carta == 1 ? pop1 : pop2;
        case 2: return carta == 1 ? area1 : area2;
        case 3: return carta == 1 ? pib1 : pib2;
        case 4: return carta == 1 ? pt1 : pt2;
        case 5: return carta == 1 ? dens1 : dens2;
        case 6: return carta == 1 ? ppc1 : ppc2;
        default: return 0;
    }
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

    int attr1, attr2;
    float valor1_attr1, valor2_attr1;
    float valor1_attr2, valor2_attr2;

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
    densidade2 = populacao2 / area2;

    pibPerCapita1 = (pib1 * 1000000000) / populacao1;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2;

    printf("\n===== MENU DE COMPARAÇÃO - ESCOLHA DOIS ATRIBUTOS =====\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Demográfica\n6 - PIB per Capita\n");

    printf("Escolha o 1º atributo para comparação: ");
    scanf("%d", &attr1);

    printf("Escolha o 2º atributo para comparação (diferente do primeiro): ");
    scanf("%d", &attr2);

    if (attr1 == attr2 || attr1 < 1 || attr1 > 6 || attr2 < 1 || attr2 > 6) {
        printf("Atributos inválidos ou repetidos. Reinicie o programa.\n");
        return 1;
    }

    valor1_attr1 = getValor(attr1, 1, populacao1, populacao2, area1, area2, pib1, pib2,
                            pontosTuristicos1, pontosTuristicos2, densidade1, densidade2, pibPerCapita1, pibPerCapita2);
    valor2_attr1 = getValor(attr1, 2, populacao1, populacao2, area1, area2, pib1, pib2,
                            pontosTuristicos1, pontosTuristicos2, densidade1, densidade2, pibPerCapita1, pibPerCapita2);
    valor1_attr2 = getValor(attr2, 1, populacao1, populacao2, area1, area2, pib1, pib2,
                            pontosTuristicos1, pontosTuristicos2, densidade1, densidade2, pibPerCapita1, pibPerCapita2);
    valor2_attr2 = getValor(attr2, 2, populacao1, populacao2, area1, area2, pib1, pib2,
                            pontosTuristicos1, pontosTuristicos2, densidade1, densidade2, pibPerCapita1, pibPerCapita2);

    float soma1 = valor1_attr1 + valor1_attr2;
    float soma2 = valor2_attr1 + valor2_attr2;

    printf("\nComparando %s (%s) x %s (%s)\n", cidade1, estado1, cidade2, estado2);
    printf("Atributo %d: %s = %.2f | %s = %.2f\n", attr1, cidade1, valor1_attr1, cidade2, valor2_attr1);
    printf("Atributo %d: %s = %.2f | %s = %.2f\n", attr2, cidade1, valor1_attr2, cidade2, valor2_attr2);

    printf("\nSoma dos Atributos:\n");
    printf("%s: %.2f\n", cidade1, soma1);
    printf("%s: %.2f\n", cidade2, soma2);

    printf("Resultado Final: ");
    if (soma1 > soma2)
        printf("%s venceu!\n", cidade1);
    else if (soma2 > soma1)
        printf("%s venceu!\n", cidade2);
    else
        printf("Empate!\n");

    return 0;
}