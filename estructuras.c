#include <stdio.h>
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

int main(){
    Nodo * ListaTareasPendientes = NULL;
    Nodo * ListaTareasRealizadas = NULL;
}