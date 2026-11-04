//Cargar las bibliotecas
#include <stdio.h>
#include <string.h>

//Definir las constantes
#define MAX_PASES 5       //espacios para los pases disponibles
#define TAM_NOMBRE 20     //19 caracteres o letras + el \0
#define COD_MIN 100       //codigo minimo
#define COD_MAX 999
#define VIAJES_MAX 40     //viajes maximos a incluir

//Prototipos (una funcion por tarea)
int leerentero(const char mensaje[], int minimo, int maximo);
int buscarCodigo(const int cod[], const int activo[], int n, int codigo);
void incluir(int cod[], char nom[][TAM_NOMBRE], int viajes[], int activo[], int *n,int codigo, const char mombre[], int cantidad);
void consultar(const int cod[], const char nom[][TAM_NOMBRE], const int viajes[], const int activo[], int n);
int usarViaje(int *viajes);
void darDeBaja(int *activo);

//Funcion principal
int main(void){
    //Asigne datos de los pases
    int cod[MAX_PASES] = {201,202,203};
    char nom[MAX_PASES][TAM_NOMBRE] = {"Ana","Luis","Sofia"};
    int viajes[MAX_PASES] = {5,1,8};
    int activo[MAX_PASES] = {1,1,1};
    int n = 3;//Espacios usados
    int opcion, codigo, pos, cantidad;
    char nombre[TAM_NOMBRE];

    //ciclo para el menu
    do
    {
        //mostrar el menu
        printf("\n=== Pases de bus ===\n");
        printf("1. Incluir 2. Consultar 3. Registrar viaje 4. Dar de baja\n");
        printf("5. Buscar 0. Salir\n");

        opcion = leerentero("Opcion",0,5); //no aceptar opciones inexistentes
        if (opcion >= 3 )
        {
            codigo = leerentero("Codigo",COD_MIN, COD_MAX);
            pos = buscarCodigo(cod, activo, n, codigo);
            //revisa si existe
            if (pos == -1)
            {
                //aviso
                printf("No existe un pase activo con el codigo %d\n",codigo);
                //para continuar
                continue;
            }
            
        }
        switch (opcion)
        {
        case 1:
            if (n == MAX_PASES)
            {
                printf("No hay espacio para mas");
                break;
            }
            //lee ccodigo con entero
            codigo = leerentero("Codigo",COD_MIN,COD_MAX);
            //revisar si el codigo
            if (buscarCodigo(cod,activo,n,codigo) != -1)
            {
                break;
            }
            //pide nombre
            printf("Nombre (una palabra): ");
            //leer nombre
            scanf("%19s",nombre);
            //leer los viajes
            cantidad = leerentero("Viajes", 1, VIAJES_MAX);
            //guardar el pase que viene por direccion
            incluir(cod,nom,viajes,activo,&n,codigo, nombre, cantidad);
            //conformar pase incluido
            printf("Pase incluido (%d de %d)\n", n, MAX_PASES);
            break;
        case 2:
            consultar(cod, nom, viajes, activo, n);
            break;
        case 3:
            //inetnta registrar viaje
            if (usarViaje(&viajes[pos]))
                printf("Viaje registrado. A %s le quedan %d\n", nom[pos], viajes[pos]);
            //no quedan vieajes
            else
                printf("%s no tiene viajes disponibles\n", nom[pos]);
            break;
        case 4:
            darDeBaja(&activo[pos]);
            printf("Pase de %s dado de baja\n", nom[pos]);
            break;

        case 5:
            //buscar un pase
            printf("%d %s: %d viajes\n", cod[pos], nom[pos], viajes[pos]);
            break;
        default:
            printf("Hasta luego\n");
        }
        
    } while (opcion != 0);
    return 0;

}

int leerentero(const char mensaje[], int minimo, int maximo){
    //dato leido
    int valor;
    //ciclo validacion para que pida el dato al menos una vez
    do
    {
        printf("%s (%d a %d): ", mensaje, minimo, maximo);
        //leer

        scanf("%d",&valor);
    } while (valor < minimo || valor > maximo);
    return valor;
}

//Busqueda secuencial de un pase
int bucarCodigo(const int cod[], const int activo[], int n, int codigo){
    int i;
    for (i = 0; i < n; i++)
    //ignora pase dados de baja
    if (cod[i] == codigo && activo[i] == 1){
        return i;
        }
    //no esta activo
    return -1;
}

//Agregar espacio en el primer espacio libre
void incluir(int cod[], char nom[][TAM_NOMBRE], int viajes[], int activo[], int *n, int codigo, const char nombre[], int cantidad){
    //guardar el codigo
    cod[*n] = codigo;
    //guardar el nombre
    strcpy(nom[*n], nombre);
    //guardar los viajes
    viajes[*n] = cantidad;
    //pase activo
    activo[*n] = 1;
    //proximo pase a posicion siguiente
    (*n)++;
}

//pases activos y suantos son
void consultar(const int cod[], const char nom[][TAM_NOMBRE], const int viajes[], const int activo[], int n){
    //indice del contador
    int i, activos = 0;

    //encabezado de la tabla
    printf("%-6s %-12s %6s\n", "Codigo", "Nombre", "Viajes disponibles");
    //recorrer los espacios usados
    for (i = 0; i < n; i++){
        //solo activos
        if (activo[i] == 1){
            printf("%-6d %-12s %6d\n", cod[i],nom[i], viajes[i]);
            //cuenta pases
            activos++;
        }
    }
    printf("Pases activos: %d\n", activos);
}

//registrar viajes si quedan 
int usarViaje(int *viajes){
    //revisa si quedan viajes
    if (*viajes == 0)
    //no registra
    return 0;
    //cambio en el arreglo
    (*viajes)--;
    return 1; //para confirmar desde main
}

//dar de baja
void darDeBaja(int *activo){
    //se marca como inactivo
    *activo = 0;
}