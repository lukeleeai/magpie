#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;

const int p=998244353;

typedef unsigned long long ull;

int n,len,mx;

long long l,r,siz[110],cnt1[110],cnt2[110],ans[26],sum[110][26];

ull fhash[200010],bhash[200010],bs[200010];

char s[200010];

void solve(long long m,int type){

	for(int i=mx;~i;i--){

		if(m>=siz[i]){

			for(int j=0;j<26;j++)

				ans[j]+=type?sum[i][j]:-sum[i][j];

			m-=siz[i];

		}

	}

	for(int i=1;i<=m;i++)

		ans[s[i]-'a']+=type?1:-1;

	return;

}

int main(){

	scanf("%s%lld%lld",s+1,&l,&r);

	n=strlen(s+1);

	bs[0]=1;

	for(int i=1;i<=n;i++){

		fhash[i]=fhash[i-1]*p+(s[i]-'a'+1);

		bs[i]=bs[i-1]*p;

	}

	for(int i=n;~i;i--)

		bhash[i]=bhash[i+1]+(s[i]-'a'+1)*bs[n-i];

	for(int i=n/2-1;~i;i--)

		if(fhash[i]==bhash[n-i+1]){

			len=i;

			break;

		}

	for(int i=1;i<=n/2;i++)

		sum[0][s[i]-'a']++;

	for(int i=0;i<26;i++)

		sum[1][i]=sum[0][i];

	for(int i=1;i<=n/2-len;i++)

		sum[1][s[i]-'a']++;

	siz[0]=n/2;

	siz[1]=n-len;

	for(int i=2;i<=100;i++){

		for(int j=0;j<26;j++)

			sum[i][j]=sum[i-1][j]+sum[i-2][j];

		siz[i]=siz[i-1]+siz[i-2];

		if(siz[i]>1e18){

			mx=i;

			break;

		}

	}

	solve(l-1,0);

	solve(r,1);

	for(int i=0;i<26;i++)

		printf("%lld ",ans[i]);

	return 0;

}