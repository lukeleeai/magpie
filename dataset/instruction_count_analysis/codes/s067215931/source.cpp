#include<cstdio>

#include<algorithm>

#include<cmath>

#include<vector>

#include<cstring>

#define SF scanf

#define PF printf

#define MAXN 200010

#define INF 10000000000000000ll

using namespace std;

int n,k;

typedef long long ll;

ll tree[MAXN*4],f[MAXN],sum;

int a[MAXN],b[MAXN],l[MAXN],r[MAXN];

vector<int> val;

ll min1(ll x,ll y){

	if(x==0)

		return y;

	if(y==0)

		return x;

	return min(x,y);	

}

ll que(int l,int r,int id,int pos){

	if(l==r)

		return tree[id];

	int mid=(l+r)>>1;

	if(pos<=mid)

		return min1(tree[id],que(l,mid,id*2,pos));

	else

		return min1(tree[id],que(mid+1,r,id*2+1,pos));

}

void change(int l,int r,int id,int pl,int pr,int v){

	if(pl>pr)

		return ;

	if(l>=pl&&r<=pr){

		tree[id]=min1(tree[id],v);	

		return ;

	}

	int mid=(l+r)>>1;

	if(pl<=mid)

		change(l,mid,id*2,pl,pr,v);

	if(pr>mid)

		change(mid+1,r,id*2+1,pl,pr,v);

}

int main(){

	SF("%d%d",&n,&k);

	for(int i=1;i<=n;i++){

		SF("%d",&a[i]);

		SF("%d",&b[i]);

		if(b[i]==1&&2*a[i]>k){

			PF("-1");

			return 0;

		}

		sum+=a[i];

		a[i]=(a[i]+a[i-1])%k;

	}

	for(int i=1;i<=n;i++){

		if(b[i]==1){

			l[i]=2*(k-a[i-1])%k;

			r[i]=2*(k-a[i])%k;

		}

		else{

			l[i]=0;

			r[i]=k-1;	

		}

		val.push_back(l[i]);

		val.push_back(r[i]);

	}

	sort(val.begin(),val.end());

	int len=unique(val.begin(),val.end())-val.begin()-1;

	for(int i=1;i<=n;i++){

		//PF("{%d %d}\n",l[i],r[i]);

		r[i]=lower_bound(val.begin(),val.begin()+len,r[i])-val.begin();

		l[i]=lower_bound(val.begin(),val.begin()+len,l[i])-val.begin();	

		//PF("<%d %d>\n",l[i],r[i]);

	}

	for(int i=n;i>=1;i--){

		int res=que(0,len,1,l[i]);

		if(res==0)

			f[i]=0;	

		else

			f[i]=f[res]+(val[l[res]]-val[l[i]]+k)%k;

		if(l[i]<=r[i]){

			change(0,len,1,0,l[i]-1,i);

			change(0,len,1,r[i]+1,len,i);

		}

		else

			change(0,len,1,r[i]+1,l[i]-1,i);

	}

	ll ans=INF;

	for(int i=0;i<=len;i++){

		ll res=que(0,len,1,i);

		if(res)

			res=f[res]+(val[l[res]]-val[i]+k)%k;

		ans=min(ans,res);

	}

	PF("%lld",ans+2ll*sum);

}