#include <stdio.h>

void burbuja ( int arreglo[], int numerodatos);
void diferencia (int arreglo[], int numerodatos);

int main() {
    int numerodatos, i=0;
    scanf("%i",&numerodatos);

    int arreglo[numerodatos];

    do {
        scanf("%i",&arreglo[i]);
        i++;
    } while (i < numerodatos);

    burbuja(arreglo, numerodatos);
    diferencia(arreglo, numerodatos);

    return 0;
}

void burbuja ( int arreglo[], int numerodatos){
    int aux;
    for (int i = 0; i < numerodatos; ++i) {
        for (int j = 0; j < numerodatos -1; ++j) {
            if(arreglo[j] > arreglo[j+1]){
                aux = arreglo[j];
                arreglo[j] = arreglo[j+1];
                arreglo[j+1] = aux;
            }
        }
    }
}

void diferencia (int arreglo[], int numerodatos){
    for (int i = 0; i < numerodatos; ++i) {
        for (int j = 0; j < numerodatos - 1; ++j) {
            if (arreglo[i] - arreglo[j] == 2){
                if(arreglo[i] < arreglo[j]){
                    printf("%i, %i\n¡",arreglo[i], arreglo[j]);
                } else{
                    printf("%i, %i\n",arreglo[j], arreglo[i]);
                }
            }
        }
        }
    }
