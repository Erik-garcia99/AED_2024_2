#include <stdio.h>

void convertir_base1000(int num) {
    int digitos[100];  // Arreglo para almacenar los dígitos, ajustar el tamaño si es necesario
    int i = 0;

    while (num > 0) {
        digitos[i] = num % 1000;
        num /= 1000;
        i++;
    }

    // Imprimir los dígitos en orden inverso
    for (int j = i - 1; j >= 0; j--) {
        printf("%d ", digitos[j]);
    }
    printf("\n");
}

int main() {
    int numero;
    printf("Ingrese un número: ");
    scanf("%d", &numero);

    convertir_base1000(numero);

    return 0;
}
