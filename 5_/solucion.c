#include <stdio.h>

#include "../semaphores_wrap.h"

// TODO: Volver a realizar el ejercicio para que ejecuten: A,B,B,C,A,B,B,C…
// -----------------------------------------

// - Globals -
sem_t semA;
sem_t semB;
sem_t semC;

void setup() {
    init(semA, 1);
    init(semB, 0);
    init(semC, 0);
}

void* procesoA(void* _) {
    while(1){
        wait(semA);

        printf("A\n");

        signal(semB);
        signal(semB);
    }

}

void* procesoB(void* _) {
    while(1){
        wait(semB);

        printf("B\n");

        signal(semC);
    }
}

void* procesoC(void* _) {
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


