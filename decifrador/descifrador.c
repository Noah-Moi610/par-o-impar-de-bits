// Máquina de estado finito, descifrador 
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define ESTADO_INICIAL 0
#define ESTADO_SALIDA 0
#define NUM_ESTADOS 2
#define NUM_ALFABETO 26

// Tabla de estado siguiente 
int transiciones[NUM_ESTADOS][NUM_ALFABETO] = 
{
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //  q0 = Transiciones al siguiente estado (cifrar)
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // q1 (Cambios cifrados)
};

// Tabla de salidas 
char salidas[NUM_ESTADOS][NUM_ALFABETO] =
{
    {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}, // q1 (Cambios para descifrado)
    {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'}, // q2 (Cambios para descifrado)
};

// Función para obtener el índice
int obtenerIndice(char simbolo) {
    if (simbolo >= 'a' && simbolo <= 'z') {
        return simbolo - 'a';
    }
    return -1; // Símbolo no válido
}

// Función principal para cifrar una cadena 
char* cifrarCadena(char *cadena) {
    int estadoActual = ESTADO_INICIAL;
    int longitud = strlen(cadena);
    char* cifrado = (char*)malloc((longitud + 1) * sizeof(char));
    if (cifrado == NULL) {
        printf("Error de asignación de memoria.");
        exit(1);
    }
    for (int i = 0; i < longitud; i++) {
        char entrada = cadena[i];
        int indice = obtenerIndice(entrada);
        if (indice == -1) {
            cifrado[i] = entrada; // Mantener los caracteres no válidos
        } else {
            char salida = salidas[estadoActual][indice];
            cifrado[i] = salida;
            estadoActual = transiciones[estadoActual][indice];
        }
    }
    cifrado[longitud] = '\0'; // Agregar el carácter nulo al final de la cadena
    return cifrado;
}

int main() {
    char cadena_original[100];
    printf("Ingrese la palabra para cifrar: ");
    scanf("%s", cadena_original);    
    char* resultado = cifrarCadena(cadena_original);
    printf("Cadena cifrada: %s\n", resultado);
    free(resultado); // Liberar la memoria asignada dinámicamente
    return 0;
}