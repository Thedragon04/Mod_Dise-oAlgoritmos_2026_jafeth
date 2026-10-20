#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXIMO 10

int main(void) {
    char titulos[MAXIMO][50];
    float precio[MAXIMO], subtotal[MAXIMO];
    int cantidad[MAXIMO];

    const float DESCUENTO=0.1,IMPUESTO=0.13;
    int i = 0,unidades_t=0,cantidad_libros=0;
    char titulo_libro[50];
    float  total_libros=0, descuento=0,impuesto=0,envio=0,total_pagar=0;


    printf("=== Pedido de la libreria ===\n");
    printf("Titulo del libro (FIN para terminar): ");
    fgets(titulo_libro, sizeof(titulo_libro),stdin);
    titulo_libro[strcspn(titulo_libro, "\n")] = '\0';

    while (strcmp(titulo_libro , "FIN") != 0 && strcmp(titulo_libro , "fin") != 0 && i < MAXIMO)
    {

        strcpy(titulos[i], titulo_libro);
        do{
            printf("Precio: ");
            scanf("%f", &precio[i]);
            if (precio[i] < 0)
            {
                printf("Precio invalido de 1 para arriba\n");
            }
            
        } while (precio[i] < 0);

        do
        {
            printf("Cantidad: ");
            scanf(" %d", &cantidad[i]);
            if (cantidad[i] < 0)
            {
                printf("Cantidad invalida de 1 para arriba\n");
            }
            
        } while (cantidad[i] < 0);

        subtotal[i] = cantidad[i] * precio[i]; 
        unidades_t += cantidad[i];
        total_libros += subtotal[i];

        i++;
        cantidad_libros++;

        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        printf("Titulo del libro (FIN para terminar): ");
        fgets(titulo_libro, sizeof(titulo_libro),stdin);
        titulo_libro[strcspn(titulo_libro, "\n")] = '\0';


    }

    if (unidades_t >= 5)
    {descuento = total_libros * DESCUENTO;}

    if(total_libros < 50)
    {envio = 8;}
    else if (total_libros < 150)
    {envio = 4;}
    else{envio = 0;}
    
    impuesto = (total_libros - descuento) * IMPUESTO;
    total_pagar = total_libros - descuento + impuesto + envio;
    

    printf("\nTitulo                    Precio Cant   Subtotal\n");
    for (i = 0; i < cantidad_libros; i++)
    {
        printf("%-20s %10.2f %5d %10.2f\n",
        titulos[i], precio[i], cantidad[i], subtotal[i]);
    }

    printf("Unidades:             %d\n", unidades_t);
    printf("Total de libros:      %.2f\n", total_libros);
    printf("Descuento:            %.2f\n", descuento);
    printf("Impuesto (13%%):       %.2f\n",impuesto);
    printf("Envio:                %.2f\n", envio);
    printf("TOTAL A PAGAR:        %.2f\n", total_pagar);

}