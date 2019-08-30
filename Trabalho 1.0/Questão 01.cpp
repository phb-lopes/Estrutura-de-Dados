#include <stdio.h>
#include <stdlib.h>

int main (){
	int x,i=0,j=0,p=0;
	int m=0,mt;
	float mf=0;
	
	printf("Quantos numeros tem seu vetor?\n");
	scanf("%d",&x);
	int v1[x];
	for(i=0;i<x;i++){
		printf("Qual o numero?\n");
		scanf("%d",&v1[i]);
		m=m+v1[i];
	}
	mf=(float)m/x;	
	mt=m/x;
	for(i=0;i<x;i++){
		if(mt<=v1[i] && mt>=v1[i++]){
				if(mt>mf){
				p=i;	
				}else{
					j=i;
				}
		}
	}
	if(mt>mf){
		printf("Media:%.1f\nPosicao mais proxima da media:%d\n",mf,p);
	}else{
		printf("Media:%.1f\nPosicao mais proxima da media:%d\n",mf,j);	
	}
	
	system("PAUSE");
}
