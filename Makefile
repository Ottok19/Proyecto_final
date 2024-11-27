Sudoku: main.o renderizado_funcionalidad.o
	gcc -o Sudoku main.o renderizado_funcionalidad.o -lSDL2 -lSDL2_ttf

%.o: %.c
	gcc -Wall -c $<

clean:
	rm -f renderizado_funcionalidad.o main.o Sudoku
