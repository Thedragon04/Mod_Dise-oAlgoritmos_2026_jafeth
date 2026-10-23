#include <stdio.h>
#include <string.h>
#include <stdbool.h> 

#define INTENTOS_MAX 3
#define MIN_LONG_USUARIO 4
#define CONTRASEÑA 50

int main() {
    char usuario[CONTRASEÑA];
    char clave[CONTRASEÑA];
    
    // Credenciales correctas
    const char usuarioCorrecto[] = "admin";
    const char claveCorrecto[] = "Ina2026";
    
    int intentos = 0;
    bool accesoConcedido = false;

    do {
        intentos++;

        printf("Usuario:\n> ");
        if (fgets(usuario, sizeof(usuario), stdin) != NULL) {
            usuario[strcspn(usuario, "\n")] = '\0';
        }

        if (strlen(usuario) < MIN_LONG_USUARIO) {
            printf("muy corto\n");
            continue; 
        }


        printf("Clave:\n> ");
        if (fgets(clave, sizeof(clave), stdin) != NULL) {
            clave[strcspn(clave, "\n")] = '\0';
        }


        bool usuarioOk = (strcmp(usuario, usuarioCorrecto) == 0);
        bool claveOk = (strcmp(clave, claveCorrecto) == 0);


        if (usuarioOk && claveOk) {
            accesoConcedido = true;
            printf("Bienvenido al sistema, %s\n", usuario);
        } else {
            printf("incorrectos (intento %d de %d)\n", intentos, INTENTOS_MAX);
        }

    } while (!accesoConcedido && intentos < INTENTOS_MAX);

    return 0;
}