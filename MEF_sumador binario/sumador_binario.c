// Máquina de estado finito, sumador binario
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define ESTADO_INICIAL 0
#define ESTADO_ACARREO 1
#define NUM_ESTADOS 2
#define NUM_SIMBOLOS 4

// Tabla de estado siguiente 
int transiciones[NUM_ESTADOS][NUM_SIMBOLOS] = 
{
    {0, 0, 0, 1}, // q1
    {0, 1, 1, 1}, // q2
};
 // Tabla de salidas 
int salidas[NUM_ESTADOS][NUM_SIMBOLOS] =
{
    {0, 1, 1, 0}, // q1
    {1, 0, 0, 1}, // q2
};

bool esEstadoFinal(int estado) {
    return estado == ESTADO_INICIAL;
}

// Oden de las columnas de las matrices
int obtenerIndice(char entrada[]) {
    if (strcmp(entrada, "00") == 0)
        return 0;
    if (strcmp(entrada, "01") == 0)
        return 1;
    if (strcmp(entrada, "10") == 0)
        return 2;
    if (strcmp(entrada, "11") == 0)
        return 3;
    return -1;
}

char* sumarBits(char cadena1[], char cadena2[]) {
    int longitud = strlen(cadena1);
    if (longitud != strlen(cadena2))
        return NULL;
    int estadoActual = ESTADO_INICIAL;
   // char *resultado = (char *)malloc((longitud + 2) * sizeof(char)); // +1 para el resultado y +1 para el carácter nulo
    int acarreo = 0;
    char resultado[10];
    for (int k = 0; k <= 9;k++)
    resultado[k]= '0';
printf("resultado: %s \n",resultado);

char entrada[3];
int contador = 0;
    for (int i = longitud - 1; i >= 0; i--) {
        entrada[0] = cadena1[i];
        entrada[1] = cadena2[i];
        entrada[2] = '\0';
        int indiceEntrada = obtenerIndice(entrada);

        int siguienteEstado = transiciones[estadoActual][indiceEntrada];
        int salida = salidas[estadoActual][indiceEntrada];

        //int resultadobit = salida; //^ acarreo; 
        
        resultado[contador] = (char)salida;
        printf("caracter: %c \n",resultado[contador]);
        contador++;

        estadoActual = siguienteEstado;

        //resultado[longitud - 1 - i] = resultadobit + '0';

        // Actualizamos el acarreo
        //acarreo = (salida & acarreo) | ((salida ^ 1) & acarreo);
    }

    if (estadoActual == ESTADO_ACARREO) {
        resultado[contador] = '1';
        resultado[contador + 1] = '\0';
    } else {
        resultado[contador] = '0';
        resultado[contador + 1] = '\0';
    }
    printf("resultado: %s \n",resultado);
    return resultado;
}

int main() {
    // se ingresa cadenas
    char cadena1[100], cadena2[100];
    printf("Ingrese la primera cadena de bits '1's y '0's: ");
    scanf("%s", cadena1);
    printf("Ingrese la segunda cadena de bits '1's y '0's: ");
    scanf("%s", cadena2);

        //Sumar las cadenas 
    char *suma = sumarBits(cadena1, cadena2);

// Se pone un "if" para validar la cadena
    if (suma != NULL) {
        printf("La suma de las dos cadenas es. %s\n", suma);
        free(suma);
    }
}
