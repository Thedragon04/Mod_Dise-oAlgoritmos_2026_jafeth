#include <stdio.h>
#include <ctype.h>

int esVocal(int c);

int esVocal(int c){
    char vocal = tolower(c);
    return (vocal == 'a' || vocal == 'e' || vocal == 'u' || vocal == 'i' || vocal == 'o');
}

int main(void){
    int c, vocal=0, consonante=0, digito=0;

    printf("Frase:");

    while ((c = getchar()) != '\n')
    {
        putchar(toupper(c));

        if (esVocal(c))
        {
            vocal++;
        }
        else if (isalpha(c))
        {
            consonante++;
        }
        else if (isdigit(c))
        {
            digito++;
        }
    }
    printf("\n");

    printf("Vocales: %d Consonantes %d Digitos %d", vocal, consonante, digito);
}