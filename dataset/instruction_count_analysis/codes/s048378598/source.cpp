#include<cstdio>

using namespace std;

int N; int a;

int A[100005];

int main(){

	scanf("%d",&N);

	for(int i=1;i<=N;++i){

		scanf("%d",&a);

		A[a]=i;

	}

	printf("%d",A[1]);

	for(int i=2;i<=N;++i){

		printf(" %d",A[i]);

	}

	return 0;

}