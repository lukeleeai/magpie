#include <cstdio>

#include <algorithm>



const int maxn=1e5+5;

#define int long long

int n,m,v,p,last,a[maxn];



inline bool cmp(int a,int b){

	return a>b;

}



inline int max(int a,int b){

	return a>b?a:b;

}



inline bool check(int x){

	if(x<=p) return true;

	if(a[x]+m<a[p]) return false;

	int now=m*(p-1+n-x+1);

	for(int i=p+1;i<x;i++){

		now+=a[x]+m-a[i];

	}now+=a[x]+m-a[p];

	return now>=m*v;

}



signed main(){

	scanf("%lld%lld%lld%lld",&n,&m,&v,&p);

	for(int i=1;i<=n;i++){scanf("%lld",&a[i]);}

	std::sort(a+1,a+n+1,cmp);

	int l=1,r=n,mid,pos=p;

	while(l<=r){

		mid=(l+r)>>1;

		if(check(mid)){

			l=mid+1;

			pos=mid;

		}else r=mid-1;

	}

	printf("%lld\n",pos);

	return 0;

}