#include<iostream>

#include<algorithm> 

using namespace std;

struct node

{

	long long v,nxt;

};

node edge[200001];

struct reads

{

	long long num,data;

	bool operator < (const reads &a)const

	{

		return data<a.data;

	}

};

reads t[100001];

long long n,m,a[100001],b[100001],head[100001],len,rt[100001],sz[100001],Mx[100001];

int find(int x)

{

	if (rt[x]==x)

		return x;

	return rt[x]=find(rt[x]);

}

void unionn(int x,int y)

{

	sz[find(y)]+=sz[find(x)];

	Mx[find(y)]=min(Mx[find(y)],max(Mx[find(x)],a[find(y)]-b[find(y)]-sz[find(x)]));

	rt[find(x)]=find(y);

	return;

}

void add(int x,int y)

{

	edge[++len].v=y;

	edge[len].nxt=head[x];

	head[x]=len;

	return;

}

int main()

{

	int x,y;

	cin>>n>>m;

	for (int i=1;i<=n;++i)

	{

		cin>>a[i]>>b[i];

		rt[i]=i;

		sz[i]=b[i];

		t[i].num=i;

		Mx[i]=max(a[i]-b[i],0ll);

		t[i].data=Mx[i];

	}

	for (int i=1;i<=m;++i)

	{

		cin>>x>>y;

		add(x,y);

		add(y,x);

	}

	sort(t+1,t+n+1);

	for (int i=1;i<=n;++i)

		for (int j=head[t[i].num];j>0;j=edge[j].nxt)

			if (a[t[i].num]>=a[edge[j].v]&&find(edge[j].v)!=find(t[i].num))

				unionn(edge[j].v,t[i].num);

	cout<<Mx[find(1)]+sz[find(1)]<<endl;

	return 0;

}