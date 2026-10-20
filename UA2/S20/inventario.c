#include <stdio.h>
#include <string.h>

#define PRODUCTOS 5

int main(void){
    // Arreglos
    int codigos[PRODUCTOS] = {101, 205, 310, 412, 518};
    char descripciones[PRODUCTOS][20] ={"Arroz 2 kg", 
    "Frijoles 1 kg", "Cafe 1 kg","Azucar 2 kg", "Aceite 1 L"};
    int existencias[PRODUCTOS]={20, 15, 12, 30, 8};
    int precio[PRODUCTOS] = {2400, 1800, 4500, 2100, 3200};
    //Variables
    float total;
    int b, p, opcion, existe = -1;
    
    printf("Codigo (0 para terminar):");
    scanf ("%d", &opcion);
    b = opcion;
    while (opcion != 0)
    {
        for (b = 0; b < PRODUCTOS; b++)
        {
            
        }
        
    }
    

}