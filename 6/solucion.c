#include <stdio.h>

#include "../semaphores_wrap.h"

// TODO: Sean los procesos A, B y C, sincronizarlos para que ejecuten de la siguiente manera: B,A,C,A,B,A,C,A...
// -----------------------------------------

// - Globals -
sem_t semA;
sem_t semB;
sem_t semC;
sem_t semBoC;

void setup() {
    init(semA, 0);
    init(semB, 1);
    init(semC, 0);
    init(semBoC, 1);
}

void* procesoA(void*) {
    while(1){
        wait(semA);

        printf("A\n");

        signal(semBoC);
    }

}

void* procesoB(void*) {
    while(1){
        wait(semB);
        wait(semBoC);

        printf("B\n");

        signal(semA);
        signal(semC);
    }
}

void* procesoC(void*) {
    while(1){
        wait(semC);
        wait(semBoC);

        printf("C\n");

        signal(semA);
        signal(semB);
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


