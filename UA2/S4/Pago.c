// Calcula el pago semanal de una persona colaborador

#include <stdio.h>
#define BONO 5000

int main(void){
    
    double horas, pagoHora, salario;

    printf("Horas trabajadas en la semana:");
    scanf("%lf",&horas);

    printf("Pago por hora:");
    scanf("%lf",&pagoHora);

    salario = horas * pagoHora + BONO;


    printf("-----------------------------\n");
    printf("%-18s %10.2f\n","Horas:", horas);
    printf("%-18s %10.2f\n","Pago por hora: ", pagoHora);
    printf("%-18s %10d\n","Bono: ", BONO);
    printf("%-18s %10.2f\n","Pago semanal:", salario);

    printf("-----------------------------");
    
}