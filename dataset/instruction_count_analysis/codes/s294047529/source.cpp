#include "stdc++.h"

typedef long long ll;

typedef double db;

#define pa pair<int,int>

#define mk make_pair

#define LOG(format, args...) fprintf(stderr, format, args)

using namespace std;

inline int rd() {

	int x=0,f=1;char ch=getchar();

	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;

	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';

	return x*f;

}

const int MAXN=5e5+100;

ll N,a[MAXN];

ll l[MAXN];

ll but[MAXN],idx[MAXN];

ll ans[MAXN];

//main========================

int main() {

	memset(idx,0x3f,sizeof idx);

	N=rd();

	for(int i=1;i<=N;++i) a[i]=rd(),l[++*l]=a[i];

	sort(l+1,l+*l+1);

	*l=unique(l+1,l+*l+1)-l-1;

	for(int i=1;i<=N;++i) a[i]=lower_bound(l+1,l+*l+1,a[i])-l;

	for(int i=1;i<=N;++i) but[a[i]]++,idx[a[i]]=min((ll)i,idx[a[i]]);

	for(int i=*l;i>=1;--i) if(but[i]) {

		but[i-1]+=but[i];

		idx[i-1]=min(idx[i],idx[i-1]);

		ans[idx[i]]+=(ll)(l[i]-(i>1?l[i-1]:0) )*but[i];

	} 

	for(int i=1;i<=N;++i) printf("%lld\n",ans[i]);

	return 0;

}
