#include <stdio.h>

#include "../semaphores_wrap.h"

// TODO: Sean los procesos A, B y C, sincronizarlos para que ejecuten de la siguiente manera: B,A,C,A,B,A,C,A...
// -----------------------------------------

// - Globals -
sem_t semA;
sem_t semB;
sem_t semC;

void setup() {
    init(semA, 0);
    init(semB, 2);
    init(semC, 1);
}

void* procesoA(void*) {
    while(1){
        wait(semA);

        printf("A\n");

        signal(semB);
        signal(semC);
    }

}

void* procesoB(void*) {
    while(1){
        wait(semB);
        wait(semB);

        printf("B\n");

        signal(semA);
    }
}

void* procesoC(void*) {
    while(1){
        wait(semC);
        wait(semC);

        printf("C\n");

        signal(semA);
    }
}







// --------------------------------------------
int main() {
    setup();

    create(a, procesoA);
    create(b, procesoB);
    create(c, procesoC);

    join(a);
    join(b);
    join(c);

    return 0;
}


