//Horas.c - horas de estudio a la semana
/*ENUNCIADO: Registrar las horas de estudio de 3 estudiantes de lunes a jueves se digite el nombre y las horas de estudio de cada dia.
Mostrar una tabla con el total de cada estudiante, quien estudio mas, el dia con mas horas y buscar a una persona del grupo por su nombre*/

#include <stdio.h>
#include <string.h>

//Definir constantes
#define EST 3 //Filas
#define DIAS 4 //Columnas

int main(void){
    //Arreglo de cadenas para los 3 nombres.
    char nombres[EST][15];// De los 15 caracteres 14 son para el nombre y 1 para '/0'

    //Matriz de horas 3 filas para estudiantes y 4 columnas para los dias
    int horas [EST][DIAS];

    //Arreglo de cadenas: Con los nombres cortos de los dias
    char dias[DIAS][4]={"Lun","Mar","Mie","Jue"};
    //Se crean los indices de fina y columna
    int e, d;

    //Arreglo: total por estudiante. total[e] es la suma de la fila e
    int total[EST];

    //Posicion: de quien estudio mas
    int mejor;

    //Acumulado de columna (Horas del grupo en un dia)
    //int mejor;

    //Suma mayor de dia
    int sumaMayor;

    //Posicion: Dia con mas horas
    int diaMejor;
    
    //cadena con el nombre a buscar
    char buscado[15];

    //Posicion donde aparece el nombre buscado
    int encontrado;

    //Lectura con los for anidados
    //ciclo externo: una vuelta por estudiante(fila)

    for (e = 0; e < EST; e++)
    {
        //Pedimos nombre del estudiante
        printf("Nombre del estudiante %d:", e+1);
        //leer una palabra en la fila de nombres
        scanf("%14s", nombres[e]);

        //ciclo interno: una vuelta por dia (columna) de la fila
        for (d = 0; d < DIAS; d++)
        {
            //pedir las horas del dia
            printf("Horas del %d:",dias[d]);
            //leer un entero en la celda
            scanf("%d", &horas[e][d]);
        }
        
    }
    
    //===Tabla===
    //Con encabezado con la palabra "nombre"
    printf("\n%-8s", "Nombre");

    //For para recorrer los dias para el encabezado
    for (d = 0; d < DIAS; d++)
    {
        //mostrar cada dia
        printf("%5s",dias[d]);

        //titulo de la ultima columna y salto de linea
        printf("%7s\n", "Total");

        //una fila de la tabla por estudiante
        for (e = 0; e < EST; e++)
        {
            //Reinicia el total de la fila e
            total[e] = 0;
            //mostrar el nombre
            printf("%-8s",nombres[e]);

            //recorre la columna de la fila e
            for (d = 0; d < DIAS; d++)
            {
                //Mostrar las horas de la celda
                printf("%5d",horas[e][d]);
                //sumar la celda al total
                total[e] += horas[e][d];
                //mostrar el total
                printf("7d\n",total[e]);

            }
            //mostrar el total
            printf("%7d\n",total[e]);
        }
        
    }
    
    //====Mayor del arreglo total====
    //supone que el primero estudio mas
    mejor = 0;
    //recorrer los demas estudiantes (posiciones 1 y 2).
    for (e = 0; e < EST; e++)
    {
        // comparar totales
        if (total[e] > total[mejor])
        {
            mejor = e;
        }

        
    }
    printf("\nEstudio mas: %s (%d horas)\n", nombres[mejor],total[mejor]);

    //==== Dia con mas horas(suma por columna)
    //mayor suma inicial en 0
    sumaMayor=0;
    diaMejor=0;

    int sumaDia;
    //recorrer columnas
    for (d = 0; d < DIAS; d++)
    {
        //Reiniciamos el acumulador
        sumaDia = 0;

        //recorrer filas de esa columna
        for (e = 0; e < EST; e++)
        {
            //suma de celda
            sumaDia += horas[e][d];

            //comparar la suma del dia con la mayor
            if (sumaDia > sumaMayor)
            {
                //guardar la nueva mayor
                sumaMayor = sumaDia;
                //guarda la posicion
                diaMejor = d;
            }
            
        }
        
    }
    //mostar el dia con mas horas
    printf("Dia con mas horas: %s (%d horas)\n",dias[diaMejor], sumaMayor);
    //==== Busqueda por nombre ====
    
    //pedir nombre a buscar
    printf("\nBuscar estudiante: ");
    //lee la palabra
    scanf("%14s", buscado);
    //marca que todavia no aparece
    encontrado = -1; // Si el for no lo encuentra el nombre sigue en -1
    // recorrer los nombres
    for (e = 0; e < EST; e++)
    {
        //comparara las dos cadenas
        //strcmp devuelve 0 si son iguales letra po letra
        if (strcmp(buscado, nombres[e]) == 0)
        {
            encontrado= e;
        }
        
        if (encontrado >= 0)
        {
            //muestra el total encontardo
            printf("%s estudio %d horas\n", nombres[encontrado],total[encontrado]);
            //en caso que no aparece
        }
        else
        {
            printf("%d no esta en la lista\n", buscado);
        }
        
        
    }
    
    return 0;
}