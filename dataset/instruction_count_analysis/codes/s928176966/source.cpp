#include<algorithm>

#include<cstdio>

using namespace std;

int s[3];

int main(){

	scanf("%d%d%d",&s[0],&s[1],&s[2]);

	sort(s,s+3);

	printf("%lld",s[0]+s[1]);

	return 0;

}