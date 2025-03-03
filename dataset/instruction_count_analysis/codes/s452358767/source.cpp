#include <cstdio>

#include <cstring>

#include <algorithm>

using namespace std;

const int maxd = 1e5+10;

char s[maxd];

int main()

{

	// freopen("a.in","r",stdin);

	// freopen("k.out","w",stdout);

	int x;

	scanf("%d %s",&x,s);

	if(x >= 3200) printf("%s",s);

	else printf("red");

	return 0;

}