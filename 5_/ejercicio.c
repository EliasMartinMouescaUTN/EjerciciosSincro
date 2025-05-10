#include <stdio.h>

#include "../semaphores_wrap.h"

// TODO: Volver a realizar el ejercicio para que ejecuten: A,B,B,C,A,B,B,C…
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


