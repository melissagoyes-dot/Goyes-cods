#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main (int argc, char *argv[]) {
    char nombres[10][20];
    int stock[10];
    float precio[10];
    int opc = 0, exit = 0, cont = 0;
    do
    {
        opc = menu();
        switch (opc)
        {
        case 1:
            cont = Producto(nombres,precio,stock,cont);
            break;
        case 2:
            verInventario(nombres,precio,stock,cont);
            break;
        case 3:
            OrdenPorPrecio(nombres, precio,cont);
            break;
        case 4: 
            buscarProducto(nombres,precio,cont);
            break;
        case 5:
            exit =2;
            break;
        }
        if (opc != 5)
        {
            printf("\nDesea seleccionar otra opcion (1.Si/2.No):");
            printf("\n>>");
            exit = validacionentero(1,2);
        }
    } while (exit == 1);
    return 0;
}