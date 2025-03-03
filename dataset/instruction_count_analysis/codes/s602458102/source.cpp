#include<iostream>

#include<cstdio>

#include<algorithm>

#include<cstring>

#include<vector>

using namespace std;

const int maxn=300050;

int sum[maxn<<3],lazy[maxn<<3],l[maxn],r[maxn];

int n,M;

vector<int>q[maxn];

inline void push_down(int ID,int l,int r){

	int m=(l+r)>>1;

	sum[ID<<1]+=(m-l+1)*lazy[ID],sum[ID<<1|1]+=(r-m)*lazy[ID];

	lazy[ID<<1]+=lazy[ID],lazy[ID<<1|1]+=lazy[ID],lazy[ID]=0;

}

inline void ins(int ID,int l,int r,int L,int R){

	if(lazy[ID])push_down(ID,l,r);

	if(l>=L&&r<=R){

		sum[ID]+=(r-l+1);

		lazy[ID]++;

		return;

	}

	int m=(l+r)>>1;

	if(m>=L)ins(ID<<1,l,m,L,R);

	if(m<R)ins(ID<<1|1,m+1,r,L,R);

	sum[ID]=sum[ID<<1]+sum[ID<<1|1];

}

inline int query(int ID,int x,int l,int r){

	if(lazy[ID])push_down(ID,l,r);

	if(sum[ID]==0)return 0;

	if(l==r)return sum[ID];

	int m=(l+r)>>1;

	if(m>=x)return query(ID<<1,x,l,m);

	else return query(ID<<1|1,x,m+1,r);

}

int main(){

	scanf("%d%d",&n,&M);

	for(register int i=1;i<=n;i++){

		scanf("%d%d",&l[i],&r[i]);

		q[r[i]-l[i]+1].push_back(i);

	}

	int remain=n;

	for(register int i=1;i<=M;i++){

		int ans=remain;

		remain-=q[i].size();

		if(i!=1)

		for(register int j=1;j*i<=M;j++)ans+=query(1,i*j,1,300000);

		for(register int j=0;j<q[i].size();j++)ins(1,1,300000,l[q[i][j]],r[q[i][j]]);

		printf("%d\n",ans);

	}

}