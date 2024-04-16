// Ejercicio 4 de maquinas de estado finito
// Noé Moisés Galidno Leal
// 15 de Abril de 2024

# include <stdio.h>
# include <stdbool.h>

// Definicicón de estados 
typedef enum {
    par,
    impar
} State;

// Función que determinará si es par o impar 
State validar(const char *cadena) {
    int count = 0;
    // Contar la cantidad de unos en la cadena
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] == '1') {
            count++;
        }
    }
    return (count % 2 == 0) ? par : impar;
}


int main() {
    char cadena[100];
    printf("Ingrese una cadena de bits: ");
    scanf("%s", cadena);

    State estado = validar(cadena);

    // Imprimir los resultados
    if (estado == par) {
        printf("La cadena es par compadre, salio 1.\n, Ni modo te toco marchar, a defender la patria.");
    } else {
        printf("la cadena es impar compadre, sali0 0,\n, que suertudo No te toca marchar.");
    }

return 0;
    
};
