#include"stdc++.h"

using namespace std;



typedef long long LL;



const int N=2e5+10;



pair<LL,LL>A[N];

LL f[N][3];



int cmp(pair<LL,LL>a,pair<LL,LL>b)

{

	if(a.first==b.first) return a.second<b.second;

	return a.first<b.first;

}

	



int n;

LL Ans;





int main()

{

	cin>>n;

	for(int i=1;i<=n;i++)

	{

		LL x,y;

		scanf("%lld%lld",&x,&y);

		if(x>y) swap(x,y);

		A[i]=make_pair(x,y);

	}

	sort(A+1,A+n+1,cmp);

	Ans=1e18;

	for(int i=1;i<=n;i++) f[i][0]=max(f[i-1][0],A[i].second);

	for(int i=n;i;i--) f[i][1]=max(f[i+1][1],A[i].second);

	f[0][2]=1e18;

	for(int i=1;i<=n;i++) f[i][2]=min(f[i-1][2],A[i].second);

	LL R1,R2,B1,B2;

	R1=A[n].first,R2=A[1].first,B1=0,B2=1e9;

	for(int i=1;i<=n;i++) B1=max(B1,A[i].second),B2=min(B2,A[i].second);

	Ans=(R1-R2)*(B1-B2);

	for(int i=1;i<n;i++)

	{

		R1=max(R1,A[i].second);

		R2=min(A[i+1].first,f[i][2]);

		B1=f[i+1][1];

		B2=A[1].first;

		if(R2<=f[i][0]) Ans=min(Ans,(R1-R2)*(B1-B2));

	}			

	cout<<Ans<<endl;

}

	

	

	