#include"stdc++.h"

#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)

#define ll long long

using namespace std;

const int N=50;

int n;

char a[N][N];

ll f[N][N][N],ans;

ll calc(int l,int i,int r){

	if(l==r)return 1;

	if(l==i||i==r)return 0;

	if(f[l][i][r]!=-1)return f[l][i][r];

	ll tot=0;

	fo(j,l,i-1)

		fo(p,j,i-1)

			fo(q,i+1,r)

				fo(k,q,r)

					if(a[j][k]=='1')

						tot+=calc(l,j,p)*calc(q,k,r)*calc(p+1,i,q-1);

	return f[l][i][r]=tot;

}

int main(){

	scanf("%d",&n);n*=2;

	fo(i,1,n)scanf("\n%s",a[i]+1);

	memset(f,255,sizeof f);

	fo(i,2,n)if(a[1][i]=='1')ans+=calc(2,i,n);

	cout<<ans;

}