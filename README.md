# Ejercicios sincro
Código con la resolución de algunos ejercicios de [esta guía](https://docs.google.com/document/d/1FpUSnTKrf_Da-aqMtZWpaEhZeH7ljRsABjX-q5M8QsM) de sincro. Con suerte, esto ayuda a bajar un poco a tierra los temas, los tipos de semáforos y eso.

## Ejercicios tipo BACA
En cada una de las carpetas [4](4/), [5](5/), [5_](5/) y [6](6/) hay un archivo (ejercicio.c) con la template sin sincronizar y otro archivo (solucion.c) con el mismo código pero con los semáforos puestos.
![Ejemplo ejercicio 4](img/ej4.png)

## Ejemplo productor-consumidor
Además de las carpetas 4-6 está la carpeta de [productor consumidor](productor_consumidor). Tiene un ejemplo mínimo de productor consumidor, está hecho para ser interactivo: así como está funciona, ya está sincronizado todo. Creo que lo mejor es tocar el código y ver que pasa.

#### Ejemplo 1
Si comentamos el _wait_ de tareas pendientes, vemos que el consumidor trata de sacar tareas hasta que la lista está vacía y rompe.
![Imagen ejemplo 1](img/ejemplo1.png)

#### Ejemplo 2
Si comentamos el _signal_ de tareas pendientes, el productor ejecuta hasta que llena la lista y el consumidor nunca llega a ejecutar porque justamente el productor no le avisa que hay tareas pendientes.
![Imagen ejemplo 2](img/ejemplo2.png)
