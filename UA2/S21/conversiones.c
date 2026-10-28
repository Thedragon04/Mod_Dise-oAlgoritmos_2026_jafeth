

#include <stdio.h>
#define TIPO_CAMBIO 510.0//Colones por dolar

//PROTOTIPOS DE LAS FUNCIONES
double celsiusFahrenheit(double celsius);//Devuelve los F
double colonesADolares(double colones);//Devuelve los dolares
int esBisiesto(int anio);// 1 o 0
int esNotavalida(double nota);// 1 o 0

//Funcion principal

int main(void){
    //Pueba la temperatura 77.0
    printf("25 C = %.1f F (esperado 77.0)\n",celsiusFahrenheit(25));

    //prueba la moneda 10.00
    printf("5100 Colones = %.2f dolares (esperado 10)\n", colonesADolares(5100));

    //Prueba anio bisisesto -> 1 verdadero
    printf("2024 bisiesto: %d (esperado 1)\n", esBisiesto(2024));

    //Prueba anio no bisisesto -> 0 falso
    printf("1900 bisiesto: %d (esperado 1)\n", esBisiesto(1900));

    //prueba la nota invalida -> 0
    printf("Nota 105 invalida: %d (esperado 0)\n", esNotavalida(105));

    //prueba la nota valida -> 1
    printf("Nota 85 valida: %d (esperado 1)\n", esNotavalida(85));

}

//conversion de temperatura
double celsiusFahrenheit(double celsius){
    return celsius * 9.0 / 5.0 + 32;
}

//conversion de moneda
double colonesADolares(double colones){
    return colones / TIPO_CAMBIO;
}

//anio bisiesto
int esBisiesto(int anio){
    return(anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;
}

//Validar nota
int esNotavalida(double nota){
    return (nota >= 0 && nota <= 100);
}