#include <stdio.h>

#include <iostream>

#include <cstdlib>

#include <cmath>

#include <cctype>

#include <string>

#include <cstring>

#include <algorithm>

#include <stack>

#include <queue>

#include <set>

#include <map>

#include <ctime>

#include <vector>

#include <fstream>

#include <list>

#include <iomanip>

#include <numeric>

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

#define ms(s) memset(s, 0, sizeof(s))

const int INF = 1e9;

inline int read(){

	int X = 0,w = 0 ;

	char ch = 0;

	while(!isdigit(ch)) {w |= ch == '-';ch = getchar();}

	while(isdigit(ch)) X = (X<<3) + (X<<1) + (ch ^ 48),ch = getchar();

	return w ? -X : X;

}

int n;

int m=1;

int a[800005];

int seg[2][800005];

int ans[200005];

struct node

{

	int a,b;

	int mint;

};

void update(int k)

{

	int odd;

	int pos=k;

	odd=k%2;

	k+=m-1;

	seg[odd][k]=pos;

	seg[(odd+1)%2][k]=INF;

	while(k>1)

	{

		k/=2;

		for(int i=0;i<2;i++)

		{

			if(seg[i][k*2]==INF and seg[i][k*2+1]!=INF)

			{

				seg[i][k]=seg[i][k*2+1];

			}

			else if(seg[i][k*2+1]==INF&&seg[i][k*2]!=INF)

			{

				seg[i][k]=seg[i][k*2];

			}

			else if(seg[i][k*2]!=INF&&seg[i][k*2+1]!=INF)

			{

				if(a[seg[i][k*2]]<a[seg[i][k*2+1]])

				{

					seg[i][k]=seg[i][k*2];

				}

				else

				{

					seg[i][k]=seg[i][k*2+1];

				}

			}

		}

	}

}

int query(int l,int r,int k,int l1,int r1)

{

	int odd=l%2;

	if(l<=l1 and r>=r1)

	{

		return seg[odd][k];

	}

	if(r<l1 or l>r1)

	{

		return INF;

	}

	else

	{

		int x=query(l,r,k*2,l1,(l1+r1)/2);

		int y=query(l,r,k*2+1,(l1+r1+1)/2,r1);

		if(x==INF and y!=INF)

		{

			return y;

		}

		else if(x!=INF and y==INF)

		{

			return x;

		}

		else if(x==INF and y==INF)

		{

			return INF;

		}

		else

		{

			if(a[x]<a[y])

			{

				return x;

			}

			else

			{

				return y;

			}

		}

	}

}

bool operator >(node x,node y)

{

	if(x.mint!=INF and y.mint!=INF)

	{

		return a[x.mint]>a[y.mint];

	}

	else if(x.mint==INF and y.mint!=INF)

	{

		return true;

	}

	else if(x.mint!=INF and y.mint==INF)

	{

		return false;

	}

	return true;

}

int main()

{

	cin>>n;

	for(int i=0;i<800000;i++)

	{

		a[i]=INF;

		seg[0][i]=INF;

		seg[1][i]=INF;

	}

	while(m<n)

	{

		m*=2;

	}

	for(int i=1;i<=n;i++)

	{

		cin>>a[i];

	}

	for(int i=1;i<=m;i++)

	{

		update(i);

	}

	priority_queue<node,vector<node>,greater<node> > pq;

	node init={1,n,query(1,n,1,1,m)};

	pq.push(init);

	int id=1;

	while(id<=n and !pq.empty())

	{

		node f=pq.top();

		pq.pop();

		ans[id++]=f.mint;

		int tmp=query(f.mint+1,f.b,1,1,m);

		node nx,dx={f.mint+1,f.b,tmp};

		if(f.a<f.mint-1)

		{

			tmp=query(f.a,f.mint-1,1,1,m);

			nx={f.a,f.mint-1,tmp};

			pq.push(nx);

		}

		ans[id++]=dx.mint;

		node sec,thir;

		if(dx.a<dx.mint-1)

		{

			tmp=query(dx.a,dx.mint-1,1,1,m);

			sec={dx.a,dx.mint-1,tmp};

			pq.push(sec);

		}

		if(dx.mint+1<dx.b)

		{

			tmp=query(dx.mint+1,dx.b,1,1,m);

			thir={dx.mint+1,dx.b,tmp};

			pq.push(thir);

		}

	}

	for(int i=1;i<=n;i++)

	{

		cout<<a[ans[i]]<<" ";

	}

	return 0;

}