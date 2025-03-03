/*

Though leaves are many, the root is one;

Through all the lying days of my youth

I swayed my leaves and flowers in the sun,

Now may I wither into the truth.



- William Butler Yeats

*/

#include <iostream>

#include <algorithm>

#include <math.h>

#include <string.h>

#include <cstdio>

#include <vector>

#include <set>

#include <cassert>

#include <cstdlib>

#include <complex>

#include <cctype>

#include <cmath>

#include <ctime>

#include <deque>

#include <queue>

#include <stack>

#include <map>

#include <set>

#include <sstream>

#include <functional>

#include <iomanip>

#include <bitset>

//#include <windows.h>  //Should be deleted when using AtCoder&POJ

using namespace std;



#define ll long long

#define pii pair<int,int>

#define qi ios::sync_with_stdio(0)

/**==Info==

*Program:6

*Problem:Distance Sums

*Date:2019-7-12

*Algorithm:Orange Boy's Greedy and Sorting

*Stats:WA*/



bool debug=false;





template<typename T1,typename T2> ostream& operator<<(ostream& o,pair<T1,T2> p){

	o<<"{";

	o<<p.first<<","<<p.second;

	o<<"}";

	return o;

}



ll n;

ll d[100005];

map <ll,ll> m;

pair<ll,ll> p[100005];

ll sub[100005];

ll sz[100005];

vector <pair<ll,ll> >res;

 

 int fa[100005];

 

int getFa(int x){

	if(fa[x]==x){

		return x;

	}

	return fa[x]=getFa(fa[x]);

}

 

 

void Union(int a,int b){

	if(fa[a]==fa[b]){

		return;

	}

	fa[getFa(a)]=getFa(b);

}



ll dp[100005];



ll dis[100005];



vector<int> nei[100005];



int main()

{

	ios_base::sync_with_stdio(false);

	cin>>n;

	for(ll i=0;i<n;i++)

	{

		cin>>d[i];

		if(d[i]>n*(n-1)/2){

			cout<<-1;

			return 0;

		}

		m[d[i]]=i;

		p[i].first=d[i];

		p[i].second=i;

		sz[i]=1;

	}

	sort(p,p+n);

	reverse(p,p+n);

	memset(sub,-1,sizeof(sub));

	for(ll i=0;i<n-1;i++)

	{

		ll de=p[i].first;

		ll x=p[i].second;

		sub[x]=n-sz[x]*2;

		if(sub[x]==0){

			cout<<-1;

			return 0;	

		}

		if(m.find(de-sub[x])==m.end()){

			cout<<-1;

			return 0;

		}

		ll par=m[de-sub[x]];

		sz[par]+=sz[x];

		dp[par]+=dp[x]+sz[x];

		res.push_back(make_pair(x,par));

	}

	

	for(int i=0;i<n-1;i++){

		nei[res[i].first].push_back(res[i].second);

		nei[res[i].second].push_back(res[i].first);

	}

	

	queue<int> q;

	memset(dis,-1,sizeof(dis));

	q.push(p[n-1].second);

	dis[p[n-1].second]=0;

	

	while(!q.empty()){

		int last=q.front();

		q.pop();

		

		for(int to:nei[last]){

			if(dis[to]==-1){

				dis[to]=dis[last]+1;

				q.push(to);

			}

		}

	}

	

	ll sm=0;

	for(int i=0;i<n;i++){

		sm+=dis[i];

	}

	if(sm!=p[n-1].first){

		cout<<-1;

		return 0;

	}

	

	for(ll i=0;i<n-1;i++)

	{

		cout<<res[i].first+1<<" "<<res[i].second+1<<endl;

	}

	

	

	return 0;

}