/*Una cooperativa eléctrica emite recibos. De cada recibo se digita el número de medidor (1000 a 9999), el tipo de cliente (1 Residencial, 2 Comercial) y el consumo del mes en kWh (0 a 3000); un dato inválido se vuelve a pedir. Residencial: los primeros 200 kWh a ₡80 cada uno, de 201 a 400 a ₡110 y los que pasan de 400 a ₡150. Comercial: ₡130 por kWh más un cargo fijo de ₡3000. A todos se les suma alumbrado público: 2 % del monto de energía. Después de cada recibo se pregunta si hay otro (S/N). Al final se muestra cuántos recibos se emitieron, el total facturado y el medidor con el recibo mayor.*/

#include <stdio.h>
#include <string.h>

#define MENOR 80
#define INTERMEDIA 110
#define MAYOR 150
#define COMERCIAL 130
#define ALUM_PUBLICO 0.02
#define FIJO 3000

int leerEntero(const char mensaje[], int minimo, int maximo);
char leerSN(const char mensaje[]);
double energiaResidencial(int kwh);
double calcularRecibo(int tipo, int kwh);

int main(void){
    double total = 0,total_actual=0, mayorRecibo = 0, medidor_mayor;
    char si_O_no;
    int recibos_emitidos=0;
    int kwh, tipo, medidor;

    do
    {
        medidor = leerEntero("Numero de medidor ",1000,9999);
        tipo = leerEntero("Tipo de cliente:\n 1. Residencial\n 2. Comercial\n opcion: ", 1,2);
        kwh = leerEntero("Consumo del mes: ", 0,3000);
        total_actual = calcularRecibo(tipo, kwh);
        if (total_actual > mayorRecibo)
        {
            mayorRecibo = total_actual;
            medidor_mayor = medidor;
        }
        total += total_actual;
        recibos_emitidos++;

        si_O_no = leerSN("Desea continuar S/N ");

    } while (si_O_no == 's' || si_O_no == 'S');
    
    printf("%d recibos\nTotal facturado %.2f\nRecibo mayor %.0f (%.2f)", recibos_emitidos, total, medidor_mayor, mayorRecibo);
    return 0;
}
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

int leerEntero(const char mensaje[], int minimo, int maximo){
    int numero;
    do
    {
        printf(mensaje);
        scanf ("%d",&numero);
        if (numero < minimo || numero > maximo){
            printf("Invalido\n");
        }
    } while (numero < minimo || numero > maximo);
    return numero;
}

double calcularRecibo(int tipo, int kwh){
    double comercial;
    switch (tipo)
    {
    case 1:
        comercial=energiaResidencial(kwh);
        break;
    case  2:
        comercial = COMERCIAL * kwh + FIJO;
        break;
    default:
        break;
    }
    return comercial;
}

double energiaResidencial(int kwh){
    double resultado, alumbrado, fijo;
    if (kwh <= 200)
    {
        resultado = kwh * MENOR;
        alumbrado = resultado * ALUM_PUBLICO;
        resultado = resultado + alumbrado; 
    }
    else if (kwh > 200 && kwh <= 400)
    {
        fijo = 200 * MENOR;
        kwh = kwh - 200;
        resultado = kwh * INTERMEDIA + fijo;
        alumbrado = resultado * ALUM_PUBLICO;
        resultado = resultado + alumbrado; 
    }
    else{
        fijo = 200 * MENOR + 200 * INTERMEDIA;
        kwh = kwh - 400;
        resultado = kwh * MAYOR + fijo;
        alumbrado = resultado * ALUM_PUBLICO;
        resultado = resultado + alumbrado; 
    }
    
    return resultado;
}