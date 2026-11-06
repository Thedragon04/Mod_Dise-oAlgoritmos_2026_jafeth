#include <stdio.h>

void sumarPuntos(int *puntos, int compra) {/*Que pasaba: no tenia un puntero, Porque: con solo poner * ya esta, Cual es la correcion: poner un * al frente de puntos*/
    *puntos = *puntos + compra / 1000;/*Que pasaba: no tenia un puntero, Porque: con solo poner * ya esta, Cual es la correcion: poner un * al frente de puntos*/
}

int main(void) {
    int puntos = 0, compra, i;
    for (i = 1; i <= 3; i++) {/*Que pasaba: Aqui no hay nada malo pero la cuenta en vez de empezar en 0 empieza en 1 y termina cuando es mayor o igual 3, Porque: Esto es para que los prinf vayan en orden numerico tradicional, Cual es la correcion: no es necesaria una correcion pero tambien puede hacer directamente en el prinf sumando un 1 a i dejando la condicion i = 0; i < 3; i++*/
        printf("Compra %d: ", i);
        scanf("%d", &compra);/*Que pasaba: No guarda el dato, Porque: Hace falta el & adelante de compra, Cual es la correcion: Poner un & adelante compra ejem &compra*/
        sumarPuntos(&puntos, compra);/*Que pasaba: Darle a la funcion la direccion del dato, Porque: Hace falta ya que la funcion al tener el puntero pide una dirrecion de memoria , Cual es la correcion: Pooner el & adelante de puntos*/
    }
    
    printf("Puntos acumulados: %d\n", puntos);
    return 0;
}
