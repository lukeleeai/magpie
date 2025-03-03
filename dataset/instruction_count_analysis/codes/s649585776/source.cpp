#include<cstdio>

using namespace std;

int a,b;

int main(){

	scanf("%d%d",&a,&b);

	if(a==1)  a=14;

	if(b==1)  b=14;

	if(a>b)  printf("Alice");

	if(a==b)  printf("Draw");

	if(a<b)  printf("Bob");

	return 0;

}