#include <stdio.h>
void divisores (int n);

int main() {
    int numero;

    scanf("%i",&numero);

    divisores(numero);

    return 0;
}
void divisores (int n){
    int cont = 0;
    for (int d = n; d > 0; --d) {
        if (n % d == 0) {
            cont = cont + 1;
        }
        printf("%i",cont);
    }
}