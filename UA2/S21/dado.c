#include <stdio.h>
#include <stdlib.h>

int lanzarDado(void);
void mostrarBarra(int cantidad);

int lanzarDado(void){
    return rand() % 6 + 1;
}

void mostrarBarra(int cantidad){
    int asteriscos = cantidad / 10, i;
    for (i = 0; i < asteriscos; i++)
    {
        printf("*");
    }
}

int main(void){
    srand(2026);
    int frecuencia[6] = {0}, i;

    for (i = 0; i < 600; i++)
    {
        int resultado = lanzarDado();
        frecuencia[resultado - 1]++;
    }
    
    for (i = 0; i < 6; i++)
    {
        printf("Cara %d: %4d  ", i +1, frecuencia[i]);
        mostrarBarra(frecuencia[i]);
        printf("\n");
    }
    return 0;
}



