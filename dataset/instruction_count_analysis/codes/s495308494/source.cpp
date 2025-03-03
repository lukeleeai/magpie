#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;

#define MAXN 200010

#define Abs(a) a>0?a:-a

char s[MAXN];

int n,ls,ans;

int main()

{

	scanf("%s",s);

	int n=strlen(s);

	for(int i=0;i<n;i++)

		if(ls==0&&s[i]=='T')

			ans++;

		else if(s[i]=='T')

			ls++;

		else if(s[i]=='S')

			ls--;

	ans+=Abs(ls);

	printf("%d\n",ans);

}
