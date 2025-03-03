#include<cstdio>

#include<algorithm>

#include<cstring>

using namespace std;

#define MAXN 200010

#define LL long long

char s[MAXN];

int cnt[30];

LL ans;

int main()

{

	scanf("%s",s);

	int n=strlen(s);

	for(int i=0;i<n;i++)

		cnt[s[i]-'a']++;

	ans=1LL*n*(n-1)/2;

	for(int i=0;i<26;i++)

		if(cnt[i]>1)

			ans-=1LL*cnt[i]*(cnt[i]-1)/2;

	ans++;

	printf("%lld\n",ans);

}