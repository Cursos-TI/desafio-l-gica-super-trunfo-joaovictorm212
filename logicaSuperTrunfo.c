#include <stdio.h>
#include <string.h>

// Definição da estrutura Carta
typedef struct {
    char estado[30];
    char codigoCarta[10];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;  // População / Área
    float pibPerCapita;           // PIB / População
} Carta;

int main() {
    // Dados reais aproximados das cidades

    // São Paulo (dados aproximados 2023)
    Carta carta1 = {
        "SP",
        "C001",
        "São Paulo",
        12252023,        // população estimada IBGE 2023
        1521.11f,        // área em km²
        680000000000.0f, // PIB em reais (2021, valor aproximado)
        140,             // número aproximado de pontos turísticos
        0.0f,
        0.0f
    };

    // Rio de Janeiro (dados aproximados 2023)
    Carta carta2 = {
        "RJ",
        "C002",
        "Rio de Janeiro",
        6748000,          // população estimada IBGE 2023
        1182.30f,         // área em km²
        320000000000.0f,  // PIB em reais (2021, valor aproximado)
        110,              // número aproximado de pontos turísticos
        0.0f,
        0.0f
    };

    // Cálculo da densidade populacional e PIB per capita
    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta1.pibPerCapita = carta1.pib / carta1.populacao;

    carta2.densidadePopulacional = carta2.populacao / carta2.area;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    // Atributo para comparação - mude aqui para comparar outro atributo
    char atributoParaComparar[] = "pibPerCapita";

    float valorCarta1 = 0.0f;
    float valorCarta2 = 0.0f;

    if (strcmp(atributoParaComparar, "populacao") == 0) {
        valorCarta1 = (float)carta1.populacao;
        valorCarta2 = (float)carta2.populacao;
    } else if (strcmp(atributoParaComparar, "area") == 0) {
        valorCarta1 = carta1.area;
        valorCarta2 = carta2.area;
    } else if (strcmp(atributoParaComparar, "pib") == 0) {
        valorCarta1 = carta1.pib;
        valorCarta2 = carta2.pib;
    } else if (strcmp(atributoParaComparar, "densidade") == 0) {
        valorCarta1 = carta1.densidadePopulacional;
        valorCarta2 = carta2.densidadePopulacional;
    } else if (strcmp(atributoParaComparar, "pibPerCapita") == 0) {
        valorCarta1 = carta1.pibPerCapita;
        valorCarta2 = carta2.pibPerCapita;
    } else {
        printf("Atributo para comparar inválido!\n");
        return 1;
    }

    printf("Comparação de cartas (Atributo: %s):\n\n", atributoParaComparar);

    printf("Carta 1 - %s (%s): %.2f\n", carta1.nomeCidade, carta1.estado, valorCarta1);
    printf("Carta 2 - %s (%s): %.2f\n\n", carta2.nomeCidade, carta2.estado, valorCarta2);

    // Regras para determinar vencedor
    if (strcmp(atributoParaComparar, "densidade") == 0) {
        if (valorCarta1 < valorCarta2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (valorCarta1 > valorCarta2) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else {
        if (valorCarta1 > valorCarta2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (valorCarta1 < valorCarta2) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    }

    return 0;
}
