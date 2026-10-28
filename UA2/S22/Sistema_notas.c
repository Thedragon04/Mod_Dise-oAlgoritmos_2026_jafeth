//Caso integrador de la unidad 2 del curso Diseño de algoritmos
/*Enunciado: El sistema registra notas de un grupo de 16 estudiantes
contiene un menu 1. agregar (nota de 0 a 100 validar). 2 ver notas (cada unna con aprobado si es 70 o mas, reprobado). 3 estadisticas(promedio, mayor y menor). y 0 para salir*/
#include <stdio.h>
#define MAX 16

// leernota no recibe datos y devuelve una nota valida
double leerNota(void);

//Recibe el arreglo y direccion de la cantidad
void agregarNota(double notas[], int *cantidad);

//Mostar notas recibe el arreglo y la cantidad por valor
void mostrarNotas(const double notas[], int cantidad);

//Calcula estadisticas: recibe el arreglo y al cantidad, y tres punteros
void calcularEstadisticas(const double notas[], int cantidad, double *promedio, double *mayor, double *menor);

int main(void){
    //Traemos el arreglo de notas
    double notas[MAX];
    //Cantidad de notas guardadas y opcion del menu
    int cantidad=0, opcion;

    //resultado de las estadisticas
    double promedio, mayor, menor;

    //ciclo del menu para repetir hasta 0
    do
    {
        //mostrar el menu
        printf("\n1. agregar 2. Ver notas 3. Estadisticas 0. Salir\n");
        //Pedir la opcion del menu
        printf("Opcion: ");
        scanf("%d",&opcion);
        //elige la rama segun opcion
        switch (opcion)
        {
        case 1:
            agregarNota(notas, &cantidad);
            break;

        //Lista de notas
        case 2:
            mostrarNotas(notas, cantidad);
            break;

        //estadisticas
        case 3:
        //revisa si hay notas
            if (cantidad == 0)
            {
                printf("No hay notas registradas\n");
            }
            else{
                //hacer la llamada que devuelve 3 resultados
                calcularEstadisticas(notas, cantidad, &promedio, &mayor, &menor);
                //mostrar resultado
                printf("Promedio: %.0f Mayor: %.1f Menor: %.1f\n",promedio,mayor,menor);
            }
            
            break;
        case 0:
            printf("Hasta luego\n");
            break;

        default:
            printf("Opcion invalida");
            break;
        }
    } while (opcion != 0);

    return 0;
    
}

double leerNota(void){
    double nota;
    //ciclo de validacion

    do
    {
        //pedir nota
        printf("Nota (0 a 100): ");
        scanf("%lf",&nota);
        //repite si esta fuera de rango
    } while (nota < 0 || nota > 100);
    return nota;
}


void agregarNota(double notas[], int *cantidad){
    //revisar si esta vacio
    if (*cantidad < MAX)
    {
        //guarde la nota
        notas[*cantidad] = leerNota();
        //aumentar la cantidad
        (*cantidad)++;
    }
    else{
        printf("EL grupo ya tiene %d notas\n",MAX);
    }
    
}

//definicion para mostrar notas
void mostrarNotas(const double notas[], int cantidad){
    //indice local para recorrer el arreglo
    int i;
    //for para recorrer las notas
    for (i = 0; i < cantidad; i++)
    {
        printf("%2d. %5.1f %s\n", i +1, notas[i], notas[i] >= 70 ? "Aprobado":"Reprobado");
    }
    
}

//Definicion de calcular estadisticas
void calcularEstadisticas(const double notas[], int cantidad, double *promedio, double *mayor, double *menor){
    //Acumulador local
    double suma = 0;
    //indice local para recorrer el arreglo
    int i;
    //se supone que la primera nota es mayor
    *menor = notas[0];
    for (i = 0; i < cantidad; i++)
    {
        //Suma la nota
        suma += notas[i];
        //compare con el mayor
        if (notas[i] > *mayor)
        {
            //guarde el nuevo mayor
            *mayor = notas[i];
        }
        
    }
    //calcule el promedio
    *promedio = suma / cantidad;
}