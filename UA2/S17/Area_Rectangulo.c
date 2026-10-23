//Area.c - Saca el area de un rectangulo

#include <stdio.h>

int main(void){
    //declara variables reales
    double area, base, altura;

    //entrada de datos, lee la base = 5
    printf("Digite la base del rectangulo:\n");
    scanf ("%lf", &base);

    //mensaje y lee altura = 3
    printf ("Digite la altura del rectangulo:\n");
    scanf ("%lf", &altura);

    //Multiplica y guarda
    area = base * altura;

    //Salida de datos 
    printf("El area seria %.2f es de cm2\n", area);

    return 0;
}