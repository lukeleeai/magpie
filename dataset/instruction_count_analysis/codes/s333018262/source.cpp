#include"stdc++.h"

#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)

#define ll long long

using namespace std;

const int N=50;

int n;

char a[N][N];

ll f[N][N][N],s[N][N],ss,ans;

int main(){

	scanf("%d",&n);n*=2;

	fo(i,1,n)scanf("\n%s",a[i]+1),f[i][i][i]=1;

	for(int len=2;len<=n-2;len+=2)

		fo(l,2,n-len){

			int r=l+len;

			fo(j,l,r)fo(k,j,r)s[j][k]=0;

			fo(j,l,r){

				fo(q,j+1,r){

					ss=0;

					fo(k,q,r)if(a[j][k]=='1')ss+=f[q][r][k];

					fo(p,j,q)s[p][q]+=ss*f[l][p][j];

				}

			}

			fo(p,l,r)fo(q,p,r)

				fo(i,p+1,q-1)f[l][r][i]+=s[p][q]*f[p+1][q-1][i];

		}

	fo(i,2,n)if(a[1][i]=='1')ans+=f[2][n][i];

	cout<<ans;

}