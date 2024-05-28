#include <stdio.h>
#include <string.h>

// Definición de los estados de la máquina de estado finito
typedef enum {
    Q0,
    Q1
} Estado;

// Definición de las órdenes como constantes
typedef enum {
    ORDEN_VEN,
    ORDEN_GRACIAS,
    ORDEN_SALUDA,
    ORDEN_QUIETO,
    // Definir más órdenes según sea necesario
} Orden;

// Función para manejar la máquina de estado finito
Estado manejarEstado(Estado estadoActual, Orden orden, const char **respuesta) {
    Estado nuevoEstado = estadoActual;

    switch (estadoActual) {
        case Q0:
            // Lógica para el estado Q0
            switch (orden) {
                case ORDEN_VEN:
                    *respuesta = "viene";
                    nuevoEstado = Q1;
                    break;
                case ORDEN_SALUDA:
                    *respuesta = "hola";
                    break;
                case 
                // Agregar más casos para otras órdenes
                default:
                    *respuesta = "No entiendo";
                    break;
            }
            break;

        case Q1:
            // Lógica para el estado Q1
            switch (orden) {
                case ORDEN_GRACIAS:
                    *respuesta = "de nada";
                    nuevoEstado = Q0;
                    break;
                case ORDEN_...
                // Agregar más casos para otras órdenes
                default:
                    *respuesta = "No entiendo";
                    break;
            }
            break;
    }

    return nuevoEstado;
}

int main() {
    Estado estadoActual = Q0;
    const char *respuesta;

    // Ejemplo de orden para la máquina de estado finito
    Orden orden = ORDEN_VEN;

    // Manejar el estado basado en la orden
    estadoActual = manejarEstado(estadoActual, orden, &respuesta);

    // Imprimir la respuesta
    printf("%s\n", respuesta);

    return 0;
}
