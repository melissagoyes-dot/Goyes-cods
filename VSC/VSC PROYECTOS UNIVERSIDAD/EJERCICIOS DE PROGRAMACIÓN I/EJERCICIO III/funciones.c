#include <stdio.h>
#include <string.h>
#include "funciones.h"

float validacion(float min)
{
    float n = 0;
    int aux = 0;
    do
    {
        aux = scanf("%f", &n);
        limpiarBuffer();
        if (aux != 1 || n < min)
        {
            printf("\nERROR: EL DATO INGRESADO ES ERRONEO, INTENTELO NUEVAMENTE\n>> ");
        }
    } while (aux != 1 || n < min);
    return n;
}
int validacionentero(int a, int b)
{
    int n = 0, aux = 0;
    do
    {
        aux = scanf("%d", &n);
        limpiarBuffer();
        if (aux != 1 || n < a || n > b)
        {
            printf("\nERROR: EL DATO INGRESADO ES INCORRECTO, INTENTELO NUEVAMENTE\n>> ");
        }
    } while (aux != 1 || n < a || n > b);
    return n;
}
void limpiarSaltoDeLinea(char cadena[])
{
    cadena[strcspn(cadena, "\n")] = '\0';
}
void limpiarBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
int menu()
{
    int opc = 0;
    printf("\n-------Bienvenidx al programa de gestion------\n");
    printf("\nSeleccione una opcion para continuar:\n");
    printf("1.Registrar producto\n");
    printf("2.Ver inventario\n");
    printf("3.Encontrar el producto mas caro y mas barato\n");
    printf("4.Buscar producto por nombre\n");
    printf("5.Salir\n");
    printf(">>");
    opc = validacionentero(1, 5);
    return opc;
}
int Producto(char nombres[10][20], float precio[10], int stock[10], int cont)
{
    if (cont < 10)
    {
        printf("Ingrese el nombre del producto %d:\n", cont + 1);
        printf(">>");
        fgets(nombres[cont], 20, stdin);
        limpiarSaltoDeLinea(nombres[cont]);
        printf("Ingrese el precio del producto %d:\n", cont + 1);
        printf(">>");
        precio[cont] = validacion(0);
        printf("Ingrese el stock del producto %d:\n", cont + 1);
        printf(">>");
        stock[cont] = validacionentero(0, 9999);
        printf("\nSE HA REGISTRADO EL PRODUCTO CON EXITO\n");
        return cont + 1;
    }
    else
    {
        printf("\nERROR: SE HAN INGRESADO EL LIMITE DE PRODUCTOS\n");
        return cont;
    }
}
void verInventario(char nombres[10][20], float precio[10], int stock[10], int cont)
{
    float totalProducto = 0, totalInventario = 0, precioPromedio = 0;
    if (cont == 0)
    {
        printf("\nERROR: NO SE HAN INGRESADO PRODUCTOS\n");
    }
    else
    {
        printf("\nINVENTARIO DEL LOCAL\n");
        printf("#\t\tNombre\t\tStock\t\tPrecio\t\tTotal\n");
        for (int i = 0; i < cont; i++)
        {
            totalProducto = stock[i] * precio[i];
            totalInventario += totalProducto;
            precioPromedio += precio[i];
            printf("%d\t\t%s\t\t%d\t\t%.2f\t\t%.2f\n", i, nombres[i], stock[i], precio[i], totalProducto);
        }
        printf("------------------------------------------------------------------------------------------------\n");
        printf("Total inventario: %.2f\n", totalInventario);
        precioPromedio /= cont;
        printf("Precio promedio de los productos: %.2f\n", precioPromedio);
    }
}
void OrdenPorPrecio(char nombres[10][20], float precio[10], int cont)
{
    int caro = 0, barato = 0;
    if (cont == 0)
    {
        printf("\nERROR: NO SE HAN INGRESADO PRODUCTOS\n");
        return;
    }
    for (int i = 1; i < cont; i++)
    {
        if (precio[i] > precio[caro])
        {
            caro = i;
        }
        if (precio[i] < precio[barato])
        {
            barato = i;
        }
    }
    printf("\n--- RESULTADOS ---\n");
    printf("\nProducto mas caro: %s (Precio: %.2f)\n", nombres[caro], precio[caro]);
    printf("Producto mas barato: %s (Precio: %.2f)\n", nombres[barato], precio[barato]);
}
void buscarProducto(char nombres[10][20], float precio[10], int cont)
{
    char busqueda[20];
    int encontrado = 0;
    if (cont == 0)
    {
        printf("\nERROR: NO SE HAN INGRESADO PRODUCTOS\n");
        return;
    }
    else
    {
        printf("\nIngrese el nombre del producto a buscar: \n>>");
        fgets(busqueda, 20, stdin);
        limpiarSaltoDeLinea(busqueda);
        for (int i = 0; i < cont; i++)
        {
            if (strcmp(nombres[i], busqueda) == 0)
            {
                printf("\nPRODUCTO ENCONTRADO:\n");
                printf("Nombre: %s | Precio: %.2f\n", nombres[i], precio[i]);
                encontrado = 1;
                break;
            }
        }
        if (encontrado == 0)
        {
            printf("\nERROR: EL PRODUCTO %s NO SE ENCUENTRA EN EL INVERNTARIO\n", busqueda);
        }
    }
}