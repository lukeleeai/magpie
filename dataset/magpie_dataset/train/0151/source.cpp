#include"stdc++.h"

#include<algorithm>

#include<vector>

#include<queue>

using namespace std;

typedef long long ll;



int main(){

	int d,n,m,x[100000],c[10000];

	while(scanf("%d",&d),d){

		scanf("%d%d",&n,&m);

		x[0]=0;

		for(int i=1;i<n;i++) scanf("%d",&x[i]);

		for(int i=0;i<m;i++) scanf("%d",&c[i]);

		int p[100001];

		for(int i=0;i<n;i++) p[i]=x[i];

		p[n]=d;

		sort(p,p+n+1);

		int res=0;

		for(int i=0;i<m;i++){

			int *lb=lower_bound(p,p+n+1,c[i]);

			if(c[i]!=0) res+=min(lb[0]-c[i],c[i]-lb[-1]);

		}

		printf("%d\n",res);

	}

}