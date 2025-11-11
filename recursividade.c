#include <stdio.h>

int somaAnteriores(int n) {
    if (n < 0) return 0;
    if (n == 1) return 1;
    return n + somaAnteriores(n-1);
}

int potencia(int a, int b) {
    if (b == 0) return 1; // elevado a zero
    if (b == 1) return a; // elevado a 1 eh ele mesmo
    return a * potencia(a, b-1); // prossegue
}

void main() {
    int base = 17;
    int expoente = 3;
    
    printf("soma ate %d eh %d\n", base, somaAnteriores(base));
    printf("%d^%d = %d", base, expoente, potencia(base, expoente));
}
