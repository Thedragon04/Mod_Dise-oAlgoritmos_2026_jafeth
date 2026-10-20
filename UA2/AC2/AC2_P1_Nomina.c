/*Una empresa de consultoría necesita calcular el salario neto de sus empleados. Escriba un
programa en C que:
1. Reciba el nombre completo del empleado (puede tener espacios; no se acepta un nombre
vacío).
2. Reciba el salario bruto, que debe ser mayor que 0; si no, muestra un mensaje y lo vuelve a
pedir.
3. Calcule los descuentos sobre el salario bruto: CAJA (9.5 %), IESS (2.5 %) e impuesto sobre la
renta (10 %, solo si el salario bruto supera 800).
4. Calcule el salario neto (bruto menos todos los descuentos).
5. Muestre un comprobante con el nombre, el salario bruto, cada descuento y el salario neto, con
dos decimales y los montos alineados.
Requisitos en C
Use constantes (#define o const) para las tasas y para el límite de 800, fgets para el nombre, strlen
para revisar que no esté vacío y un do … while para validar el salario.
Al inicio del archivo escriba en comentarios el enunciado, qué se logra, cómo se logra y el
resultado esperado, y comente el uso de cada variable y constante.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    //Variables
    char nombre[50];
    float caja, iess, renta, salario_bruto, salario_neto;
    //Constantes
    const float CAJA=0.095, IESS = 0.025, RENTA=0.1;

    //Validar la entrada del nombre no sea vacio
    printf("=== Calculo de nomina ===\n");
    do
    {
        printf("Nombre del empleado: ");
        fgets(nombre, sizeof(nombre),stdin);
        nombre[strcspn(nombre, "\n")] = '\0';
        if (strlen(nombre) == 0)
        {
            printf("Nombre invalido, no puede ir en blanco\n");
        }
        
    } while (strlen(nombre) == 0);
    //Validar que la cantidad sea mayor a 1
    do
    {
        printf("Salario bruto: ");
        scanf("%f", &salario_bruto);
        if (salario_bruto < 1)
        {
            printf("El salario no puede ser menor a 1\n");
        }
        
    } while (salario_bruto < 1);
    
    //Reviso si es que tiene que pagar renta
    if (salario_bruto > 800)
    {
        renta = salario_bruto * RENTA;
    }
    else{
        renta = 0;
    }
    //Calculo de deducciones finales
    caja = salario_bruto * CAJA;
    iess = salario_bruto * IESS;
    //Salario neto con todas las deducciones 
    salario_neto = salario_bruto - caja - iess - renta;

    //Salidas
    printf("\n------- Comprobante de pago -------\n");
    printf("Empleado:               %10s\n",nombre);
    printf("Salario bruto:          %10.2f\n", salario_bruto);
    printf("Descuento CAJA (9.5%%): %11.2f\n",caja);
    printf("Descuento IESS (2.5%%): %11.2f\n",iess);
    printf("Impuesto renta (10%%):  %11.2f\n",renta);
    printf("Salario neto:           %10.2f\n",salario_neto);
    system("pause");
    return 0;
}
