#include <stdio.h>
#include <stdlib.h>

int lanzardado(void);

int lanzardado(void){
    return rand() % 6 + 1;
}

int main(void){
    int veces = 600, i, cantidad;
    srand(2026);
    cantidad = lanzardado();
    for (i = 0; i < 6; i++)
    {
        printf("%d",cantidad);
    }


}