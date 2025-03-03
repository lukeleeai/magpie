#include<cstdio>

#include<algorithm>

using namespace std;

int main(){

	int n;

	scanf("%d",&n);

	int a,b,c=0;

	scanf("%d %d",&a,&b);

	c=__gcd(a,b);

	while(n-2){

		int x;scanf("%d",&x);

		if(x%c){

			c=x%c;

		}

		n--;

	}

	printf("%d",c);

	return 0;

} 