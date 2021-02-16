/*
Implementare i metodi enqueue() e dequeue()  e creare un programma che permetta
all’utente di riempire una coda di numeri interi di lunghezza arbitraria. Successivamente
testare la funzione dequeue per svuotare la coda.
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct queue_node{
    int valore;
    struct queue_node *next;
};

bool is_empty(struct queue_node *punt){
    return punt==NULL;
}

void printCoda(struct queue_node *head){
    while(!is_empty(head)){
        printf("%d", head->valore);
        head = head->next;
    }

}

void enqueue(struct queue_node **head, struct queue_node **tail, struct queue_node *element){
    if(is_empty(*head)){
        *head=element;

    }else{
        (*tail)->next=element;
    }

    *tail=element;
    element->next=NULL;
}

struct queue_node * dequeue(struct queue_node **head, struct queue_node **tail){
    struct queue_node *ret = *head;
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

void main(){
    char choice;

    struct queue_node* number = NULL;
    struct queue_node* head = NULL;
    struct queue_node* tail = NULL;
    

    
    do{
        number = (struct queue_node*) malloc (sizeof(struct queue_node));

        printf("Inserisci un numero..."); 
        fflush(stdin);  
        scanf("%d", &number->valore);    
        enqueue(&head, &tail, number);

        printf("Ne vuoi inserire ancora? s,S (si) n,N (no)");
        fflush(stdin); 
        scanf("%c", &choice);
    }while (choice == 's' || choice == 'S');

    while(!is_empty(head)){
        number = dequeue(&head, &tail);
        printf("%d ", number->valore);
        free(number);
    }
}