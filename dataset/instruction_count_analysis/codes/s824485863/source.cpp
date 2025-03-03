#include"stdc++.h"

#define F(i,a,b) for(int i=a;i<=b;i++)

using namespace std;

typedef long long ll;

const int N=305;

ll sum;

int a[N][N],p[N][N];

int n;

int main() {

//	freopen("1.in","r",stdin);

	cin>>n;

	F(i,1,n) F(j,1,n) cin>>a[i][j],sum+=a[i][j];

	F(k,1,n) F(i,1,n) F(j,1,n) 

		if(a[i][k]+a[k][j]<a[i][j]){

			cout<<-1;return 0;

		}

	F(k,1,n) F(i,1,n) F(j,1,n) 

		if(a[i][k]+a[k][j]==a[i][j]&&i!=k&&k!=j&&i!=j)

			p[i][j]=1;

	F(i,1,n) F(j,1,n)

		if(p[i][j]) sum-=a[i][j];

	cout<<sum/2;

}