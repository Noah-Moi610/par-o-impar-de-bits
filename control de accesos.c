#include <stdio.h>
#include <stdbool.h>

// Definición de los estados
typedef enum {
    STATE_IDLE,
    STATE_CARD_INSERTED,
    STATE_PIN_ENTERED,
    STATE_ACCESS_GRANTED,
    STATE_ACCESS_DENIED
} State;

// Definición de los eventos
typedef enum {
    EVENT_CARD_INSERTED,
    EVENT_PIN_ENTERED_CORRECT,
    EVENT_PIN_ENTERED_INCORRECT,
    EVENT_TIMEOUT
} Event;

// Estructura de la FSM
typedef struct {
    State currentState;
} FSM;

// Prototipos de funciones
void handleEvent(FSM *fsm, Event event);
void onEnterIdle(FSM *fsm);
void onEnterCardInserted(FSM *fsm);
void onEnterPinEntered(FSM *fsm);
void onEnterAccessGranted(FSM *fsm);
void onEnterAccessDenied(FSM *fsm);

// Implementación de la FSM
void handleEvent(FSM *fsm, Event event) {
    switch (fsm->currentState) {
        case STATE_IDLE:
            if (event == EVENT_CARD_INSERTED) {
                fsm->currentState = STATE_CARD_INSERTED;
                onEnterCardInserted(fsm);
            }
            break;
        case STATE_CARD_INSERTED:
            if (event == EVENT_PIN_ENTERED_CORRECT) {
                fsm->currentState = STATE_ACCESS_GRANTED;
                onEnterAccessGranted(fsm);
            } else if (event == EVENT_PIN_ENTERED_INCORRECT) {
                fsm->currentState = STATE_ACCESS_DENIED;
                onEnterAccessDenied(fsm);
            } else if (event == EVENT_TIMEOUT) {
                fsm->currentState = STATE_IDLE;
                onEnterIdle(fsm);
            }
            break;
        case STATE_ACCESS_GRANTED:
            if (event == EVENT_TIMEOUT) {
                fsm->currentState = STATE_IDLE;
                onEnterIdle(fsm);
            }
            break;
        case STATE_ACCESS_DENIED:
            if (event == EVENT_TIMEOUT) {
                fsm->currentState = STATE_IDLE;
                onEnterIdle(fsm);
            }
            break;
        default:
            break;
    }
}

// Funciones de manejo de estado
void onEnterIdle(FSM *fsm) {
    printf("Estado: IDLE\n");
}

void onEnterCardInserted(FSM *fsm) {
    printf("Estado: CARD INSERTED. Esperando PIN...\n");
}

void onEnterAccessGranted(FSM *fsm) {
    printf("Estado: ACCESS GRANTED. Abriendo puerta...\n");
}

void onEnterAccessDenied(FSM *fsm) {
    printf("Estado: ACCESS DENIED. Tarjeta bloqueada...\n");
}

// Función principal
int main() {
    FSM fsm;
    fsm.currentState = STATE_IDLE;

    onEnterIdle(&fsm);

    // Simulación de eventos
    handleEvent(&fsm, EVENT_CARD_INSERTED);
    handleEvent(&fsm, EVENT_PIN_ENTERED_CORRECT);
    handleEvent(&fsm, EVENT_TIMEOUT);
    handleEvent(&fsm, EVENT_CARD_INSERTED);
    handleEvent(&fsm, EVENT_PIN_ENTERED_INCORRECT);
    handleEvent(&fsm, EVENT_TIMEOUT);

    return 0;
}
