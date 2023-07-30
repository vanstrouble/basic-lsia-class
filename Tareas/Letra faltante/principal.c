#include <stdio.h>

char letrafaltante (char arreglo[], int numeroletras);

int main() {
    int numeroletras, i = 0, n;

    printf("\tLETRA FALTANTE\n");

    printf("\n¿Cuántas letras quieres ingresar?\n");
    scanf("%i", &numeroletras);

    char arreglo[numeroletras];

    do{
        while ((n = getchar()) != '\n' && n != EOF){}
        printf("\nIngrese una letra: ");
        scanf("%c",&arreglo[i]);
        i++;
    } while (i < numeroletras);

    printf("\nTe faltó la letra: %c", letrafaltante(arreglo, numeroletras));

    return 0;
}

char letrafaltante (char arreglo[], int numeroletras){
    char letra;
    for (int i = 0; i < numeroletras - 1; ++i) {
        if ((arreglo[i] + 1) != arreglo[i + 1]){
            letra = arreglo[i + 1] - 1;
        }
    }
    return letra;
}