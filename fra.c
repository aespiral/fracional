#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct fr {
    int nu; // NUmerador
    int de; // DEnominador
};

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

int mmc(int m, int n) {
    return m * (n / mdc(m, n));
}

// calcula quantos algarismos tem a representacao decimal de n
int largura_dec(int n) {
    int aux = n;

    int i;
    for (i = 0; aux != 0; i = i + 1, aux = aux / 10);
    return i;
}

// Pretty Print
void pprint(struct fr f) { 
    int larg_num = largura_dec(f.nu);
    int larg_den = largura_dec(f.de);

    int larg = larg_num > larg_den ? larg_num : larg_den;
    int marg_num = (larg - larg_num) / 2 + 1;
    int marg_den = (larg - larg_den) / 2 + 1;

    int i;
    for (i = 0; i< marg_num; i = i + 1)
        putchar(' ');
    printf("%d\n", f.nu);
    for (i = 0; i<larg+2; i = i + 1)
        putchar('-');
    putchar('\n');
    for (i = 0; i< marg_den; i = i + 1)
        putchar(' ');
    printf("%d\n", f.de);

}

bool normalizada(struct fr f) {
    return mdc(f.nu, f.de) == 1;
}

/*
 * Funcoes sobre fracoes
 */
struct fr res; // variavel global para improvisar retorno de fracoes

// seria:
// struct fr normalizar(struct fr f)
void normalizar(struct fr f) {
    int d = mdc(f.nu,f.de);
    res.nu = f.nu/d; res.de = f.de/d;
}

// seria:
// struct fr somar(struct fr f, struct fr g)
void somar(struct fr f, struct fr g) {
    int d = mmc(f.de, g.de);

    struct fr aux;
    aux.nu = (f.nu * d) / f.de + (g.nu * d) / g.de;
    aux.de = d;

    normalizar(aux);
}

int main() {
    printf("O M.D.C. de 144 e 96 eh %d\n", mdc(144,96));
    printf("O M.D.C. de 3 e 2 eh %d\n", mdc(2,3));

    struct fr f1; f1.nu = 6; f1.de = 9; 
    pprint(f1); 
    if (normalizada(f1))
        puts("A fracao eh normalizada\n");
    else
        puts("A fracao não eh normalizada\n");
    
    struct fr f2; f2.nu = 1024; f2.de = 15;
    pprint(f2);
    if (normalizada(f2))
        puts("A fracao eh normalizada\n");
    else
        puts("A fracao não eh normalizada\n");
    
    normalizar(f1);
    pprint(res);

    struct fr f3; f3.nu = 1; f3.de = 6;
    struct fr f4; f4.nu = 2; f4.de = 9;
    somar(f3, f4);
    struct fr f5; f5.nu = res.nu; f5.de = res.de;
    pprint(f5);
}