#include<cstdio>

#include<cstring>

#include<algorithm>

#include<cmath>

#define SF scanf

#define PF printf

#define MAXN 200010

using namespace std;

typedef long long ll;

char s[MAXN];

ll ans,cnt[30];

int main(){

	SF("%s",s);

	int len=strlen(s);

	for(int i=0;i<len;i++){

		ans+=(i-cnt[s[i]-'a']);

		cnt[s[i]-'a']++;

	}

	PF("%lld",ans+1ll);

}