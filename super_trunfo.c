#include <stdio.h>

int main() {

    /* Troquei de compilador e as palavras com acento pararam de funcionar corretamente, então alguns textos estão com acento e outros sem. Creio que não importe nesse trabalho */
    // Declaração das variáveis, algumas variáveis de tipo igual foram separadas para facilitar a leitura, mas dá na mesma

    char uf1, uf2; // O código do estado será apenas um caracter, representando um dos 8 estados disponíveis (foi a quantidade solicitada...)
    char codigo1[4], codigo2[4]; // O código precisa permitir até 3 caracteres + o \0 indicando o fim da string
    char Cidade1[50], Cidade2[50]; // O nome da cidade pode ter até 49 caracteres + o \0
    int pop1, pop2, pontosTuristicos1, pontosTuristicos2; // População e pontos turísticos são todos em números inteiros
    float area1, area2, pib1, pib2; // Área e PIB precisam ser float para permitir o uso de casas decimais
    float dens1, dens2, pibpc1, pibpc2; // Densidade populacional e PIB per capita também são valores reais
    int opcao1, opcao2; // escolhas do jogador para os dois atributos
    float a1_c1, a1_c2, a2_c1, a2_c2; // valores dos atributos 1 e 2 para as duas cartas
    float a1_pts_c1, a1_pts_c2, a2_pts_c1, a2_pts_c2; // “pontuação” ajustada (densidade é invertida)
    float soma_c1, soma_c2; // soma das pontuações
    int venceuA1 = 0, venceuA2 = 0, venceuFinal = 0; // resultados parciais e final
    char nomeAtrib1[40] = "", nomeAtrib2[40] = ""; // nomes legíveis dos atributos

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
    dens1  = (float)pop1 / area1; // Densidade populacional = população / área
    dens2  = (float)pop2 / area2;
    pibpc1 = (pib1 * 1000000000.0) / (double)pop1; // PIB per capita = (PIB em R$) / população
    pibpc2 = (pib2 * 1000000000.0) / (double)pop2;

    // Exibição do cadastro
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

    // ======== MENU 1 ========
    printf("\nEscolha o PRIMEIRO atributo para comparacao:\n");
    printf(" 1 - Populacao\n");
    printf(" 2 - Area\n");
    printf(" 3 - PIB\n");
    printf(" 4 - Numero de pontos turisticos\n");
    printf(" 5 - Densidade demografica (menor vence)\n");
    printf("Opcao: ");
    scanf("%d", &opcao1);

    switch (opcao1) {
        case 1:
            a1_c1 = pop1; a1_c2 = pop2;
            a1_pts_c1 = a1_c1; a1_pts_c2 = a1_c2;
            sprintf(nomeAtrib1, "Populacao");
            venceuA1 = (a1_c1 > a1_c2) ? 1 : (a1_c2 > a1_c1 ? 2 : 0);
            break;
        case 2:
            a1_c1 = area1; a1_c2 = area2;
            a1_pts_c1 = a1_c1; a1_pts_c2 = a1_c2;
            sprintf(nomeAtrib1, "Area");
            venceuA1 = (a1_c1 > a1_c2) ? 1 : (a1_c2 > a1_c1 ? 2 : 0);
            break;
        case 3:
            a1_c1 = pib1; a1_c2 = pib2;
            a1_pts_c1 = a1_c1; a1_pts_c2 = a1_c2;
            sprintf(nomeAtrib1, "PIB");
            venceuA1 = (a1_c1 > a1_c2) ? 1 : (a1_c2 > a1_c1 ? 2 : 0);
            break;
        case 4:
            a1_c1 = pontosTuristicos1; a1_c2 = pontosTuristicos2;
            a1_pts_c1 = a1_c1; a1_pts_c2 = a1_c2;
            sprintf(nomeAtrib1, "Pontos Turisticos");
            venceuA1 = (a1_c1 > a1_c2) ? 1 : (a1_c2 > a1_c1 ? 2 : 0);
            break;
        case 5:
            a1_c1 = dens1; a1_c2 = dens2;
            a1_pts_c1 = -a1_c1; a1_pts_c2 = -a1_c2; // menor vence, por isso valor negativo
            sprintf(nomeAtrib1, "Densidade Demografica");
            venceuA1 = (a1_c1 < a1_c2) ? 1 : (a1_c2 < a1_c1 ? 2 : 0);
            break;
        default:
            printf("\nOpcao invalida. Encerrando.\n");
            return 0;
    }

    // ======== MENU 2 ========
    printf("\nEscolha o SEGUNDO atributo para comparacao (diferente do primeiro):\n");
    printf(" 1 - Populacao\n");
    printf(" 2 - Area\n");
    printf(" 3 - PIB\n");
    printf(" 4 - Numero de pontos turisticos\n");
    printf(" 5 - Densidade demografica (menor vence)\n");
    printf("Opcao: ");
    scanf("%d", &opcao2);

    if (opcao2 == opcao1) {
        printf("\nVoce nao pode escolher o mesmo atributo duas vezes. Encerrando.\n");
        return 0;
    }

    switch (opcao2) {
        case 1:
            a2_c1 = pop1; a2_c2 = pop2;
            a2_pts_c1 = a2_c1; a2_pts_c2 = a2_c2;
            sprintf(nomeAtrib2, "Populacao");
            venceuA2 = (a2_c1 > a2_c2) ? 1 : (a2_c2 > a2_c1 ? 2 : 0);
            break;
        case 2:
            a2_c1 = area1; a2_c2 = area2;
            a2_pts_c1 = a2_c1; a2_pts_c2 = a2_c2;
            sprintf(nomeAtrib2, "Area");
            venceuA2 = (a2_c1 > a2_c2) ? 1 : (a2_c2 > a2_c1 ? 2 : 0);
            break;
        case 3:
            a2_c1 = pib1; a2_c2 = pib2;
            a2_pts_c1 = a2_c1; a2_pts_c2 = a2_c2;
            sprintf(nomeAtrib2, "PIB");
            venceuA2 = (a2_c1 > a2_c2) ? 1 : (a2_c2 > a2_c1 ? 2 : 0);
            break;
        case 4:
            a2_c1 = pontosTuristicos1; a2_c2 = pontosTuristicos2;
            a2_pts_c1 = a2_c1; a2_pts_c2 = a2_c2;
            sprintf(nomeAtrib2, "Pontos Turisticos");
            venceuA2 = (a2_c1 > a2_c2) ? 1 : (a2_c2 > a2_c1 ? 2 : 0);
            break;
        case 5:
            a2_c1 = dens1; a2_c2 = dens2;
            a2_pts_c1 = -a2_c1; a2_pts_c2 = -a2_c2;
            sprintf(nomeAtrib2, "Densidade Demografica");
            venceuA2 = (a2_c1 < a2_c2) ? 1 : (a2_c2 < a2_c1 ? 2 : 0);
            break;
        default:
            printf("\nOpcao invalida. Encerrando.\n");
            return 0;
    }

    // Soma das pontuações
    soma_c1 = a1_pts_c1 + a2_pts_c1;
    soma_c2 = a1_pts_c2 + a2_pts_c2;

    // Determina o vencedor final (usando operador ternário)
    venceuFinal = (soma_c1 > soma_c2) ? 1 : (soma_c2 > soma_c1 ? 2 : 0);

    // ======== RESULTADOS ========
    printf("\n===== Resultado da Comparacao com Dois Atributos =====\n");
    printf("Carta 1: %s (%c)\n", Cidade1, uf1);
    printf("Carta 2: %s (%c)\n", Cidade2, uf2);

    printf("\nAtributo 1: %s\n", nomeAtrib1);
    printf("  %s: %.2f | %s: %.2f\n", Cidade1, a1_c1, Cidade2, a1_c2);
    printf("  Vencedor: %s\n", (venceuA1==1)? Cidade1 : ((venceuA1==2)? Cidade2 : "Empate"));

    printf("\nAtributo 2: %s\n", nomeAtrib2);
    printf("  %s: %.2f | %s: %.2f\n", Cidade1, a2_c1, Cidade2, a2_c2);
    printf("  Vencedor: %s\n", (venceuA2==1)? Cidade1 : ((venceuA2==2)? Cidade2 : "Empate"));

    printf("\nSoma das pontuacoes (ajustada para regra da densidade):\n");
    printf("  %s: %.2f\n", Cidade1, soma_c1);
    printf("  %s: %.2f\n", Cidade2, soma_c2);

    printf("\nResultado final: %s\n", (venceuFinal==1)? "Carta 1 venceu!" : ((venceuFinal==2)? "Carta 2 venceu!" : "Empate!"));

    return 0;
}
