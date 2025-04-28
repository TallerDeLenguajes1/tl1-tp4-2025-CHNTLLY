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
Nodo * crearNodo(int ID,char * Desc,int dur);
void insertarNodo(Nodo ** start,Nodo * insertar);
void mostrarLista(Nodo * Lista);
Nodo * buscarNodo(Nodo * Lista,int buscado);
Nodo * QuitarNodo(Nodo ** Start, int IDquitar);
void liberarNodo(Nodo * eliminado);
void buscarTareaID(Nodo * Lista1,Nodo * Lista2,int ID);
void buscarTareaPalabraCLave(Nodo * Lista1,Nodo * Lista2,char * buscar);

int main()
{
    Nodo * TareasPendientes = crearLista();
    Nodo * TareasRealizadas = crearLista();
    int idTarea=1000;
    int duracion;
    int opcion=0;
    int IDtransferir;
    int IDbuscar;
    printf("Desea ingresar una tarea pendiente? Presione 1(uno) para si o 0(cero) para no: ");
    scanf("%d",&opcion);
    getchar();
    while(opcion!=0)
    {
        char * buff =(char *)malloc(sizeof(char)*300); //puntero auxiliar para guardar la descripcion
        printf("\nIngrese la descripcion de la tarea: ");
        gets(buff); //guardo la terea en mi puntero auxiliar
        char * descripcionTarea=(char*)malloc(sizeof(char)*strlen(buff)+1); //puntero final para guardar la descripcion
        strcpy(descripcionTarea,buff); //guardo la descripcion
        free(buff); //libero la memoria del auxiliar
        //puts(descripcionTarea);


        printf("\nIngrese la duracion (en minutos) de la tarea, debe ser entre 10 y 100: ");
        scanf("%d",&duracion);
        while (duracion<10 || duracion>100)
        {
            printf("\nDuracion invalida, ingrese la duracion nuevamente, debe ser entre 10 y 100:");
            scanf("%d",&duracion);
        }
        //printf("\n%d",duracion);


        Nodo * nuevo = crearNodo(idTarea,descripcionTarea,duracion);
        idTarea=idTarea+1; //ID de la tarea es un numero incremental 

        insertarNodo(&TareasPendientes,nuevo);

        printf("Desea ingresar otra tarea pendiente?\nPresione 1(uno) para seguir, 0(cero) para parar:");
        scanf("%d",&opcion);
        getchar();
    }

    mostrarLista(TareasPendientes);

    opcion=0;
    printf("Desea transferir una Tarea Pendiente a Tarea Realizada?\nPresione 1(uno) para si y 0(cero para no): ");
    scanf("%d",&opcion);
    while(opcion!=0)
    {
        printf("\nIngrese el ID de la tarea a transferir: ");
        scanf("%d",&IDtransferir);
        Nodo * Buscado = buscarNodo(TareasPendientes,IDtransferir);
        if(Buscado == NULL)
        {
            printf("No se encontro ninguna Tarea con ese ID\n");
        }
        else
        {
            Nodo * Copia = crearNodo(Buscado->T.TareaID, Buscado->T.Descripcion, Buscado->T.Duracion);
            insertarNodo(&TareasRealizadas, Copia);
            Nodo * Borrar = QuitarNodo(&TareasPendientes, IDtransferir);
            liberarNodo(Borrar);
        }
        printf("Desea transferir otra tarea Pendiante a Realizadas?\nPresione 1(uno) para si y 0(cero para no):");
        scanf("%d",&opcion);
        getchar();
    }

    mostrarLista(TareasPendientes);

    mostrarLista(TareasRealizadas);
    opcion=0;
    printf("Desea buscar una tarea por ID o por palabra clave?\nPresiona 1 para buscar por ID\nPresione 2 para buscar por papalbra clave\npresione 0 para salir");
    scanf("%d",&opcion);
    getchar();
    while(opcion!=0)
    {
        if(opcion==1)
        {
            printf("Ingrese el ID a buscar: ");
            scanf("%d",&IDbuscar);
            buscarTareaID(TareasPendientes,TareasRealizadas,IDbuscar);
        }
        else if(opcion==2)
        {
            char * buscar = (char *)malloc(sizeof(char)*300);
            printf("Ingrese la palabra calve a buscar: ");
            gets(buscar);
            buscarTareaPalabraCLave(TareasPendientes,TareasRealizadas,buscar);
            free(buscar);
        }
        printf("Desea buscar otra tarea por ID o por palabra clave?\nPresiona 1 para buscar por ID\nPresione 2 para buscar por papalbra clave\npresione 0 para salir");
        scanf("%d",&opcion);
        getchar();
    }
    
    return(0);
}

Nodo * crearLista()
{
    return(NULL);
};

Nodo * crearNodo(int ID,char * Desc,int dur)
{
    Nodo * nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->T.TareaID=ID;
    nuevo->T.Duracion=dur;
    nuevo->T.Descripcion=(char *)malloc(sizeof(char)*strlen(Desc)+1);
    strcpy(nuevo->T.Descripcion,Desc);
    nuevo->Siguiente=NULL;
    return(nuevo);
};


void insertarNodo(Nodo ** start,Nodo * insertar)
{
    insertar->Siguiente = *start;
    *start = insertar;
};

void mostrarLista(Nodo * Lista)
{
    Nodo * aux=Lista;
    while (aux!=NULL)
    {
        printf("\n");
        puts(aux->T.Descripcion);
        printf("%d",aux->T.TareaID);
        printf("\n%d",aux->T.Duracion);
        aux=aux->Siguiente;
        printf("\n");
    }
}

Nodo * buscarNodo(Nodo * Lista,int buscado)
{
    Nodo * aux = Lista;
    while(aux && aux->T.TareaID != buscado)
    {
        aux=aux->Siguiente;
    }
    return(aux);
}

Nodo * QuitarNodo(Nodo ** Start, int IDquitar)
{
    Nodo * aux = (*Start);
    Nodo * ant = NULL;
    while(aux != NULL && aux->T.TareaID != IDquitar)
    {
        ant=aux;
        aux=aux->Siguiente;

    }
    if(aux!=NULL)
    {   
        if(aux == (*Start))
        {
            (*Start) = aux->Siguiente;
        }
        else
        {
            ant->Siguiente = aux->Siguiente;
        }
        aux->Siguiente=NULL;
    }
    return(aux);
}

void liberarNodo(Nodo * eliminado)
{
    if(eliminado != NULL)
    {
        free(eliminado->T.Descripcion);
        free(eliminado);
    }
}

void buscarTareaID(Nodo * Lista1,Nodo * Lista2,int ID)
{
    
    if(buscarNodo(Lista1,ID))
    {
        Nodo * buscado = buscarNodo(Lista1,ID);
        printf("TAREA PENDIENTE\n");
        printf("Duracion: %d",buscado->T.Duracion);
        printf("Descripcion: ");
        puts(buscado->T.Descripcion);
        printf("ID: %d\n",buscado->T.TareaID);
    }
    else if(buscarNodo(Lista2,ID))
    {
        Nodo * buscado = buscarNodo(Lista2,ID);
        printf("TAREA REALIZADA\n");
        printf("Duracion: %d",buscado->T.Duracion);
        printf("Descripcion: ");
        puts(buscado->T.Descripcion);
        printf("ID: %d\n",buscado->T.TareaID);
    }
    else
    {
        printf("No se encontro ninguna tarea con el id buscado");
    }
}

void buscarTareaPalabraCLave(Nodo * Lista1,Nodo * Lista2,char * buscar)
{
    Nodo *aux=Lista1;
    char * estado;
    if(aux==NULL)
    {
        estado==NULL;
    }
    else
    {
        estado=strstr(aux->T.Descripcion,buscar);
    }
    while (aux != NULL && estado == NULL)
    {
        aux=aux->Siguiente;
    }
    if(aux==NULL)
    {
        aux=Lista2;
        estado=strstr(aux->T.Descripcion,buscar);
        while (aux != NULL && estado==NULL)
        {
            aux=aux->Siguiente;
        }
        if(aux!=NULL)
        {
            printf("TAREA REALIZADA\n");
            printf("Duracion: %d",Lista2->T.Duracion);
            printf("Descripcion: ");
            puts(Lista2->T.Descripcion);
            printf("ID: %d\n",Lista2->T.TareaID);
        }   
        if(aux==NULL)
        {
            printf("No se encontro ninguna tarea que concuerde con esa palabra clave");
        }
    }
    else
    {
        printf("TAREA PENDIENTE\n");
        printf("Duracion: %d",Lista1->T.Duracion);
        printf("Descripcion: ");
        puts(Lista1->T.Descripcion);
        printf("ID: %d\n",Lista1->T.TareaID);
    }
}