#include "stdc++.h"

using namespace std;

int n,m;

int f[100004],h[100004];

int F(int x){

	if(f[x]==x)return x;

	int pa=F(f[x]);

	h[x]+=h[f[x]],f[x]=pa;

	return f[x];

}

int main(){

	scanf("%d%d",&n,&m);

	for(int i=1;i<=n;i++)f[i]=i;

	for(int i=1;i<=m;i++){

		int L,R,D;scanf("%d%d%d",&L,&R,&D);

		int l=F(L),r=F(R);

		if(l==r){

			if(h[R]-h[L]!=D){

				puts("No");

				return 0;

			}

		}else{

			f[r]=l;

			h[r]=D+h[L]-h[R];

		}

	}

	puts("Yes");

}