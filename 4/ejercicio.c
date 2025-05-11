#include <stdio.h>

#include "../semaphores_wrap.h"

// TODO: sean dos procesos A y B, sincronizarlos para que se ejecuten de manera alternada: A,B,A,B…
// -----------------------------------------

// - Globals -
// sem_t sem;

void setup() {
    // init(sem, 1);
}

void* procesoA(void* _) {
    while(1){

        printf("A\n");


    }
}

void* procesoB(void* _) {
    while(1){

        printf("B\n");


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


