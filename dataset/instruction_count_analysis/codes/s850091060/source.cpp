#include"stdc++.h"

using namespace std;

int a[200010];

int main(){

	int n,k,m,l,sum=0,cot=0,x=1e7,y=-1;

	memset(a,0,sizeof(a));

	cin>>n>>k;

	for(int i=1;i<=n;i++){

		cin>>m;

		a[m]++;

		x=min(x,m);

		y=max(y,m);

	}

	if((y-x+1)<=k){

		cout<<0;

		return 0;

	}

	sort(a+x,a+y+1);

	while((y-x+1)>k){

		sum+=a[x];

		x++;

	}

	cout<<sum;

	return 0;

}