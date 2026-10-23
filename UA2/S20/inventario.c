#include <stdio.h>
#include <string.h>

#define PRODUCTOS 5

int main(void){
    // Arreglos
    char codigos[PRODUCTOS][5] = {"101", "205", "310", "412", "518"};
    char descripciones[PRODUCTOS][20] ={"Arroz 2 kg", 
    "Frijoles 1 kg", "Cafe 1 kg","Azucar 2 kg", "Aceite 1 L"};
    int existencias[PRODUCTOS]={20, 15, 12, 30, 8};
    float precio[PRODUCTOS] = {2400, 1800, 4500, 2100, 3200};
    //Variables
    char buscada[5];
    float total;
    int b, opcion, existe = -1,encontrada;
    

    printf("\nCodigo (0 para terminar): ");
    fgets(buscada, sizeof(buscada), stdin);
    buscada[strcspn(buscada, "\n")] = '\0'; 
    
    while (strcmp(buscada, "0") != 0)
    {
    

        encontrada = -1;                       
        for (b = 0; b < PRODUCTOS; b++) {
            
            if (strcmp(buscada, codigos[b]) == 0) 
                encontrada = b;           
        }

        

    if (encontrada >= 0){
        printf("%s %d unidades a %.2f\n", descripciones[encontrada], existencias[encontrada], precio[encontrada]);
    }
    else{
        printf("Codigo %s no encontrado\n", buscada);
    }
    printf("\nCodigo (0 para terminar): ");
        fgets(buscada, sizeof(buscada), stdin);
        buscada[strcspn(buscada, "\n")] = '\0'; 
    }

    for (b = 0; b < PRODUCTOS; b++)
    {
        total += existencias[b] * precio[b];
    }
    printf("Valor del inventario: %.2f", total);


    return 0;

}