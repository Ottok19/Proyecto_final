#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include "renderizado_funcionalidad.h"

int main () {

	crear_ventana();

        TTF_Font *font = TTF_OpenFont("GeistMono-VariableFont_wght.ttf", 24); //Se inicializa la fuente a utilizar

        if (!font) {
                printf("Failed to load font: %s\n", TTF_GetError()); //En caso de no poder inicializar la fuente

        }

        correr_juego(font);

        destruir_ventana(font);

        return 0;

}
