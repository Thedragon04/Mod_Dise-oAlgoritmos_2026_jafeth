//lectura de la nota sea válida
#include <stdio.h>

int main(void){
    int nota;

    printf("Nota (0 a 100): ");
    scanf("%d", &nota);

    if (nota >= 0 && nota <= 100){
        if (nota > 69)
        {
            printf("Estas aprobado");
        }
        else{
            printf("Estas reprobado");
        }
    }
    else{
        printf("Nota invalida");
    }
}