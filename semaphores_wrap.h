#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>      // For printf in peek()

// Wrappers! para no tener que escribir tanto "sem_" y tanto ampersand(&), y para que el codigo se parezca mas al pseudocodigo de la guia.

// == Semaforos ==
// wait(sem): Hace un wait al semaforo "sem". Ej: wait(semA);
#define wait(SEM) sem_wait(&SEM)

// signal(sem): Hace signal al semaforo "sem". Ej: signal(semA);
#define signal(SEM) sem_post(&SEM)

// init(sem, value): Inicializa el semaforo "sem" en el valor pasado como parametro. Hay que crear el semaforo primero.
// Ej:  sem_t semA; 
//      init(semA, 1);
#define init(SEM,SEM_VALUE) sem_init(&SEM, 0, SEM_VALUE);

// peek(sem): Imprime por stdout el nombre y valor del semaforo. Ej: peek(sem);
#define peek(SEM) {int SEM_VALUE; sem_getvalue(&SEM, &SEM_VALUE); printf(#SEM": %d\n", SEM_VALUE);}

// == Threads ==
// create(thread, worker): Crea un nuevo hilo que ejecuta "worker".
#define create(thread, worker) pthread_t thread; pthread_create(&thread, NULL, worker, NULL); 

// join(thread): Hace un join al thread.
#define join(thread) pthread_join(thread, NULL);


