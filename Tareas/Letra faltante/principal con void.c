#include <stdio.h>

void letrafaltante (char arreglo[], int numeroletras);

int main() {
    int numeroletras, i = 0, n;

    scanf("%i", &numeroletras);

    char arreglo[numeroletras];

    do{
        while ((n = getchar()) != '\n' && n != EOF){}
        scanf("%c",&arreglo[i]);
        i++;
    } while (i < numeroletras);

    letrafaltante(arreglo, numeroletras);
    
    return 0;
}

void letrafaltante (char arreglo[], int numeroletras){
    char letra;
    for (int i = 0; i < numeroletras - 1; ++i) {
        if ((arreglo[i] + 1) != arreglo[i + 1]){
            letra = arreglo[i + 1] - 1;
        }
    }
    printf("%c",letra);
}