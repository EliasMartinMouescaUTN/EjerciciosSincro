#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "definitions.h"
#include "../semaphores_wrap.h"

// ---- Declarations ----
typedef int tarea_t;                // Una tarea es un int, por qué no? 0 es la tarea NULL, no válida
void poner_tarea(tarea_t*);
tarea_t sacar_tarea(tarea_t*);
void hacer(tarea_t);


// ---- Globales ----
tarea_t * lista_tareas = NULL;      // Nuestra lista global de tareas
sem_t hay_tareas_pendientes;
sem_t capacidad_en_lista;
sem_t mutex_lista;


// ---- Constantes ----
const int DELAY_PRODUCTOR = 1000;
const int DELAY_CONSUMIDOR = 1000;
const int CAPACIDAD_LISTA = 5;


void* productor(void* _) {
    while (1) {
        puts(COLOR_PRODUCTOR "Productor: Esperando a que haya espacio...");
        wait(capacidad_en_lista);       // Esperamos a que haya espacio en la lista
        puts(COLOR_PRODUCTOR "Productor: Hay espacio en la lista!");
        wait(mutex_lista);              // Esperamos a que la lista este disponible para usar
        poner_tarea(lista_tareas);
        signal(mutex_lista);            // Liberamos el mutex
                                        //
        signal(hay_tareas_pendientes);  // Avisamos que hay tareas en la lista
        
        sleep(DELAY_PRODUCTOR);
    }
    return NULL;
}

void* consumidor(void* _) {
    while (1) {
        puts(COLOR_CONSUMIDOR "Consumidor: Esperando tareas...");
        wait(hay_tareas_pendientes);
        puts(COLOR_CONSUMIDOR "Consumidor: Hay tareas pendientes!");

        wait(mutex_lista);
        tarea_t tarea = sacar_tarea(lista_tareas);
        signal(mutex_lista);

        signal(capacidad_en_lista);

        hacer(tarea);

        sleep(DELAY_CONSUMIDOR);
    }

    return NULL;
}


// --------------------------------------------------------------------


void poner_tarea(tarea_t* lista) {
    puts(COLOR_PRODUCTOR "Productor: Poniendo tarea...");
    for (int i = 0; i < CAPACIDAD_LISTA; i++) {
        if (lista[i] == 0){
            lista[i] = 1;
            printf(COLOR_PRODUCTOR "Productor: Hay lugar en %d\n", i);
            return;
        }
    }

    puts(COLOR_RED "\nProductor: Quise poner una tarea y no había espacio :(\n");
    exit(1);
}

tarea_t sacar_tarea(tarea_t* lista) {
    puts(COLOR_CONSUMIDOR "Consumidor: Sacando tarea...");
    for (int i = 0; i < CAPACIDAD_LISTA; i++) {
        if (lista[i] != 0){
            lista[i] = 0;
            printf(COLOR_CONSUMIDOR "Consumidor: Saqué la tarea %d\n", i);
            return 1;
        }
    }

    puts(COLOR_RED "\nConsumidor: Quise sacar una tarea y la lista estaba vacía :(\n");
    exit(1);
}

void hacer(tarea_t _) {}

int main() {

    // Inicializamos los semáforos
    init(hay_tareas_pendientes, 0);             // Al principio no hay tareas por realizar, arranca en 0
    init(capacidad_en_lista, CAPACIDAD_LISTA);  // Al princpio, la lista tiene CAPACIDAD_LISTA lugares
    init(mutex_lista, 1);                       // Los mutex siempre se inicializan en 1

    // -----------------------------------------
    
    // Inicializamos lista
    lista_tareas = malloc(CAPACIDAD_LISTA * sizeof(tarea_t));
    memset(lista_tareas, 0, CAPACIDAD_LISTA);   // 0 era la tarea NULL, o sea, vaciamos la lista
    
    // Creamos los threads
    create(thread_productor, productor);
    create(thread_consumidor, consumidor);

    join(thread_productor);
    join(thread_consumidor);

    return 0;

}
