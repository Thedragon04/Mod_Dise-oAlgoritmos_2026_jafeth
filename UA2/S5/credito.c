#include <stdio.h>

int main(void){
    double salario, cuota;
    int antiguedad;
    char respDeudas, respFiador;
    int capacidadPago, tieneDeudas, tieneFiador, aprobado;

    printf("Salario mensual:");
    scanf ("%lf", &salario);

    printf("Cuota mensual del crédito:");
    scanf("%lf", &cuota);

    printf("¿Tiene deudas atrasadas? (S/N)");
    scanf("%c", &respDeudas);

    printf("Años de antigüedad laboral:");
    scanf("%d", &antiguedad);

    printf("¿Tiene fiador? (S/N)");
    scanf("%c", &respFiador);

    capacidadPago = salario >= cuota * 3;
    tieneDeudas = 
}