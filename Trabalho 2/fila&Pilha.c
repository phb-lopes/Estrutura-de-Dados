#include <stdio.h>
#include <stdlib.h>

struct no{
	int num;
	struct no *prox;
};

struct no *pushFila(struct no **lista,int num){
	struct no *v1;
	struct no *aux;
	
	if(*lista == NULL){
		v1 = (struct no*)malloc(sizeof(struct no));
    if(v1 == NULL)
    	return *lista;
    
    v1->num = num;
    v1->prox = NULL;
    *lista = v1;
    
	}else{
		aux = *lista;
		v1 = (struct no*)malloc(sizeof(struct no));
    	v1->num = num;
    	
		if(aux == NULL)
	    	return *lista;	
	    
	    while(aux->prox != NULL)
			aux = aux->prox;
    	
    	v1->prox = aux->prox;
        aux->prox = v1;
	}
	return *lista;
}

struct no *pushPilha(struct no **lista,int num){
    struct no *v1;
    struct no *aux;
    
    if(*lista == NULL){
        v1 = (struct no*)malloc(sizeof(struct no));
        if(v1 == NULL)
            return *lista;
        v1->num = num;
        v1->prox = NULL;
        *lista = v1;
    }else{
        aux = (struct no*)malloc(sizeof(struct no));
        if(aux == NULL)
            return *lista;
        aux->num = num;
        aux->prox = *lista;
        *lista = aux;
    }
    return *lista;
}

struct no *pop(struct no **lista){
    struct no *v1;		
	
	if(*lista == NULL){
		printf("Lista vazia\n");
		return NULL;	
	}
    
    v1 = *lista;
    *lista = v1->prox;
    printf("Numero revomido: %d\n\n", v1->num);
    free(v1);
	return *lista;
}

void imprimirLista(struct no **lista){
    struct no *v2 = *lista;
    int x=1;
    
    for(v2 = *lista; v2 != NULL ; v2 = v2->prox){ 
		printf("Ordem de saida: %d Numero: %d\n",x,v2->num);
		x++;
    }
    printf("\n");
}

int tamanhoLista(struct no **lista){
	struct no *v2;
    int cont=0;
    for(v2 = *lista; v2 != NULL ; v2 = v2->prox)
    	cont++;
	return cont;
}

void fila(){
    struct no *lista= NULL;
    int op, num;
    while(op > 0){
        printf("-> Fila <-\n");
        printf("Digite:\n0 - Sair\n1 - Inserir Numero\n2 - Remover\n3 - Informacao sobre o tamanho\n");
        scanf("%d",&op);
        switch(op){
            case 1:{
                printf("Qual o valor?\n");
                scanf("%d",&num);
                pushFila(&lista,num);
                imprimirLista(&lista);   
                break;
            }   
            case 2:{
                pop(&lista);
                imprimirLista(&lista);
                break;
            }
            case 3:{
                printf("Tamanho da Lista: [%d]\n",tamanhoLista(&lista));
                imprimirLista(&lista);
                break;
            }
        }
    }
}

void pilha(){
    struct no *lista = NULL;
    int op, num;
     while(op > 0){
        printf("-> Pilha <-\n");
        printf("Digite:\n1 - Inserir Numero\n2 - Remover\n3 - Informacao sobre o tamanho\n");
        scanf("%d",&op);
        switch(op){
            case 1:{
                printf("Qual o valor?\n");
                scanf("%d",&num);
                pushPilha(&lista,num);
                imprimirLista(&lista);   
                break;
            }   
            case 2:{
                pop(&lista);
                imprimirLista(&lista);
                break;
            }
            case 3:{
                printf("Tamanho da Lista:[%d]\n",tamanhoLista(&lista));
                imprimirLista(&lista);
                break;
            }
        }
    }
}

int main(){
	int op;
    while(op > 0){
        printf("Digite:\n0 - Sair\n1 - Fila\n2 - Pilha\n");
        scanf("%d",&op);
        switch(op){
            case 1:{
                fila();
                break;
            }   
            case 2:{
                pilha();
                break;
            }
        }
    }
    return 0;   
}
