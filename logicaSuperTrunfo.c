#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[30];
    char codigoCarta[10];
    char nomeCidade[50];
    int populacao;
    double area;
    double pib;
    int pontosTuristicos;
    double densidadePopulacional;
    double pibPerCapita;
} Carta;

void calcularAtributos(Carta* carta) {
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
}

// Função que compara dois valores com base na regra: se menorMelhor==1, menor vence, senão maior vence
const char* comparar(double v1, double v2, int menorMelhor) {
    if (v1 == v2) return "Empate";
    if (menorMelhor) {
        return (v1 < v2) ? "Carta 1" : "Carta 2";
    } else {
        return (v1 > v2) ? "Carta 1" : "Carta 2";
    }
}

int main() {
    Carta carta1 = {
        "SP",
        "C001",
        "São Paulo",
        12252023,
        1521.11,
        680000000000.0,
        140
    };

    Carta carta2 = {
        "RJ",
        "C002",
        "Rio de Janeiro",
        6748000,
        1182.30,
        320000000000.0,
        110
    };

    calcularAtributos(&carta1);
    calcularAtributos(&carta2);

    // Array com os atributos para comparar
    struct {
        char nome[50];
        double valorCarta1;
        double valorCarta2;
        int menorMelhor;
    } atributos[] = {
        {"População", (double)carta1.populacao, (double)carta2.populacao, 0},
        {"Área (km²)", carta1.area, carta2.area, 0},
        {"PIB (R$)", carta1.pib, carta2.pib, 0},
        {"Densidade Populacional (hab/km²)", carta1.densidadePopulacional, carta2.densidadePopulacional, 1},
        {"PIB per Capita (R$)", carta1.pibPerCapita, carta2.pibPerCapita, 0},
        {"Pontos Turísticos", (double)carta1.pontosTuristicos, (double)carta2.pontosTuristicos, 0}
    };

    int total = sizeof(atributos)/sizeof(atributos[0]);

    for (int i = 0; i < total; i++) {
        printf("Atributo: %s\n", atributos[i].nome);

        // Exibe valores formatados conforme atributo
        if (strcmp(atributos[i].nome, "População") == 0 || strcmp(atributos[i].nome, "Pontos Turísticos") == 0) {
            printf("  %s: %.0lf\n", carta1.nomeCidade, atributos[i].valorCarta1);
            printf("  %s: %.0lf\n", carta2.nomeCidade, atributos[i].valorCarta2);
        } else {
            printf("  %s: %.2lf\n", carta1.nomeCidade, atributos[i].valorCarta1);
            printf("  %s: %.2lf\n", carta2.nomeCidade, atributos[i].valorCarta2);
        }

        const char* vencedor = comparar(atributos[i].valorCarta1, atributos[i].valorCarta2, atributos[i].menorMelhor);

        if (strcmp(vencedor, "Empate") == 0) {
            printf("  Resultado: Empate!\n");
        } else if (strcmp(vencedor, "Carta 1") == 0) {
            printf("  Resultado: %s venceu!\n", carta1.nomeCidade);
        } else {
            printf("  Resultado: %s venceu!\n", carta2.nomeCidade);
        }
        printf("\n");
    }

    return 0;
}
