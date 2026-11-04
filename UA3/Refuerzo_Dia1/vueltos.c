//Una caja calcula el vuelto de cada compra.
// Se digita el total de la compra (1 a 1 000 000) y el monto pagado, que no puede ser menor que el total (si lo es, se vuelve a pedir). 
//El programa muestra el vuelto y cuántos billetes o monedas de cada denominación entregar, empezando por la mayor (20 000, 10 000, 5000, 2000, 1000, 500, 100, 50, 25, 10 y 5); solo se muestran las que se usan. Si sobran colones que no se pueden entregar (menos de 5), se indica.
//Al final se muestra la cantidad total de piezas. Después de cada compra se pregunta si hay otra (S/N). 

#include <stdio.h>
#define CANTIDAD_DENOMINACIONES 11

// Prototipos.
int compra(int total_compra); 
int monto(int monto_pagado);
int cuantas(int *resto, int denominacion);

int main(void){
    // Definir variables.
    int denominaciones[CANTIDAD_DENOMINACIONES] = {20000, 10000, 5000, 2000, 1000, 500, 100, 50, 25, 10, 5};
    int monto_pagado, total_compra = 0, e, mostrar_vuelto, resto, total_piezas = 0, piezas;
    char opcion;

    // Entradas y lecturas en bucle principal.
    do{ 
        total_compra = compra(total_compra);
        monto_pagado = monto(total_compra);

        // Calcular Vuelto Total
        mostrar_vuelto = monto_pagado - total_compra;
        resto = mostrar_vuelto; // Inicializamos el resto con el vuelto total
        total_piezas = 0;       // Reiniciamos las piezas para cada compra

        printf("=====================================\n");
        printf("Vuelto total: %d colones\n", mostrar_vuelto);
        printf("=====================================\n");

        // Desglose de billetes y monedas
        for (e = 0; e < CANTIDAD_DENOMINACIONES; e++)
        {
            piezas = cuantas(&resto, denominaciones[e]);

            if (piezas > 0)
            {
                printf("%d billetes / monedas de %d colones\n", piezas, denominaciones[e]);
                total_piezas += piezas; // Acumulamos las piezas usadas
            }
        }

        // Si sobran colones que no se pueden entregar (menos de 5)
        if (resto > 0)
        {
            printf("Sobran %d colones sin entregar (menos de 5)\n", resto);
        }

        printf("=====================================\n");
        printf("Cantidad total de piezas: %d\n", total_piezas);
        printf("=====================================\n");

        // Preguntar si desea realizar otra compra
        printf("Desea realizar otra compra (S/N): ");
        scanf(" %c", &opcion); // Quitamos el \n sobrante del scanf

    } while (opcion == 's' || opcion == 'S'); // Se repite si el usuario indica que sí

    return 0;
}

// Definiciones de funciones.

int compra(int total_compra){
    char c;
    do
    {
        printf("Total de la compra (1 a 1 000 000): \n");
        scanf("%d", &total_compra);
        while ((c = getchar()) != '\n' && c != EOF); // Limpiar búfer
    } while (total_compra < 1 || total_compra > 1000000);
    return total_compra;
}

int monto(int total_compra){
    int monto_pagado;
    char c;
    do
    {
        printf("Ingrese el monto pagado: \n");
        scanf("%d", &monto_pagado);
        while ((c = getchar()) != '\n' && c != EOF); // Limpiar búfer
    } while (monto_pagado < total_compra);

    return monto_pagado;
}

int cuantas(int *resto, int denominacion){
    int piezas = *resto / denominacion;
    *resto = *resto % denominacion;

    return piezas; 
}
