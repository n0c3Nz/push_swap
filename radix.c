#include <stdio.h>

// Función para encontrar el máximo elemento en un arreglo
int encontrarMaximo(int arr[], int n) {
    int maximo = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maximo) {
            maximo = arr[i];
        }
    }
    return maximo;
}

// Función para realizar el ordenamiento por conteo basado en el dígito "posición"
void contarOrdenar(int arr[], int n, int posición) {
    const int rango = 10; // 10 dígitos posibles (0-9)
    int salida[n];
    int conteo[rango] = {0};

    for (int i = 0; i < n; i++) {
        conteo[(arr[i] / posición) % rango]++;
    }

    for (int i = 1; i < rango; i++) {
        conteo[i] += conteo[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        salida[conteo[(arr[i] / posición) % rango] - 1] = arr[i];
        conteo[(arr[i] / posición) % rango]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = salida[i];
    }
}

// Función para ordenar un arreglo de enteros utilizando el algoritmo radix sort
void radixSort(int arr[], int n) {
    int maximo = encontrarMaximo(arr, n);

    for (int posición = 1; maximo / posición > 0; posición *= 10) {
        contarOrdenar(arr, n, posición);
    }
}

int main() {
    int arreglo[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);

    printf("Arreglo original:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arreglo[i]);
    }

    radixSort(arreglo, n);

    printf("\nArreglo ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arreglo[i]);
    }

    return 0;
}
