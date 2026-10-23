#include <stdio.h>
#define MINIMO 50000

int main(void){
    const double TASA = 0.10;
    double compra, descuento, total;
    printf("Monto de la compra:");
    scanf ("%lf", &compra);

    if (compra >= MINIMO)
    {
        descuento = compra * TASA;
    }
    else{
        descuento = 0;
    }

    total = compra - descuento;

    printf("Descuento: %.2f\n", descuento);
    printf("Total a pagar: %.2f", total);


}