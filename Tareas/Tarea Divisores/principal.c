#include <stdio.h>
int divisores (int n);

int main() {
    int numero;

    scanf("%i",&numero);

    printf("%i", divisores(numero));

    return 0;
}
int divisores (int n){
    int cont = 0;
    for (int d = n; d > 0; --d) {
        if (n % d == 0){
            cont = cont + 1;
        }
    }
    return cont;
}