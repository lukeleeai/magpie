#include"stdc++.h"

using namespace std;



int main(){

	int a,b;double cnt=0;

	cin>>a>>b;

	for(int i=1;i<=a;i++){

		double tot=1.0/a;int now=i;

		while(now<b){

			now*=2;//翻倍 

			tot/=2;//几率减半 

		}

		cnt+=tot;

	}

	cout<<fixed<<setprecision(12)<<cnt<<endl;

	return 0;

}


