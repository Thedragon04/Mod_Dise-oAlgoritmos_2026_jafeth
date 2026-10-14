//Pago semanal con horas extra de varias personas colaboradoras

#include <stdio.h>
#include <stdbool.h>

int main(void){
    int cantidad, i, conExtra;
    char nombre[50];
    double horas, tarifa, horasExtra, pago, totalPlanilla;
    bool valido;
    totalPlanilla = 0;
    conExtra = 0;

    printf("Cantidad de personas colaboradoras:");
    scanf("%d", &cantidad);

    for (i = 0; i < cantidad; i++)
    {
        valido = true;
        printf("Nombre: ");
        scanf(" %s", &nombre);

        while (valido)
        {
            printf("Horas de la semana (0 a 72):");
            scanf(" %lf", &horas);
            if (horas >= 0 && horas <= 72)
            {
                printf("Horas validas\n");
                valido = false;
            }
            else{
                printf("Dato inválido, intente de nuevo\n");
            }
        }

        printf("Tarifa por hora: ");
        scanf("%lf", &tarifa);

        if (horas > 48)
        {
            horasExtra = horas - 48;
            pago = 48 * tarifa + horasExtra * tarifa * 1.5;
            conExtra += 1;
        }
        else{
            pago = horas * tarifa;
        }
        printf("%s : %.1f\n", nombre, pago);
        totalPlanilla += pago;
        
    }
    printf("Total de la plantilla: %f\n", totalPlanilla);
    printf("Personas con horas extra: %d", conExtra);
    
}