/*Una tienda de electrónica necesita procesar las compras de sus clientes. Escriba un programa en C
que:
1. Reciba el nombre del cliente.
2. Permita registrar varios productos (máximo 10): nombre (puede tener espacios), precio
unitario y cantidad. Después de cada producto pregunta si desea agregar otro (S/N); solo acepta S o N (mayúscula o minúscula).
3. Valide que el precio y la cantidad sean positivos.
4. Muestre el subtotal de cada producto (precio × cantidad) al ingresarlo y acumule el total.
5. Aplique el descuento según el total: menos de 100, sin descuento; de 100 a menos de 500, 5 %; de 500 a 1000, 10 %; más de 1000, 15 %.
6. Calcule el total con descuento y el impuesto (13 % sobre el total con descuento).
7. Muestre una factura con el cliente, el detalle de cada producto (nombre, precio, cantidad y subtotal), la cantidad de productos, el subtotal, el descuento, el total con descuento, el impuesto y el total a pagar.
Requisitos en C
Guarde los productos en arreglos paralelos (nombres, precios y cantidades) para poder mostrar el detalle al final con un for. Use fgets para los nombres. Recuerde descartar el Enter pendiente
(getchar) antes de leer un nombre con fgets después de un scanf.
Al inicio del archivo escriba en comentarios el enunciado, qué se logra, cómo se logra y el resultado esperado, y comente el uso de cada variable y constante.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXIMO 10

int main(void) {
    //Arreglo para un guardar un maximo de 10 productos
    char articulos[MAXIMO][50];
    float precio[MAXIMO], subtotal[MAXIMO];
    int cantidad[MAXIMO];
    //Constantes para los calculos
    const float IMPUESTO=0.13;
    //Variables
    int i = 0,cantidad_articulos=0, parar=0;
    char articulo[50],nombre[50],salir[5];
    float  total_articulos=0, descuento=0,impuesto=0,total_pagar=0,total_con_descuento = 0;

    printf("=== Compra en la tienda ===\n");
    printf("Nombre del cliente: ");
    fgets(nombre, sizeof(nombre),stdin);
    printf("\n");
    nombre[strcspn(nombre, "\n")] = '\0';
    

    while (i < MAXIMO){
    parar = 0;

    printf("Producto %d\n", i+1);
    printf("Nombre: ");
    fgets(articulo, sizeof(articulo),stdin);
    articulo[strcspn(articulo, "\n")] = '\0';
    strcpy(articulos[i], articulo);
    do
    {
        printf("Precio unitario: ");
        scanf("%f",&precio[i]);
        if (precio[i] < 1)
        {
            printf("Precio invalido solo de 1 para arriba\n");
        }

    } while (precio[i] < 1);
        
    do
    {
        printf("Cantidad: ");
        scanf("%d",&cantidad[i]);
        if (cantidad[i] < 1)
        {
            printf("Cantidad invalido solo de 1 para arriba\n");
        }
    } while (cantidad[i] < 1);

    subtotal[i]= precio[i]*cantidad[i];
    total_articulos += subtotal[i];
    printf("Subtotal: %.2f\n", subtotal[i]);
    cantidad_articulos++;
    i++;


    while  (getchar() != '\n');
    if (i >= MAXIMO)
    {
        printf("Limite de articulos alcanzado (10)\n");
        break;
    }
    
    do
    {
        printf("Desea agregar otro producto? (S/N): \n");
        fgets(salir, sizeof(salir),stdin);
        salir[strcspn(salir, "\n")] = '\0';

        if (strcmp(salir , "S") == 0 || strcmp(salir , "s") == 0){
            parar = 1;
        }
        else if (strcmp(salir , "N") == 0 || strcmp(salir , "n") == 0)
        {
            parar = 2;
        }
        else{
            printf("Solo acepta S o N (mayúscula o minúscula)\n");
        }
        
    } while (parar == 0);

    if (parar == 2){break;}

    }

    if (total_articulos > 1000)
    {descuento = total_articulos * 0.15;}
    else if (total_articulos < 1000 && total_articulos >= 500)
    {descuento = total_articulos * 0.10;}
    else if (total_articulos < 500 && total_articulos >= 100)
    {descuento = total_articulos * 0.05;}
    else{descuento = 0;}

    impuesto = total_articulos * IMPUESTO;
    total_con_descuento = total_articulos - descuento;
    impuesto = total_con_descuento * IMPUESTO;
    total_pagar = total_con_descuento + impuesto;
    
    printf("================= FACTURA =================\n");
    printf("Cliente: %s\n",nombre);
    printf("Producto                Precio Cant Subtotal\n");
    for (i = 0; i < cantidad_articulos; i++)
    {
        printf("%-20s %10.2f %5d %10.2f\n",
        articulos[i], precio[i], cantidad[i], subtotal[i]);
    }
    //salida final
    printf("Productos registrados:      %d\n", cantidad_articulos);
    printf("Subtotal:                   %.2f\n", total_articulos);
    printf("Descuento:                  %.2f\n", descuento);
    printf("Total con descuento:        %.2f\n", total_con_descuento);
    printf("Impuesto (13%%):             %.2f\n",impuesto);
    printf("TOTAL A PAGAR:              %.2f\n", total_pagar);
    
    
    system("pause");
    return 0;

}

