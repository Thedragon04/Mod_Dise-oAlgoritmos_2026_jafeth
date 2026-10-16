/*ventas.c Ventas de una cadena de sodas por sucursal y por dia
Que logra: Guardar en una matriz las ventas de 3 sucursales en 4 dias.
Sumas cada sucursal (fila) y cada dia por medio de la (columna) e identificar la sucursal que mas vendio, con su nombre guardado en una cadena.
RESULTADO ESPERADO: Centro 470, Norte 350, Sur 410; por dia 330 270 330; Sucursal con más vnetas: Centro (470) 
*/

#include <stdio.h>
#include <string.h> //strcpy
#include <stdlib.h>
#define SUC 3       //Fila sucursales
#define DIAS 4      //Columnas dias

int main(void){
    //Arreglo de cadenas: una fila por nombre (hasta 9 letras + '\0')
    char nombres[SUC] [10] = {"Centro","Norte","Sur"};

    //Ventas em miles de colones
    int ventas[SUC] [DIAS] =    {{120, 100, 130, 120},
                                {90, 80, 100, 80},
                                {120, 90, 100, 100}};
    char mejor[10];//Nombre de la sucursal ganadora
    int s, d, total, totalDia, mayor = 0;

    //Encabezado : D1 a D4
    printf("%-8s", "");
    for (d = 0; d < DIAS; d++)
    {
        printf("  D%d", d + 1);
    }
    printf("  |  Total\n");

    for (s = 0; s < SUC; s++)
    {
        total = 0;  //Reinicia cada fila
        printf("%-8s", nombres[s]);// Nombre a la izquierda
        for (d = 0; d < DIAS; d++)
        {
            printf("%5d", ventas[s][d]);
            total += ventas[s][d];
        }
        printf("  | %5d\n",total); //470, 350, 410
        
        //Guardar la variables con mayor total; strcpy copia el nombre
        if(total > mayor){
            mayor = total;
            strcpy(mejor, nombres[s]);//mejor = Centro
        }
    }
    //Recorrido por columnas. El for externo recorre los dias
    printf("%-8s","Dia");
    for (d = 0; d < DIAS; d++)
    {
        totalDia = 0;
        for (s = 0; s < SUC; s++)
        {
            totalDia += ventas [s] [d];
        }
        printf("%5d", totalDia); //330 270 330 300
    }
    printf("\n");
    //SALIDAS: Sucursal con mas: Centro 470
    printf("Sucursal con mas ventas: %s (%d)\n", mejor, mayor);

    system("pause");
    return 0;
}
