// Algoritmo para saber el salario neto
#include <stdio.h>

int main(void){

    const double DEDUCCION = 0.10;
    double horas,tarifaHora, bruto, deduccion, neto;

    printf("Horas trabajadas:");
    scanf("%lf", &horas);

    printf("Pago por hora:");
    scanf("%lf", &tarifaHora);

    bruto = horas * tarifaHora;
    deduccion = bruto * DEDUCCION;
    neto = bruto - deduccion;

    printf("Salario bruto: ,%.2f\n",bruto);
    printf("Deduccion: ,%.2f\n", deduccion);
    printf("Salario neto, %.2f\n", neto);



}