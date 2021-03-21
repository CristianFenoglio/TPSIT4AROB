//fenoglio cristian 4 a rob
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define NCARTE 13
#define NSEMI 4
typedef struct el{
    int n;
    char seme;
    struct el *next;
}El;//il refactor crea danni con le else

bool isEmpty(El *head){
    return (head==NULL); 
}


void push(El **head, El *element){

    if (isEmpty(*head)){           //if (is_empty(*head) == NULL)
        *head = element;
        element->next = NULL;
    }else{
        element->next = *head;
        *head = element;
    }
}

El* pop(El **head){
    El* ret = *head;
    if (isEmpty(*head)){
        return NULL;
    }else{
        *head = ret->next;
    }
    return ret;
}




void fillMazzo(El **mazzo){//riempio il mazzo
    ///CUORI
    int a[NCARTE];//mi tiene i numeri per il controllo
    int i, j;
    for(i=0;i<NCARTE;i++) {
        a[i]=rand()%NCARTE+1;//lo riempio con un numero random
        for(j=0;j<i;j++) {
       	    if(a[i]==a[j]|| a[i]==0) {//se è già presente quel numero gli rifaccio fare il giro da capo diminuendo la i
                i--;
                break;//se lo trova esce dal for
            }
        }
    }

    for(i=1; i<=NCARTE; i++){
        El* element=(El*) malloc(sizeof(El));
    
        element->seme='C';
        element->n= a[i];
        
        push(mazzo, element);
        
    }
    ////////////////////////////////PICCHE

    for(i=0;i<NCARTE;i++) {
        a[i]=rand()%NCARTE+1;//lo riempio con un numero random
        for(j=0;j<i;j++) {
       	    if(a[i]==a[j]|| a[i]==0) {//se è già presente quel numero gli rifaccio fare il giro da capo diminuendo la i
                i--;
                break;//se lo trova esce dal for
            }
        }
    }

    for(i=1; i<=NCARTE; i++){
        El* element=(El*) malloc(sizeof(El));
        
        element->seme='P';
        element->n=a[i];
        push(mazzo, element);
        
    }

    //////////////////DIAMONDS
    for(i=0;i<NCARTE;i++) {
        a[i]=rand()%NCARTE+1;//lo riempio con un numero random
        for(j=0;j<i;j++) {
       	    if(a[i]==a[j]|| a[i]==0) {//se è già presente quel numero gli rifaccio fare il giro da capo diminuendo la i
                i--;
                break;//se lo trova esce dal for
            }
        }
    }

    for(i=1; i<=NCARTE; i++){
        El* element=(El*) malloc(sizeof(El));
       
        element->seme='D';
        element->n=a[i];
        push(mazzo, element);
        
    }




    //////////////////FIORI
    for(i=0;i<NCARTE;i++) {
        a[i]=rand()%NCARTE+1;//lo riempio con un numero random
        for(j=0;j<i;j++) {
       	    if(a[i]==a[j]|| a[i]==0) {//se è già presente quel numero gli rifaccio fare il giro da capo diminuendo la i
                i--;
                break;//se lo trova esce dal for
            }
        }
    }
    for(i=1; i<=NCARTE; i++){
        El* element=(El*) malloc(sizeof(El));
        
        element->seme='F';
        element->n=a[i];
        push(mazzo, element);
        
    }
    

}


int main(){
    El* mazzo=NULL;
    El* manoAlice=NULL;//player 1
    El* manoBob=NULL;//player 2
    srand(time(NULL)); //inizializza il generatore sull'ora attuale dell'elaboratore time(0)
    fillMazzo(&mazzo);//riempie il mazzo
    int numeropescatore;//per capire chi deve pescare
    int contaturni=0;
    while(!isEmpty(mazzo)){  //fino a quando la coda ha elementi
        contaturni++;
        printf("\nturno %d", contaturni);
        numeropescatore=1+rand()%2;
        if(numeropescatore==1){//pesca prima alice
            push(&manoAlice, pop(&mazzo));
            push(&manoBob, pop(&mazzo));
        }else{//pesca prima bob
            push(&manoBob, pop(&mazzo));
            push(&manoAlice, pop(&mazzo));
        }
    }
    El* carta;
    while(!isEmpty(manoAlice)){//stampa della mano di alice
        carta=pop(&manoAlice);
        printf("\n carta di : %c num: %d",carta->seme, carta->n);
        free(carta);
    }
    

    return 0;
}