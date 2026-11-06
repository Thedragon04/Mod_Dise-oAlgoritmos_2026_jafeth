#include <stdio.h>
#include <string.h>/*Que pasaba:Vi que no se estaba utilizando la biblioteca, Porque: No se estaba utilizando ninguna funcion de esta, Cual es la correcion: Utilizarla en la linea 8*/
#define N 4

int buscar(const char nombres[][15], int n, const char buscado[]) {
    int i;
    for (i = 0; i < n; i++)/*Que pasaba: El for pasaba por un 4 y este no existe, Porque: Porque la i <= n donde n es cuatro y como solo existen 4 elementos y llegar al 4 no es correcto, Cual es la correcion: Quitar el = de i <= n y con esto solo se valora los elemntos existentes*/
        if (strcmp(nombres[i],buscado) == 0)/*Que pasaba: Que se estaba comparando cadenas con ==, Porque: Esto lo que hace es comparar los espacios de memoria y no las cadenas, Cual es la correcion: llamar a la funcion de strcmp(a[i],b) == 0 esto pregunta si las cadenas son identicas si lo son da verdadero y devuelve el i actual*/
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
