#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Tarea{
    int TareaID;   //Numérico autoincremental comenzando en 1000
    char *Descripcion;
    int Duracion; // entre 10 – 100
}typedef Tarea;

struct Nodo{
    Tarea T;
    struct Nodo *Siguiente;
}typedef Nodo;

Nodo * crearLista();

int main()
{
    Nodo * TareasPendientes = crearLista();
    Nodo * TareasRealizadas = crearLista();
    int opcion=1;
    int id=1000;
    int duracion;
    char * buff;
    while (opcion!=0)
    {
        printf("Ingrese la descripcion de la tarea: ");
        buff = (char *)malloc(100 * sizeof(char));
        gets(buff);
        getchar();
        printf("Ingrese la duracion de la tarea: ");
        scanf("%d",&duracion);
        printf("Desea seguir ingresando tareas? presione 1 para si y 0 para no: ");
        scanf("%d",&opcion);
        Nodo * Ingresar = crearNodo(id,buff,duracion);
        id=id+1;
    }
    

}

Nodo * crearLista()
{
    return(NULL);
}

Nodo * crearNodo(int ID,char * Desc,int dur)
{
    Nodo * nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->T.TareaID=ID;
    strcpy(nuevo->T.Descripcion,Desc);
    nuevo->T.Duracion=dur;
    nuevo->Siguiente=NULL;
    return(nuevo);
}

void insertarNodo(Nodo ** start,Nodo * insertar)
{
    insertar->Siguiente=*start;
    *start=insertar;
}

/*Nodo * CrearNodo(int ID, char *Descrip, int Dur)
{
    Nodo * nuevo = (Nodo *) malloc (sizeof(Nodo));
    nuevo->T.TareaID=ID;
    nuevo->T.Descripcion=Descrip;
    nuevo->T.Duracion=Dur;
return nuevo;
}

Nodo * Insertar(Nodo *Lista,Nodo *Ingresar)
{
    Ingresar->Siguiente=Lista;
    Lista=Ingresar;
}



int main(){
    Nodo * ListaTareasPendientes = NULL;
    Nodo * ListaTareasRealizadas = NULL;

    int op = 1;
    int ID=1000;
    while(op != 0)
    {
        char *descripcion;
        int duracion;
        printf("Ingrese la descripcion de la tarea a realizar: ");
        gets(descripcion);
        printf("Ingrese la duracion de la tarea a realizar: ");
        scanf("%d",&duracion);





        puts("Ingrese 1 para añadir una nueva tarea, Ingrese 0 para dejar de ingresar");
        scanf("%d",&op);
        
    }
}*/


/*srand(time(NULL));
    Nodo * Lista = NULL;
    Nodo * nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->T.TareaID=50;
    //printf(nuevo->T.TareaID);
    printf("%d",nuevo->T.TareaID);
    char * buff = (char *)malloc(100*sizeof(char));
    printf("\ningrese la descripcion: ");
    gets(buff);
    nuevo->T.Descripcion = (char *)malloc(sizeof(char)*(strlen(buff)+1));
    strcpy(nuevo->T.Descripcion,buff);
    puts(nuevo->T.Descripcion);
    free(buff);
    nuevo->T.Duracion=10 + rand()%(100 - 10 + 1);
    printf("\nduracion: %d",nuevo->T.Duracion);
    Lista=nuevo;
    nuevo->Siguiente=NULL;*/