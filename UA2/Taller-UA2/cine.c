//Problema de cine en la presentacion del documento taller

#include <stdio.h>
//Definir constantes
#define MAX_COMPRAS 10
#define PRECIO_GENERAL 3500
#define PRECIO_NINO 2500
#define PRECIO_MAYOR 2000
#define MIN_DESCUENTO 5
#define TAZA_DESCUENTO 0.10

//Prototipos de funciones
int leerEntero(const char mensaje[], int minimo, int maximo);
double precioEntrada(int tipo);
double calcularTotal(int tipo, int cantidad);
void resumir(const int cant[], const double tot[],int n, double *total, int *posMayor, int *conDescuento);

int main(void){
    //Definir arreglos y variables
    char clientes[MAX_COMPRAS][15];//Nombres de los Clientes de la compra
    int cantidades[MAX_COMPRAS];//Cantidad de compras posibles
    double totales[MAX_COMPRAS];//Subtotal de cada compra
    // cantidad de compras, indice y el tipo de entrada
    int n, i = 0, tipo;
    //resultados
    double totalVendido;
    int posMayor, conDescuento = 0;

//portada
printf("==== Venta de Entradas ====\n");
printf("Tipos: 1. General 3500, 2. Niño 2500, 3. Adulto mayor 2000\n");

//Leer cantidad de compras -> 4
n = leerEntero("Cantidad de compras", 1, MAX_COMPRAS);

//FOR para una vuelta por compra
for (i = 0; i < n; i++)
{
    printf("Compra %d\n Cliente: ", i + 1);//Numero de compra y pedido de cliente
    scanf("%14s",clientes[i]);

    //Leer el tipo de entrada
    tipo = leerEntero("Tipo",1,3);
    //leer cantidad entradas
    cantidades[i] = leerEntero("Entradas",1,8);
    
    //Calcular el total de la compra
    totales[i] = calcularTotal(tipo, cantidades[i]);
}

//calcular el resumen de una pasada
resumir(cantidades, totales, n, &totalVendido, &posMayor, &conDescuento);
//Encabezado de la tabla

printf("\n%-12s%9s%12s\n","Clientes","Cant","Subtotal");

//recorrer las compras
for (i = 0; i < n; i++)
{
    //mostrar fila
    printf("%-12s%9d%12.2f\n", clientes[i],cantidades[i], totales[i]);
}
    //total vendido
    printf("Total vendido: %12.2f\n", totalVendido);
    //compra mayor
    printf("Compra Mayor: %s (%.2f)\n", clientes[posMayor],totales[posMayor]);
    //compras con descuento
    printf("Con descuento:      %d compra(s)\n", conDescuento);
    //termina main con un return por valor
    return 0;
}

//Definiciones. Leer entero
int leerEntero(const char mensaje[], int minimo, int maximo){
    int numero;

    do
    {
        printf("%s (%d a %d): ",mensaje,minimo,maximo);
        scanf("%d", &numero);
        
    } while (numero < minimo || numero > maximo);

    return numero;
}

//definicion precioEntrada
double precioEntrada(int tipo){
    switch (tipo)
    {
    case 1:
        return PRECIO_GENERAL;//Return termina la funcion sin necesidad de un break
    case 2:
        return PRECIO_NINO;
    case 3:
        return PRECIO_MAYOR;
    default:
        return 0;
    }
}

double calcularTotal(int tipo, int cantidad){
    double total = precioEntrada(tipo) * cantidad;

    if (cantidad >= MIN_DESCUENTO)
    {
        total = total * (1 - TAZA_DESCUENTO);
    }
    return total;
}

//definir resumir
void resumir(const int cant[], const double tot[],int n, double *total, int *posMayor, int *conDescuento){
    int i;
    //inicializo los tres resultados en la memoria de main
    *total = 0;
    *posMayor = 0;

    //rocorrer las compras
    for  (i = 0; i < n; i++)
    {
        *total += tot[i];
        //comparar la compra mayor
        if (tot[i] > tot[*posMayor])
        {
            *posMayor = i;
        }

        if (cant[i] >= MIN_DESCUENTO)
        {
            *conDescuento = *conDescuento + 1;
        }
    }
    
}