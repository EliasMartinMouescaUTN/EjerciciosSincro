#include <stdio.h>

#include "../semaphores_wrap.h"

// TODO: Sean los procesos A, B y C, sincronizarlos para que ejecuten de manera alternada: A,B,C,A,B,C…
// -----------------------------------------

// - Globals -
// sem_t sem;

void setup() {
    // init(sem, 1);
}

void* procesoA(void*) {
    while(1){

        printf("A\n");


    }
}

void* procesoB(void*) {
    while(1){

        printf("B\n");


    }
}

void* procesoC(void*) {
    while(1){

        printf("C\n");

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


