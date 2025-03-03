#include<cstdio>

using namespace std;

int main(){

	unsigned int n;

	unsigned long long int a,ev=0,o=0;

	scanf("%u",&n);

	while(n--){

		scanf("%llu",&a);

		if(a&1)

		++ev;

		else

		++o;

	}

	if(ev%2==0)

	printf("YES");

	else

	printf("NO");

	return 0;

}