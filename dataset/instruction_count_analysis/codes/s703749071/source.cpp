#include <cstdio>

int n,t=1,u=4;

int main(){

	scanf("%d", &n);

	for(;t*2<=n;t*=2);

	if(t==n) return 0*puts("No");

	puts("Yes");

	printf("1 2\n2 3\n3 %d\n%d %d\n%d %d\n",n+1,n+1,n+2,n+2,n+3);

	for(;u<n;u+=2) printf("%d %d\n%d 1\n1 %d\n%d %d\n", u+1,u,u,u+n+1,u+n+1,u+n);

	if(n==u) printf("%d %d\n%d %d\n", n,u^t,t+1+n,n*2);

}