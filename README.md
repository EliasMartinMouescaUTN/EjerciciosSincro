# Ejercicios sincro
Código con la resolución de algunos ejercicios de [esta guía](https://docs.google.com/document/d/1FpUSnTKrf_Da-aqMtZWpaEhZeH7ljRsABjX-q5M8QsM) de sincro. Con suerte, esto ayuda a bajar un poco a tierra los temas, los tipos de semáforos y eso.

## Ejercicios tipo BACA
En cada una de las carpetas [4](4/), [5](5/), [5_](5_/) y [6](6/) hay un archivo (_ejercicio.c_) con la template sin sincronizar y otro archivo (_solucion.c_) con el mismo código pero con los semáforos puestos.
![Ejemplo ejercicio 4](img/ej4.png)

## Ejemplo productor-consumidor
Además de las carpetas 4-6, está la carpeta de [productor consumidor](productor_consumidor). Tiene un ejemplo más básico y típico de productor-consumidor; así como está, funciona, ya está sincronizado, todo. Está hecho para ser interactivo, la idea es tocar el código y ver que pasa. Hay algunas constantes al principio de [main.c](productor_consumidor/main.c) que también está bueno revisar para hacer que el problema se manifieste más rápido o tarde más en aparecer.

#### Ejemplo 1
Si comentamos el _wait_ de tareas pendientes, vemos que el consumidor trata de sacar tareas hasta que la lista está vacía y rompe.
![Imagen ejemplo 1](img/ejemplo1.png)

#### Ejemplo 2
Si comentamos el _signal_ de tareas pendientes, el productor ejecuta hasta que llena la lista y el consumidor nunca llega a ejecutar porque justamente el productor no le avisa que hay tareas pendientes.
![Imagen ejemplo 2](img/ejemplo2.png)

#### Comparación con go
Dejé en la misma carpeta un archivo [main.go](productor_consumidor/main.go). Está ahí para ser un punto de comparación entre C y Go. [main.go](productor_consumidor/main.go) hace, en un principio, lo mismo que [main.c](productor_consumidor/main.c) pero mejor y con menos lineas, usando los canales de go. Se puede correr con `go run main.go`.

## Uso
Todas las carpetas tienen un link al Makefile en root. Estando en cualquier carpeta y hacer `make` compila todos los .c que encuentre. Probé los programas en windows 10 (_en proceso_) y en un derivado de ubuntu y andaba, cualquier cosa me hablan por [telegram](https://t.me/eliasmouesca) o por [mail](emouesca@frba.utn.edu.ar), cualquier idea también es bienvenida.

