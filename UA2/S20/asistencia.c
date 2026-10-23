#include <stdio.h>

#define FILAS 4
#define COLUMNAS 5

int main() {
    //Arreglos
    char nombres[FILAS][10] = {
        "Ana","Luis","Sofia","Daniel"};
    int asistencia[FILAS][COLUMNAS] =   {{1, 1, 1, 1, 1}, 
                                        {1, 0, 1, 1, 0}, 
                                        {1, 1, 1, 0, 1},
                                        {0, 1, 1, 1, 1} };
    int presentes_por_dia[COLUMNAS];

    // Muestra el nombre, asistencia en formato P/A y porcentaje individual
    for (int i = 0; i < FILAS; i++) {
        int suma_asistencia = 0;
        
        // Imprime el nombre
        printf("%-10s", nombres[i]);

        for (int j = 0; j < COLUMNAS; j++) {
            // Uso del operador ternario '?:' para mostrar 'P' o 'A'
            printf("%c ", asistencia[i][j] == 1 ? 'P' : 'A');

            // Acumula presentes para el estudiante actual
            suma_asistencia += asistencia[i][j];

            // Acumula presentes por cada día
            presentes_por_dia[j] += asistencia[i][j];
        }

        // Porcentaje
        float porcentaje = ((float)suma_asistencia / COLUMNAS) * 100;

        printf("%3.0f%%\n", porcentaje);
    }

    // Imprime la fila de totales por día
    printf("%-10s", "Dia");
    for (int j = 0; j < COLUMNAS; j++) {
        printf("%d ", presentes_por_dia[j]);
    }
    printf("\n");

    return 0;
}