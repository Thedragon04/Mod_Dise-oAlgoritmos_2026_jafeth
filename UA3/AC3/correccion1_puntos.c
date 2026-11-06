#include <stdio.h>

void sumarPuntos(int *puntos, int compra) {//Faltaba darle un puntero a la funcion para cambiar directamente los puntos sin tener que devolver nada de la funcion
    *puntos = *puntos + compra / 1000;//Añadi un puntero
}

int main(void) {
    int puntos = 0, compra, i;
    for (i = 1; i <= 3; i++) {// i = 1 es para hacer el prinf directamente con el i actual de cada iteracion hasta que sea mayr a 3
        printf("Compra %d: ", i);
        scanf("%d", &compra);//Faltaba el ampersan
        sumarPuntos(&puntos, compra);//Faltaba hacer que la variable estuviera enlazada al puntero
    }
    
    printf("Puntos acumulados: %d\n", puntos);
    return 0;
}
