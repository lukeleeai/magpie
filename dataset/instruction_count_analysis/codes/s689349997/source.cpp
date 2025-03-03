#include"stdc++.h"

#define reg register

using namespace std;

typedef long long ll;

const int MN=1e5+5;

int n,a[MN],c[MN][2];

int main(){

	scanf("%d",&n);

	for(reg int i=1;i<=n;i++)scanf("%d",a+i);

	for(reg int i=1;i<=n;i++)c[a[i]][i&1]++;

	reg int mx1=0,smx1=0,mx2=0,smx2=0;

	for(reg int i=1;i<=MN-5;i++){

		if(c[mx1][1]<c[i][1])smx1=mx1,mx1=i;

		else if(c[smx1][1]<c[i][1])smx1=i;

		if(c[mx2][0]<c[i][0])smx2=mx2,mx2=i;

		else if(c[smx2][0]<c[i][0])smx2=i;

	}

	reg int ans;

	if(mx1!=mx2)ans=n-c[mx1][1]-c[mx2][0];

	else ans=min(n-c[mx1][1]-c[smx2][0],n-c[smx1][1]-c[mx2][0]);

	printf("%d\n",ans);

	return 0;

}