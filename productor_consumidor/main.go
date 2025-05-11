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
	fmt.Println(ColorProductor + "Productor: Esperando a que haya espacio...")
	// Esto directamente se bloquea si no hay espacio para agregar una tarea
	lista <- Tarea(1)

	// En el ejemplo de C, esto son dos momentos separados: esperar a que haya espacio Y poner la tarea
	// Acá, con el canal, es t0do una misma operación
	fmt.Println(ColorProductor + "Productor: Hay espacio en la lista! Puse una tarea")
}

func sacarTarea(lista <-chan Tarea) Tarea {
	fmt.Println(ColorConsumidor + "Consumidor: Esperando tareas...")
	// Esto directamente se bloquea si no hay nada que sacar de la lista (no hay tareas pendientes)
	tarea := <-lista

	// En el ejemplo de C, esto son dos momentos separados: esperar a que haya tareas pendientes Y sacar la tarea
	// Acá, se hace t0do en una misma operación
	fmt.Println(ColorConsumidor + "Consumidor: Hay tareas pendientes! Saqué una tarea")
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
	// Esto cumple el rol de lista_tareas y los 3 semáforos de C, en una sola variable
	lista := make(chan Tarea, CapacidadLista) // Semáforos? Qué es eso? Un solo channel alcanza!

	// Más bonito que hacer los pthread_t t, pthread_create(...), ...
	go productor(lista)
	go consumidor(lista)

	// Equivalente a las lineas de pthread_join(thread) en C,
	// solo que este no hace join a los hilos sino que queda esperando por siempre
	select {}
}
