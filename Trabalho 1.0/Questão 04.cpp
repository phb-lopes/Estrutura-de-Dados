#include <stdio.h>
#include <stdlib.h>
#define x 5
int main(){
	float v1[x][x],v2[x][x];
	int i,j;
	for(j=0;j<x;j++){
		for(i=0;i<x;i++){
			printf("Insira o numero\n");
			scanf("%f",&v1[i][j]);
		}
	}
	for(i=0;i<x;i++){
		for(j=0;j<x;j++){
		v2[j][i]=v1[i][j];
		}
	}
	
	printf("Matriz preenchida\n");
	for(i=0;i<x;i++){
		for(j=0;j<x;j++){
			printf("%.1f\t",v2[i][j]);
		}
		printf("\n");
	}
	
	printf("Matriz Resultande:\n");
	for(i=0;i<x;i++){
		for(j=0;j<x;j++){
			printf("%.1f\t",v1[i][j]);
		}
		printf("\n");
	}
	
	system("PAUSE");
}

