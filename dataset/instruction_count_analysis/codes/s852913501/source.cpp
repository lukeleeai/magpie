#include<algorithm>

#include<cstdio>

#include<cstring>

#include<iostream>

#include<vector>

#define debug(...) fprintf(stderr,__VA_ARGS__)

using namespace std;

const int mod=1e9+7;

const int maxn=1e5+50;

int n;

int f[maxn];

int nex[maxn];

int sum[maxn];

char s[maxn];

vector<int> pos[3];

inline int add(int x)

{

	return x>=mod?x-mod:x;

}

inline int idx(char c)

{

	return c=='a'?1:2;

}

int solve()

{

	bool flag=true;

	for(int i=1;i<n;++i)

	{

		if(s[i]==s[i+1])

		{

			flag=false;

			break;

		}

	}

	if(flag)

	{

		return 1;

	}

	for(int i=1;i<=n;++i)

	{

		sum[i]=(sum[i-1]+idx(s[i]))%3;

		pos[sum[i]].push_back(i);

	}

	nex[n]=n+1;

	for(int i=n-1;i>=0;--i)

	{

		nex[i]=s[i]==s[i+1]?i+1:nex[i+1];

	}

	f[0]=1;

	for(int i=0;i<n;++i)

	{

		f[i+1]=add(f[i+1]+f[i]);

		int c=idx('a'+'b'-s[i+1]);

		const vector<int> &v=pos[(sum[i]+c)%3];

		int p=lower_bound(v.begin(),v.end(),nex[i])-v.begin();

		if(p!=int(v.size()))

		{

			f[v[p]]=add(f[v[p]]+f[i]);

		}

	}

	int an=0;

	for(int i=1;i<=n;++i)

	{

		if(sum[i]==sum[n])

		{

			an=add(an+f[i]);

		}

	}

	return an;

}

int main()

{

	scanf("%s",s+1);

	n=strlen(s+1);

	printf("%d\n",solve());

	return 0;

} 