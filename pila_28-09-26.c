#include <stdio.h>
#include <stdlib.h>


struct Nodo{
  int valor;
  struct Nodo *sig;

};


void imprimir(struct Nodo *copia)
{
    struct Nodo *tmp;
    tmp = copia;
    if(copia==NULL)
    {
       printf("ERROR: Lista vacía.\n");
       return; 
    }
    while(tmp!=NULL)
    {
     printf("Valor de nodo: %d.\n", tmp->valor);
     tmp=tmp->sig;
    }  
}

int contar_nodos(struct Nodo *copia)
{
    struct Nodo *tmp;
    tmp = copia;
    int contador=0;
    if(copia==NULL)
    {
       printf("ERROR: Lista vacía.\n");
       return; 
    }
    while(tmp!=NULL)
    {
     contador++;
     tmp=tmp->sig;
    }  
    return contador;
}

struct Nodo *nuevonodo(int dato)
{
  struct Nodo *nodo = malloc(sizeof(struct Nodo));
  if (nodo == NULL)
    {
        printf("Error: no se pudo reservar memoria.\n");
        exit(1);
    }
  nodo->valor = dato;
  nodo->sig = NULL;
  return nodo;
}

struct Nodo *eliminar_nodo(struct Nodo *head)
{
    printf("Eliminando nodo.\n");
    struct Nodo *aux;
    aux = head;
    printf("Valor de nodo eliminado: %d.\n", head->valor);
    head=head->sig;
    free(aux);
    return head;
}

void eliminar_lista(struct Nodo *copia)
{
    printf("Eliminando la lista.\n");
    struct Nodo *tmp;
    tmp = copia;
    while(tmp!=NULL)
    {
     printf("Valor de nodo: %d.\n", tmp->valor);
     tmp=tmp->sig;
     free(copia);
     copia=tmp;
    }  
}

int main()
{
  
  int nro=0;
  printf("Ingrese nro: ");
  scanf("%d",&nro);
  struct Nodo *nodo1 = nuevonodo(nro);
  
  printf("Ingrese nro. 2: ");
  scanf("%d",&nro);
  struct Nodo *nodo2 = nuevonodo(nro);
  nodo2->sig=nodo1;
  
  //struct Nodo *nodo3 = malloc(sizeof(struct Nodo));
  printf("Ingrese nro. 3: ");
  scanf("%d",&nro);
  struct Nodo *nodo3 = nuevonodo(nro);
  nodo3->sig=nodo2;
  
  struct Nodo *aux;
  imprimir(nodo3);

  struct Nodo *head;
  head=eliminar_nodo(nodo3);
  imprimir(head);

  eliminar_lista(head);
  
 
   return 0;
}
