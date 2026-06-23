#include <stdio.h>
#include "funciones.h"

int main (int argc, char *argv[]) {
    Libros libro[10];
    int opc=0, exit=0, cont=0;
    do
    {
        opc=menu();
        switch (opc)
        {
        case 1:
            Registrarlibro(libro, &cont);
            break;
        case 2:
            MostrarDatosLibro(libro,&cont);
            break;
        case 3:
            MostrarLibroEspecifico(libro,&cont);
            break;
        case 4:
            ActualizarEstado(libro, &cont);
            break; 
        case 5:
            EliminarLibro(libro, &cont);
            break;
        }
        printf("\nDesea seleccionar alguna otra opcion? (1.Si, 2.No / Salir)\n");
        exit=validacionentero(1,2);
    } while (exit ==1);
    return 0;
}