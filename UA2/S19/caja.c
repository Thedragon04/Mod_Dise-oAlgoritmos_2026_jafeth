//caja.c - Caja registradora con menu

#include <stdio.h>

int main(void){
    //Declaracion de variables
    int opcion;         //opcion elegida en el menu
    int productos = 0;  //contador de productos de la venta
    double precio;      //precio para cada producto
    double total = 0;   //Acumulador de la venta

    //Do while: El menu se muestra al menos una vez

    do
    {
        //mostrar el menu y lee la opcion -> 1
        printf("\n1. Agregar \n2. Ver total \n3. Cobrar \n0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        //SWITCH: (Segun): salta al case que coincida con la opcion elegida
        switch (opcion)
        {
        case 1:
            //Validacion: repite mientras el precio no sea positivo
            do
            {
                printf("Precio del producto: ");
                scanf("%lf", &precio); //-> 1500
                if (precio <= 0)
                {
                    printf("Precio inavalido\n");
                }
                
            } while (precio <= 0);
            productos++;
            total += precio;
            
            break;
        
        case 2:
        //Muestra el avance
            printf("Productos: %d Total: %.2f\n", productos, total);
            break;

        case 3:
            //cobra y reinicia el contador y acumulador
            printf("Cobrado: %.2f. Nueva venta\n", total);
            productos = 0;
            total = 0;
            break;

        case 0:
            //Termina el ciclo principal
            printf("Caja Cerrada\n");
            break;
        
        default:
            //Ningun caso coincide 
            printf("Opcion fuera de rango");
            break;
        }

    } while (opcion != 0);
    return 0;
    
}