#include <cstdio>

#include <cstdlib>



const int MAXN=100011;



int gcd(int a, int b){

	return (b==0)?a:gcd(b, a%b);

}



void Show(bool i){

	if(i)	puts("POSSIBLE");

	else	puts("IMPOSSIBLE");

}



int N, K;

int A[MAXN], G;



void Test(int a){

	if(a>=0 && a%G==0){

		Show(true);

		exit(0);

	}

}



int main(){

	

	scanf("%d%d", &N, &K);

	for(int i=1;i<=N;++i)	scanf("%d", &A[i]);

	

	G=0;

	for(int i=1;i<=N;++i)	G=gcd(A[i], G);

	

	for(int i=1;i<=N;++i)	Test(A[i]-K);

	

	Show(false);

	

	return 0;

}