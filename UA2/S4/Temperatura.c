// Convierte grados Celsius a Fahrenheit

#include <stdio.h>

int main(void){
    double celsius, farenheit;

    printf("Temperatura en grados Celsius:");
    scanf("%lf", &celsius);

    farenheit = celsius * 9 / 5 + 32;

    printf("%.2f, °C equivalen a, %.2f, °F\n", celsius, farenheit);
}