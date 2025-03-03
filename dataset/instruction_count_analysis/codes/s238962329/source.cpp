#include"stdc++.h"

using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)

int n, t=1, u=2;

int main(){

	scanf("%d", &n);

	for(;t<n;t*=2);

	if(t==n) return 0*puts("No");

	puts("Yes");

	if(n==3) return 0*printf("1 2\n2 3\n3 4\n4 5\n5 6\n");

	t/=2;

	for(;u<t;u++) printf("%d %d\n%d %d\n", u-1,u,u-1+n,u+n);

	printf("%d %d\n", u-1,1+n);

	for(;u<n;u+=2) printf("%d %d\n%d 1\n1 %d\n%d %d\n", u,u+1,u+1,u+n,u+n,u+n+1);

	if(n==u) printf("%d %d\n%d %d\n", n,u%4==2?t+1:t+n,u^t,n+n);

}