#include<cstdio>

#include<map>

#define maxn 100005

using namespace std;

int n,a[maxn],b[maxn],fa[maxn],siz[maxn],cnt,ans;

map<int,int> mp,val;

int find(int x)

{

	if(fa[x]==x) return x;

	return fa[x]=find(fa[x]);

}

int main()

{

	scanf("%d",&n);

	int x=0;

	for(int i=1;i<=n;i++)

	{

		scanf("%d",&a[i]);

		mp[a[i]]++; x^=a[i];

		if(!val[a[i]]) val[a[i]]=++cnt;

	}

	mp[x]++;

	for(int i=1;i<=n;i++)

	{

		scanf("%d",&b[i]);

		if(!mp[b[i]]) { printf("-1\n"); return 0; }

		mp[b[i]]--;

		if(!val[b[i]]) val[b[i]]=++cnt;

	}

	for(int i=1;i<=cnt;i++) fa[i]=i,siz[i]=1;

	for(int i=1;i<=n;i++)

		if(a[i]!=b[i])

		{

			int r1=find(val[a[i]]),r2=find(val[b[i]]);

			if(r1!=r2) fa[r1]=r2,siz[r2]+=siz[r1];

			ans++;

		}

	bool f=true;

	for(int i=1;i<=n;i++)

		if(a[i]!=b[i]) { f=false; break; }

	if(f) { printf("0\n"); return 0; }

	if(!val[x]) ans++;

	for(int i=1;i<=cnt;i++)

		if(find(i)==i&&siz[i]>1) ans++;

	printf("%d\n",ans-1);

}