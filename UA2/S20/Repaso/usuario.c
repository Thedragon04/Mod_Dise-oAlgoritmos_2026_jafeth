/*Una plataforma educativa crea las cuentas de sus estudiantes. Escriba un programa en C que:
1. Pida el nombre completo (con espacios; no se acepta vacío).
2. Arme el nombre de usuario con la primera letra del nombre seguida del primer apellido (la
palabra después del primer espacio): Ana Rojas Mena → ARojas. Si el nombre tiene una sola
palabra, el usuario es esa palabra.
3. Pida una contraseña y su confirmación (una palabra cada una) y repita hasta que tenga al
menos 8 caracteres y las dos coincidan; muestre un mensaje distinto para cada error.
4. Muestre el usuario con su cantidad de caracteres y el mensaje Cuenta creada para …
armado en una cadena con strcpy y strcat.*/

#include <stdio.h>
#include <string.h>

int main(void){
    //Variables
    char nombre[50], apellido[25], usuario[30],letra[2];
    char clave1[20] , clave2[20];
    //Estas estan para condiciones del while
    int noVacio = 0, coinciden = 0;
    //Contadores
    int i = 0, j = 0, caracteres = 0; 

    printf("=== Crear cuenta de usuario ===\n");

    //Hasta que noVacio sea diferente de 0 se repite
    while (noVacio == 0)
    {
        printf("Nombre completo: ");
        fgets(nombre, sizeof(nombre),stdin);
        nombre[strcspn(nombre, "\n")] = '\0';

        if (strlen(nombre) == 0)
        {
            printf("El nombre no puede ser vacio\n");
        }
        else{
            for (i = 0; i < 1; i++)
            {
                letra[i] = nombre[i];
            }
            noVacio = 1;
        }
    }

    i = 0;// Reinicio por si acaso

    //while para ver donde esta el espacio
    while (nombre[i] != '\0' && nombre[i] != ' ')
    {
        i++;
    }
    if (nombre[i] == ' ')//Cuando encuentra el espacio
    {
        i++;

        while (nombre[i] != '\0' && nombre[i] != ' ')//Busca que hasta encontrar el fin o otro espacio
        {
            apellido[j] = nombre[i];//copia caracter por caracter
            i++;
            j++;
        }
    }
    apellido[j] = '\0';//cierro con \0
    caracteres = strlen(letra) + strlen(apellido);
    strcpy(usuario, letra);
    strcat(usuario, apellido);

    while (coinciden== 0)
    {
        printf("Contrasena (minimo 8 caracteres): ");
        fgets(clave1, sizeof(clave1),stdin);
        clave1[strcspn(clave1, "\n")] = '\0';

        if (strlen(clave1) <= 8)
        {
            printf("Muy corta: debe tener al menos 8 caracteres \n");
        }
        else{
            printf("Confirme la contrasena: ");
            fgets(clave2, sizeof(clave2),stdin);
            clave2[strcspn(clave2, "\n")] = '\0';

            if (strcmp(clave1,clave2) != 0)
            {
                    printf("Las contrasenas no coinciden \n");
            }
            else{
                coinciden = 1;
                }
            
        }
    }

    printf("Usuario:: %s (%d caracteres)\n",usuario,caracteres);
    printf("Cuenta creada para %s",nombre);

    return 0;

}