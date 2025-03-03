#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;

int n;

int main(){

	scanf("%d",&n);

	if(n%2) printf("%d\n",n*2);

	else printf("%d\n",n);

	return 0;

}