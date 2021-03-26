//cristian fenoglio
/*
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define LUNGMAX 100

float inserisciNum(float lim){
    float n;
    do{
        scanf("%f",&n);
    }while(n>lim);

    return n;
}

int decOUndec(){//domanda e riceve una risposta se vuoi decodificare o codificare la frase
    int risp;
    printf("vuoi decodificare(inserire 0) o codificare(inserire 1)?    ");
    do{
        scanf("%d", &risp);
    }while(risp!=0 && risp!=1);
    return risp;
    
}

void inserireParola(char parola[]){//carica la parola
    printf("inserire la parola");
    fflush(stdin);
    gets(parola);
    return;
}

void codif(char parola[], int lung){
    int t=0;//serve a scorrere il stringa parola
    int k;//serve ad aggiornare t
    int count=0;//tiene il conto delle lettere uguali di fila
    int cont;
    bool z=false;
    char temp[lung];//stringa d'appoggio
    int scorrTemp=0;
    while(parola[t]!= '\0'){//finchè non finisce la stringa
        k=0;//risetto k a 0
        while(parola[t]==parola[t+k]){//finchè la lettera non cambia 
            count++;
            k++;
            z=true;
        }
        if(count!=1){//se è uno c'era solo 1 lettera(a) se diverso devo scrivere anche il numero (2a) e quindi aggiornare la stringa d'appoggio in modo differente
            temp[scorrTemp]=count+48;
            scorrTemp++;
            temp[scorrTemp]=parola[t];
            scorrTemp++;
            if(z){
                cont =cont +2;
            }else{
                 cont =cont +1;
            }
            
            z=false;

        }else{
            temp[scorrTemp]=parola[t];
            scorrTemp++;
        }
        count=0;//resett del count a 0
      t=t+k;  
    }
    for(int h=0;h<cont; h++){//evita di salvare valori indesiderati
        parola[h]=temp[h];
    }

}



void decodif(char parola[], int lung){
    int t=0;
    char temp[lung];//stringa d'appoggio
    int cont=0;
    int scorrTemp=0;//scorre la stringa d'appoggio
    while(parola[t]!= '\0'){//fino a fine stringa
        if(parola[t]>1+48 && parola[t]<=9+48){//se è compreso tra 2 e 9 salva il numero di volte indicato la lettera nella cella dopo(3a--> aaa)
            cont=cont+(parola[t]-48);
            
            for(int j=0; (parola[t]-48)>j; j++)
            {
                temp[scorrTemp]=parola[t+1];
                scorrTemp++; 
            }
            t=t+2;
            
        }else if(( parola[t]>='a' && parola[t]<='z' )|| ( parola[t]>='A' && parola[t]<='Z')){//se è compreso tra tar a e z o A e Z
            cont=cont+1;
            temp[scorrTemp]=parola[t];
             scorrTemp++;
             t++;

        }
    }
    
    for(int h=0;h<cont; h++){//evita di salvare valori indesiderati
        parola[h]=temp[h];
    }
   
    

}

void main(){
    char parola[LUNGMAX];
    for (int clr=0; clr<LUNGMAX; clr++){
        parola[clr]=' ';
    }
    int risp=decOUndec();  
    inserireParola(parola);

    if(risp==1){
        codif(parola, LUNGMAX);
        printf("\n");
        printf("%s", parola);
    }else if(risp==0){
        int contdec;
        decodif(parola, LUNGMAX);
        printf("\n");
         printf("%s", parola);
    }
    getch();


}
