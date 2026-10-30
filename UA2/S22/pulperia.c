#include <stdio.h>
//Productos totales
#define PRODUCTOS 4
//Funcion para leer enteros con validaxion
int leerEntero(const char mensaje[], int minimo, int maximo);
//Funcion para mostrar la lista de con sus nombre, precios y cantidades
void listar(const char productos[PRODUCTOS][20], const double precio[PRODUCTOS], int existencias[PRODUCTOS]);
//Funcion para saber la suma de todo los productos
double valorInventario(const double precio[PRODUCTOS], int existencias[PRODUCTOS]);
//Funcion para vender producto 
int vender(int *existencia, int cantidad);
//Funcion para reponer producto
void reponer(int *existencia, int cantidad);

//Funcion principal
int main(void){
    //Arreglos
    char productos[PRODUCTOS][20] = {"Arroz 2kg","Frijoles 1kg","Cafe 1kg", "Aceite 1L"};
    double precio[PRODUCTOS] = {2400,1800,4500,3200};
    int existencias[PRODUCTOS] = {20,15,12,8};
    //Variables
    double valorInven;
    int producto,cantidad, pasa, opcion;

    //Ciclo que termina cuando se digita un 0
    do
    {
        printf("\n1. Listar 2. Vender 3. Reponer 4. Valor 0. Salir\n");
        opcion = leerEntero("Opcion(0 a 4): ",0,4);

        switch (opcion)
        {
        case 1:
            //Muestra funcion de listar
            listar(productos,precio,existencias);
            break;
        case 2:
            //muestra funcion vender pidiendo dos numeros enteros primero una para que existencias sepa cual tiene que tomar y el otro es solo la cantidad
            producto = leerEntero("Producto (1 a 4):",1,4);
            cantidad = leerEntero("Cantidad (1 a 50)", 1, 50);
            pasa = vender(&existencias[producto-1], cantidad);
            if (pasa == 1)
            {
                printf("Vendido: %d x %s = %.2f\n",cantidad,productos[producto-1], cantidad * precio[producto-1]);
            }
            break;
        case 3:
            producto = leerEntero("Producto (1 a 4):",1,4);
            cantidad = leerEntero("Cantidad (1 a 50)", 1, 50);
            reponer(&existencias[producto-1], cantidad);
            printf("Existencias de %s: %d\n", productos[producto-1], existencias[producto-1]);
            break;
        case 4:
            valorInven = valorInventario(precio,existencias);
            printf("Valor del inventario: %.2f\n",valorInven);
            break;
        case 0:
            printf("Hasta luego");
            break;
        default:
            printf("Opcion invalida\n");
            break;
        }
    } while (opcion != 0);
}

//Funcion para validar los numeros que entren
int leerEntero(const char mensaje[], int minimo, int maximo){
    int numero;
        do
    {
        printf(mensaje);
        scanf("%d", &numero);
        if (numero < minimo || numero > maximo)
        {printf("Fuera de rango\n");}
        
    } while (numero < minimo || numero > maximo);
    
    return numero;
}
//Funcion para que se muestre la lista con nombre, precios y cantidades
void listar(const char productos[PRODUCTOS][20], const double precio[PRODUCTOS], int existencias[PRODUCTOS]){
    int i;
    
    for (i = 0; i < PRODUCTOS; i++)
    {
        printf("%-20s %.2f %4d\n", productos[i],precio[i], existencias[i]);
    }

}

//Funcion de venta que toma el puntero
int vender(int *existencia, int cantidad){
    int pasa = 0;

    if (cantidad > *existencia)
    {printf("Solo hay %d unidades\n", *existencia);}

    else{
        *existencia -= cantidad;
        pasa = 1;
        }
    return pasa;
    
}

//Funcion de reponer que toma el puntero
void reponer(int *existencia, int cantidad){
    *existencia += cantidad;
}
//Funcion que suma todo el inventario y lo devuelve ya como un solo numero float
double valorInventario(const double precio[PRODUCTOS], int existencias[PRODUCTOS]){
    int i;
    double suma;

    for (i = 0; i < PRODUCTOS; i++)
    {
        suma += precio[i] * existencias[i];
    }
    return suma;
}