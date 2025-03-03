#include<stdio.h>

int main(){

	int N,K,i,j,S[100],B,a;

	while(a=1,scanf("%d %d",&N,&K),N||K){

		for(i=K;i--;)scanf("%d",S+i);

		for(i=N;i--;)for(j=K;j--;)scanf("%d",&B),S[j]-=B,S[j]<0?a=0:0;

		puts(a?"Yes":"No");

	}

}