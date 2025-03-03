#include<cstdio>

using namespace std;

int N;

int a[100010],b[100010];



int main(){

	scanf("%d",&N);

	for(int i=1;i<=N;i++){

		scanf("%d",&a[i]);

		b[a[i]]=i;

	}

	for(int i=1;i<=N;i++)

		printf("%d ",b[i]);

	printf("\n");

	return 0;	

}