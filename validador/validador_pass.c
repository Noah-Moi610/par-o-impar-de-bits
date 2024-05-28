#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define ESTADO_INICIAL 0
#define ESTADO_FINAL 3
#define NUM_ESTADOS 5
#define NUM_SIMBOLOS 62

// Tabla de transiciones
int transiciones[NUM_ESTADOS][NUM_SIMBOLOS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // Estado 0: Inicial
    {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}, // Estado 1: Minúscula encontrada
    {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}, // Estado 2: Minúscula y mayúscula encontradas
    {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4}, // Estado 3: Minúscula, mayúscula y dígito encontrados
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}  // Estado 4: Final
};

// Tabla de salidas
char salidas[NUM_ESTADOS][NUM_SIMBOLOS] = {
    {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}, // Estado 0: Inicial
    {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}, // Estado 1: Minúscula encontrada
    {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}, // Estado 2: Minúscula y mayúscula encontradas
    {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}, // Estado 3: Minúscula, mayúscula y dígito encontrados
    {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}  // Estado 4: Final
};

// Función para obtener el índice de un símbolo
int obtenerIndice(char simbolo) {
    if (simbolo >= 'a' && simbolo <= 'z') {
        return simbolo - 'a';
    } else if (simbolo >= 'A' && simbolo <= 'Z') {
        return simbolo - 'A' + 26;
    } else if (simbolo >= '0' && simbolo <= '9') {
        return simbolo - '0' + 52;
    }
    return -1; // Símbolo no válido
}

// Función principal para validar una contraseña
bool validarContraseña(char *contraseña) {
    int estadoActual = ESTADO_INICIAL;
    int contadorMayuscula = 0;
    int contadorMinuscula = 0;
    int contadorDigito = 0;
    int longitud = strlen(contraseña);
    if (longitud != 8 || longitud % 2 != 0) {
        return false; // La contraseña no tiene una longitud válida (debe ser un múltiplo de 2)
    }
    for (int i = 0; i < longitud; i += 2) {
        char simbolo1 = contraseña[i];
        char simbolo2 = contraseña[i+1];
        int indice1 = obtenerIndice(simbolo1);
        int indice2 = obtenerIndice(simbolo2);
        if (indice1 == -1 || indice2 == -1) {
            return false; // Símbolo no válido
        }
        // Consultamos el estado actual y la salida para el primer símbolo
        estadoActual = transiciones[estadoActual][indice1];
        char salida1 = salidas[estadoActual][indice1];
        // Consultamos el estado actual y la salida para el segundo símbolo
        estadoActual = transiciones[estadoActual][indice2];
        char salida2 = salidas[estadoActual][indice2];
        // Verificamos la salida del primer símbolo
        if (salida1 == ' ') {
            return false; // Símbolo no válido según la tabla de salidas
        }
        // Verificamos la salida del segundo símbolo
        if (salida2 == ' ') {
            return false; // Símbolo no válido según la tabla de salidas
        }
        // Incrementamos los contadores según las salidas
        if (salida1 >= 'a' && salida1 <= 'z') {
            contadorMinuscula++;
        } else if (salida1 >= 'A' && salida1 <= 'Z') {
            contadorMayuscula++;
        } else if (salida1 >= '0' && salida1 <= '9') {
            contadorDigito++;
        }  
        if (salida2 >= 'a' && salida2 <= 'z') {
            contadorMinuscula++;
        } else if (salida2 >= 'A' && salida2 <= 'Z') {
            contadorMayuscula++;
        } else if (salida2 >= '0' && salida2 <= '9') {
            contadorDigito++;
        }
    }
    return (contadorMayuscula > 0 && contadorMinuscula > 0 && contadorDigito > 0);
}

int main() {
    char contraseña[9]; // Incluyendo el carácter nulo
    printf("Ingrese la contrasena: ");
    scanf("%s", contraseña);
    if (validarContraseña(contraseña)) {
        printf("La contrasena es valida.\n");
    } else {
        printf("La contrasena tiene mas de 8 caracteres o no cumple con los requisitos.\n");
    }
    return 0;
}
