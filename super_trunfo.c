#include <stdio.h>

int main() {
    // Declaração das variáveis, algumas variáveis de tipo igual foram separadas para facilitar a leitura, mas dá na mesma

    char uf1, uf2; // O código do estado será apenas um caracter, representando um dos 8 estados disponíveis (foi a quantidade solicitada...)
    char codigo1[4], codigo2[4]; // O código precisa permitir até 3 caracteres + o \0 indicando o fim da string
    char Cidade1[50], Cidade2[50]; // O nome da cidade pode ter até 49 caracteres + o \0
    int pop1, pop2, pontosTuristicos1, pontosTuristicicos2; // População e pontos turísticos são todos em números inteiros
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
    scanf("%d", &pontosTuristicicos1);

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
    scanf("%d", &pontosTuristicicos2);

    // Cálculo da densidade populacional e PIB per capita
    dens1  = (float)pop1 / area1; // Densidade populacional = população / área
    dens2  = (float)pop2 / area2;
    pibpc1 = (pib1 * 1000000000.0) / (double)pop1; /* PIB per capita = (PIB em R$) / população (o PIB é digitado em bilhões, 
    então aqui multiplico por 1000000000 para converter) */
    pibpc2 = (pib2 * 1000000000.0) / (double)pop2;

    // Após o cadastro, as linhas a seguir irão mostrar na tela o que foi cadastrado pelo usuário

    printf("\nCarta 1:\n");
    printf("Estado: %c\n", uf1);
    printf("Codigo: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", Cidade1);
    printf("Populacao: %d\n", pop1);
    printf("Area: %.2f km²\n", area1);
    printf("PIB: %.2f bilhoes de reais\n", pib1);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", dens1);
    printf("PIB per capita: R$ %.2f\n", pibpc1);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", uf2);
    printf("Codigo: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", Cidade2);
    printf("Populacao: %d\n", pop2);
    printf("Area: %.2f km²\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", dens2);
    printf("PIB per capita: R$ %.2f\n", pibpc2);

    // Menu interativo para escolher o atributo de comparação
    // Opções: 1-Nome (apenas exibir), 2-Populacao, 3-Area, 4-PIB, 5-Pontos Turisticos, 6-Densidade
    int opcao; // guarda a escolha do jogador
    printf("\nEscolha o atributo para comparacao:\n");
    printf(" 1 - Nome do pais (apenas exibe)\n");
    printf(" 2 - Populacao\n");
    printf(" 3 - Area\n");
    printf(" 4 - PIB\n");
    printf(" 5 - Numero de pontos turisticos\n");
    printf(" 6 - Densidade demografica (menor vence)\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    // Switch define qual atributo será comparado e exibe o cabeçalho apropriado
    switch (opcao) {
        case 1:
            // Nome do país/cidade não é comparável diretamente (string), só exibimos os nomes.
            printf("\nAtributo: Nome (sem comparacao)\n");
            printf("Carta 1: %s | Carta 2: %s\n", Cidade1, Cidade2);
            // Não altera v1/v2 nem cartaVencedora; apenas informa.
            break;

        case 2:
            // População: maior vence
            printf("\nComparacao de cartas (Atributo: Populacao)\n");
            printf("Carta 1 - %s (%c): %d\n", Cidade1, uf1, pop1);
            printf("Carta 2 - %s (%c): %d\n", Cidade2, uf2, pop2);

            v1 = (float)pop1; // guarda os valores a comparar
            v2 = (float)pop2;

            // if-else  para determinar vencedor
            if (v1 > v2)
                cartaVencedora = 1;
            else {
                if (v2 > v1)
                    cartaVencedora = 2;
                else
                    cartaVencedora = 0; // empate
            }
            break;

        case 3:
            // Área: maior vence
            printf("\nComparacao de cartas (Atributo: Area)\n");
            printf("Carta 1 - %s (%c): %.2f km²\n", Cidade1, uf1, area1);
            printf("Carta 2 - %s (%c): %.2f km²\n", Cidade2, uf2, area2);

            v1 = area1;
            v2 = area2;

            if (v1 > v2)
                cartaVencedora = 1;
            else {
                if (v2 > v1)
                    cartaVencedora = 2;
                else
                    cartaVencedora = 0;
            }
            break;

        case 4:
            // PIB: maior vence — lembrando que o valor digitado foi em bilhões
            printf("\nComparacao de cartas (Atributo: PIB)\n");
            printf("Carta 1 - %s (%c): %.2f bilhoes R$\n", Cidade1, uf1, pib1);
            printf("Carta 2 - %s (%c): %.2f bilhoes R$\n", Cidade2, uf2, pib2);

            v1 = pib1;
            v2 = pib2;

            if (v1 > v2)
                cartaVencedora = 1;
            else {
                if (v2 > v1)
                    cartaVencedora = 2;
                else
                    cartaVencedora = 0;
            }
            break;

        case 5:
            // Pontos turísticos: maior vence
            printf("\nComparacao de cartas (Atributo: Pontos Turisticos)\n");
            printf("Carta 1 - %s (%c): %d\n", Cidade1, uf1, pontosTuristicicos1);
            printf("Carta 2 - %s (%c): %d\n", Cidade2, uf2, pontosTuristicicos2);

            v1 = (float)pontosTuristicicos1;
            v2 = (float)pontosTuristicicos2;

            if (v1 > v2)
                cartaVencedora = 1;
            else {
                if (v2 > v1)
                    cartaVencedora = 2;
                else
                    cartaVencedora = 0;
            }
            break;

        case 6:
            // Densidade demográfica: menor vence
            printf("\nComparacao de cartas (Atributo: Densidade Demografica)\n");
            printf("Carta 1 - %s (%c): %.2f hab/km²\n", Cidade1, uf1, dens1);
            printf("Carta 2 - %s (%c): %.2f hab/km²\n", Cidade2, uf2, dens2);

            v1 = dens1;
            v2 = dens2;

            // if-else aninhado invertendo, o menor vence
            if (v1 < v2)
                cartaVencedora = 1;
            else {
                if (v2 < v1)
                    cartaVencedora = 2;
                else
                    cartaVencedora = 0;
            }
            break;

        default:
            // Opção inválida no menu
            printf("\nOpcao invalida. Tente novamente e escolha uma das opcoes de 1 a 6.\n");
            return 0; // encerra o programa sem fazer comparação
    }

    // Exibição do resultado da comparação
    if (opcao >= 2 && opcao <= 6) {
        if (cartaVencedora == 1)
            printf("Resultado: Carta 1 (%s) venceu!\n", Cidade1);
        else if (cartaVencedora == 2)
            printf("Resultado: Carta 2 (%s) venceu!\n", Cidade2);
        else
            printf("Resultado: Empate!\n");
    }

    return 0;
}

