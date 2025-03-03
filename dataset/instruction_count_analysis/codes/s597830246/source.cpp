#include"stdc++.h"

#define sz(x) ((int)x.size())

#define pb push_back

#define ii pair<int,int>

#define ppb pop_back

#define orta ((bas+son)>>1)

#define st first

#define nd second

#define ll long long

#define N 200005

#define inf 1000000000

#define MOD 1000000007

#define LOG 20

#define EPS 0.000000001

#define M 305

using namespace std;



int to;

int n;

ll k;

int a[N];



ll cmp(ll val) {



	int ptr=to+1;

	ll cnt=0;

	for(int i=to;i>=1 && ptr<=n;i--) {

		while(val<0 && ptr<=n && abs((ll)a[i]*a[ptr])<abs(val))

			ptr++;

		cnt+=max(0,n-ptr+1);

	}

	return cnt;



}



ll in(int l,int r,ll val) {



	int ptr=r;

	ll cnt=0;

	for(int i=l;i<ptr;i++) {

		while(ptr>0 && (ll)a[i]*a[ptr]>val) 

			ptr--;

		cnt+=max(0,ptr-i);

	}

	return cnt;



}



ll cnt(ll val) {



	return in(1,to,val)+in(to+1,n,val)+cmp(val);



}



int main() {



	ios_base::sync_with_stdio(0);

	cin.tie(0);cout.tie(0);



	cin>>n>>k;

	for(int i=1;i<=n;i++) {

		cin>>a[i];

	}

	sort(a+1,a+1+n);

	for(to=1;to<=n;to++) 

		if(a[to]>=0)

			break ;

	reverse(a+1,a+to);

	to--;

	ll bas=-(ll)inf*inf;

	ll son=-bas;

	while(bas<=son) {	

		if(cnt(orta)>=k) 

			son=orta-1;

		else bas=orta+1;

	}

	cout<<bas;



}