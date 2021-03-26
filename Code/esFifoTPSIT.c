//esFifoTPSIT
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

void enqueue( Nodo **head,  Nodo **tail,  Nodo* element){
    if(is_empty(*head))
        *head=element;
    else
    {
        *(tail)->next=element;
    }
    *tail=element;
    element->next=NULL;
}


struct Nodo*  dequeue(Nodo **head, Nodo **tail){
    struct Nodo* ret = *(head);
    if(is_empty(*head)){
        return NULL;
    }else{
        *head = ret->next;
    }

    if(*head == NULL){
        *tail = NULL;
    }

    return ret;
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

void printCoda( Nodo *head, Nodo *tail){
    Nodo* number;
    while(!is_empty(head)){
        number = dequeue(&head, &tail);
        printf("%d ", number->valore);
    }

}

void es1(){
    Nodo* pila;
    Nodo* head = NULL;
    Nodo* tail = NULL;
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
        enqueue(&head, &tail, contr);
    }
    printCoda(head, tail);
}
void main(){
    es1();
}