#include <stdio.h>

int main() {
    // Declaração das variáveis, algumas variáveis de tipo igual foram separadas para facilitar a leitura, mas dá na mesma

    char uf1, uf2; // O código do estado será apenas um caracter, representando um dos 8 estados disponíveis (foi a quantidade solicitada...)
    char codigo1[4], codigo2[4]; // O código precisa permitir até 3 caracteres + o \0 indicando o fim da string
    char Cidade1[50], Cidade2[50]; // O nome da cidade pode ter até 49 caracteres + o \0
    int pop1, pop2, pontosTuristicos1, pontosTuristicos2; // População e pontos turísticos são todos em números inteiros
    float area1, area2, pib1, pib2; // Área e PIB precisam ser float para permitir o uso de casas decimais
    float dens1, dens2, pibpc1, pibpc2; // Densidade populacional e PIB per capita também são valores reais
    float v1, v2; // Valores do atributo escolhido para comparação
    int cartaVencedora = 0; // 0 = empate, 1 = carta1, 2 = carta2

 
    // A seguir, cada linha irá pedir ao usuário que digite algo (código da carta, nome da cidade, etc.) e a linha seguinte irá capturar essa informação. 

    printf("Cadastro da Carta 1:\n"); 
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &uf1);

    printf("Digite o Codigo da Carta (ex: A01): ");
    scanf("%s", codigo1);

    printf("Digite o Nome da Cidade (sem espacos): ");
    scanf("%s", Cidade1);

    printf("Digite a Populacao: ");
    scanf("%d", &pop1);

    printf("Digite a Area (em km²): ");
    scanf("%f", &area1);

    printf("Digite o PIB (em bilhoes de reais): ");
    scanf("%f", &pib1);

    printf("Digite o Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos1);

    printf("\nCadastro da Carta 2:\n");
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &uf2);

    printf("Digite o Codigo da Carta (ex: B03): ");
    scanf("%s", codigo2);

    printf("Digite o Nome da Cidade (sem espacos): ");
    scanf("%s", Cidade2);

    printf("Digite a Populacao: ");
    scanf("%d", &pop2);

    printf("Digite a Area (em km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB (em bilhoes de reais): ");
    scanf("%f", &pib2);

    printf("Digite o Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculo da densidade populacional e PIB per capita
    dens1  = (double)pop1 / area1; // Densidade populacional = população / área
    dens2  = (double)pop2 / area2;
    pibpc1 = (pib1 * 1000000000.0) / (double)pop1; // PIB per capita = (PIB em R$) / população (o PIB é digitado em bilhões, mas o usário provavelmente não vai digitar todos os dígitos, então aqui eu fiz o valor digitado ser multiplicado por 1000000000
    pibpc2 = (pib2 * 1000000000.0) / (double)pop2;

    // Após o cadastro, as linhas a seguir irão mostrar na tela o que foi cadastrado pelo usuário

    printf("\nCarta 1:\n");
    printf("Estado: %c\n", uf1);
    printf("Codigo: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", Cidade1);
    printf("Populacao: %d\n", pop1);
    printf("Area: %.2f km²\n", area1);
    printf("PIB: %.2f bilhoes de reais\n", pib1);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", dens1);
    printf("PIB per capita: R$ %.2f\n", pibpc1);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", uf2);
    printf("Codigo: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", Cidade2);
    printf("Populacao: %d\n", pop2);
    printf("Area: %.2f km²\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", dens2);
    printf("PIB per capita: R$ %.2f\n", pibpc2);

    // Comparação entre as cartas
    // O atributo selecionado para comparação é: DENSIDADE POPULACIONAL
    v1 = dens1;
    v2 = dens2;

    printf("\nComparacao de cartas (Atributo: Densidade Populacional):\n");
    printf("Carta 1 - %s (%c): %.2f hab/km²\n", Cidade1, uf1, dens1);
    printf("Carta 2 - %s (%c): %.2f hab/km²\n", Cidade2, uf2, dens2);

    // Determinação da carta vencedora (menor densidade vence)
    if (v1 < v2)
        cartaVencedora = 1;
    else if (v2 < v1)
        cartaVencedora = 2;
    else
        cartaVencedora = 0;

    // Exibição do resultado da comparação
    if (cartaVencedora == 1)
        printf("Resultado: Carta 1 (%s) venceu!\n", Cidade1);
    else if (cartaVencedora == 2)
        printf("Resultado: Carta 2 (%s) venceu!\n", Cidade2);
    else
        printf("Resultado: Empate!\n");

    return 0;
}
