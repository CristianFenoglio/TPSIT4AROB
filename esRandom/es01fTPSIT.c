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
    struct canzone* next;
   
}Canzone;

	
void push(Canzone* p, int i, char*titolo, char* autore){
    
    if(p->num!=1){
        
        p=(Canzone*) malloc(sizeof(Canzone));
        p->num=i;
        strcpy(p->nome,autore);
        strcpy(p->autor,autore);
        p->next=NULL;
    }else{
        Canzone* p_appoggio;
        p_appoggio=p;
        while(p_appoggio->next !=NULL){
            p_appoggio=p_appoggio->next;
        }
        p_appoggio->next=(Canzone*) malloc(sizeof(Canzone));
        p_appoggio->next->num=i;
        strcpy(p_appoggio->next->nome,autore);
        strcpy(p_appoggio->next->autor,autore);
        p_appoggio->next->next=NULL;

    }
    
}


/*Canzone* trova(Canzone* psec, int n){//3  2  1  0
    printf("!%d!  ", n);  
    if(n==0){                     
        return psec;
    }else{
        printf("%d--", n);
        return trova(psec->next, n-1);
    }
}
*/


Canzone* trova(Canzone* p, int n){
    Canzone* r;
    r=p;
    for(int k=0; k<n; k++){
        r=r->next;
    }
    return r;
}

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


void randomEsecuzione(Canzone* p, int d){//d è la dimensione
    int* vett;//contiene i numeri delle canzoni da ancora suonare
    vett=(int*)malloc(d*sizeof(int));
    for(int k=0; k<d; k++){
        *(vett+k)=k;//assegna alla cella 0 0 alla 1 1 ecc...
    }

    int suona;//il numero della canone da suonare
    srand(time(NULL));//per il random
    Canzone* run;
    for(int j=0; j<d; j++){
        do{
            suona=rand()%(d);//formula per ottennere un numero random tra 0 e d
        }while(!eCont(suona, vett, d));
        *(vett+suona)=-1;//così non c'è la possibilità di ripetere una canzone
        printf("ola");
        run=trova(p,suona);
        printf("ola2");
        printf("%s %s\n", run->nome, run->autor);//printa  


            
    }
    free(vett);


}

void legg(Canzone* p){
    FILE *fp;
   
    char* line=(char*)malloc(sizeof(char)*LUNG);
    int num;
    char* stringaA1;
    char* stringaA2;
    char nomeFile[]="music.csv";
    if((fp=fopen(nomeFile, "r"))==NULL){
            printf("______________________iL FiLe NoN EsIsTe_______________________");
    }else{
        while(fgets(line, LUNG, fp)!=NULL){
            //trovo i vari pezzi
            
            num=atoi(strtok(line, ",\n"));
           
            //strcpy(stringaA1, strtok(NULL,",\n"));
            stringaA1=strdup(strtok(NULL,",\n"));
            //strcpy(stringaA2, strtok(NULL,",\n"));
            stringaA2=strdup(strtok(NULL,",\n"));
            
            push(p, num, stringaA1, stringaA2);

        } 
         
        fclose(fp);
    }
    free(stringaA1);
    free(stringaA2);    
        
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
    
    Canzone* p;
    p=(Canzone*)malloc(sizeof(Canzone));
    legg(p);
    
    int c=trovaRighe("music.csv");
    randomEsecuzione(p, c);
    printf("ciao");
    Canzone* tof;
    for(int k=c; k>0; k++){
        tof=trova(p, k);
        free(tof);
    }   
}