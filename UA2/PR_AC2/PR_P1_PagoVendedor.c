#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define VENTAS 4

int main(void)
{
    //Arreglo
    float ventas[VENTAS];
    //Constates para los porcentajes
    const float RETENCION = 0.02, COMISION = 0.05;
    //Variables
    int i,j, correcto;
    char nombre[50];
    float total, bono, pago, retencion;

    //Pedimos nombre 
    printf("=== Pago del vendedor ===\n");
    printf("Nombre del vendedor: ");
    fgets(nombre, sizeof(nombre),stdin);
    //ciclo for para las ventas por semana
    for (i = 0; i < VENTAS; i++)
    {
        correcto = 0;
        do
        {
            // Lee venta[i]
            printf("Venta de la semana %d: ", i+1);
            scanf("%f",&ventas[i]);
            //Reviso que no sea menor a 0 y sumo a total
            if (ventas[i] >= 0)
            {
                total += ventas[i];
                correcto = 1;
            }
            else{
                printf("Venta invalida\n");
            }
            
        } while (correcto == 0);
        
    }
    //Reviso si total es mayor 2000 para ver si obtiene bono
    if (total > 2000)
    {bono = 50;}
    else{bono =0;}
    //Ultimos calculos
    pago = total * COMISION;
    retencion = (pago + bono)*RETENCION;

    //Salidas
    printf("\n------- Pago de Carlos Vega -------\n");
    for (j = 0; j < VENTAS; j++)
    {
        printf("Semana %d %21.2f\n",j+1,ventas[j]);
    }
    printf("Ventas del mes: %14.2f\n",total);
    printf("Comision (5%%): %15.2f\n", total * COMISION);
    printf("Bono: %24.2f\n", bono);
    printf("Retencion (2%%): %14.2f\n",retencion);
    printf("Pago del mes: %16.2f\n", pago + bono - retencion);
    

    system("pause");
    return 0;
}
