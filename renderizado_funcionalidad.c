#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include "renderizado_funcionalidad.h"

#define SCREEN 630
#define CELL 70
#define GRID 9

SDL_Window * window = NULL;
SDL_Renderer * renderer = NULL;

int FilaActual;
int ColumnaActual;

int sudoku[GRID][GRID] = {
                {8, 0, 0, 0, 7, 5, 0, 9, 4},
                {0, 6, 0, 9, 8, 4, 0, 0, 1},
                {7, 0, 0, 3, 0, 1, 0, 0, 8},
                {0, 7, 8, 0, 0, 6, 4, 2, 0},
                {3, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 6, 7},
                {0, 3, 5, 6, 0, 0, 8, 0, 2},
                {0, 0, 0, 7, 5, 0, 0, 0, 6},
                {6, 2, 7, 4, 3, 8, 9, 0, 5}
        };


void crear_ventana() {

        SDL_Init(SDL_INIT_VIDEO);
        TTF_Init();

        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
                printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        }

        if (TTF_Init() == -1) {
                printf("TTF_Init failed! SDL_ttf Error: %s\n", TTF_GetError());
                SDL_Quit();
        }

        window = SDL_CreateWindow("Sudoku",		  //Nombre de la ventana
                                  SDL_WINDOWPOS_CENTERED, //Posición de la ventana en x
                                  SDL_WINDOWPOS_CENTERED, //Posición de la ventana en y
                                  SCREEN,		  //Ancho de la ventana
                                  SCREEN,		  //Alto de la ventana
				  SDL_WINDOW_SHOWN);	  //Para mostrar la ventana

        renderer = SDL_CreateRenderer(window,			 //Ventana donde se renderizará 
				      -1, 			 //Drivers, -1 por defecto
				      SDL_RENDERER_ACCELERATED); //Flags

}

void renderizar_tablero(SDL_Renderer * renderer) {

        for (int i = 0; i <= GRID; ++i) {

                if( (i == 3) || (i == 6) ) {

                        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Color rojo

                }

                else {
                        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);   // Color negro
                }
                SDL_RenderDrawLine(renderer,
                                   i * CELL, 0,
                                   i * CELL, SCREEN); // Líneas verticales
                SDL_RenderDrawLine(renderer,
                                   0, i * CELL,
                                   SCREEN, i * CELL); // Líneas horizontales
        }

}

void renderizar_numeros(SDL_Renderer *renderer, TTF_Font *font) {

        for (int i = 0; i < GRID; ++i) {
                for (int j = 0; j < GRID; ++j) {
                        if( sudoku[i][j] != 0 ) {

                                char number[2];
                                sprintf(number, "%d", sudoku[i][j]);
                                SDL_Color numberColor = {0, 0, 0, 255}; // Color negro
                                SDL_Surface *surface = TTF_RenderText_Solid(font, number, numberColor);
                                SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
                                int textWidth = surface->w;	//Se extrae el ancho de la fuente de texto
                                int textHeight = surface->h;    //Se extrae el alto de la fuente de texto
                                SDL_Rect destRect = {j * CELL + (CELL-textWidth)/2,	// Celda en columnas
                                                     i * CELL + (CELL-textHeight)/2,	// Celda en filas
                                                     textWidth,textHeight};	// Ancho y alto del número

                                SDL_RenderCopy(renderer, texture, NULL, &destRect);
                                SDL_FreeSurface(surface);
                                SDL_DestroyTexture(texture);
                        }
                }
        }

}

void leer_entradas(SDL_Event*e) {

        int solucion[GRID][GRID] = {
                {0, 1, 3, 2, 0, 0, 6, 0, 0},
                {5, 0, 2, 0, 0, 0, 7, 3, 0},
                {0, 9, 4, 0, 6, 0, 2, 5, 0},
                {1, 0, 0, 5, 9, 0, 0, 0, 3},
                {0, 4, 6, 1, 2, 7, 5, 8, 9},
                {2, 5, 9, 8, 4, 3, 1, 0, 0},
                {4, 0, 0, 0, 1, 9, 0, 7, 0},
                {9, 8, 1, 0, 0, 2, 3, 4, 0},
                {0, 0, 0, 0, 0, 0, 0, 1, 0}

        };

        if (e->type==SDL_MOUSEBUTTONDOWN) {		//Cuando se presiona el ratón

                FilaActual = e->button.y/CELL;
                ColumnaActual = e->button.x/CELL;

                printf("Ha seleccionado la casilla %d %d\n", FilaActual+1, ColumnaActual+1);

        }

        int numero;

        if (e->type==SDL_KEYDOWN) {			// Cuando se presiona una tecla
                if(e->key.keysym.sym == SDLK_1) {	// Tecla número 1
                        numero = 1;
                }
                if(e->key.keysym.sym == SDLK_2) {	// Tecla número 2
			numero = 2;
                }
                if(e->key.keysym.sym == SDLK_3) {	// Tecla número 3
                        numero = 3;
                }
                if(e->key.keysym.sym == SDLK_4) {	// Tecla número 4
                        numero = 4;
                }
                if(e->key.keysym.sym == SDLK_5) {	// Tecla número 5
                        numero = 5;
                }
                if(e->key.keysym.sym == SDLK_6) {	// Tecla número 6
                        numero = 6;
                }
                if(e->key.keysym.sym == SDLK_7) {	// Tecla número 7
                        numero = 7;
                }
                if(e->key.keysym.sym == SDLK_8) {	// Tecla número 8
                        numero = 8;
                }
                if(e->key.keysym.sym == SDLK_9) {	// Tecla número 9
                        numero = 9;
                }
		
		// Si la casilla no tiene número y el número que se quiere ingresar es el correcto entonces
		// se realiza la actualización en el sudoku para renderizar el nuevo número.

                if(sudoku[FilaActual][ColumnaActual] == 0) {			
                        if(numero == solucion[FilaActual][ColumnaActual]) {
                                sudoku[FilaActual][ColumnaActual] = numero;
                        }
                        else {
                                printf("El número %d no va en esta posición\n", numero);
                        }

		}

                int contador = 0;
		
		// Si el contador llega a 43, el número de números qu hay que ingresar para completar el 
		// sudoku, entonces se imprime el mensaje felicitando al usuario.

                for (int i = 0; i < GRID; ++i) {
                        for (int j = 0; j < GRID; ++j) {
                                if( sudoku[i][j] == solucion[i][j] ) {
                                        contador += 1;
                                        if ( sudoku[i][j] != solucion[i][j] ) {
                                                contador = 0;
                                        }
                                }
                        }
                }

                if ( contador == 43 ) {
                        printf("Felicidades, ha completado el juego\n");
                }
        }

}

void correr_juego(TTF_Font *font) {

        int running = 1;
        SDL_Event e;
		
		// Ciclo para mantener el programa leyendo eventos y renderizandolos cuando sea necesario mientras
		// no se cierre la ventana.

                while (running) {
                while (SDL_PollEvent(&e)) {
                        if (e.type == SDL_QUIT) {
                                running = 0;
                        }

                        leer_entradas(&e); // Función para leer eventos

                }

                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Color blanco
                SDL_RenderClear(renderer);

                renderizar_tablero(renderer);		// Función para renderizar el tablero
                renderizar_numeros(renderer, font);	// Función para renderizar los números

                SDL_RenderPresent(renderer);
        }
}

void destruir_ventana(TTF_Font *font) {

        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_CloseFont(font);
        TTF_Quit();
	SDL_Quit();

}

