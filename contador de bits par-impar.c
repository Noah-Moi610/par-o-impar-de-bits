// Noé Moisés Galindo Leal 
// Se incluye las librerias 
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Se define los estados 
#define ESTADO_INICIAL 0
#define ESTADO_FINAL 0
#define NUM_ESTADOS 2
#define NUM_SIMBOLOS 2

// Tabla de estado siguiente 
int transiciones[NUM_ESTADOS][NUM_SIMBOLOS] =
{
    {0, 1},
    {1, 0},
};

bool esEstadoFinal(int estado) {
    return estado == ESTADO_FINAL;
}

int obtenerIndiceEntrada(char entrada) {
    if (entrada == '0')
        return 0;
    if (entrada == '1')
        return 1;
    return -1;
}
bool validarCadena(char cadena[]){
    // "G0" estado inicial
    int estadoActual = ESTADO_INICIAL;
    int longitud = strlen(cadena);
    
    for (int i = 0; i< longitud; i++) {
        int indiceEntrada = obtenerIndiceEntrada(cadena[i]);
        if (indiceEntrada == -1) {
            printf("Error: La cadena contiene caracteres no validos. \n");
            return false;
        }
        // Tabla de transiciones 
        estadoActual = transiciones[estadoActual][indiceEntrada];
    }
    return esEstadoFinal(estadoActual);
}

int main() {
    // se ingresa una cadena
    char cadena[100];
    printf("Ingrese una cadena de bits '1' s y '0's: ");
    scanf("%s", cadena);

// Se pone un "if" para validar la cadena
    if (validarCadena(cadena)) {
        printf("La cadena es par. \n");
    } else{
    }

    return 0;
}

