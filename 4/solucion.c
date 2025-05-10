#include <stdio.h>

#include "../semaphores_wrap.h"

// TODO: sean dos procesos A y B, sincronizarlos para que se ejecuten de manera alternada: A,B,A,B…
// -----------------------------------------

// - Globals -
sem_t semA;
sem_t semB;

void setup() {
    init(semA, 1);
    init(semB, 0);
}

void* procesoA(void*) {
    while(1){
        wait(semA);

        printf("A\n");

        signal(semB);

    }
}

void* procesoB(void*) {
    while(1){
        wait(semB);

        printf("B\n");

        signal(semA);

    }
}








// --------------------------------------------
int main() {
    setup();

    create(a, procesoA);
    create(b, procesoB);

    join(a);
    join(b);

    return 0;
}


