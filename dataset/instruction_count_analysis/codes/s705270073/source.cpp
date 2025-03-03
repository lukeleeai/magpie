#include"stdc++.h"

using namespace std;

int cmp(int x,int y){

	return x>y;

}

int main(){

	int n,a[100005],i;

	long long ansc=0,ansk=0;

	bool use[100005]={0};

	cin>>n;

	for(i=1;i<=n;i++)

		cin>>a[i];

	sort(a+1,a+1+n,cmp);

	for(i=1;i<=n;i++){

		if(a[i]==a[i-1]&&use[i-1]==0){

			if(ansc!=0){

				ansk=a[i];

				cout<<ansc*ansk;

				return 0;

			}

			else {

				use[i-1]=1;

				use[i]=1;

				ansc=a[i];

			}

		}

	}

	cout<<ansk*ansc;

	return 0;

}