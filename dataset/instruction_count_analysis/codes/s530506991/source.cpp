#include<cstdio>

#include<cstring>

#include<algorithm>

#define fail {puts("NO");return 0;}

#define suc {puts("YES");return 0;}

using namespace std;

int a,b,c;

char ch[100010];



int main()

{

	scanf("%s",ch);int n=strlen(ch);

	for(int i=0;i<n;i++)

		if(ch[i]=='a')

			a++;

		else if(ch[i]=='b')

			b++;

		else if(ch[i]=='c')

			c++;

	int mn=min(a,min(b,c));

	a-=mn;b-=mn;c-=mn;

	if(a<2&&b<2&&c<2)

		suc

	else

		fail

	return 0;

}