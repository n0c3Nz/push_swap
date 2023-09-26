#include <stdio.h>

// Función para encontrar el máximo número en un arreglo
int findMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Función para realizar el ordenamiento por el dígito específico
void countingSort(int arr[], int n, int exp)
{
    int output[n];
    int count[10] = {0};

    // Contar la frecuencia de cada dígito
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Calcular las posiciones finales de los dígitos
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Construir el arreglo de salida
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copiar el arreglo de salida de regreso al arreglo original
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Función principal de Radix Sort
void radixSort(int arr[], int n)
{
    int max = findMax(arr, n);

    // Realizar el ordenamiento por cada dígito, desde el dígito menos significativo al más significativo
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

// Función para imprimir un arreglo
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
	int k = sizeof(arr);
	int j = sizeof(arr[0]);
	printf("Curiosidad:\nn[%d]\tk[%d]\tj[%d]\n",n,k,j);
    printf("Arreglo original: ");
    printArray(arr, n);

    radixSort(arr, n);

    printf("Arreglo ordenado: ");
    printArray(arr, n);

    return 0;
}
