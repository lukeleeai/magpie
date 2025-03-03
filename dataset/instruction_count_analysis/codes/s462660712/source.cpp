#include"stdc++.h"

#define N 55

#define LL long long

#define int long long

using namespace std;

int n,d,x,alsz;

int co[N],fa[N],sz[N];

int w[N];

int bk[N*N*N*N];

inline void getans(int len,int cost,const int m=alsz*d){

	if(cost>x)return;

	for(int i=m;i>=len;--i)bk[i]=min(bk[i],bk[i-len]+cost);

}



inline void work1(int tal,const int m){

	memset(bk,0x3f,sizeof(int)*(m+1));

	bk[0]=0;

	for(int i=1;i<=n;++i){

		int al=tal;

		for(int j=0;(1<<j)<=al;++j){

			al-=1<<j;int len=(1<<j)*sz[i],cost=min(1ll+x,(1ll<<j)*co[i]);

			getans(len,cost,m);

		}

		int len=al*sz[i],cost=min(1ll+x,1ll*al*co[i]);

		getans(len,cost,m);

	}

}

int a[N];

inline bool cmp(const int &a,const int &b){

	return 1ll*sz[a]*co[b]>1ll*sz[b]*co[a];

}

inline void work2(){

	int m;

	if(d>n){d-=n;work1(n,m=alsz*n);}

	else {work1(d,m=alsz*d);d=0;}

	for(int i=1;i<=n;++i)a[i]=i;sort(a+1,a+n+1,cmp);

	int ans=0;

	for(int i=m,mi=x+1,j=1,sum=0,al=0;~i;--i){

		if(bk[i]>=mi||x-sum<bk[i])continue;

		mi=bk[i];

		while(a[j]>1&&x-sum-bk[i]>1ll*co[a[j]]*(a[j]==1?x:d)){

			al+=sz[a[j]]*d;

			sum+=co[a[j]]*d;

			++j;

		}

		ans=max(ans,(x-sum-bk[i])/co[a[j]]*sz[a[j]]+al+i);

	}

	cout<<ans<<endl;

}

main(){

	scanf("%lld%lld%lld",&n,&x,&d);

	scanf("%lld",&co[1]);

	for(int i=2;i<=n;++i)scanf("%lld%lld",&co[i],&fa[i]);

	for(int i=n;i;--i){

		++sz[i];

		sz[fa[i]]+=sz[i];co[fa[i]]+=co[i];

		co[fa[i]]=min(co[fa[i]],x+1);

		alsz+=sz[i];

	}

	work2();

	return 0;

}

/*

3 100 10

15

10 1

20 1



*/