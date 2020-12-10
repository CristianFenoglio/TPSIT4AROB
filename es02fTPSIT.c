//Leggere un file di testo "testo.txt" carattere per carattere, contare le parole presenti caricando ogni parola in un vettore di stringhe (supporre che non ci siano più di 100 parole di lunghezza massima 20)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#define LUNG 1000
#define DIM 1000
#define DATI 14

typedef struct regione{
    char* data;
    char* stato;
    int numReg;
    char* nome;
    float lat;
    float longit;
    int terInt;
    int totCasi;
    //int* numVari;
    /*


     top 3 delle regioni per numero di ricoveri in terapia intensiva 1
    2) totale dei ricoverati in terapia intensiva
    3) top 3 delle regioni con meno casi totali positivi.

    0 int RicSint;
    1 int terInt;------------------------
    2 int totOsp;
    3 int dom;
    4 int totPos;
    5int varTotPos;
    6int nuovPos;
    7int dimessiGuarit;
    8int dec;
    9int casSospDiagn;
    int casi_da_screening;
    int totCasi;-----------------------
    int tamp;
    int casiTest;
    */
}Regione;


bool eCont(int n, int* vett, int d){//controlla se un valore c'è dentro ad un vettore
    bool ok=false;//risultato
    int z=0;//scorre il vettore
    while(ok==false && z<d){
        if(n==*(vett+z)){
            ok=true;

        }
        z++;
    }
    return ok;
}


void minCasiTot(Regione* p, int d, int* classifica){//d è la dimensione
int minTot;
    for(int k=0; k<d; k++){
        if(k==0){
            minTot=(p+k)->totCasi;
        }else if(minTot>(p+k)->totCasi){
            minTot=(p+k)->totCasi;
        }
    }
    *classifica=minTot;
    int e=0;//mi dice se sono entrato nel ciclo
    for(int k=0; k<d; k++){
        if((p+k)->totCasi>*classifica){
            if(e==0){
                minTot=(p+k)->totCasi;
                e=1;
            }else if(minTot>(p+k)->totCasi){
                minTot=(p+k)->totCasi;
            }
        }
        
    }
    *(classifica+1)=minTot;
    e=0;
    for(int k=0; k<d; k++){
        if((p+k)->totCasi>*(classifica+1)){
            if(e==0){
                minTot=(p+k)->totCasi;
                e=1;
            }else if(minTot>(p+k)->totCasi){
                minTot=(p+k)->totCasi;
            }
        }
        
    }
    *(classifica+2)=minTot;

}




void maxtein(Regione* p, int d, int* classifica){//d è la dimensione
int minTot;
    for(int k=0; k<d; k++){
        if(k==0){
            minTot=(p+k)->terInt;
        }else if(minTot<(p+k)->terInt){
            minTot=(p+k)->terInt;
        }
    }
    *classifica=minTot;
    int e=0;//mi dice se sono entrato nel ciclo
    for(int k=0; k<d; k++){
        if((p+k)->terInt<*classifica){
            if(e==0){
                minTot=(p+k)->terInt;
                e=1;
            }else if(minTot<(p+k)->terInt){
                minTot=(p+k)->terInt;
            }
        }
        
    }
    *(classifica+1)=minTot;
    e=0;
    for(int k=0; k<d; k++){
        if((p+k)->terInt<*(classifica+1)){
            if(e==0){
                minTot=(p+k)->terInt;
                e=1;
            }else if(minTot<(p+k)->terInt){
                minTot=(p+k)->terInt;
            }
        }
        
    }
    *(classifica+2)=minTot;

}
void legg(Regione* p, int c){
    FILE *fp;
    char line[LUNG];
    int cont=0;
    char nomeFile[]="dati.csv";
    char* inut;
    if((fp=fopen(nomeFile, "r"))==NULL){
            printf("______________________iL FiLe NoN EsIsTe_______________________");
    }else{
        while(fgets(line, LUNG, fp)!=NULL){
            //trovo i vari pezzi
            
            (p+cont)->data=strdup(strtok(line,",\n"));
            (p+cont)->stato=strdup(strtok(NULL,",\n"));
            (p+cont)->numReg=atof(strtok(NULL, ",\n"));
            (p+cont)->nome=strdup(strtok(NULL,",\n"));
            (p+cont)->lat=atof(strtok(NULL, ",\n"));
            (p+cont)->longit=atof(strtok(NULL, ",\n"));
            for(int k=0; k<DATI; k++){
                
                if(k==1){
                    (p+cont)->terInt=atoi(strtok(NULL, ",\n"));
                    
                }
                if(k==8){
                        (p+cont)->totCasi=atoi(strtok(NULL, ",\n"));
                        break;
                }
                if(k!=1&&k!=8){
                    inut=strtok(NULL, ",\n");
                }
                
                
            }
            cont=cont+1;
            

        } 
         
        fclose(fp);
    }    
        
}

int totTot(Regione* p, int c){
    int tot=0;
    for(int k=0; k<c; k++){ 
        printf("%d\n",tot); 
        tot=tot+(p+k)->totCasi;  
    }
    return tot;
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

	

#define TOP 3
    
int main(){
    Regione* italy;
    char nomeFile[]="dati.csv";
    int c=trovaRighe(nomeFile);
    int*clMinTot=(int*) malloc(sizeof(int)*TOP);
    //
    int*clTerapInt=(int*) malloc(sizeof(int)*TOP);
    italy=(Regione*)malloc(c*sizeof(Regione));
    
    legg(italy, c);
    
    minCasiTot(italy, c, clMinTot);
    
    int tot=totTot(italy,c);
    
    printf("%d",tot);
    free (italy);
    
}