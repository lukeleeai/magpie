#include<cstdio>

#include<cstring>

#include<iostream>

#include<queue>

#include<vector>

using namespace std;

struct node

{

    long long v,tag;

}tree[1000000*4+1];

void build(int node,int l,int r)

{

    if(l==r)

    {

        tree[node].v=l;

        return;

    }

    build(node*2,l,(l+r)/2);

    build(node*2+1,(l+r)/2+1,r);

    tree[node].v=max(tree[node*2].v,tree[node*2+1].v);

}

void pushdown(int node,int l,int r)

{

    if(tree[node].tag)

    {

        tree[node*2].v+=tree[node].tag;

        tree[node*2+1].v+=tree[node].tag;

        tree[node*2].tag+=tree[node].tag;

        tree[node*2+1].tag+=tree[node].tag;

        tree[node].tag=0;

    }

}

long long query(int node,int st,int ed,int l,int r)

{

    if(st>r||ed<l)

        return -1;

    if(st>=l&&ed<=r)

        return tree[node].v;

    pushdown(node,st,ed);

    return max(query(node*2,st,(st+ed)/2,l,r),query(node*2+1,(st+ed)/2+1,ed,l,r));

}

void update(int node,int st,int ed,int l,int r,int ind)

{

    if(st>r||ed<l)

        return;

    if(st>=l&&ed<=r)

    {

        tree[node].v+=ind;

        tree[node].tag+=ind;

        return;

    }

    pushdown(node,st,ed);

    update(node*2,st,(st+ed)/2,l,r,ind);

    update(node*2+1,(st+ed)/2+1,ed,l,r,ind);

    tree[node].v=max(tree[node*2].v,tree[node*2+1].v);

}

vector<int> p[200001];

int main()

{

    long long n,m; 

    cin>>n>>m;

    for(int i=1;i<=n;i++)

	{

		int l,r;

		scanf("%d%d",&l,&r);

		p[l].push_back(r);

    }

	long long ans=n-m;

    build(1,1,m+1);

	for(int i=0;i<=m;i++)

	{

		for(int j=0;j<p[i].size();j++)

		{

			int right=p[i][j];

			update(1,1,m+1,1,right,1);

		}

		ans=max(ans,query(1,1,m+1,i+1,m+1)-m-i-1);

	}

	printf("%lld",ans);

    return 0;

}