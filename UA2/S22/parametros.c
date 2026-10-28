#include <stdio.h>
//Propotipo de intercambiar
void intercambiar(int *a, int *b);

//prototipo de dividir
void dividir(int dividiendo, int divisor, int *cociente, int *residuo);

//funcion principal
int main(void){
    //los dos numeros del ciciente y residuo
    int x,y,c,r;

    //pedir el primer numero
    printf("Primer numero: ");
    scanf("%d", &x);

    printf("Segundo numero: ");
    scanf("%d", &y);

    //revision de si x es menor que y -> 5 < 17 si.
    if (x<y)
    {
        //intercambiar x y y -> x = 17, y = 5.
        intercambiar(&x,&y);
    }
    //mostrar numeros ordenados
    printf("Ordenados: %d y %d\n", x, y);

    //Validar division entre 0
    
    if (y == 0)
    {
        printf("No se puede dividir entre 0\n");
    }
    else{
        dividir(x,y, &c, &r);
        // mostrar la division
        printf("%d / %d = %d residuo %d\n", x, y, c, r);
        //comprobar
        printf("Comprobacion: %d * %d + %d = %d\n", c, y, r, c * y + r);

    }
    return 0;
}

//hacer el intercambio
void intercambiar(int *a, int *b){
//variable aux respladar el valor de x=5
int aux = *a;

//x recibe el valor de y = 17
*a = *b;

//recibe aux
*b = aux;
}

//definicion de dividir

void dividir(int dividiendo, int divisor, int *cociente, int * residuo){
    *cociente = dividiendo / divisor;
    *residuo = dividiendo % divisor;
}