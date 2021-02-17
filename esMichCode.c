/*
es: Riscrivere le funzioni pop e push usando la enqueue e la dequeue.
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

typedef struct el{
    int n;
    struct el *next;
}El;

bool isEmpty(El *head){
    return (head==NULL); 
}

void enqueue(El **head, El **tail, El *element){
    if(isEmpty(*head))
        *head = element;
    else
        (*tail)->next = element;

    *tail = element;
    element->next = NULL;
}

El *dequeue(El **head, El **tail){
    El *ret = *head;

    if(isEmpty(*head))
        return NULL;
    else
        *head = ret->next;

    if(*head == NULL)
        *tail = NULL;
    
    return ret;
}

void push(El **head, El **tail, El *element){
    enqueue(head, tail, element); 
}

El *pop(El **head, El **tail){
    El *ret = (El*) malloc(sizeof(El));
    El *testa=NULL;
    El *fondo=NULL;
    El* rinfila=NULL;
    if(!isEmpty(*head)){
        do{ 
            ret = dequeue(head, tail);// (tail) D c b a (head) | NULL --->  D c b | a -->  c D |  (tail) b a (head) --> D | c b a---> NULL | a b c ret= D
            if(!isEmpty(*head)){
                push(&testa, &fondo, ret);
            }
        }while(!isEmpty(*head));

        while(!isEmpty(testa)){
            rinfila = dequeue(&testa, &fondo);
            push(head, tail, rinfila);
        }
        return ret;
    }
    *tail=NULL;
    return NULL;
    
}

int main(){
    char risposta;
    El *head = NULL;
    El *element = NULL;
    El *tail = NULL;

    do{
        element = (El*) malloc(sizeof(El));

        printf("Inserisci il numero: ");
        scanf("%d", &element->n);
        
        push(&head, &tail, element);

        printf("Vuoi ancora inserire un numero? (s per inserire ancora): ");
        fflush(stdin);
        scanf("%c", &risposta);

    }while(risposta == 's' || risposta == 'S'); //fino a quando la risposta è s o S carico numeri

    while(!isEmpty(head)){  //fino a quando la coda ha elementi
        printf("n: %d ", pop(&head, &tail)->n);   //stampa
    }

    return 0;
}