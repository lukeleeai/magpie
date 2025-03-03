#include<iostream>

#include<algorithm>

#define ios ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

using namespace std;

typedef long long ll;

int N;

const int maxn=2e6+10;

ll a[maxn],b[maxn];



int main()

{

	ios;

	cin>>N;

	int cnt=0;

	for(int i=1;i<=N;i++)

	{

		ll x,y;

		cin>>x>>y;

		a[cnt]=x+y;

		b[cnt++]=x-y;

	}

	sort(a,a+cnt);

	sort(b,b+cnt);

	ll maxsum=max(a[cnt-1]-a[0],b[cnt-1]-b[0]);

	cout<<maxsum<<"\n";

	return 0;

 } 