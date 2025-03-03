#include <cstdio>

int n,i;

int main(){

	scanf("%d", &n);

	for(;n--;)for(i=n;i--;)printf("%d%c",__builtin_ffs(n^i),i?' ':'\n');

}