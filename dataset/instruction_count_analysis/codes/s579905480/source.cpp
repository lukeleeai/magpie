#include<cstdio>

#include<iostream>

#include<algorithm>

#include<cstring>

#include<cmath>



using namespace std;



typedef long long ll;

const ll mod=1e9+7;

const ll MAXN=1e5+10;

const ll INF=0x7fffffff;



int a[MAXN],n;



void swp(int x,int y){

	int t=a[x];

	a[x]=a[y];

	a[y]=t;

}

//

//void print(){

//	for(int i=1;i<=n;i++){

//		cout<<a[i]<<" ";

//	}

//	cout<<endl;

//} 



int main()//所有的循环已改正 

{

	cin>>n;

	for(int i=1;i<=n;i++){

		scanf("%d",&a[i]);

	}

	int ans=0;

	for(int i=1;i<=n;i++){

		if(a[i]==i){

			swp(i,i+1);

			ans++;

//			print();

		}

	}

	cout<<ans<<endl;

	return 0;

}	 
