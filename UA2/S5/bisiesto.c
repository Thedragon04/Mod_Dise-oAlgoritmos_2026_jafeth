#include <stdio.h>
#include <stdbool.h>

int main(void){
    int año;
    char siEs, comprobacion;
    bool esBisiesto;
    printf("Año: ");
    scanf("%d", &año);

    printf("%d %s bisiesto\n", año, ((año % 4 == 0 && año % 100 != 0) || año % 400 == 0) ? "es" : "no es");

    siEs = (año % 4 == 0 && año % 100 != 0) || año % 400 == 0;
    printf("%d %s bisiesto\n", año, siEs ? "es" : "no es" );
}