#include"stdc++.h"

#define x first



using namespace std;



typedef long long ll;

typedef pair<int,int> pii;

typedef pair<int,pii> pip; 



struct node

{

	int num,l,r,ls,rs;

	node(int _l,int _r)

	{

		num=0;

		l=_l;

		r=_r;

	}

};



vector<node> T;

vector<ll> d;



int make(int l,int r)

{

	int id=T.size();

	T.push_back(node(l,r));

	T[id].ls=(l+1==r?-1:make(l,(l+r)/2));

	T[id].rs=(l+1==r?-1:make((l+r)/2,r));

	return id;

}



void update(int id,int l,int r,int t)

{

	if(l==r||T[id].l>=r||T[id].r<=l)

		return ;

	if(T[id].l>=l&&T[id].r<=r)

	{

		T[id].num+=t;

		return ;

	}

	int mid=(T[id].l+T[id].r)>>1;

	if(l<mid)

		update(T[id].ls,l,r,t);

	if(r>mid)

		update(T[id].rs,l,r,t);

	int mi=min(T[T[id].ls].num,T[T[id].rs].num);

	T[id].num+=mi;

	T[T[id].ls].num-=mi;

	T[T[id].rs].num-=mi;

}



ll gettot(int id)

{

	if(id==-1) return 0; 

	if(T[id].num>0)

		return d[T[id].r]-d[T[id].l];

	return gettot(T[id].ls)+gettot(T[id].rs);

}



int main()

{

	T.reserve(50000);

	int n;

	scanf("%d",&n);

	set<int> s;

	priority_queue<pip,vector<pip>,greater<pip> > pq; 

	for(int i=0;i<n;i++)

	{

		int x1,y1,x2,y2;

		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

		s.insert(y1);s.insert(y2);

		pq.push(make_pair(x1,make_pair(y1,y2)));

		pq.push(make_pair(x2,make_pair(y2,y1)));

	}

	map<int,int> y;

	d.clear();

	for(set<int>::iterator it=s.begin();it!=s.end();it++)

	{

		y[*it]=d.size();

		d.push_back(*it);

	}

	make(0,d.size()-1);

	ll ans=0;

	while(true)

	{

		pip t=pq.top();pq.pop();

		if(pq.empty()) break;

		if(t.second.first<t.second.second)

			update(0,y[t.second.first],y[t.second.second],1);

		else

			update(0,y[t.second.second],y[t.second.first],-1);

		ans+=gettot(0)*(pq.top().x-t.x);

	}

	printf("%lld\n",ans);

	return 0;

}