#ifndef RENDERIZADO_FUNCIONALIDAD_H
#define RENDERIZADO_FUNCIONALIDAD_H

// Esta función se encarga de crear la ventana y el renderer que se utilizaran para realizar el sudoku.

void crear_ventana();


// Esta función se encarga de renderizar el tablero a partir del renderer reccibido, generando las líneas
// verticales y horizontales para dividir el tablero en 9x9 casillas, diferenciando las líneas 3 y 6 de
// diferente color para resaltar los cuadradados 3x3 individuales del sudoku.

void renderizar_tablero(SDL_Renderer * renderer);

// Esta función se encarga de renderizar y mostrar en pantalla los números iniciales y los que se van introduciendo
// mientras el juego está corriendo utilizando el renderer y la fuente recibidas.

void renderizar_numeros(SDL_Renderer *renderer, TTF_Font *font);

// Esta función se encarga de configurar las entradas que va a leer el programa, y asignar la celda seleccionada
// y el número que se quiere introducir en ella, a la vez que valida si es el número correcto o no, y lleva un
// contador de los números correctos para indicar que se completo el juego con éxito una vez se ingresen todos
// los números correctos faltantes. La función recibe el puntero al evento e que es el que alamcena cada entrada
// que presiona el usuario.

void leer_entradas(SDL_Event*e);

// Esta función recibe la fuente de la textura y se encarga de correr el juego y actualizar sus entradas y
// renderizado hasta que el usuario decide salir. Esta función contiene dentro de ella las funciones leer_entrada(),
// renderizar_tablero() y renderizar_numero() en un ciclo que termina al salir del juego.

void correr_juego(TTF_Font *font);

// Esta función recibe la fuente de la textura y se encarga de eliminar la ventana y el renderer creado, junto a la
// fuente inicializada, y salir tanto de la librería SDL2 como de su extensión TTF.

void destruir_ventana(TTF_Font *font);


#endif
