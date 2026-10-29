#include <stdio.h>

#define PRODUCTOS 4

int leerEntero(const char mensaje[], int minimo, int maximo);

void valorInventario(double *valorInventario,const double precio[PRODUCTOS], int existencias[PRODUCTOS]);

void listar(const char productos[PRODUCTOS][20], const double precio[PRODUCTOS], int existencias[PRODUCTOS]);

void vender(const char productos[PRODUCTOS][20], const double precio[PRODUCTOS], int existencias[PRODUCTOS]);

void reponer(const char productos[PRODUCTOS][20], const double precio[PRODUCTOS], int existencias[PRODUCTOS]);

int main(void){
    int opcion;
    char productos[PRODUCTOS][20] = {"Arroz 2kg","Frijoles 1kg","Cafe 1kg", "Aceite 1L"};
    double precio[PRODUCTOS] = {2400,1800,4500,3200};
    int existencias[PRODUCTOS] = {20,15,12,8};
    double valorInven;

    do
    {
        printf("\n1. Listar 2. Vender 3. Reponer 4. Valor 0. Salir\n");
        opcion = leerEntero("Opcion: ",-1,5);

        switch (opcion)
        {
        case 1:
            listar(productos,precio,existencias);
            break;
        case 2:
            vender(productos,precio,existencias);
            break;
        case 3:
            reponer(productos,precio,existencias);
            break;
        case 4:
            valorInventario(&valorInven, precio, existencias);
            printf("Valor del inventario: %.2f\n", valorInven);
            break;
        case 0:
            printf("Hasta luego");
            break;
        default:
            printf("Opcion invalida");
            break;
        }
    } while (opcion != 0);
}

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

void valorInventario(double *valorInventario,const double precio[PRODUCTOS], int existencias[PRODUCTOS]){
    double suma;
    int i;
    for ( i = 0; i < PRODUCTOS; i++)
    {
        suma += existencias[i] * (double)precio[i];
    }

    *valorInventario = suma;
}

void listar(const char productos[PRODUCTOS][20], const double precio[PRODUCTOS], int existencias[PRODUCTOS]){
    int i;
    
    for (i = 0; i < PRODUCTOS; i++)
    {
        printf("%-20s %.2f %4d\n", productos[i],precio[i], existencias[i]);
    }

}
void vender(const char productos[PRODUCTOS][20], const double precio[PRODUCTOS], int existencias[PRODUCTOS]){
    int producto, cantidad, correcto = 1;
    int v/*Posicion de precio*/, e/*Posicion de existencias*/;


    producto = leerEntero("Producto (1 a 4): ",0,5);

    e = existencias[producto - 1];
    v = precio[producto - 1];
    do
    {
        cantidad = leerEntero("Cantidad (1 a 50): ",0,51);
        if (e == 0 || cantidad == 0)
        {
            correcto = 0;
        }
        else if (e < cantidad)
        {
            printf("Solo hay %d unidades\n",e);
        }
        else{
            existencias[producto - 1] = e - cantidad;
            correcto = 0;
        }
        
        
    } while (correcto != 0);
    
    if (e != 0 || cantidad != 0)
    {
        printf("Vendido: %d x %s = %.2f\n", cantidad, productos[producto - 1] , cantidad * 
        (double)v);
    }
}

void reponer(const char productos[PRODUCTOS][20], const double precio[PRODUCTOS], int existencias[PRODUCTOS]){
    int producto, cantidad, correcto = 1;
    int e/*Posicion de existencias*/;


    producto = leerEntero("Producto (1 a 4): ",0,5);

    e = existencias[producto - 1];
    do
    {
        cantidad = leerEntero("Cantidad (1 a 50): ",0,51);
        if (e == 50)
        {   
            printf("Almacen lleno");
            correcto = 0;
        }
        else if (cantidad + e > 50)
        {
            printf("Mucho\n");
        }
        
        else{
            existencias[producto - 1] = e + cantidad;
            correcto = 0;
        }
    } while (correcto != 0);
    
    if (e != 50)
    {
        printf("Existencias de %s: %d\n", productos[producto - 1], e + cantidad);
    }
}