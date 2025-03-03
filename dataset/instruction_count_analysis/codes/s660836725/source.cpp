#include<iostream>

#include<cmath>

#include<algorithm>

#include<cstdio>

#include<stack>

#include<queue>

#include<map>

#include<cstring>



using namespace std;



const int MAX=1e5+10;



int a[MAX];

int p[MAX];



long long mod_exp(int b){

	long long res,t;

	res=1;

	t=2;

	while(b){

		if(b&1){

			res=res*t%1000000007;

		}

		t=t*t%1000000007;

		b>>=1;

	}

	return res;

}



int main(){

	int n;

	cin>>n;

	memset(p,0,sizeof(p));

	for(int i=0;i<n;i++){

		scanf("%d",&a[i]);

		p[a[i]]++;

	}

	int cnt=0;

	bool flag=true;

	for(int i=0;i<n;i++){

		if((n+a[i]+1)%2!=0||(n-a[i]+1)%2!=0||(p[0]!=1&&n%2==1)||(p[a[i]]!=2&&a[i]!=0)){

			cout<<"0"<<endl;

			flag=false;

			break;

		}

		if(p[i]==2)

		cnt++;

	}

	if(flag)

	cout<<mod_exp(cnt)<<endl;

	return 0;

}