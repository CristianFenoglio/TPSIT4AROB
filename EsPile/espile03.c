/*
Creare un programma che dato un numero intero, avente un numero arbitrario di cifre inserite
dall’utente, lo scriva in output con le cifre in ordine inverso. Utilizzare una pila e le implementazioni
dei metodi push e pop.
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int valore;
    struct nodo* next;
}Nodo;

int is_empty(Nodo* head){
    
    if (head == NULL){
        return 1;
    }else{
        return 0;
    }
}

void push(Nodo **head, Nodo *element){

    if (is_empty(*head)){           //if (is_empty(*head) == NULL)
        *head = element;
        element->next = NULL;
    }else{
        element->next = *head;
        *head = element;
    }
}

Nodo* pop(Nodo **head){
    Nodo* ret = *head;
    if (is_empty(*head)){
        return NULL;
    }else{
        *head = ret->next;
    }
    return ret;
}


void es1(){
    Nodo* pila;
    printf("inserire numero di cifre :");
    int nvolte=0;
    do{
        scanf("%d", &nvolte);
    }while(nvolte<0);
    int n=0;
    int cifra=0;
    printf("\ninserire il numero: ");
    scanf("%d", &n);
    Nodo *p;
    for(int x=0; x<nvolte; x++){
        cifra=n%10;
        p=(Nodo*) malloc(sizeof(Nodo));
        p->valore=cifra;
        p->next=NULL;
        push(&pila, p);
        n=n/10;
    }
    int nInv=0;

    for(int y=0; y<nvolte; y++){
        Nodo* contr=pop(&pila);
        nInv=nInv+(contr->valore)*pow(10,y);
        free(contr);  
    }
    printf("%d", nInv);
}


int main(){
    es1();
}