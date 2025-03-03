//A,Elebereth Gilthoniel mantae!

//For Temeria!

#include<iostream>

#include<algorithm>

#include<cmath>

#include<string>

#include<vector>

#include<set>

#include<cstdio>

#include<map>

#include<stack>

#include<queue>

#include<cstring> 

using namespace std;

unsigned long long sum[105];unsigned long long pa[105];unsigned long long cnt[105];

unsigned long long dep[105];unsigned long long opd[105];

vector<unsigned long long> v[105];

void ini()

{

	for(unsigned long long i=0;i<102;i++) sum[i]=pa[i]=dep[i]=0,opd[i]=0;;

}

void dfs(unsigned long long x)

{

	sum[x]=1;

	for(unsigned long long i=0;i<v[x].size();i++)

	{

		unsigned long long t=v[x][i];

		if(t==pa[x]) continue;

		dep[t]=dep[x]+1,pa[t]=x;dfs(t);sum[x]+=sum[t];

	}

}

int main()

{

	unsigned long long n;cin>>n;

	for(unsigned long long i=0;i<n-1;i++)

	{

		unsigned long long a,b;cin>>a>>b;

		v[a].push_back(b),v[b].push_back(a);

	}

	unsigned long long ro=1;

	ini();dfs(1);

	for(unsigned long long i=0;i<=n;i++)

	{

		if(dep[i]>dep[ro]) ro=i;

	}

	ini();dfs(ro);unsigned long long diam=0;

	for(unsigned long long i=1;i<=n;i++)

	{

		diam=max(diam,dep[i]);

	}diam++;

	cout<<(diam+1)/2<<" ";

	

	

	

	

	if(diam%2==0)

	{

	

		unsigned long long ans=1;

		

		vector<unsigned long long> er;unsigned long long op,opd=0;;vector<unsigned long long> sig;

		//	cout<<er[654654];

	//	if(n>3) cout<<er[465654];

		for(unsigned long long i=1;i<=n;i++) if(dep[i]==(diam-2)/2) er.push_back(i),sig.push_back(0);

		for(unsigned long long i=1;i<=n;i++)if(dep[i]==diam/2)er.push_back(i),sig.push_back(2);

		

		for(unsigned long long i=1;i<=n;i++) if(dep[i]>opd) opd=dep[i],op=i;

		ini();dfs(op);vector<unsigned long long> re;

		for(unsigned long long i=0;i<er.size();i++)

		{

			if(dep[er[i]]==((diam)/2-sig[i]/2))

			{

				re.push_back(er[i]);

			}

		}

		unsigned long long a=re[0],b=re[1];//cout<<a<<b;

		ini();pa[a]=b;

		dfs(a); 

		pa[b]=a;

		dfs(b);

		for(unsigned long long i=0;i<=n;i++) cnt[i]=0;

		for(unsigned long long i=1;i<=n;i++)

		{

			unsigned long long t=v[i].size();

			cnt[dep[i]]=max(cnt[dep[i]],t-1);

		}

	//	cnt[0]++;

		for(unsigned long long i=0;i<=n;i++)

		{

			if(cnt[i]==0) break;

			ans*=cnt[i];//cout<<cnt[i]<<" ";

		}

		ans*=2;

		cout<<ans;

	}

	

	

	

	else

	{

		unsigned long long ans=1;vector<unsigned long long> er;unsigned long long op,opd=0;;

		for(unsigned long long i=1;i<=n;i++) if(dep[i]==diam/2) er.push_back(i);

		for(unsigned long long i=1;i<=n;i++) if(dep[i]>opd) opd=dep[i],op=i;

		ini();dfs(op);vector<unsigned long long> re;

		for(unsigned long long i=0;i<er.size();i++)

		{

			if(dep[er[i]]==(diam)/2)

			{

				re.push_back(er[i]);

			}

		}

		unsigned long long a=re[0];

		ini();dfs(a);

		for(unsigned long long i=0;i<=n;i++) cnt[i]=0;

		for(unsigned long long i=1;i<=n;i++)

		{

			unsigned long long t=v[i].size();

			cnt[dep[i]]=max(cnt[dep[i]],t-1);

		}

		cnt[0]++;

		for(unsigned long long i=0;i<=n;i++)

		{

			if(cnt[i]==0) break;

			ans*=cnt[i];//cout<<cnt[i]<<" ";

		}

		

		

		

		for(unsigned long long ii=0;ii<v[a].size();ii++)

		{

			unsigned long long sum=2;

			unsigned long long b=v[a][ii];

			ini();pa[a]=b;

			dfs(a); 

			pa[b]=a;

			dfs(b);

			for(unsigned long long i=0;i<=n;i++) cnt[i]=0;

			for(unsigned long long i=1;i<=n;i++)

			{

				unsigned long long t=v[i].size();

		

				cnt[dep[i]]=max(cnt[dep[i]],t-1);

			}

			

			for(unsigned long long i=0;i<=n;i++)

			{

				if(cnt[i]==0) break;

				sum*=cnt[i];

			}

			ans=min(ans,sum);

		}

		cout<<ans;

	}

	return 0;

}