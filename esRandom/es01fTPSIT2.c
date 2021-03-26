

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#define LUNG 100
#define DIM 100


typedef struct canzone{
    int num;
    char *nome;
    char *autor;
    struct canzone* next;
   
}Canzone;

	
void push(Canzone* p, int i, char*titolo, char* autore){
    
    if(p == NULL){
        
        p->num = i;
        p->nome = strdup(titolo);
        p->autor = strdup(autore);
        p->next = NULL;
    }else{
        Canzone* p_appoggio = p;

        while(p_appoggio->next !=NULL){
            p_appoggio=p_appoggio->next;
        }
        p_appoggio->next = (Canzone*) malloc(sizeof(Canzone));
        p_appoggio->next->num = i;
        p_appoggio->next->autor = strdup(autore);
        p_appoggio->next->nome = strdup(titolo);
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
        
        run=trova(p,suona);
        
        printf("%s %s\n", run->nome, run->autor);//printa  


            
    }
    free(vett);


}

void leggi(Canzone* p){
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
           
            stringaA1=strdup(strtok(NULL,",\n"));
            
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
    p= (Canzone*)malloc(sizeof(Canzone));
    leggi(p);
    
    for(Canzone* k = p; k != NULL; k = k->next)
        printf("\n%d %s", k->num, k->nome);
    printf("\n-------------------------------");
    int c=trovaRighe("music.csv");
    
    randomEsecuzione(p, c);
    
    
    for(Canzone* k = p; k != NULL; k = k->next)
        free(k);
}