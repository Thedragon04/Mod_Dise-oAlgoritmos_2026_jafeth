#include <stdio.h>
#include <stdbool.h>

int main(void){
    //Variables
    int opcion;
    double lado, base, altura, radio;
    bool salir;
    const double PI = 3.141592653589793;

    salir = true;//Para que inicie el ciclo

    //ciclo do while con una condicion logica para el cierre
    do
    {
        printf("\n0. Salir\n");
        printf("1. Cuadrado\n");
        printf("2. Rectangulo\n");
        printf("3. Circulo\n");
        printf("Opcion: \n");
        scanf("%d",&opcion);

        switch (opcion)
        {
        case 1:
            printf("Lado: \n");
            scanf("%lf",&lado);
            printf("Area: %f\n",lado * lado);
            break;
        case 2:
            printf("Base: \n");
            scanf("%lf",&base);
            printf("Altura: \n");
            scanf("%lf",&altura);
            printf("Area: %f\n",base * altura);
            break;
        case 3:
            printf("Radio: \n");
            scanf("%lf",&radio);
            printf("Area: %f\n",PI * (radio * radio));
            break;
        case 0:
            printf("Hasta luego\n");
            salir = false;
            break;
        default:
            printf("Opcion invalida\n");
            break;
        }
    } while (salir);
    
}