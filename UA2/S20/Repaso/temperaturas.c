/*
Enunciado:
El Instituto Meteorologico registra la temperatura maxima de cada dia. 
Escriba un programa en C que pida la temperatura maxima de cada dia de la 
semana (grados C, de 0 a 45). Guarde las temperaturas en un arreglo de 7 
posiciones, calcule el promedio, encuentre el dia mas caluroso y liste los 
dias que superaron el promedio con su cantidad.

Que se logra:
Calcular el promedio semanal de temperaturas, identificar el dia mas 
caluroso y reportar los dias con temperaturas superiores al promedio.

Como se logra:
1. Se utiliza un arreglo de cadenas para almacenar los nombres de los dias y un arreglo unidimensional para almacenar las temperaturas.
2. Mediante un ciclo `for` con validaciones `do-while`, se solicitan y acumulan las temperaturas validas.
3. Se calcula el promedio dividiendo la suma total entre 7.
4. En el primer ciclo se busca la posicion del dia mas caluroso.
5. En un segundo ciclo se comparan las temperaturas individuales contra el promedio para contar y mostrar los dias sobre el promedio.

Resultado esperado:
Un reporte en pantalla con las temperaturas diarias, el promedio redondeado 
a dos decimales, el dia mas caluroso y los dias que superaron el promedio.
*/

#include <stdio.h>

int main(void) {
    // Constante para el numero de dias de la semana
    const int DIAS = 7;

    // Arreglo de cadenas con los nombres de los dias
    char dias[7][4] = {"Lun", "Mar", "Mie", "Jue", "Vie", "Sab", "Dom"};

    // Arreglo para almacenar las temperaturas ingresadas por el usuario
    float temp[7];

    // Variables acumuladoras y auxiliares
    float suma = 0.0f;
    float promedio = 0.0f;
    int pos_max = 0;       // Indice de la temperatura mas alta
    int cant_sobre_prom = 0; // Contador de dias que superan el promedio

    printf("=== Temperaturas de la semana ===\n");

    // Lectura y validacion de datos
    for (int i = 0; i < DIAS; i++) {
        do {
            printf("Temperatura del %s (0 a 45): ", dias[i]);
            scanf("%f", &temp[i]);

            if (temp[i] < 0.0f || temp[i] > 45.0f) {
                printf("Error: La temperatura debe estar entre 0 y 45.\n");
            }
        } while (temp[i] < 0.0f || temp[i] > 45.0f);

        // Acumular para el promedio
        suma += temp[i];

        // Guardar la posicion del mayor
        if (i == 0 || temp[i] > temp[pos_max]) {
            pos_max = i;
        }
    }

    // Calculo del promedio
    promedio = suma / (float)DIAS;

    // Reporte de resultados
    printf("\n---- Reporte de la semana\n");
    for (int i = 0; i < DIAS; i++) {
        printf("%s: %.1f C\n", dias[i], temp[i]);
    }

    printf("Promedio: %.2f C\n", promedio);
    printf("Mas caluroso: %s (%.1f C)\n", dias[pos_max], temp[pos_max]);

    // Recorrido secundario para identificar dias sobre el promedio
    printf("Sobre el promedio: ");
    for (int i = 0; i < DIAS; i++) {
        if (temp[i] > promedio) {
            printf("%s ", dias[i]);
            cant_sobre_prom++;
        }
    }
    printf("(%d dias)\n", cant_sobre_prom);

    return 0;
}