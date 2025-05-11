package main

import (
	"fmt"
	"time"
)

const (
	ColorReset      = "\033[0m"
	ColorRed        = "\033[31m"
	ColorGreen      = "\033[32m"
	ColorBlue       = "\033[34m"
	ColorProductor  = ColorGreen
	ColorConsumidor = ColorBlue
)

// ---- Constantes ----
const (
	DelayProductor  = 1000 * time.Millisecond
	DelayConsumidor = 1000 * time.Millisecond
	CapacidadLista  = 5
)

type Tarea int

func ponerTarea(lista chan<- Tarea) {
	fmt.Println(ColorProductor + "Productor: Esperando a que haya espacio..." + ColorReset)
	// Esto directamente se bloquea si no hay espacio para agregar una tarea
	lista <- Tarea(1)

	// En el ejemplo de C, esto son dos momentos separados: esperar a que haya espacio Y poner la tarea
	// Aca, con el canal, es t0do una misma operacion
	fmt.Println(ColorProductor + "Productor: Hay espacio en la lista! Puse una tarea" + ColorReset)
}

func sacarTarea(lista <-chan Tarea) Tarea {
	fmt.Println(ColorConsumidor + "Consumidor: Esperando tareas..." + ColorReset)
	// Esto directamente se bloquea si no hay nada que sacar de la lista (no hay tareas pendientes)
	tarea := <-lista

	// En el ejemplo de C, esto son dos momentos separados: esperar a que haya tareas pendientes Y sacar la tarea
	// Aca, se hace t0do en una misma operacion
	fmt.Println(ColorConsumidor + "Consumidor: Hay tareas pendientes! Saque una tarea" + ColorReset)
	return tarea
}

func hacer(tarea Tarea) {}

func productor(lista chan Tarea) {
	for {
		ponerTarea(lista)
		time.Sleep(DelayProductor)
	}
}

func consumidor(lista chan Tarea) {
	for {
		tarea := sacarTarea(lista)
		hacer(tarea)
		time.Sleep(DelayConsumidor)
	}
}

func main() {
	// Esto cumple el rol de lista_tareas y los 3 semaforos de C, en una sola variable
	lista := make(chan Tarea, CapacidadLista) // Semaforos? Que es eso? Un solo channel alcanza!

	// Mas bonito que hacer los pthread_t t, pthread_create(...), ...
	go productor(lista)
	go consumidor(lista)

	// Equivalente a las lineas de pthread_join(thread) en C,
	// solo que este no hace join a los hilos sino que queda esperando por siempre
	select {}
}
