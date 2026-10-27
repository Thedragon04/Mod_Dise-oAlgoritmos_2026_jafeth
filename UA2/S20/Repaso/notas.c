/*
Enunciado:
Un docente quiere organizar las notas de un grupo pequeno de 4 estudiantes 
en 3 evaluaciones (de 0 a 100). Escriba un programa en C que lea nombres y notas, muestre una tabla con las notas y promedios por estudiante,calcule el promedio de cada evaluacion, determine el estudiante con el mejor promedio y permita buscar a un estudiante por nombre para indicar su promedio y condicion (APROBADO con >= 70, sino NO APROBADO).

Que se logra:
Procesar calificaciones en una matriz bidimensional, generar reportes 
resumidos y realizar busquedas de informacion por texto.

Como se logra:
1. Se emplea una matriz `notas[4][3]` para almacenar notas, un arreglo bidimensional `nombres[4][15]` para los nombres y `prom[4]` para promedios.
2. Se utilizan ciclos anidados para la lectura con validacion (0 a 100).
3. Se calculan los promedios individuales recorriendo filas y los promedios por evaluacion recorriendo columnas.
4. Se busca el promedio maximo registrando su indice.
5. Se lee un nombre a buscar y mediante `strcmp` se localiza al estudiante para determinar con `strcpy` y mostrar su condicion.

Resultado esperado:
Tabla comparativa de notas por alumno, promedios por evaluacion, indicacion del mejor promedio y el resultado de la busqueda individual.
*/

#include <stdio.h>
#include <string.h>

int main(void) {
    const int ESTUDIANTES = 4;
    const int EVALUACIONES = 3;

    // Arreglos principales
    char nombres[4][15];
    int notas[4][3];
    float prom[4];

    // Variables de trabajo
    float suma_estudiante = 0.0f;
    float suma_eval = 0.0f;
    int pos_mejor = 0;

    // Variables para la busqueda
    char busqueda[15];
    char condicion[15];
    int encontrado = 0;

    printf("=== Notas del grupo ===\n");

    // Lectura de datos por estudiante y evaluacion
    for (int e = 0; e < ESTUDIANTES; e++) {
        printf("Nombre del estudiante %d: ", e + 1);
        scanf("%14s", nombres[e]);

        suma_estudiante = 0.0; // Reinicio del acumulador de la fila

        for (int v = 0; v < EVALUACIONES; v++) {
            do {
                printf("Nota %d de %s: ", v + 1, nombres[e]);
                scanf("%d", &notas[e][v]);

                if (notas[e][v] < 0 || notas[e][v] > 100) {
                    printf("Error: La nota debe estar entre 0 y 100.\n");
                }
            } while (notas[e][v] < 0 || notas[e][v] > 100);

            suma_estudiante += (float)notas[e][v];
        }

        // Calculo del promedio del estudiante
        prom[e] = suma_estudiante / (float)EVALUACIONES;

        // Determinacion del mejor promedio
        if (e == 0 || prom[e] > prom[pos_mejor]) {
            pos_mejor = e;
        }
    }

    // Muestreo de la tabla de notas y promedios por fila
    printf("\nNombre\t\tN1\tN2\tN3\tPromedio\n");
    for (int e = 0; e < ESTUDIANTES; e++) {
        printf("%-10s\t%d\t%d\t%d\t%.2f\n", 
            nombres[e], notas[e][0], notas[e][1], notas[e][2], prom[e]);
    }
    printf("\n");

    // Calculo y visualizacion del promedio por evaluacion (por columnas)
    for (int v = 0; v < EVALUACIONES; v++) {
        suma_eval = 0.0; // Reinicio del acumulador de la columna
        for (int e = 0; e < ESTUDIANTES; e++) {
            suma_eval += (float)notas[e][v];
        }
        printf("Promedio de la evaluacion %d: %.2f\n", v + 1, suma_eval / (float)ESTUDIANTES);
    }

    printf("Mejor promedio: %s (%.2f)\n\n", nombres[pos_mejor], prom[pos_mejor]);

    // Busqueda de un estudiante por nombre
    printf("Buscar estudiante: ");
    scanf("%14s", busqueda);

    for (int e = 0; e < ESTUDIANTES; e++) {
        if (strcmp(nombres[e], busqueda) == 0) {
            encontrado = 1;
            if (prom[e] >= 70.0) {
                strcpy(condicion, "APROBADO");
            } else {
                strcpy(condicion, "NO APROBADO");
            }
            printf("%s: %.2f %s\n", nombres[e], prom[e], condicion);
            break;
        }
    }

    if (!encontrado) {
        printf("El estudiante %s no se encuentra en el grupo.\n", busqueda);
    }

    return 0;
}