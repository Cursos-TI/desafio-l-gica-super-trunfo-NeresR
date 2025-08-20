#include <stdio.h>

typedef struct {
    char estado;
    char codigo[4];
    char cidade[50];
    unsigned long int populacao; // Alterado para suportar números grandes
    float area;
    float pib;
    int pontos;
    float densidadepopulacional;
    float pibpercapita;
    float superpoder;
} Carta;

void lerCarta(Carta *c) {
    printf("Digite o estado (A-H): ");
    scanf(" %c", &c->estado);

    printf("Digite o codigo (ex: A01): ");
    scanf("%s", c->codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", c->cidade);

    printf("Digite a populacao: ");
    scanf("%lu", &c->populacao);

    printf("Digite a area (km²): ");
    scanf("%f", &c->area);

    printf("Digite o PIB (em bilhoes): ");
    scanf("%f", &c->pib);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &c->pontos);

    // Cálculos de densidade populacional e PIB per capita
    c->densidadepopulacional = (float)c->populacao / c->area;
    c->pibpercapita = (c->pib * 1e9) / c->populacao;

    // Super Poder: soma de atributos numéricos + inverso da densidade
    c->superpoder = (float)c->populacao + c->area + c->pib + c->pontos + c->pibpercapita + (1.0f / c->densidadepopulacional);
}

void mostrarCarta(Carta c, int num) {
    printf("\n--- Carta %d ---\n", num);
    printf("Estado: %c\n", c.estado);
    printf("Codigo: %s\n", c.codigo);
    printf("Nome da Cidade: %s\n", c.cidade);
    printf("Populacao: %lu\n", c.populacao);
    printf("Area: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhoes de reais\n", c.pib);
    printf("Numero de Pontos Turisticos: %d\n", c.pontos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidadepopulacional);
    printf("PIB per capita: %.2f reais\n", c.pibpercapita);
    printf("Super Poder: %.2f\n", c.superpoder);
}

void compararCartas(Carta c1, Carta c2) {
    printf("\nComparacao de Cartas:\n");

    printf("Populacao: Carta 1 venceu (%d)\n", c1.populacao > c2.populacao ? 1 : 0);
    printf("Area: Carta 1 venceu (%d)\n", c1.area > c2.area ? 1 : 0);
    printf("PIB: Carta 1 venceu (%d)\n", c1.pib > c2.pib ? 1 : 0);
    printf("Pontos Turisticos: Carta 1 venceu (%d)\n", c1.pontos > c2.pontos ? 1 : 0);
    
    // Densidade populacional: menor valor vence
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", c1.densidadepopulacional < c2.densidadepopulacional ? 1 : 0);

    printf("PIB per Capita: Carta 1 venceu (%d)\n", c1.pibpercapita > c2.pibpercapita ? 1 : 0);
    printf("Super Poder: Carta 1 venceu (%d)\n", c1.superpoder > c2.superpoder ? 1 : 0);
}

int main() {
    Carta carta1, carta2;

    printf("=== Carta 1 ===\n");
    lerCarta(&carta1);

    printf("\n=== Carta 2 ===\n");
    lerCarta(&carta2);

    mostrarCarta(carta1, 1);
    mostrarCarta(carta2, 2);

    compararCartas(carta1, carta2);


    if(carta1.populacao > carta2.populacao){
    printf("carta 1 venceu pela populaçao!\n");
    }
    else{
    printf("carta 2 venceu pela populaçao!\n");
    }







    return 0;
}