#include <stdio.h>
int main(int argc, char const *argv[])
{
    char ID[10];
    char nombre[30];
    int stock=0,opc=0,aux, exit, unidades=0, ventas=0,descuento=0, producto=0;
    float precio,ganancias=0, total_vent;
    do
    {
        printf("\n---BIENVENIDX AL PROGRAMA DE GESTION---\n");
        do{
            printf("\nSeleccione una opción para continuar:\n");
            printf("1.Registrar nuevo producto\n");
            printf("2.Vender producto\n");
            printf("3.Reabastecer producto\n");
            printf("4.Consultar informacion\n");
            printf("5.Mostrar ganancias totales\n");
            printf("6.Salir\n");
            printf(">> ");
            fflush(stdin);
            aux = scanf("%d",&opc);
            if (aux != 1 || opc < 0 || opc > 6){
                printf("\nERROR: EL DATO INGRESADO ES ERRONEO, INTENTELO NUEVAMENTE\n");
            }
        }while(aux != 1 || opc < 0 || opc > 6);
        switch(opc){
            case 1:
                producto++;
                printf("Ingrese el ID del producto:\n");
                scanf("%s",&ID);
                fflush(stdin);
                printf("Ingrese el nombre del producto:\n");
                fgets(nombre,30,stdin); 
                printf("Ingrese el stock del producto:\n");
                fflush(stdin);
                aux = scanf("%d",&stock);
                while (aux != 1 || stock < 0 )
                {
                    printf("\nERROR: EL DATO INGRESADO ES ERRONEO, INTENTELO NUEVAMENTE\n");
                    printf("Ingrese el stock del producto:\n");
                    fflush(stdin);
                    aux = scanf("%d",&stock);
                }
                printf("Ingrese el precio del producto:\n");
                fflush(stdin);
                aux = scanf("%f",&precio);
                while (aux != 1 || precio < 0)
                {
                    printf("\nERROR: EL DATO INGRESADO ES ERRONEO, INTENTELO NUEVAMENTE\n");
                    printf("Ingrese el precio del producto:\n");
                    fflush(stdin);
                    aux = scanf("%f",&precio);
                }
                break;
            case 2:
                if (stock ==0)
                {
                    printf("ERROR: NO HAY STOCK DISPONIBLE PARA VENDER\n");
                }else{
                    printf("\nVA A VENDER EL PRODUCTO %s",nombre);
                    printf("EL PRECIO DEL PRODUCTO ES DE: %.2f\n",precio);
                    printf("Cuantas unidades desea vender?\n");
                    fflush(stdin);
                    aux = scanf("%d",&unidades);
                    while (aux != 1 || unidades < 0 || unidades > stock )
                    {
                        printf("\nERROR: EL DATO INGRESADO ES ERRONEO O INTENTA VENDER MAS UNIDADES DE LAS QUE HAY EN STOCK, INTENTELO NUEVAMENTE\n");
                        printf("Cuantas unidades desea vender?\n");
                        fflush(stdin);
                        aux = scanf("%d",&unidades);
                    }
                    printf("Desea agregar un descuento? (1. Si, 2.No)\n");
                    fflush(stdin);
                    aux = scanf("%d",&opc);
                    while (aux != 1 || opc < 1 || opc > 2 )
                    {
                        printf("\nERROR: EL DATO INGRESADO ES ERRONEO, INTENTELO NUEVAMENTE\n");
                        printf("Desea agregar un descuento? (1. Si, 2.No)\n");
                        fflush(stdin);
                        aux = scanf("%d",&opc);
                    }
                    if (opc == 1)
                    {
                        printf("De cuanto es el procentaje de descuento que desea aplicar?\n");
                        fflush(stdin);
                        aux = scanf("%d",&descuento);
                        while (aux != 1 || descuento < 0 || descuento > 100 )
                        {
                            printf("\nERROR: EL DATO INGRESADO ES ERRONEO, INTENTELO NUEVAMENTE\n");
                            printf("De cuanto es el procentaje de descuento que desea aplicar?\n");
                            fflush(stdin);
                            aux = scanf("%d",&descuento);
                        }
                    }else
                    {
                        descuento = 0;
                    }
                    stock = stock - unidades;
                    total_vent = ((unidades * precio) - ((unidades * precio) * (descuento / 100.0)));
                    ganancias = ganancias + total_vent ;
                    ventas++;
                    printf("\nEl precio total de esta venta fue de:\n %.2f", total_vent);
                    printf("\nVENTA REALIZADA CON EXITO\n");
                }
                break;
            case 3:
                if (producto == 0)
                {
                    printf("\nERROR: NO SE HA REGISTRADO NINGUN PRODUCTO, NO HAY PRODUCTO AL CUAL REABASTECER\n");
                }else{
                    printf("SE VA A REABASTECER EL PRODUCTO: %s\n",nombre);
                    printf("Cuantas unidades desea reabastecer?\n");
                    fflush(stdin);
                    aux = scanf("%d",&unidades);
                    while (aux != 1 || unidades < 0)
                    {
                        printf("\nERROR: EL DATO INGRESADO ES ERRONEO, INTENTELO NUEVAMENTE\n");
                        printf("Cuantas unidades desea reabastecer?\n");
                        fflush(stdin);
                        aux = scanf("%d",&unidades);
                    }
                    stock = stock + unidades;
                    printf("REABASTECIMIENTO REALIZADO CON EXITO\n");
                }
                break;
            case 4:
                if (producto == 0)
                {
                    printf("ERROR: NO SE HA REGISTRADO NINGUN PRODUCTO");
                }else
                {
                    printf("\n*****DATOS DEL PRODUCTO:*****\n");
                    printf("\nID: %s",ID);
                    printf("\nNombre: %s",nombre);
                    printf("\nStock: %d",stock);
                    printf("\nPrecio: %.2f",precio);
                }
                break;
            case 5:
                printf("\nUsted ha vendido %d productos", ventas);
                printf("\nSus ganacias totales hasta el momento son de: %.2f dolares", ganancias);
                break;
        }
        printf("\nDesea realizar alguna otra acción? (1. Si, 0. NO-Salir)\n");
        printf(">> ");
        fflush(stdin);
        aux = scanf("%d", &exit);
        while (aux != 1 || (exit< 0 || exit>1))
        {
            printf("\nERROR: EL DATO INGRESADO ES ERRONEO, INTENTELO NUEVAMENTE\n");
            printf("Desea realizar alguna otra acción? (1. Si, 0. Salir)\n");
            printf(">> ");
            fflush(stdin);
            aux = scanf("%d", &exit);
        }
    } while (exit!=0);
    printf("------------HASTA LUEGO, VUELVA PRONTO----------");
    return 0;
}