//circulo.c trabaj con la constante de PI
#include <stdio.h>
#define PI 3.14159265358979 //Constante Simbolica: el preocesador cambia PI por el numero

int main(void){
    //constante de candena: no se puede cambiar durante el programa
    const char UNIDAD[]="cm";
    //Variables reales
    double radio, area, perimetro;

    //ENTRADA: lee el radio -> radio = 4
    printf("Radio del circulo (cm):");
    scanf("%lf",&radio);

    //Proceso: En C no existe ^; radio al cuadrado = radio * radio
    area = PI *radio*radio;

    //Perimetro = 2 * PI * Radio
    perimetro = 2 * PI * radio;

    //SALIDA: %.2f muestra 2 decimales y %s muestra la cadena UNIDAD
    printf("Area: %.2f %s2\n", area, UNIDAD);
    printf("Perimetro: %.2f %s2\n", perimetro, UNIDAD);

    return 0;
}