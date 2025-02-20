//Bokan ga bokka--nn!!

//Daily Lunch Special Tanoshii !!

#include <cstdio>

#include <cstring>

#include <cstdlib>

#include <cmath>

#include <ctime>

#include <cassert>

#include <string>

#include <algorithm>

#include <vector>

#include <queue>

#include <stack>

#include <functional>

#include <iostream>

#include <map>

#include <set>

using namespace std;

typedef pair<int,int> P;

typedef pair<int,P> P1;

typedef pair<P,P> P2;

typedef long long ll;

#define pu push

#define pb push_back

#define mp make_pair

#define eps 1e-7

#define INF 2000000000

#define f first

#define s second

#define rep(i,x) for(int i=0;i<x;i++)

struct house

{

	int x,y;

	house(){}

	house(int x,int y):x(x),y(y){}

}h[100005];

struct comp_x

{

	bool operator()(const house& a, const house& b)const

	{

		if(a.x!=b.x) return a.x<b.x;

		return a.y<b.y;

	}

};

struct comp_y

{

	bool operator()(const house& a, const house& b)const

	{

		if(a.y!=b.y) return a.y<b.y;

		return a.x<b.x;

	}

};

int main()

{

	srand((unsigned int)time(NULL));

	int hh,w,n; scanf("%d %d",&hh,&w); scanf("%d",&n);

	for(int i=0;i<n;i++)

	{

		scanf("%d %d",&h[i].x,&h[i].y);

	}

	set<int>se1,se2;

	sort(h,h+n,comp_x());

	se1.insert(h[(n-2)/2].x);

	se1.insert(h[n/2].x);

	sort(h,h+n,comp_y());

	se2.insert(h[(n-2)/2].y);

	se2.insert(h[n/2].y);

	ll ret=1e15;int px=INF,py=INF;

	for(set<int>::iterator it=se1.begin();it!=se1.end();++it)

	{

		for(set<int>::iterator it2=se2.begin();it2!=se2.end();++it2)

		{

			int X=*it; int Y=*it2; //cout << X << " " << Y << endl;

			ll val=0,gen=0;

			for(int i=0;i<n;i++)

			{

				val+=2LL*(abs(h[i].x-X)+abs(h[i].y-Y));

				gen=max(gen,1LL*(abs(h[i].x-X)+abs(h[i].y-Y)));

			}

			if(ret>val-gen || (ret==val-gen && ((px>X)||(px==X&&py>Y))))

			{

				ret=val-gen;

				px=X;py=Y;

			}

		}

	}

	printf("%lld\n%d %d\n",ret,px,py);

}