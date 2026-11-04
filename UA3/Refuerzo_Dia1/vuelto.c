/*Una caja calcula el vuelto de cada compra. Se digita el total de la compra (1 a 1 000 000) y el monto pagado, que no puede ser menor que el total (si lo es, se vuelve a pedir). El programa muestra el vuelto y cuántos billetes o monedas de cada denominación entregar, empezando por la mayor (20 000, 10 000, 5000, 2000, 1000, 500, 100, 50, 25, 10 y 5); solo se muestran las que se usan. Si sobran colones que no se pueden entregar (menos de 5), se indica. Al final se muestra la cantidad total de piezas. Después de cada compra se pregunta si hay otra (S/N).*/

#include <stdio.h>
#include <string.h>

int leerEntero(const char mensaje[], int minimo, int maximo);
char leerSN(const char mensaje[]);
int cuantas(int *resto, int denominacion);






char leerSN(const char mensaje[]){
    char si_O_no[50];
    int pasa;
    while (getchar() != '\n');
    do
    {
        printf(mensaje);
        fgets(si_O_no, sizeof(si_O_no), stdin);
        si_O_no[strcspn(si_O_no, "\n")] = '\0';
        if (strcmp(si_O_no,"S") == 0 || strcmp(si_O_no,"s")==0 || strcmp(si_O_no,"n")==0 ||strcmp(si_O_no,"N")==0 )
        {
            pasa = 0;
        }
        else{
            printf("Solo S/N\n");
            pasa = 1;
        }
        
    } while (pasa != 0);
    
    return si_O_no[0];
}