#include"stdc++.h"

using namespace std;

typedef long long ll;

const int N = 1e5+10;

int n;

struct node{

	int id,val;

}a[N],b[N];

bool cmp(const node &a,const node &b)

{

	return a.val<b.val;

}

bool cmp2(const node &a,const node &b)

{

	return a.id<b.id;

}

map<int,int>mp;

int main()

{

	cin>>n;

	for(int i=1;i<=n;i++)

	{

		cin>>a[i].val;

		a[i].id=i;

	}

	for(int i=1;i<=n;i++)

	{

		cin>>b[i].val;

		b[i].id=i;

	}

	sort(a+1,a+n+1,cmp);

	sort(b+1,b+n+1,cmp);

	for(int i=1;i<=n;i++)

	{

		if(b[i].val<a[i].val)

		{

			cout<<"No\n";

			return 0;

		}

	}

	for(int i=1;i<n;i++)

	{

		if(b[i].val>=a[i+1].val)

		{

			cout<<"Yes\n";

			return 0;

		}

	}

	for(int i=1;i<=n;i++)

	b[i].val=min(b[i].val,a[i].val);

	sort(a+1,a+n+1,cmp2);

	sort(b+1,b+n+1,cmp2);

	for(int i=1;i<=n;i++)

	mp[b[i].val]=i;

	int cnt=0;

	for(int i=1;i<=n;i++)

	{

		if(a[i].val==b[i].val)

		continue;

		int pos=mp[a[i].val];

		cnt++;

		swap(mp[b[i].val],mp[a[i].val]);

		swap(b[i].val,b[pos].val);

	}

	if(cnt>n-2)

	cout<<"No\n";

	else

	cout<<"Yes\n";

}