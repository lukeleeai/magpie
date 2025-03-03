#include"stdc++.h"

#define ll long long

#define ull unsigned ll

#define uint unsigned

#define pii pair<int,int>

#define pll pair<ll,ll>

#define IT iterator

#define PB push_back

#define fi first

#define se second

#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)

#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)

#define CLR(a,v) memset(a,v,sizeof(a));

#define CPY(a,b) memcpy(a,b,sizeof(a));

#define debug puts("wzpakking")

#define y1 ysghysgsygsh

using namespace std;

const int N=5005;

int n,mo,a[N],f[N];

int main(){

	scanf("%d%d",&n,&mo);

	int T=(n-1)/2;

	For(i,1,T+1) a[i]=1;

	For(i,n-T+1,n) a[i]=-1;

	Rep(i,n,1) a[i]+=a[i+1];

	For(i,2,n) a[i]*=-1;

	sort(a+2,a+n+1);

	reverse(a+2,a+n+1);

	For(i,2,n) a[i]++;

	f[0]=1;

	For(i,2,n) For(k,0,n-a[i])

		f[k+a[i]]=(f[k+a[i]]+f[k])%mo;

	int ans=0;

	For(i,0,n)

		ans=(ans+1ll*(n-i)*f[i])%mo;

	printf("%d\n",ans); 

}

/*

5000 998244353

*/
