#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h> 

/* Limpa todos os espacos de uma string */
void LimpaEspacos(char* str) {
    char* i = str;
    char* j = str;
    while (*j != 0) {
        *i = *j++;
        if (*i != ' ') i++;
    }
    *i = 0;
}

/* Extrai os coeficientes a, b e c.
   Retorna 1 se for válida, 0 se for inválida. */
int extrairCoeficientes(const char* equacao, int* a, int* b, int* c) {
    char copia[100];
    strcpy(copia, equacao);

    int len = strlen(copia);
    if (!(len > 2 && copia[len - 2] == '=' && copia[len - 1] == '0')) {
        printf("Formato invalido. A equacao deve terminar com =0\n");
        return 0;
    }

    copia[len - 2] = '\0'; // Limpa '=0'
    *a = 0; *b = 0; *c = 0;

    char* posX2 = strstr(copia, "x^2");
    char* posX = strstr(copia, "x");

    if (posX2) {
        char parteA[20] = {0};
        strncpy(parteA, copia, posX2 - copia);
        if (strcmp(parteA, "") == 0 || strcmp(parteA, "+") == 0) *a = 1;
        else if (strcmp(parteA, "-") == 0) *a = -1;
        else *a = atoi(parteA);

        char* restante = posX2 + 3;
        char* posXb = strstr(restante, "x");

        if (!posXb) {
            *b = 0;
            *c = atoi(restante);
            return 1;
        }

        char parteB[20] = {0};
        strncpy(parteB, restante, posXb - restante);
        if (strcmp(parteB, "") == 0 || strcmp(parteB, "+") == 0) *b = 1;
        else if (strcmp(parteB, "-") == 0) *b = -1;
        else *b = atoi(parteB);

        char* parteC = posXb + 1;
        if (*parteC != '\0') *c = atoi(parteC);

    } else if (posX) {
        char parteB[20] = {0};
        strncpy(parteB, copia, posX - copia);
        if (strcmp(parteB, "") == 0 || strcmp(parteB, "+") == 0) *b = 1;
        else if (strcmp(parteB, "-") == 0) *b = -1;
        else *b = atoi(parteB);

        char* parteC = posX + 1;
        if (*parteC != '\0') *c = atoi(parteC);
    } else {
        printf("Equacao invalida: nao contem 'x'\n");
        return 0;
    }

    return 1;
}

/* Resolve a equacao com base nos coeficientes */
void resolverEquacao(int a, int b, int c) {
    if (a != 0) {
        int delta = b * b - 4 * a * c;
        if (delta < 0) {
            printf("Tipo: 2o grau | Solucao real: Nao | Solucao: Nenhuma\n");
        } else if (delta == 0) {
            double x = -b / (2.0 * a);
            printf("Tipo: 2o grau | Solucao real: Sim | Solucao unica: x=%.2f\n", x);
        } else {
            double raiz = sqrt(delta);
            double x1 = (-b + raiz) / (2.0 * a);
            double x2 = (-b - raiz) / (2.0 * a);
            printf("Tipo: 2o grau | Solucao real: Sim | Solucoes: x=%.2f, x=%.2f\n", x1, x2);
        }
    } else {
        if (b == 0) {
            printf("Tipo: 1o grau | Solucao real: Nao | Solucao: Nenhuma\n");
        } else {
            double resultado = -(double)c / b;
            printf("Tipo: 1o grau | Solucao real: Sim | Solucao: x=%d/%d = %.2f\n", -c, b, resultado);
        }
    }
}

int main() {
    char entrada[100];
    int a, b, c;
    char continuar;

    while (1) {
        int valido = 0;

        // Loop até que uma equação válida seja digitada
        do {
            printf("\nDigite a equacao (ex: x^2+2x+1=0 ou 6x+10=0):\n> ");
            fgets(entrada, sizeof(entrada), stdin);
            entrada[strcspn(entrada, "\n")] = '\0';

            LimpaEspacos(entrada);
            valido = extrairCoeficientes(entrada, &a, &b, &c);
        } while (!valido);

        resolverEquacao(a, b, c);

        printf("\nDeseja resolver outra equacao? (s/n): ");
        scanf(" %c", &continuar);
        getchar(); // Limpa buffer

        if (tolower(continuar) == 'n') break;
    }

    printf("\nPrograma finalizado.\n");
    return 0;
}
