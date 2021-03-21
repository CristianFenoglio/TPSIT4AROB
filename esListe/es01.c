#include <stdio.h>
#include <stdlib.h>
struct El
{
    int valore;
    struct El *next;
};


struct El* push(struct El* lista, int n){
    if (lista == NULL) /* se la lista è vuota */
    {
        /* alloca il primo elelmento e mette l come puntatore a questa */

        lista = (struct El *)malloc(sizeof(struct El));
        lista->valore=n;
        lista->next=NULL;
        
        
    }
    else /* se la lista esiste già */
    {
        /* creo un nuovo elemento della lista incatenandolo a quello precedente e sposto il puntatore su di esso */
        struct El* l=lista;
        
        while(l->next!=NULL){
            l=l->next;
        }
        l->next = (struct El *)malloc(sizeof(struct El));
        l->next->valore = n;  /* assegno al valore il numero in input */
        l->next->next = NULL; /* scrivo che quell elemento ora è l'ultimo elemento */

    }
    return lista;
}

/*
void stampa(struct El*lista){   
    struct El*k=lista;
    while(k!=NULL){
        printf("%d - %p \n",k->valore, k->next);
        k=k->next;
    }
}*/
void stampa(struct El*lista){ 
    if(lista!=NULL){
      printf("\n %d  ",lista->valore);
      stampa(lista->next);  
    }
}


void deallocaLista(struct El*lista){
    struct El* l;
    while(lista!=NULL){
        l=lista;
        lista=lista->next;
        free(l);
    }
}

void delallocaListaRico(struct El*lista){
    if(lista!=NULL){
        delallocaListaRico(lista->next);
        free(lista);
    }
}





/*Definire una funzione ordinaLista che modifica una ListaDiElementi data ordinandola in modo crescente. La
funzione non deve usare allocazione dinamica della memoria (malloc e free), né modificare il campo info
degli elementi.
La funzione restituisce il puntatore al primo elemento ottenuto dopo l’ordinamento.*/

struct El* ordinaLista(struct El*lista){//Non Va.................
    struct El*sost;
    struct El*l=lista;
    struct El*gira;
    struct El* scorr;
    while(l->next!=NULL){
        scorr=l;
        while(scorr->next!=NULL){
            if(l->valore>l->next->valore){///////2 5 1 3--> 2 l sost 3--> gira L sost  3
                sost=l->next;
                gira=lista;
                while(gira->next!=l){
                    gira=gira->next;
                }
                gira->next=sost;
                l->next=sost->next;
                sost->next=l;  
            }
            scorr=scorr->next;
        }
        l=l->next;
    }
    return lista;
}



struct El*merge(struct El*lista1, struct El*lista2){//1-4-8-456-123-134
    struct El* lista=lista1;
    while(lista->next!=NULL){
        lista=lista->next;
    }
    lista->next=lista2;
    lista=ordinaLista(lista);
}





int main(){
    int n;
    struct El *lista;
    lista = NULL; /* inizializzo la lista a null  */
    do
    {
        printf("Inserisci un naturale o -1 per terminare\n");
        scanf("%d", &n);
        if(n>=0){
            lista=push(lista, n);
        }
    } while (n >= 0);
    printf("numeri inseriti: ");
    stampa(lista);    
    lista=ordinaLista(lista);
    stampa(lista);
    return 0;
}
