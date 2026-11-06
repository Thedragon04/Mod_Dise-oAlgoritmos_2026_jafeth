#include <stdio.h>
#include <string.h>//No se estaba usando esta biblioteca en la linea 8 cambie el nombre[i] == buscado, esto compara las direcciones de memoria y no las cadenas
#define N 4

int buscar(const char nombres[][15], int n, const char buscado[]) {
    int i;
    for (i = 0; i < n; i++)//Se quito el = de la comparacion para que no evalue al 4 ya que lee de 0 1 2 3 y estos serian los 4 que lee sino estaria leyendo 5
        if (strcmp(nombres[i],buscado) == 0)//Condicion cambiada ya que con strcmp es que se comparan cadenas
            return i;
    return -1;
}

int main(void) {
    char nombres[N][15] = {"Arroz", "Frijoles", "Cafe", "Azucar"};
    double precios[N] = {1200, 1500, 3200, 900};
    char buscado[15];
    int pos;
    printf("Producto: ");
    scanf("%14s", buscado);
    pos = buscar(nombres, N, buscado);
    if (pos == -1)
        printf("No existe\n");
    else
        printf("%s cuesta %.2f\n", nombres[pos], precios[pos]);
    return 0;
}
