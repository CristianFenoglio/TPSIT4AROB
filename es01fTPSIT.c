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


void randomEsecuzione(Canzone* p, int d){//d è la dimensione
    int* vett;//contiene i numeri delle canzoni da ancora suonare
    vett=(int*)malloc(d*sizeof(int));
    for(int k=0; k<d; k++){
        *(vett+k)=k;//assegna alla cella 0 0 alla 1 1 ecc...
    }

    int suona;//il numero della canone da suonare
    srand(time(NULL));//per il random
   
    for(int j=0; j<d; j++){
        do{
            suona=rand()%(d+1);//formula per ottennere un numero random tra 0 e d
        }while(!eCont(suona, vett, d));
        *(vett+suona)=-1;//così non c'è la possibilità di ripetere una canzone
        printf("%s %s\n", (p+suona)->nome, (p+suona)->autor);//printa  


            
    }
       
}

void legg(Canzone* p, int c){
    FILE *fp;
   
    char line[LUNG];
    int cont=0;
    char nomeFile[]="music.csv";
    if((fp=fopen(nomeFile, "r"))==NULL){
            printf("______________________iL FiLe NoN EsIsTe_______________________");
    }else{
        while(fgets(line, LUNG, fp)!=NULL){
            //trovo i vari pezzi
            (p+cont)->num=atoi(strtok(line, ",\n"));
            strcpy((p+cont)->nome, strtok(NULL,",\n"));
            strcpy((p+cont)->autor, strtok(NULL,",\n"));
            cont=cont+1;

        } 
         
        fclose(fp);
    }    
        
}


int trovaRighe(char nomeFile[]){
    FILE *fp;
    int c=0;
    char* l;
    l=(char*)malloc(sizeof(char)*100);
    if((fp=fopen(nomeFile, "r"))==NULL){
            printf("______________________iL FiLe NoN EsIsTe_______________________");
    }else{
        while(fgets(l, LUNG, fp)!=NULL){
            c=c+1;
        }  
        fclose(fp);
    }
    return c;

}  

	


    
int main(){
    char nomeFile[]="music.csv";
    int c=trovaRighe(nomeFile);
    Canzone* p;
    p=(Canzone*)malloc(c*sizeof(Canzone));
    legg(p, c);
    randomEsecuzione(p, c);
    
}