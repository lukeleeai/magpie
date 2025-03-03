#include <cstdio>

#include <cstdlib>



const int MAXN=100011;



int N;

char str[MAXN];



bool isWolf[MAXN];



void Shift(){

	for(int i=2;i<N;++i){

		if(isWolf[i-1]){

			if(str[i-1]=='x')

				isWolf[i]=isWolf[i-2];

			else	isWolf[i]=!isWolf[i-2];

		}

		else{

			if(str[i-1]=='o')

				isWolf[i]=isWolf[i-2];

			else	isWolf[i]=!isWolf[i-2];

		}

	}

}



bool Test(int a){

	int p=a-1;if(p<0)	p+=N;

	int n=a+1;if(n>=N)	n-=N;

	if(isWolf[a]^(str[a]=='o'))

		return isWolf[p]==isWolf[n];

	return isWolf[p]!=isWolf[n];

}



bool Test(){

	bool ret=true;

	for(int i=0;i<N;++i){

		ret&=Test(i);

	}

	return ret;

}



void Show(){

	for(int i=0;i<N;++i){

		if(isWolf[i])

			printf("W");

		else	printf("S");

	}

	puts("");

	exit(0);

}



int main(){

	

	scanf("%d", &N);

	

	scanf("%s", str);

	

	isWolf[0]=false;isWolf[1]=false;

	Shift();

	if(Test())	Show();

	

	isWolf[0]=false;isWolf[1]=true;

	Shift();

	if(Test())	Show();

	

	isWolf[0]=true;isWolf[1]=false;

	Shift();

	if(Test())	Show();

	

	isWolf[0]=true;isWolf[1]=true;

	Shift();

	if(Test())	Show();

	

	puts("-1");

	

	return 0;

}