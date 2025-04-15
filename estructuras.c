#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Tarea{
    int TareaID;//Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion; // entre 10 – 100
}typedef Tarea;

struct Nodo{
    Tarea T;
    Nodo *Siguiente;
}typedef Nodo;

Nodo * CrearNodo(int ID, char *Descrip, int Dur)
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
}