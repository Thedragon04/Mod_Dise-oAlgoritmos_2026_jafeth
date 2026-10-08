//Factura con IVA

#include <stdio.h>

int main(void){
    //Constante para el IVA
    const double TASA_IVA = 0.13;

    //variables centradaspara cantidad y reales para montos
    int cantidad;
    double precio, subtotal, iva, total;
    //Entrada: pedir y almacenar cantidad
    printf("Cantidad: \n");
    scanf("%d", &cantidad);

    //leer u double precio
    printf("Precio unitario: \n");
    scanf("%lf", &precio);

    //PROCESO: 
    subtotal = cantidad * precio;
    //sacamos IVA con la constante 
    iva = subtotal * TASA_IVA;
    //TOTAL -> 16950
    total = subtotal + iva;

    //SALIDAS: usar 2 decimales 
    printf("Subtotal: %.2f\n", subtotal);
    printf("IVA (13%%): %.2f\n", iva);
    printf("Total: %.2f\n", total);

    return 0;

}




