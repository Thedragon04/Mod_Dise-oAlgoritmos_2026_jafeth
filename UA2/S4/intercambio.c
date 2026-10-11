//Intercambio de varibles 

#include <stdio.h>

int main(void){
    int a,b,aux;
    a = 5;
    b = 9;
    aux = a;
    a = b;
    b = aux;
    printf("Antes:   a = %d b = %d\n", aux,a);
    printf("Despues: a = %d b = %d", a,b);
}