#include <stdio.h>
#include <string.h>
#include <ctype.h>
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
    int opc;
    printf("\n-----BienvenidX al sistema de la biblioteca------- \n");
    printf("-Seleccione una opcion para continuar \n");
    printf("1. Registrar nuevos libros\n");
    printf("2. Mostrar libros registrados\n");
    printf("3. Mostrar libro especifico registrado\n");
    printf("4. Actualizar estado de permanencia de algun libro\n");
    printf("5. Elimminar libro de la biblioteca\n");
    printf(">>> ");
    opc = validacionentero(1, 5);
    return opc;
}

int BuscarID(Libros libro[], int *n, int idBuscado)
{
    int index = -1;
    for (int i = 0; i < *n; i++)
    {
        if (libro[i].ID == idBuscado)
        {
            index = i;
            break;
        }
    }
    return index;
}

int BuscarPorTitulo(Libros libro[], int *n, char tituloBuscado[])
{
    int index = -1;
    for (int i = 0; i < *n; i++)
    {
        if (strcmp(libro[i].titulo, tituloBuscado) == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

void PedirEstado(char estadoFinal[])
{
    int valido = 0;
    char entradaTemporal[20];
    do
    {
        fgets(entradaTemporal, 20, stdin);
        limpiarSaltoDeLinea(entradaTemporal);
        for (int i = 0; entradaTemporal[i] != '\0'; i++)
        {
            entradaTemporal[i] = tolower(entradaTemporal[i]); // el tolower convierte en minusculas
        }
        if (strcmp(entradaTemporal, "disponible") == 0)
        {
            strcpy(estadoFinal, "Disponible");
            valido = 1;
        }
        else if (strcmp(entradaTemporal, "prestado") == 0)
        {
            strcpy(estadoFinal, "Prestado");
            valido = 1;
        }
        else
        {
            printf("\nERROR: SE HA INGRESADO UNA RESPUESTA INVALIDA , INTENTELO NUEVAMENTE\n");
        }
    } while (valido == 0);
}

void Registrarlibro(Libros libros[], int *n)
{
    int index = 0, TemporalID = 0;
    if (*n < 10)
    {
        printf("\n---- REGISTRO DE LIBRO --------\n");
        do
        {
            printf("Ingrese el ID unico de 6 digitos para el nuevo libro\n >>> ");
            TemporalID = validacionentero(100000, 999999);
            index = BuscarID(libros, n, TemporalID);
            if (index != -1)
            {
                printf("\n**ERROR: EL ID COLOCADO YA SE ENCUENTRA EN UN LIBRO EXISTENTE , PORFAVOR VUELVA A INTENTARLO**\n");
            }
        } while (index != -1);
        libros[*n].ID = TemporalID;
        printf("Ingrese el titulo del nuevo libro:\n >>> ");
        fgets(libros[*n].titulo, 100, stdin);
        limpiarSaltoDeLinea(libros[*n].titulo);
        printf("Ingrese el autor del nuevo libro:\n >>> ");
        fgets(libros[*n].autor, 20, stdin);
        limpiarSaltoDeLinea(libros[*n].autor);
        printf("Ingrese el año de publicacion del nuevo libro:\n >>> ");
        libros[*n].añoDePublicacion = validacionentero(868, 2026); // le pongo desde 868 pq es el libro mas antiguo que hay con esa fecha , y 2026 pq es este año ps xd//
        printf("El libro se encuentra disponible o prestado? (Escriba su respuesta (Disponible o Prestado))\n >>> ");
        PedirEstado(libros[*n].Estado);
        (*n)++;
        printf("\n.*.*.*.*.*.* SE HA REGISTRADO EL NUEVO LIBRO *.*.*.*.*.*.*.*\n");
    }
    else
    {
        printf("\nERROR: YA SE HAN INGRESADO EL MAXIMO DE LIBROS PARA LA BIBLIOTECA\n");
    }
}

void MostrarDatosLibro(Libros libro[], int *n)
{
    if (*n == 0)
    {
        printf("ERROR: NO SE HA REGISTRADO NINGUN LIBRO\n");
    }
    else
    {
        printf("#\t\tID\t\tTITULO\t\tAUTOR DEL LIBRO\t\tAÑO DE PUBLICACION\t\tESTADO DEL LIBRO\n");
        for (int i = 0; i < *n; i++)
        {
            printf("%d\t\t%d\t\t%s\t\t%s\t\t\t%d\t\t\t%s\n", i + 1, libro[i].ID, libro[i].titulo, libro[i].autor, libro[i].añoDePublicacion, libro[i].Estado);
        }
    }
}

void MostrarLibroEspecifico(Libros libro[], int *n)
{
    int index = -1, TemporalID = 0, opc = 0, encontrados = 0;
    char TemporalTitulo[100];
    if (*n == 0)
    {
        printf("ERROR: NO SE HA REGISTRADO NINGUN LIBRO\n");
    }
    else
    {
        printf("-------Busqueda especializada de libros-------\n");
        printf("Porfavor seleccione por cual medio buscar el libro en especifico\n1- Titulo \n2- ID\n>>> ");
        opc = validacionentero(1, 2);
        switch (opc)
        {
        case 1:
            printf("Ingrese el TITULO del libro que desea buscar:\n >>> ");
            fgets(TemporalTitulo, 100, stdin);
            limpiarSaltoDeLinea(TemporalTitulo);
            printf("\n--- RESULTADOS DE LA BUSQUEDA ---\n");
            printf("#\tID\tTITULO\t\tAUTOR\t\tAÑO DE PUBLICACION\tESTADO\n");
            for (int i = 0; i < *n; i++)
            {
                if (strcmp(libro[i].titulo, TemporalTitulo) == 0)
                {
                    printf("%d\t%d\t%s\t\t%s\t\t\t%d\t\t\t%s\n", i + 1, libro[i].ID, libro[i].titulo, libro[i].autor, libro[i].añoDePublicacion, libro[i].Estado);
                    encontrados++;
                }
            }
            if (encontrados == 0)
            {
                printf("\nERROR:NO SE ENCONTRO NINGUN LIBRO CON ESE TITULO\n");
            }
            else
            {
                printf("\nSe encontraron %d libro(s) con el titulo '%s'\n", encontrados, TemporalTitulo);
            }
            break;
        case 2:
            printf("Ingrese el ID del libro que desea ver su informacion individual\n");
            TemporalID = validacionentero(100000, 999999);
            index = BuscarID(libro, n, TemporalID);
            if (index == -1)
            {
                printf("\nERROR: NO SE ENCUENTRA EL ID VUELVA A INTENTALO NUEVAMENTE\n");
            }
            else
            {
                printf("ID\t\tTITULO\t\tAUTOR DEL LIBRO\t\tAÑO DE PUBLICACION\t\tESTADO DEL LIBRO\n");
                printf("%d\t\t%s\t\t%s\t\t\t%d\t\t\t%s\n", libro[index].ID, libro[index].titulo, libro[index].autor, libro[index].añoDePublicacion, libro[index].Estado);
            }
            break;
        }
    }
}

void ActualizarEstado(Libros libro[], int *n)
{
    int index = -1, TemporalID = 0;
    if (*n == 0)
    {
        printf("ERROR: NO SE HA REGISTRADO NINGUN LIBRO\n");
    }
    else
    {
        printf("Ingrese el ID del libro que desea actualizar su estado de permanencia\n");
        TemporalID = validacionentero(100000, 999999);
        index = BuscarID(libro, n, TemporalID);
        if (index == -1)
        {
            printf("\nERROR: NO SE ENCUENTRA EL ID INGRESADO\n");
        }
        else
        {
            printf("DATOS GENERALES DEL LIBRO SELECCIONADO:\n");
            printf("\nID\t\tTITULO\t\tAUTOR DEL LIBRO\t\tAÑO DE PUBLICACION\t\tESTADO DEL LIBRO\n");
            printf("%d\t\t%s\t\t%s\t\t\t%d\t\t\t%s\n", libro[index].ID, libro[index].titulo, libro[index].autor, libro[index].añoDePublicacion, libro[index].Estado);
            printf("\nIngrese el nuevo estado de permanencia del libro:\n");
            PedirEstado(libro[index].Estado);
            printf("*****ESTADO DE PERMANENCIA ACTUALIZADO CORRECTAMENTE*****\n");
        }
    }
}

void EliminarLibro(Libros libro[], int *n)
{
    int index = 0, TemporalID = 0;
    
    if (*n == 0)
    {
        printf("\nERROR: NO SE HA REGISTRADO NINGUN LIBRO\n");
    }
    else
    {
        printf("\n------ELIMINADOR DE LIBROS----\n");
        printf("\n----Datos generales de los libros registrados-----\n");
        MostrarDatosLibro(libro, n);
        
        printf("\nID del libro que desea eliminar:\n>>> ");
        TemporalID = validacionentero(100000, 999999);
        index = BuscarID(libro, n, TemporalID);
        
        if (index == -1)
        {
            printf("\nERROR: NO SE HA ENCONTRADO EL ID INGRESADO\n");
        }
        else
        {
            for (int i = index; i < (*n) - 1; i++)
            {
                libro[i] = libro[i + 1];
            }
            (*n)--;
            printf("\n****** Libro eliminado con exito ******\n");
        }
    }
}