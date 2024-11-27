# Proyecto_final

Este proyecto desarrolla un juego de Sudoku utilizando el lenguaje de C. El Sudoku tiene su propia interfaz gráfica interactiva donde el usuario puede seleccionar la casilla que desee e ingresar el número que crea correcto y el programa validará si ese es el número de la solución y lo dibujará en la casilla, o por el contrario, le indicará al usuarió que el número que quiere ingresar no va en esa casilla. Al completar el Sudoku el programa muestra un mensaje de felicitación al usuario.

Es importante aclarar que el programa solo cuenta con un sudoku y que para volverlo a jugar se debe cerrar y correr de nuevo el programa. La validación de la solución se realiza comparando el sudoku con su solución.

# Dependencias e instalación

Para este programa se utiliza la librería estandar de stdio.h la cual viene con el lenguaje C. Además, se utiliza la biblioteca SDL2 y su extensión TTF las cuales se pueden instalar con los siguiente comandos:

sudo apt-get install libsdl2-dev

sudo apt-get install libsdl2-ttf-dev

# Pasos para ejecución

Para ejecutar el programa se deben descargar los archivos de este repositorio en una misma carpeta, incluyendo la fuente .ttf, y simplemente correr el comando make, con el cual el archivo Makefile se encargara de compilar el programa y con el comando ./Sudoku se puede correr el mismo.
Adicionalmente, si desea limpiar los archivos, puede correr el comando make clean, el cual elimina los archivos .o y el binario ejecutable que se haya generado.
