/*
Nombre del archivo: Taller 8. Experimentación con Punteros y Arrays.
Autor: Cesar Alejandro Velazquez Mercado
Fecha de creación: 08 de noviembre de 2023
Descripción: Busca palabras y cuenta el tiempo que tardo
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 50
#define ARRAY_SIZE 1000

int busquedaLinealPalabra(char *arreglo[], int n, char *palabra);

int main() 
{
    srand(time(NULL));

    int n = ARRAY_SIZE; // Tamaño del arreglo
    char *arreglo[n];

    
    for (int i = 0; i < n; i++)  // Llenar el arreglo con palabras aleatorias
    {
        arreglo[i] = (char *)malloc(MAX_STRING_LENGTH * sizeof(char));
        snprintf(arreglo[i], MAX_STRING_LENGTH, "Palabra%d", i);
    }

    
    char palabraBuscada[MAX_STRING_LENGTH]; // Palabra aleatoria a buscar
    snprintf(palabraBuscada, MAX_STRING_LENGTH, "Palabra%d", rand() % n);

    
    printf("Arreglo de cadenas:\n"); // Imprimir el arreglo de cadenas
    for (int i = 0; i < n; i++) {
        printf("%s\n", arreglo[i]);
    }

    clock_t inicio, fin;
    double tiempo;

    
    inicio = clock(); // Realizar la búsqueda lineal de la palabra y medir el tiempo
    int resultado = busquedaLinealPalabra(arreglo, n, palabraBuscada);
    fin = clock();
    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;

    if (resultado != -1) 
    {
        printf("Palabra '%s' encontrada en la posición %d\n", palabraBuscada, resultado);
    } else {
        printf("Palabra '%s' no encontrada\n", palabraBuscada);
    }

    printf("Tiempo de ejecución: %f segundos\n", tiempo);

    
    for (int i = 0; i < n; i++)  // Liberar la memoria asignada a las cadenas
    {
        free(arreglo[i]);
    }

    return 0;
}

int busquedaLinealPalabra(char *arreglo[], int n, char *palabra) // Función para realizar una búsqueda lineal de una palabra en un arreglo de cadenas
{
    for (int i = 0; i < n; i++) 
    {
        if (strcmp(arreglo[i], palabra) == 0) 
        {
            return i;
        }
    }
    return -1; //en caso de no encontrar
}
