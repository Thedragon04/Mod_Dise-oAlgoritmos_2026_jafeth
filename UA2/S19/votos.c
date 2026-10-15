/*El grupo va a elegir a su representante entre tres candidatos: 1 Ana, 2 Luis y 3 Sofía. Cada estudiante pasa a la computadora y digita el número de su candidato. No se sabe cuántas personas votarán: la votación termina cuando alguien digita 0.

Cualquier otro numero es voto nulo. Al fina se muestra una barra de * con los votos del candidato*/

#include <stdio.h>  //printf y scanf
#define FIN 0       //se definen e inicializan constantes

int main(void){     //es la función principal
    int i,c,voto, ana=0, luis=0, sofia=0, nulo=0, mayor, empatados;
    int total = 0, cantidad;
    printf("====== Eleccion de representante ======\n");
    printf("1 Ana     2 Luis     3 Sofia    (0 cierra)\n\n");
    //LECTURAS PREVIAS
printf("voto: ");
scanf("%d", &voto);

//WHILE con centinela. Se repite mientras el voto no sea 0
while (voto != FIN){
    total++;

    switch (voto)
    {
    case 1:
        ana++;
        break;
    case 2:
        luis++;
        break;
    case 3:
        sofia++;
        break;
    case 0:
        printf("\nGracias por votar\n");
        break;

    default:
        nulo++;
        printf("\nVoto nulo\n");
        break;
    }



    printf("voto: ");
    scanf("%d", &voto);


}

printf("\nVotos recibidos: %d\n", total);

for (c = 1; i < 3; c++)
{
    switch (c)
    {
    case 1:
        printf("Ana  "); 
        cantidad = ana;
        break;
    case 2:
        printf("Luis  "); 
        cantidad = luis;
        break;
    default:
        printf("Sofia  "); 
        cantidad = sofia;
        break;
    }
    //interno
    for (i = 1; i <= cantidad; i++)
    {
        printf("*");
    }
    printf("(%d)\n",cantidad);
}
printf("Nulos:  (%d)\n", nulo);

//MAYOR de tres: el primer lugar
mayor = ana;
if (luis > mayor) mayor = luis;
if (sofia > mayor) mayor = sofia;
//empatados
empatados = 0;
if (ana == mayor) empatados++;
if (luis == mayor) empatados++;
if (sofia == mayor) empatados++;

//DESICION: solo se ejecuta el primer bloque que se cumpla
//DESICION: solo se ejecuta el primer bloque que se cumpla
if (mayor == 0)
printf("No hubo votos válidoso\n");
else if (empatados > 1)
printf("empate con %d votos: se repite la votacion\n",mayor);

else if (ana == mayor)
printf("Gana Ana con %d votos: se repite la votacion\n", mayor); //3votos

else if (luis == mayor)
printf("Gana Luis con %d votos: se repite la votacion\n", mayor);

else if (sofia == mayor)
printf("Gana Sofia con %d votos: se repite la votacion\n", mayor); //3votos



return 0;
}