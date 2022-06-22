#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 
 * Funcoes auxiliares
 */
int mdc(int m, int n) {
    if (m == 0 || n == 0) {
        printf("ERRO: zero como divisor\n");
        exit(1);
    }
    if (m < 0 || n <0) {
        printf("Versao nao atende números negativos\n");
        exit(2);
    }
    int dendo, sor; // diviDENDO, diviSOR
    if (m > n) {
        dendo = m; sor = n;   
    } else {
        dendo = n; sor = m;
    }
    int quoc = dendo / sor, resto = dendo % sor;
    
    while(resto != 0) {
        dendo = sor; sor = resto;
        quoc = dendo / sor; resto = dendo % sor;
    }
    return sor;
}

int main() {
    printf("O M.D.C. de 144 e 96 eh %d\n", mdc(144,96));
    printf("O M.D.C. de 3 e 2 eh %d\n", mdc(2,3));

}