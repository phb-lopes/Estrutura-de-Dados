#include <stdio.h>
#include <stdlib.h>

struct no{
int num;
struct no *prox;
};

// pilha insere no começo e remove no começo
// fila insere no começo e remove no fim

struct no *push(struct no **lista,int num){
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
	    
	    while(aux->prox != NULL){	
			aux = aux->prox;
    	}
    	v1->prox = aux->prox;
        aux->prox = v1;
	}
	return *lista;
}

struct no *pop(struct no **lista, int *num){
        //struct no *aux;
        struct no *v1;		
		
		if(*lista == NULL){
		printf("Lista vazia\n");
		return NULL;	
		}
        
        v1 = *lista;
        *lista = v1->prox;
		*num = v1->num;
        free(v1);
        
		return *lista;
}

void imprimir(struct no **lista){
        struct no *v2;
        v2 = *lista;
        int x=1;
        for(v2 = *lista; v2 != NULL ; v2 = v2->prox){ 
				printf("Ordem: %d Numero:%d!\n",x,v2->num);
				x++;
        } 
}

int tamanho(struct no **lista){
	struct no *v2;
    int cont=0;
    for(v2 = *lista; v2 != NULL ; v2 = v2->prox){
    	cont++;
    } 
	return cont;
}

int main(){
	struct no *lista;
	lista = NULL;
	int x, y = 0,num=0;
	 while(x>0){
        printf("Digite:\n1 - Inserir Numero\n2 - Remover\n3 - Informacao sobre o tamanho\n");
        scanf("%d",&x);
        switch(x){
        	case 1:{
        		printf("Qual o valor?\n");
				scanf("%d",&num);
				push(&lista,num);
				imprimir(&lista);	
        		break;
        	}	
        	case 2:{
        		pop(&lista, &y);
        		printf("Numero revomido: %d\n",y);
        		imprimir(&lista);
        		break;
        	}
        	case 3:{
        		printf("Tamanho da Lista:%d\n",tamanho(&lista));
        		imprimir(&lista);
        		break;
        	}
    	}
	}
	
}
