#include "stdc++.h"

using namespace std;

typedef pair<int,int> P;

#define F first

#define S second

#define INF 400000

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

int n,q,s[200005];

P x[200005];

SEG d,p;

int main(void){

    scanf("%d",&n);

    for(int i=1;i<=n;i++){

		int a;

		scanf("%d",&a);

		if(a)s[i]--;

		else s[i]++;

		s[i]+=s[i-1];

	}

	scanf("%d",&q);

	for(int i=0;i<q;i++)scanf("%d%d",&x[i].F,&x[i].S);

	sort(x,x+q);

	d.up(0,(n-s[n])/2);

	p.up(0,(n-s[n])/2);

	for(int i=0;i<q;i++){

		int l=x[i].F,r=x[i].S;

		int o=min(s[r]-s[l-1]+d.que(0,l-1,0,(1<<18)-1,0),s[r]+p.que(l,r,0,(1<<18)-1,0));

		d.up(r,o);

		p.up(r,o-s[r]);

	}

	printf("%d\n",d.que(0,n,0,(1<<18)-1,0));

}
