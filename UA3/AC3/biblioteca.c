/*La biblioteca de un colegio necesita un sistema para controlar el préstamo de sus libros. Puede 
registrar hasta 5 libros. De cada libro se guarda: el código (100 a 999, no se repite), el título (una 
sola palabra, hasta 19 letras), los ejemplares disponibles y si el libro está activo o dado de baja. 
El programa inicia con 3 libros ya cargados (tabla de abajo). Debe mostrar un menú que se repite 
hasta elegir 0; toda opción o dato fuera de rango se vuelve a pedir. */
/*Que se logra: Hacer un algoritmo que pueda recibir y dar diversas cantidades de informacion y con base en un menu nosotros podamos canbiar a voluntad*/
/*Como se logra: Se logro utilizando arreglos, funciones, ciclos, etc. Y aplicando logica de algoritmos por ejemplo si necesito pedir un numero pero este esta en un rango entonces creo algo que solo admita lo que este en el*/
/*Resultado esperado: Un algoritmo que no tenga errores de logica, ni de escritura que los valores que se cambien vayan concordes con lo que se esta escribiemdo y viendo*/
#include <stdio.h>
#include <string.h>
//Constantes
#define MAX_LIBROS 5 
#define COD_MIN 100
#define COD_MAX 999
#define MAX_LETRAS 20 
#define EJEMPLARES 20

//prototipos
int leerEntero(const char mensaje[], int minimo, int maximo);
int buscarCodigo(const int cod[], const int activo[], int n, int codigo);
void incluir(int cod [], char nom[][MAX_LETRAS], int ejemplares[], int activo[], int *n,int codigo,const char nombre[],int cantidad);
void consultar(const int cod[], const char nom[][MAX_LETRAS],const int ejemplares[], const int activo[],int n);
int prestar(int *ejemplares);
void darDeBaja(int *activo);

int main(void){
//Arreglos
int cod[MAX_LIBROS] = {101,102,103};
int ejemplares[MAX_LIBROS] = {3,2,4};
char nom[MAX_LIBROS][MAX_LETRAS] = {"Quijote","Principito","Cocori"};
int activo[MAX_LIBROS] = {1,1,1};
//Variables
int opcion, n = 3, codigo, pos, cantidad;
char nombre[MAX_LETRAS];

//ciclo while que se detiene al poner opcion = 0
do
{
    printf("\nPrestamos de libros\n");
    printf("1. Incluir libro\n2. Consultar libros\n3. Prestar un ejemplar\n4. Dar de baja un libro\n5. Buscar libro\n0. Salir\n");
    opcion = leerEntero("Opcion",0,5);//Llama a la funcion pasando su rango
    if (opcion >= 3)// Si la opcion es 3 o mayor esto es para el case 3 al 5
    {
        codigo = leerEntero("Codigo",COD_MIN,COD_MAX);
        pos = buscarCodigo(cod, activo, n, codigo);
        if (pos == -1)
        {
            printf("No existe un libro activo con el codigo %d\n",codigo);
            continue;
        }
        
    }
    //Para que el usuario pueda decidir que hacer
    switch (opcion)
    {
    case 1:
        //Si n llega a 5 ya no se podran incljuir mas libros
        if (n == MAX_LIBROS)
        {
            printf("Cantidad maxima alcanzada\n");
            break;
        }
        //Lee codigo
        codigo = leerEntero("Codigo",COD_MIN,COD_MAX);
        //Si el codigo ya existe imprime esto
        if (buscarCodigo(cod, activo, n, codigo) != -1)
        {
            printf("El codigo %d ya existe\n",codigo);
            break;
        }
        //Pide el nombre del libro
        printf("Nombre del libro ");
        scanf("%s",nombre);
        cantidad = leerEntero("Cantidad ",1,EJEMPLARES);//lee la cantidad de ejemplares
        incluir(cod,nom,ejemplares,activo,&n,codigo,nombre,cantidad);//Llama a la funcion que los incluye
        printf("Ejemplar incluido %d de %d\n",n,MAX_LIBROS);

        break;
    case 2:
        //Llama a una funcion que solo imprime
        consultar(cod,nom,ejemplares,activo,n);
        break;
    case 3:
        //pongo a prestar como condicion para que lea el codigo en especifico he imprima uno de los dos mensajes con un puntero para que vaya al codigo exacto que se escriba
        if (prestar(&ejemplares[pos]))
        {
            printf("Disponibles %d\n",ejemplares[pos]);
        }
        else{
            printf("No hay ejemplares disponibles\n");
        }
        break;
    case 4:
        //LLamo a dar de baja para quitar el libro con el codigo digitado
        darDeBaja(&activo[pos]);
        printf("Libro %s dado de baja\n",nom[pos]);
        break;
    case 5:
        //imprime solo la informacion que se le pide al codigo en especifico
        printf("%d %s: %d disponibles\n",cod[pos],nom[pos],ejemplares[pos]);
        break;
    default:
        break;
    }

} while (opcion != 0);
}

int leerEntero(const char mensaje[], int minimo, int maximo){
    int valor;
    do
    {
        printf("%s (%d a %d): ",mensaje,minimo,maximo);//Limite
        scanf("%d",&valor);
    } while (valor < minimo || valor > maximo);//Sale si los dos son falsos
    return valor;
}

int buscarCodigo(const int cod[], const int activo[], int n, int codigo){
    int i;
    for (i = 0; i < n; i++)
    {
        if (cod[i] == codigo && activo[i] == 1)//Ve si el codigo existe y si esta activo
        {
            return i;//devuelve un i
        }
    }
    return -1;
}

void incluir(int cod [], char nom[][MAX_LETRAS], int ejemplares[], int activo[], int *n,int codigo,const char nombre[],int cantidad){
    cod[*n] = codigo;//Pone el codigo en posicion n
    strcpy(nom[*n],nombre);//Copia el nombre en posicion n
    ejemplares[*n] = cantidad;//Copia la cantidad en posicion n
    activo[*n] = 1;//Activa en posicion n
    (*n)++;//Suma en posicion n
}
void consultar(const int cod[], const char nom[][MAX_LETRAS],const int ejemplares[], const int activo[],int n){
    int i, activos = 0;

    printf("\n%-6s %-12s %18s\n", "Codigo", "Nombre", "Ejemplares disponibles");
    for (i = 0; i < n; i++)
    {
        if (activo[i] == 1)//Si esta activo imprime
        {
            printf("%-6d %-12s %18d\n",cod[i],nom[i],ejemplares[i]);
            activos ++;//Suma a activos
        }
    }
    printf("Libros activos %d\n",activos);
}

int prestar(int *ejemplares){
    if (*ejemplares == 0)//Si no hay ejemplares devuelve 0
    {
        return 0;
    }
    else{
        (*ejemplares)--;//sino resta uno al puntero y devulve 1
        return 1;
    }
    
}
void darDeBaja(int *activo){
    *activo = 0;//Elimina el libro
}