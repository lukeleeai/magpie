#include "stdc++.h"

#define rep(i,n)for(int i=0;i<(n);i++)

using namespace std;

typedef pair<int,int>P;



#ifndef MAX

#define MAX 800000

#endif



//Range Update Query+Range Minimum Query

template<class T>

class RUQ_RMQ {

public:

	int n;

	T dat[MAX], lazy[MAX], DEFAULT;

	bool(*cmp)(T, T);

	void init(int n_,

		bool(*c)(T, T) = [](int a, int b) {return a < b; }, T d = INT_MAX) {

		cmp = c;

		DEFAULT = d;

		n = 1; while (n < n_)n <<= 1;

		for (int i = 0; i < 2 * n - 1; i++) {

			dat[i] = lazy[i] = DEFAULT;

		}

	}

	inline void push(int k) {

		if (lazy[k] == DEFAULT)return;

		dat[k] = lazy[k];

		if (k < n - 1) {

			lazy[k * 2 + 1] = lazy[k];

			lazy[k * 2 + 2] = lazy[k];

		}

		lazy[k] = DEFAULT;

	}

	inline void update_node(int k) {

		if (cmp(dat[k * 2 + 1], dat[k * 2 + 2]))dat[k] = dat[k * 2 + 1];

		else dat[k] = dat[k * 2 + 2];

	}

	inline void update(int a, int b, T x, int k, int l, int r) {

		push(k);

		if (r <= a || b <= l)return;

		if (a <= l&&r <= b) {

			lazy[k] = x; push(k); return;

		}

		update(a, b, x, k * 2 + 1, l, (l + r) / 2);

		update(a, b, x, k * 2 + 2, (l + r) / 2, r);

		update_node(k);

	}

	inline T query(int a, int b, int k, int l, int r) {

		push(k);

		if (r <= a || b <= l)return DEFAULT;

		if (a <= l&&r <= b)return dat[k];

		T lb = query(a, b, k * 2 + 1, l, (l + r) / 2);

		T rb = query(a, b, k * 2 + 2, (l + r) / 2, r);

		update_node(k);

		if (cmp(lb, rb))return lb;

		return rb;

	}

	inline void update(int a, int b, T x) {

		update(a, b, x, 0, 0, n);

	}

	inline void update(int a, T x) {

		update(a, a + 1, x);

	}

	inline T query(int a, int b) {

		return query(a, b, 0, 0, n);

	}

	inline T query(int a) {

		return query(a, a + 1);

	}

};



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

RUQ_RMQ<P>tree;

int main(){

	string s;int k;cin>>s>>k;

	rep(i,s.size()-1)add(i+1,1);

	tree.init(s.size(),[](P a,P b){return a<b;},P(INT_MAX,INT_MAX));

	rep(i,s.size())tree.update(i,P(s[i],i));

	string ans;

	int a=k;

	rep(i,s.size()){

		int l=1,r=s.size();

		while(l!=r){

			int t=(l+r)/2;

			if(r-l==1)t=r;

			if(sum(t-1)<=k)l=t;

			else r=t-1;

		}

		P p=tree.query(0,l);

		ans+=p.first;

		k-=sum(p.second);

		a+=sum(p.second);

		add(p.second+1,-1);

		tree.update(p.second,P(INT_MAX,i));

		P pp=tree.query(p.second);

	}

	cout<<ans<<endl;

}