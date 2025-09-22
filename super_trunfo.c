#include <stdio.h>

int main() {
    // Declaração das variáveis

    char uf1, uf2; // O código do estado será apenas um caracter, representando um dos 8 estados disponíveis (foi a quantidade solicitada...)
    char codigo1[4], codigo2[4]; // O código precisa permitir até 3 caracters + o \0 indicando o fim da string
    char Cidade1[50], Cidade2[50]; // O nome da cidade pode ter até 49 caracters  + o \0, conforme descrevi acima
    int pop1, pop2, pontosTuristicos1, pontosTuristicos2; // População e pontos turísticos são todos em números inteiros
    float area1, area2, pib1, pib2; // Área e PIB precisam ser float para permitir o uso de cadas decimais

    /* Como ainda não é para usar nenhum tipo de laço, cada carta precisa ter sua própria requisição de dados
    A seguir, cada linha irá pedir ao usuário que digite algo (código da carta, nome da cidade, etc) e a linha seguinte irá capturar essa informação */

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

    // Após o cadastro, as linhas a seguir irão mostrar na tela o que foi cadastrado pelo usuário nos blocos de código anteriores

    printf("\nCarta 1:\n");
    printf("Estado: %c\n", uf1);
    printf("Codigo: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", Cidade1);
    printf("Populacao: %d\n", pop1);
    printf("Area: %.2f km²\n", area1);
    printf("PIB: %.2f bilhoes de reais\n", pib1);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos1);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", uf2);
    printf("Codigo: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", Cidade2);
    printf("Populacao: %d\n", pop2);
    printf("Area: %.2f km²\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos2);

    return 0;
}
