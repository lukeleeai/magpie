#include "stdc++.h"

#define rep(i,n)for(int i=0;i<(n);i++)

using namespace std;

typedef pair<int,int>P;



#define MAX 800000



P dat[MAX];

int N;



void init(int n){

	N=1;while(N<n)N<<=1;

}

void update(int k,P x){

	k+=N-1;

	dat[k]=x;

	while(k){

		k=(k-1)/2;

		dat[k]=min(dat[k*2+1],dat[k*2+2]);

	}

}

P query(int a,int b,int k,int l,int r){

	if(b<=l||r<=a)return P(INT_MAX,INT_MAX);

	if(a<=l&&r<=b)return  dat[k];

	return min(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));

}



int bit[300000];

void add(int k,int x){

	k++;

	while(k<300000){

		bit[k]+=x;

		k+=k&-k;

	}

}

int sum(int k){

	k++;

	int ans=0;

	while(k){

		ans+=bit[k];

		k-=k&-k;

	}

	return ans;

}

int main(){

	string s;int k;cin>>s>>k;

	rep(i,s.size()-1)add(i+1,1);

	init(s.size());

	rep(i,s.size())update(i,P(s[i],i));

	string ans;

	rep(i,s.size()){

		int l=1,r=s.size();

		while(l!=r){

			int t=(l+r)/2;

			if(r-l==1)t=r;

			if(sum(t-1)<=k)l=t;

			else r=t-1;

		}

		P p=query(0,l,0,0,N);

		ans+=p.first;

		k-=sum(p.second);

		add(p.second+1,-1);

		update(p.second,P(INT_MAX,i));

	}

	cout<<ans<<endl;

}