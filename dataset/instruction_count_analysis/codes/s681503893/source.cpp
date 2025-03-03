#include "stdc++.h"

using namespace std;

typedef pair<int,int> P;

#define F first

#define S second

#define INF 1<<19

struct SEG{

	int seg[1<<19];

	SEG(void){for(int i=0;i<1<<19;i++)seg[i]=INF;}

	void up(int a,int x){

		a+=(1<<18)-1;

		seg[a]=min(seg[a],x);

		while(a>0){

			a=(a-1)/2;

			seg[a]=min(seg[a*2+1],seg[a*2+2]);

		}

	}

	int que(int a,int b,int l,int r,int k){

		if(r<a||b<l)return INF;

		if(a<=l&&r<=b)return seg[k];

		return min(que(a,b,l,(l+r-1)/2,k*2+1),que(a,b,(l+r+1)/2,r,k*2+2));

	}

};

int n,q,s[1<<18],l,r,a,o,dp[1<<18],d=INF,e;

P x[1<<18];

SEG p;

int main(void){

    scanf("%d",&n);

    for(int i=1;i<=n;i++){

		scanf("%d",&a);

		if(a)s[i]--;

		else s[i]++;

		s[i]+=s[i-1];

		dp[i]=INF;

	}

	scanf("%d",&q);

	for(int i=0;i<q;i++)scanf("%d%d",&x[i].F,&x[i].S);

	sort(x,x+q);

	p.up(0,(n-s[n])/2);

	dp[0]=(n-s[n])/2;

	for(int i=0;i<q;i++){

		l=x[i].F,r=x[i].S;

		while(e<l)d=min(d,dp[e++]);

		o=min(d+s[r]-s[l-1],s[r]+p.que(l,r,0,(1<<18)-1,0));

		p.up(r,o-s[r]);

		dp[r]=o;

	}

	while(e<=n)d=min(d,dp[e++]);

	printf("%d\n",d);

}
