#include<cstdio>

#include<cstring>

using namespace std;

int N,K;

char sz[5000];

bool ok(int n,char a[],int lo){

	if(lo==0)	return true;

	for(int i=n;i<n+lo;i++){

		if(sz[i]!=a[i-n])	return false;

	}

	return true;

}

void sou(char a[]){

	if(K==0)	return;

	char b[5000]={0};

	bool o[26]={false};

	int ng=strlen(a);

	for(int i=0;i<ng;i++)	b[i]=a[i];

	for(int i=ng;i<N;i++){

		if(ok(i-ng,a,ng))	o[sz[i]-'a']=true;

	}

	for(int i=0;i<26;i++){

		if(o[i]){

			b[ng]=i+'a';

			--K;

			if(K==0){

				printf("%s",b);

				return;

			}

			sou(b);

		}

		if(K==0)	return;

	}

}

int main(){

	scanf("%s %d",sz,&K);

	while(sz[N]!='\0')	++N;

	char a[5000]={'\0'};

	sou(a);

}