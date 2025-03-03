// luogu-judger-enable-o2

#include <cstdio>

#include <cstring>

char s[110000];

int main(){

	scanf("%s",s);

	int l=strlen(s),ans=0;

	for(int i=0;i<l-1;++i)

		if(s[i]!=s[i+1]) ++ans;

	printf("%d\n",ans);

	return 0;

}