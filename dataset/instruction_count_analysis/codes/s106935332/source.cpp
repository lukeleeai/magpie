#include <cstdio>

#include <cstring>

#define ri register int

const int N=5e5+5;

char s[N]; 

int pnxt[N],snxt[N];

int main(){

	ri n,i,j,ans;

	scanf("%s",s+1);

	n=strlen(s+1);

	for(i=2;i<=n;++i){

		j=pnxt[i-1];

		while(j&&s[j+1]!=s[i]) j=pnxt[j];

		if(s[j+1]==s[i]) pnxt[i]=j+1;

	}

	if(!pnxt[n]||n%(n-pnxt[n])) // 不是循环串

		return puts("1\n1"),0;

	else if(pnxt[n]==n-1) // 所有字母都相等

		return printf("%d\n1\n",n),0; 

	snxt[n]=n+1;

	for(i=n-1;i;--i){

		j=snxt[i+1];

		while(j!=n+1&&s[j-1]!=s[i]) j=snxt[j];

		if(s[j-1]==s[i]) snxt[i]=j-1;

		else snxt[i]=n+1;

	}

	ans=0;

	for(i=1;i^n;++i)

		if((!pnxt[i]||i%(i-pnxt[i]))&&(snxt[i+1]==n+1||(n-i)%(n-i-(n-snxt[i+1]+1)))) ++ans;

	printf("2\n%d\n",ans);

	return 0;

}