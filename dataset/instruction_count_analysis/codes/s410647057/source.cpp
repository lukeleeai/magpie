#include "stdc++.h"

using namespace std;

int pr[30002],n,i,vis[30002];

int main(){

	

	vector <int> v;

	int sum=0;

	cin>>n;

	if(n==3){

		cout<<"2 5 63"<<endl;

		return 0;

	}

	for(i=30000;i>=2;i=i-2){

		if(n>2){

			v.push_back(i);

			vis[i]=1;

			n--;

			sum+=i;

			if(i==8 && n%2==0 && sum%3==0)

			break;

			if(i==6 && n%2==0 && sum%3==0)

			break;

			if(i==4 && n%2==0 && sum%3==0)

			break;

		}

		else

		break;

	}

	int j=3;

	while(n){

		if(sum%j==0 && vis[j]==0){

			for(i=j;i<30000 && n!=0 ;i=i+j)

				if(vis[i]==0 && i%2==1){

					v.push_back(i);

					vis[i]=1;

					n--;

					sum+=i;

				}

		}

		j=j+2;

	}

	for(i=0;i<v.size();i++)

		cout<<v[i]<<endl;

}