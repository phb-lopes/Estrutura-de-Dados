#include <stdio.h>
#include <stdlib.h>
#define x 100
#define x2 200

int main (){
	int v1[x],v2[x],v3[x2];
	int i=0,j=0;
	for(i=0;i<x;i++){
		printf("Qual o %d numero do 01 vetor?\n",i+1);	
		scanf("%d",&v1[i]);
	}
	printf("\nA partir daqui comeca o 02 vetor\n\n");
	for(j=0;j<x;j++){
		printf("Qual o %d numero do 02 vetor?\n",j+1);	
		scanf("%d",&v2[j]);
	}
	for(i=0;i<x;i++){
		for(j=0;j<x;j++){
			if(v1[i] == v2[i]){
				v3[i]=v2[i];
			}
			else{
				v3[i]=v1[i];
			}
		}
	}
	for(i=x;i<x2;i++){
		v3[i]=v2[i];
	}
	printf("Vetor 03:\n");
	for(i=0;i<x2;i++){
		printf("%d\n",v3[i]);
	}
	
	system("PAUSE");
}
