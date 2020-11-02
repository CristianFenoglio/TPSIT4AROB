//Leggere un file di testo "testo.txt" carattere per carattere, contare le parole presenti caricando ogni parola in un vettore di stringhe (supporre che non ci siano più di 100 parole di lunghezza massima 20)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#define LUNG 100
#define DIM 100


typedef struct canzone{
    int num;
    char nome[LUNG];
    char autor[LUNG];
}Canzone;


bool eCont(int n, int vett[], int d){//controlla se un valore c'è dentro ad un vettore
    bool ok=false;//risultato
    int z=0;//scorre il vettore
    while(ok==false && z<d){
        if(n==vett[z]){
            ok=true;

        }
        z++;
    }
    return ok;
}


void randomEsecuzione(Canzone elenco[], int d){//d è la dimensione
    int vett[d];//contiene i numeri delle canzoni da ancora suonare
    for(int k=0; k<d; k++){
        vett[k]=k;//assegna alla cella 0 0 alla 1 1 ecc...
    }

    int suona;//il numero della canone da suonare
    srand(time(NULL));//per il random
   
    for(int j=0; j<d; j++){
        do{
            suona=rand()%(d+1);//formula per ottennere un numero random tra 0 e d
        }while(!eCont(suona, vett, d));
        vett[suona]=-1;//così non c'è la possibilità di ripetere una canzone
        printf("%s %s\n", elenco[suona].nome, elenco[suona].autor);//printa  

            
    }
       
}

#define LUNG 100

void legg(Canzone elenco[], int* c){
    FILE *fp;
    char line[LUNG];
    char nomeFile[]="music.csv";
    if((fp=fopen(nomeFile, "r"))==NULL){
            printf("______________________iL FiLe NoN EsIsTe_______________________");
    }else{
        while(fgets(line, LUNG, fp)!=NULL){
            //trovo i vari pezzi
            elenco[*c].num=atoi(strtok(line, ",\n"));
            strcpy(elenco[*c].nome, strtok(NULL,",\n"));
            strcpy(elenco[*c].autor, strtok(NULL,",\n"));
            *c=*c+1;

        }  
        fclose(fp);
    }    
        
}
    



    
int main(){
    Canzone elenco[DIM];
    int c=0;
    legg(elenco, &c);
    randomEsecuzione(elenco, c);
    
}
