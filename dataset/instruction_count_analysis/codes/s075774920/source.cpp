#include<iostream>

#include<cstdio>

#include<cstring>

#include<algorithm>

#define MAXN (101010)

#define LL long long

using namespace std;

int n; 

struct Node{

	LL p,v;

	bool operator < (const Node &a)const{

		return p<a.p;

	}

	void Read(){

		scanf("%lld %lld",&p,&v);

	}

}T[MAXN];

LL C,A1[MAXN],A2[MAXN],B1[MAXN],B2[MAXN],p[MAXN],v[MAXN];

LL Max(LL a,LL b){

	if (a>b) return a;

	return b;

}

int main(){

	scanf("%d %lld",&n,&C);

	int i;

	LL ans=0;

	for (i=1;i<=n;i++) 

		T[i].Read();

	sort(T+1,T+n+1);

	for (i=1;i<=n;i++) p[i]=T[i].p,v[i]=T[i].v;

	p[n+1]=C;

	for (i=1;i<=n;i++){

		A1[i]=A1[i-1]+v[i]-(p[i]-p[i-1]);

		ans=Max(A1[i],ans);

		B1[i]=A1[i]-p[i];

		if (i>1) B1[i]=Max(B1[i],B1[i-1]);

	}

	for (i=n;i>=1;i--){

		A2[i]=A2[i+1]+v[i]-(p[i+1]-p[i]);

		ans=Max(ans,A2[i]);

		B2[i]=A2[i]-(C-p[i]);

		if (i<n) B2[i]=Max(B2[i],B2[i+1]);

	}

	for (i=1;i<n;i++) ans=Max(ans,A1[i]+B2[i+1]);

	for (i=2;i<=n;i++) ans=Max(ans,A2[i]+B1[i-1]);

	cout<<ans;

	

}