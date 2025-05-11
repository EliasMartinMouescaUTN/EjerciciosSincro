#include <stdio.h>

#include "../semaphores_wrap.h"

// TODO: Sean los procesos A, B y C, sincronizarlos para que ejecuten de la siguiente manera: B,A,C,A,B,A,C,A...
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

void* procesoC(void* _) {
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


