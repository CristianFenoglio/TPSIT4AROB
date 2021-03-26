
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef struct nodo{
    char valore;
    struct nodo *next;
}Nodo;

int isEmpty(Nodo *head){
    if(head == NULL)
        return 1;
    else
        return 0;   
}

void push(Nodo **head, Nodo *element){
    if(isEmpty(*head)){     //= if(isEmpty(*head) == 0)
        *head = element;
        element->next = NULL;
    }else{
        element->next = *head;
        *head = element;
    }
}

Nodo *pop(Nodo **head){
    Nodo *ret = *head;

    if(isEmpty(*head)){
        return NULL;
    }else{
        *head = ret->next;
    }
    return ret;
}

int main(){//controllo se una stringa ha le parentesi in modo corretto
    char stringa[100];
    Nodo *head = NULL;
    Nodo *pila = NULL;
    Nodo *appoggio = NULL;
    bool ok = true;

    printf("inserisci una stringa con parentesi graffe tonde e quandre al suo interno: ");
    scanf("%s", stringa);//leggo

    for(int k = 0; stringa[k] != '\0' && ok == true; k++){
        pila = (Nodo*) malloc(sizeof(Nodo));
        pila->valore = stringa[k];

        if(stringa[k] == '(' || stringa[k] == '[' || stringa[k] == '{'){//push se è una par aperta
            push(&head, pila);
            
        }else if(stringa[k] == ')'){//pop e controlli se è una chiusa
            appoggio = pop(&head);
            if(appoggio != NULL){
                if(appoggio->valore != '(')
                    ok = false;
            }else{
                ok = false;
                break;
            }

        }else if(stringa[k] == ']'){
            appoggio = pop(&head);
            if(appoggio != NULL){
                if(appoggio->valore != '[')
                    ok = false;
            }else{
                ok = false;
                break;
            }

        }else if(stringa[k] == '}'){
            appoggio = pop(&head);
            if(appoggio != NULL){
                if(appoggio->valore != '{')
                    ok = false;
            }else{
                ok = false;
                break;
            }  
        }
    }

    if(ok == true)//visualizzazione risultato
        printf("Ordine parentesi corretto");
    else
        printf("Ordine parentesi errato");

    return 0;
}