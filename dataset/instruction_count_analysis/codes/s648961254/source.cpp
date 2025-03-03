#include<cstdio>

#include<cstring>

using namespace std;

int n,p,c[100010];

char a[100010];

int change(char k)

{

	if(k=='b') return 1;

	else if(k=='d') return -1;

	else if(k=='p') return 2;

	else return -2;

}

int main()

{

	scanf("%s",a);

	n=strlen(a)-1;

	for(int i=0;i<=n/2+1;i++)

	{

		int x=change(a[i]),y=change(a[n-i]);

		if(x+y!=0) {p=1;break;}

	}

	if(!p) puts("Yes");

	else puts("No");

	return 0;

}