#include<cstdio>

using namespace std;

int a,b,c;

int main(){

	scanf("%d%d%d",&a,&b,&c);

	if(b-a==c-b) printf("YES\n");

	else printf("NO\n");

	return 0;

}