#include <stdio.h>

int sumarPuntos(int puntos, int compra) {//La funcion tenia que devolver algo en este caso un numero entero
    puntos = puntos + compra / 1000;
    return puntos;//Faltaba el return para dar los puntos
}

int main(void) {
    int puntos = 0, compra, i;
    for (i = 1; i <= 3; i++) {
        printf("Compra %d: ", i);
        scanf("%d", &compra);//Faltaba el ampersan
        puntos = sumarPuntos(puntos, compra);//Faltaba hacer que la funcion estuviera enlazada a puntos
    }
    
    printf("Puntos acumulados: %d\n", puntos);
    return 0;
}
