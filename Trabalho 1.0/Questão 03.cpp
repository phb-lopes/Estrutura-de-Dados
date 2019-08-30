#include <stdio.h>
#include <stdlib.h>
#define x 10
int main(){
    int i,j;
	int v1[x][x],v2[x][x];

	printf("Qual o valor da matriz %dx%d:\n", x,x);
	for(i=0;i<x;i++){
		for(j=0;j<x;j++){
			printf("Posicao %d %d:",i+1,j+1);
			scanf("%d",&v1[i][j]);
		}
	}

	printf("\nMatriz:\n");
     for(i=0;i<x;i++){
        for(j=0;j<x;j++){
            printf("%d\t",v1[i][j]);
        }
        printf("\n");
    }

    printf("\n\nMatriz com as linhas trocadas:\n");

	for(i=0;i<x;i++){
		if(i%2==0){
			for(j=0;j<x;j++){
				v2[i][j]=v1[i][j];
            }
        }else{
          	for(j=0;j<x;j++){
           	v1[i-1][j]=v1[i][j];
           	v1[i][j]=v2[i-1][j];
        	}
        }
    }
 	for(i=0;i<x;i++){
        for(j=0;j<x;j++){
            printf("%d\t",v1[i][j]);
        }
     printf("\n");
    }
	system("PAUSE");
}


