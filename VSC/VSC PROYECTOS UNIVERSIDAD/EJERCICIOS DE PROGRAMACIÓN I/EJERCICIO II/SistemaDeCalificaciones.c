#include <stdio.h>
int main(int argc, char const *argv[])
{
    float calificacion[5][3][3] = {0};
    float PromediosPorMateria[5][3][1] = {0};
    float PromediosGenerales[5][1] = {0};
    char nombres[5][20];
    char asignaturas[3][20] = {"Matemáticas", "Fisica", "Química"};
    int opc, aux, alumno = 0, selAlumno = 0, aprobados = 0, reprobados = 0;
    float suma, notaMax, notaMin, notaActual, promedioClase = 0;
    do
    {
        printf("\n------Bienvenidx al sistema de calificaciones------\n");
        do
        {
            printf("\n Seleccione una opción para continuar\n");
            printf("1. Registrar nombre de un nuevo alumno\n");
            printf("2. Registrar calificaciones del alumno\n");
            printf("3. Promedio de cada alumno por asignatura\n");
            printf("4. Promedio general de cada alumno\n");
            printf("5. Promedio general de cada asignatura\n");
            printf("6. Calificación mas alta y baja por estudiante\n");
            printf("7. Calificación más alta y baja por materia\n");
            printf("8. Estudiamtes aprobados y reprobados por asignatura\n");
            printf("9. Salir\n");
            printf("\nSe han registrado %d alumnos", alumno);
            printf("\n>>");
            fflush(stdin);
            aux = scanf("%d", &opc);
            if (aux != 1 || opc < 0 || opc > 9)
            {
                printf("\nERROR: EL DATO INGRESADO ES ERRONEO, INTENTELO NUEVAMENTE\n");
            }
        } while (aux != 1 || opc < 0 || opc > 9);
        switch (opc)
        {
        case 1:
            if (alumno < 5)
            {
                printf("Ingrese el nombre del alumno %d:\n", alumno + 1);
                fflush(stdin);
                fgets(nombres[alumno], 20, stdin);
                alumno++;
                printf("\n ALUMNO REGISTRADO CON EXITO  \n");
            }
            else
            {
                printf("\nERROR: YA A REGISTRADO EL MÁXIMO DE ALUMNOS\n");
            }
            break;
        case 2:
            if (alumno == 0)
            {
                printf("\nERROR: NO SE HA REGISTRADO NINGUN ALUMNO AL SISTEMA\n");
            }
            else
            {
                do
                {
                    printf("\nSeleccione el alumno del que va a registrar las calificaciones:\n");
                    for (int i = 0; i < alumno; i++)
                    {
                        printf("\n%d, %s", i + 1, nombres[i]);
                    }
                    printf("\n>>");
                    fflush(stdin);
                    aux = scanf("%d", &selAlumno);
                    if (aux != 1 || selAlumno < 1 || selAlumno > alumno)
                    {
                        printf("\nERROR: EL DATO INGRESADO ES ERRONEO, INTENTELO NUEVAMENTE\n");
                    }
                } while (aux != 1 || selAlumno < 1 || selAlumno > alumno);
                do
                {
                    printf("\nSeleccione la materia de la cual va a registrar las notas:\n");
                    for (int i = 0; i < 3; i++)
                    {
                        printf("\n%d, %s", i + 1, asignaturas[i]);
                    }
                    printf("\n>>");
                    fflush(stdin);
                    aux = scanf("%d", &opc);
                    if (aux != 1 || opc < 0 || opc > 3)
                    {
                        printf("\nERROR: EL DATO INGRESADO ES ERRONEO, INTENTELO NUEVAMENTE\n");
                    }
                } while (aux != 1 || opc < 0 || opc > 3);
                switch (opc)
                {
                case 1:
                    for (int i = 0; i < 3; i++)
                    {
                        do
                        {
                            printf("\nIngrese la nota %d", i + 1);
                            printf("\n>>");
                            fflush(stdin);
                            aux = scanf("%f", &calificacion[selAlumno - 1][0][i]);
                            if (aux != 1 || calificacion[selAlumno - 1][0][i] < 0 || calificacion[selAlumno - 1][0][i] > 10)
                            {
                                printf("\nERROR: EL DATO INGRESADO ES ERRONEO, INTENTELO NUEVAMENTE\n");
                            }
                        } while (aux != 1 || calificacion[selAlumno - 1][0][i] < 0 || calificacion[selAlumno - 1][0][i] > 10);
                        printf("\nNOTA Nro %d REGISTRADA CON EXITO", i + 1);
                    }
                    break;
                case 2:
                    for (int i = 0; i < 3; i++)
                    {
                        do
                        {
                            printf("\nIngrese la nota %d", i + 1);
                            printf("\n>>");
                            fflush(stdin);
                            aux = scanf("%f", &calificacion[selAlumno - 1][1][i]);
                            if (aux != 1 || calificacion[selAlumno - 1][1][i] < 0 || calificacion[selAlumno - 1][1][i] > 10)
                            {
                                printf("\nERROR: EL DATO INGRESADO ES ERRONEO, INTENTELO NUEVAMENTE\n");
                            }
                        } while (aux != 1 || calificacion[selAlumno - 1][1][i] < 0 || calificacion[selAlumno - 1][1][i] > 10);
                        printf("\nNOTA Nro %d REGISTRADA CON EXITO", i + 1);
                    }
                    break;
                case 3:
                    for (int i = 0; i < 3; i++)
                    {
                        do
                        {
                            printf("\nIngrese la nota %d", i + 1);
                            printf("\n>>");
                            fflush(stdin);
                            aux = scanf("%f", &calificacion[selAlumno - 1][2][i]);
                            if (aux != 1 || calificacion[selAlumno - 1][2][i] < 0 || calificacion[selAlumno - 1][2][i] > 10)
                            {
                                printf("\nERROR: EL DATO INGRESADO ES ERRONEO, INTENTELO NUEVAMENTE\n");
                            }
                        } while (aux != 1 || calificacion[selAlumno - 1][2][i] < 0 || calificacion[selAlumno - 1][2][i] > 10);
                        printf("\nNOTA Nro %d REGISTRADA CON EXITO", i + 1);
                    }
                    break;
                }
                suma = 0;
                for (int i = 0; i < 3; i++)
                {
                    suma += calificacion[selAlumno - 1][opc - 1][i];
                }
                PromediosPorMateria[selAlumno - 1][opc - 1][0] = (suma) / 3;
                suma = 0;
                for (int i = 0; i < 3; i++)
                {
                    suma += PromediosPorMateria[selAlumno - 1][i][0];
                }
                PromediosGenerales[selAlumno - 1][0] = suma / 3;
                printf("\nSE HAN REGISTRADO CON EXITO LAS NOTAS DEL AREA DE %s\n", asignaturas[opc - 1]);
            }
            break;
        case 3:
            if (alumno == 0)
            {
                printf("\nERROR: NO SE HA REGISTRADO NINGUN ALUMNO AL SISTEMA\n");
            }
            else
            {
                do
                {
                    printf("\nSeleccione el alumno del que quiere sacar el promedio:\n");
                    for (int i = 0; i < alumno; i++)
                    {
                        printf("\n%d, %s", i + 1, nombres[i]);
                    }
                    printf("\n>>");
                    fflush(stdin);
                    aux = scanf("%d", &selAlumno);
                    if (aux != 1 || selAlumno < 1 || selAlumno > alumno)
                    {
                        printf("\nERROR: EL DATO INGRESADO ES ERRONEO, INTENTELO NUEVAMENTE\n");
                    }
                } while (aux != 1 || selAlumno < 1 || selAlumno > alumno);
                do
                {
                    printf("\nSeleccione la materia de la cual desea calcular el promedio:\n");
                    for (int i = 0; i < 3; i++)
                    {
                        printf("\n%d. %s", i + 1, asignaturas[i]);
                    }
                    printf("\n>>");
                    fflush(stdin);
                    aux = scanf("%d", &opc);
                    if (aux != 1 || opc < 1 || opc > 3)
                    {
                        printf("\nERROR: EL DATO INGRESADO ES ERRONEO, INTENTELO NUEVAMENTE\n");
                    }
                } while (aux != 1 || opc < 1 || opc > 3);
                printf("\n El promedio del alumno seleccionado en la materia %s es de %.2f", asignaturas[opc - 1], PromediosPorMateria[selAlumno - 1][opc - 1][0]);
            }
            break;
        case 4:
            if (alumno == 0)
            {
                printf("\nERROR: NO SE HA REGISTRADO NINGUN ALUMNO AL SISTEMA\n");
            }
            else
            {
                do
                {
                    printf("\nSeleccione el alumno del que quiere sacar el promedio general:\n");
                    for (int i = 0; i < alumno; i++)
                    {
                        printf("%d. %s", i + 1, nombres[i]);
                    }
                    printf(">> ");
                    fflush(stdin);
                    aux = scanf("%d", &selAlumno);
                    if (aux != 1 || selAlumno < 1 || selAlumno > alumno)
                    {
                        printf("\nERROR: EL DATO INGRESADO ES ERRONEO, INTENTELO NUEVAMENTE\n");
                    }
                } while (aux != 1 || selAlumno < 1 || selAlumno > alumno);
                printf("\nEl promedio general del alumno seleccionado es de %.2f\n", PromediosGenerales[selAlumno - 1][0]);
            }
            break;
        case 5:
            if (alumno == 0)
            {
                printf("\nERROR: NO SE HA REGISTRADO NINGUN ALUMNO AL SISTEMA\n");
            }
            else
            {
                do
                {
                    printf("\nSeleccione la materia para calcular el promedio general:\n");
                    for (int i = 0; i < 3; i++)
                    {
                        printf("%d. %s\n", i + 1, asignaturas[i]);
                    }
                    printf(">> ");
                    fflush(stdin);
                    aux = scanf("%d", &opc);
                    if (aux != 1 || opc < 1 || opc > 3)
                    {
                        printf("\nERROR: EL DATO INGRESADO ES ERRONEO, INTENTELO NUEVAMENTE\n");
                    }
                } while (aux != 1 || opc < 1 || opc > 3);
                suma = 0;
                for (int i = 0; i < alumno; i++)
                {
                    suma += PromediosPorMateria[i][opc - 1][0];
                }
                promedioClase = suma / alumno;
                printf("\n--- RENDIMIENTO GENERAL DEL CURSO ---\n");
                printf("\nMateria: %s", asignaturas[opc - 1]);
                printf("\nPromedio de los %d alumnos: %.2f", alumno, promedioClase);
            }
            break;
        case 6:
            if (alumno == 0)
            {
                printf("\nERROR: NO SE HA REGISTRADO NINGUN ALUMNO AL SISTEMA\n");
            }
            else
            {
                do
                {
                    printf("\nSeleccione el alumno del que desea conocer su calificación más alta y baja:\n");
                    for (int i = 0; i < alumno; i++)
                    {
                        printf("%d. %s", i + 1, nombres[i]);
                    }
                    printf(">> ");
                    fflush(stdin);
                    aux = scanf("%d", &selAlumno);
                    if (aux != 1 || selAlumno < 1 || selAlumno > alumno)
                    {
                        printf("\nERROR: EL DATO INGRESADO ES ERRONEO, INTENTELO NUEVAMENTE\n");
                    }
                } while (aux != 1 || selAlumno < 1 || selAlumno > alumno);
                notaMax = calificacion[selAlumno - 1][0][0];
                notaMin = calificacion[selAlumno - 1][0][0];
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        notaActual = calificacion[selAlumno - 1][i][j];
                        if (notaActual > notaMax)
                        {
                            notaMax = notaActual;
                        }
                        if (notaActual < notaMin)
                        {
                            notaMin = notaActual;
                        }
                    }
                }
                printf("\n****Resultados para el alumno seleccionado:***\n");
                printf("-Calificación más alta alcanzada: %.2f\n", notaMax);
                printf("-Calificación más baja alcanzada: %.2f\n", notaMin);
            }
            break;
        case 7:
            if (alumno == 0)
            {
                printf("\nERROR: NO SE HA REGISTRADO NINGUN ALUMNO AL SISTEMA\n");
            }
            else
            {
                do
                {
                    printf("\nSeleccione la materia para ver la nota más alta y baja de todo el curso:\n");
                    for (int i = 0; i < 3; i++)
                    {
                        printf("%d. %s\n", i + 1, asignaturas[i]);
                    }
                    printf(">> ");
                    fflush(stdin);
                    aux = scanf("%d", &opc);
                    if (aux != 1 || opc < 1 || opc > 3)
                    {
                        printf("\nERROR: EL DATO INGRESADO ES ERRONEO, INTENTELO NUEVAMENTE\n");
                    }
                } while (aux != 1 || opc < 1 || opc > 3);
                notaMax = calificacion[0][opc - 1][0];
                notaMin = calificacion[0][opc - 1][0];
                for (int i = 0; i < alumno; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        notaActual = calificacion[i][opc - 1][j];
                        if (notaActual > notaMax)
                        {
                            notaMax = notaActual;
                        }
                        if (notaActual < notaMin)
                        {
                            notaMin = notaActual;
                        }
                    }
                }
                printf("\n*****Calificaciones de la materia de %s*****\n", asignaturas[opc - 1]);
                printf("La calificación más alta de todo el grupo es: %.2f\n", notaMax);
                printf("La calificación más baja de todo el grupo es: %.2f\n", notaMin);
            }
            break;
        case 8:
            if (alumno == 0)
            {
                printf("\nERROR: NO SE HA REGISTRADO NINGUN ALUMNO AL SISTEMA\n");
            }
            else
            {
                do
                {
                    aprobados = 0;
                    reprobados = 0;
                    printf("\nSeleccione la materia para ver aprobados y reprobados:\n");
                    for (int i = 0; i < 3; i++)
                    {
                        printf("%d. %s\n", i + 1, asignaturas[i]);
                    }
                    printf(">> ");
                    fflush(stdin);
                    aux = scanf("%d", &opc);
                    if (aux != 1 || opc < 1 || opc > 3)
                    {
                        printf("\nERROR: EL DATO INGRESADO ES ERRONEO, INTENTELO NUEVAMENTE\n");
                    }
                } while (aux != 1 || opc < 1 || opc > 3);
                for (int i = 0; i < alumno; i++)
                {

                    if (PromediosPorMateria[i][opc - 1][0] >= 6)
                    {
                        aprobados++;
                    }
                    else
                    {
                        reprobados++;
                    }
                }
                printf("\n--- RESUMEN DE %s ---\n", asignaturas[opc - 1]);
                printf("\nTotal Aprobados: %d", aprobados);
                printf("\nTotal Reprobados: %d\n", reprobados);
            }
            break;
        }
        if (opc != 9)
        {
            do
            {
                printf("\nDesea Seleccionar otra opción? (1. Si, 2. No-Salir)");
                printf("\n>>");
                fflush(stdin);
                aux = scanf("%d", &opc);
                if (aux != 1 || opc < 0 || opc > 2)
                {
                    printf("\nERROR: EL DATO INGRESADO ES ERRONEO, INTENTELO NUEVAMENTE\n");
                    fflush(stdin);
                    aux = scanf("%d", &opc);
                }
            } while (aux != 1 || opc < 0 || opc > 2);
        }
    } while (opc == 1);
    printf("\n*****SALIENDO DEL PROGRAMA******\n");
    printf("\nHasta pronto :D\n");
    return 0;
}