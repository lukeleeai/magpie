#include <vector>

#include <algorithm>

#include <set>

#include <map>

#include <queue>

#include <stack>

#include <iostream>

#include <cstdio>

#include <cmath>

#include <cstring>

using namespace std;

typedef long long ll;

typedef pair<ll,ll> P;

typedef double db;



#define fr first

#define sc second

#define pb push_back

#define rep(i,x) for(ll i=0;i<x;i++)

#define rep1(i,x) for(ll i=1;i<=x;i++)

#define rrep(i,x) for(ll i=x-1;i>=0;i--)

#define rrep1(i,x) for(ll i=x;i>0;i--)



ll n,l;

ll a[100000];

bool fallen[100000];

bool ko[100000];

priority_queue<P,vector<P>,greater<P> > q;

ll now=0;

void jud(ll x){

	if(x<0||n<=x||fallen[x]) return;

	if((x-1>0&&!ko[x-1]&&a[x-1]<a[x])||(x+1<n&&!ko[x+1]&&a[x+1]<a[x])) return;

	q.push(P(a[x]+now,x));

	fallen[x]=1;

	return;

}

int main()

{

	cin>>n>>l;

	rep(i,n){

		cin>>a[i];

		a[i]=l-a[i];

	}

	

	if(n>1&&a[0]<a[1]){

		q.push(P(a[0],0));

		fallen[0]=1;

	}

	if(n>2&&a[n-2]>a[n-1]){

		q.push(P(a[n-1],n-1));

		fallen[n-1]=1;

	}

	rep1(i,n-2){

		if(a[i-1]>a[i]&&a[i]<a[i+1]){

			q.push(P(a[i],i));

			fallen[i]=1;

		}

	}

	while(!q.empty()){

		P next=q.top();

		q.pop();

		//cout<<now<<endl;

		now=next.fr;

		ko[next.sc]=1;

		jud(next.sc-1);

		jud(next.sc+1);

	}

	cout<<now<<endl;

}