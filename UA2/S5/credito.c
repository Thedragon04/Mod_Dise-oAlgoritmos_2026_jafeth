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
    scanf(" %c", &respDeudas);

    printf("Años de antigüedad laboral:");
    scanf("%d", &antiguedad);

    printf("¿Tiene fiador? (S/N)");
    scanf(" %c", &respFiador);

    capacidadPago = salario >= cuota * 3;

    if (respDeudas == 's' || respDeudas == 'S'){
        tieneDeudas = 1;//verdadero
    }
    else{
        tieneDeudas = 0;//Falso
    }

    if (respFiador == 's' || respFiador == 'S'){
        tieneFiador = 1;//verdadero
    }
    else{
        tieneFiador = 0;//Falso
    }


    if (capacidadPago && tieneDeudas != 1 && (antiguedad >= 1 || tieneFiador == 1))
    {
        aprobado = 1;
    }
    else{
        aprobado = 0;
    }

    if (aprobado == 1)
    {
        printf("Credito aprobado");
    }
    else{
        printf("Credito rechazado");
    }

    
    
} 