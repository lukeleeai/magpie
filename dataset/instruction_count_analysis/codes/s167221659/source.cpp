#include"stdc++.h"

using namespace std;

int p[100010],sum[100010]; 

int main(){

	p[1] = 1;

	p[2] = 0;

	for (int i=2;i<=100000;i++){

		for(int j=i*2;j<=100000;j=i+j){

			p[j]=1;

		}

	}

	sum[2]=1;

	for (int i=1;i<=100000;i++){

		if (p[i]==0&&p[(i+1)/2]==0){

			sum[i] = sum[i-1]+1;

		}

		else

		    sum[i]=sum[i-1];

	}

	int T;

	cin>>T;

	while (T--){

		int n,m;

		cin>>n>>m;

		cout<<sum[m]-sum[n-1]<<endl;

	} 

	return 0;

} 