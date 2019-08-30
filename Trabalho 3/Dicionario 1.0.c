#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

struct elemento {
	char palavra[50];
	char traducao[50];
	struct elemento *prox;
};

struct tabela_hash {
struct elemento **v;
int tam;
int p[50];
};

int funcao_hash(struct tabela_hash *t, char *chave){
	int soma=0,i;
	
	for(i=0;i<t->tam;i++){
		soma += chave[i]*t->p[i];
	}
	return soma%(t->tam);

}

char *hash_buscar(struct tabela_hash *t, char *palavra){
	int indice = funcao_hash(t, palavra);
	struct elemento *i;
	for(i = t->v[indice] ; i != NULL ; i=i->prox){
		if(strcmp(palavra,t->v[indice]->palavra)==0){
			printf("Palavra:%s\nTraducao:%s\n",i->palavra,i->traducao);
			return i->traducao;
		}
	}
	printf("Palavra nao existe!\n");
	return NULL;
}

struct tabela_hash *hash_criar(int tam){
	int i=0;
    struct tabela_hash *v1;
    v1 = (struct tabela_hash*)malloc(sizeof(struct tabela_hash));
    if(v1 == NULL)
        return v1;
    v1->v = (struct elemento **)malloc(tam*sizeof(struct elemento *));
    v1->tam = tam;
    if(v1->v == NULL){
        free(v1);
        return NULL;
    }
    for(i=0;i<tam;i++){
        v1->v[i] = NULL;
    }
    for (i = 0; i < tam; i++){
    	v1->p[i] = (rand() % 110)+4;
    }

    return v1;
}

struct tabela_hash *hash_inserir(struct tabela_hash *t, char *palavra, char *traducao){
    int indice;
    struct elemento *aux;
    if(t == NULL)
    	return NULL;
    indice = funcao_hash(t, palavra);
    aux = (struct elemento*)malloc(sizeof(struct elemento));
    strcpy(aux->palavra, palavra);
    strcpy(aux->traducao,traducao);
    aux->prox = t->v[indice];
    t->v[indice] = aux;
    return t;
}


void hash_remover(struct tabela_hash *t, char *palavra){
    int indice = funcao_hash(t, palavra);
    
	struct elemento *antes = NULL;
    struct elemento *next = NULL;
    struct elemento *i;
    struct tabela_hash *v1;
    v1 = t;
    
	for(i = t->v[indice] ; i != NULL ; i=i->prox){
		
        while (v1->v[indice] != NULL && strcmp(v1->v[indice]->palavra ,palavra)==0){
            antes = v1->v[indice];
            v1->v[indice] = v1->v[indice]->prox;
            next = v1->v[indice];
        }
        if ( next == NULL ){
            printf("\nPalavra nao encontrada!\n");
            return t;
        }
        if  (antes==NULL ){
            printf("Palavra:%s Removida\nTraducao:%s Removida\n",i->palavra,i->traducao);
            t->v[indice] = v1->v[indice]->prox;
            return t;
        }
        else{
            printf("Palavra:%s Removida\nTraducao:%s Removida\n",i->palavra,i->traducao);
            antes->prox = v1->v[indice]->prox;
        }
        free(v1);
    }
}

void imprimir(struct tabela_hash *t, int tam){
    struct tabela_hash *v2;
    struct elemento *v3;
    int x=1;
    v2 = t;
    v3 = *v2->v;
    while(v2 != NULL){
        for(; v3 != NULL; v3 = v3->prox){
            printf("palavra:%s!\nTraducao:%s!\n",v3->palavra,v3->traducao);
            x++;
        }
        if(x == tam){
			break;
        }
    }
}

void hash_destruir(struct tabela_hash *t){
	int i;
	struct elemento *j;
	for( i = 0 ; i < t->tam ; i++){
		for( j= t->v[i]; j!=NULL; j=j->prox){
			free(j);
    	}
    }
    free(t->v);
    free(t);    
}

int main(){
        int x,tam;
        char palavra[50];
        char traducao[50];
        struct tabela_hash *T;
        srand(time(NULL));
        T = NULL;
        printf("Qual o tamanho do dicionario?\n");
        scanf("%d",&tam);
        T=hash_criar(tam);
        while(x>0){
                printf("Insira:\n1 - Inserir Palavra\n2 - Buscar\n3 - Imprimir todas as palavras\n4 - Remover uma palavra\n5 - Destruir\n");
                scanf("%d",&x);
                switch(x){
                        case 1:{
                        		fgetc(stdin);
                                printf("Digite a palavra\n");
                                scanf("%s",palavra);
                                printf("Digite a traducao\n");
                                scanf("%s",traducao);
                                hash_inserir(T,palavra,traducao);
                                break;
                        }
                        case 2:{
                        	printf("Qual palavra deseja buscar?\n");
                        	scanf("%s",palavra);
                        	hash_buscar(T,palavra);
                        	break;
                        }
                        case 3:{
                        	imprimir(T,tam);
                        	break;
                        }
                        case 4:{
                        	printf("Qual palavra deseja remover?\n");
                        	scanf("%s",palavra);
                        	hash_remover(T,palavra);
                        	break;
                        }
                        case 5:{
                        	hash_destruir(T);
                        	printf("Dicionario destruido!\n");
                        	break;
                        }
                }
        }
        system("PAUSE");
        return 0;

}

