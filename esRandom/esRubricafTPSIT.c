#define MAX_NUM_CONTATTI 1024
//utilizzare una lista come una rubrica
struct contatto{
    int id;
    char nome [64];
    char numero[16];
};

struct rubrica{
    int num_inseriti;
    strcut contatto db [MAX_NUM_CONTATTI];
};

int inserisci(struct rubrica *r, char *nome, char *numero{//inserimento
    strcut contatto *p;
    if(r->num_inseriti == MAX_NUM_CONTATTI){
        printf("Rubrica piena");
        return -1;
    }
    p=&r->db[r->num_inseriti];

    strcpy(p->nome,nome);
    strcpy(p->numero,numero);
    p->id=r->num_inseriti;
    r->num_inseriti++;
    return 0;
}

char *trova_numero_da_nome(strcut rubrica *r, char *nome){//funzione di ricerca su una lista
    int i;
    strcut contatto *p;
    for(i=0;i<MAX_NUM_CONTATTI; i++){
        if(i==r->num_inseriti)
            break;
        p= &r->db[i];

        if(strcmp(p->nome,nome)==0)
            return p->numero;
    }
    return NULL;
}

void stampa_rubirca(strcut rubrica *r){//stampa tutta la rubrica
    int i;
    strcut contatto *p;

    printf ("\nStampa rubirca: %d contatti\n",r->num_inseriti);

    for(i=0; i<MAX_NUM_CONTATTI; i++){
        if(i==r->num_inseriti)
            break;
        p= &r->db[i];
    }
}
