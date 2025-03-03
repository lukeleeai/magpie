#include<cstdio>

using namespace std;

typedef long long ll;

int main()

{

	ll a,b;

	char s[5];

	scanf("%lld%s",&a,&s);

	b=(s[0]-'0')*100+(s[2]-'0')*10+(s[3]-'0');

	printf("%lld\n",a*b/100);

	return 0;

}