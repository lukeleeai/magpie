#include<iostream>

#include<cstring>

#include<algorithm>

using namespace std;

int f[1000000];

int main(){

//	freopen("j.txt","r",stdin);

	int n;

	cin>>n;

	memset(f,0,sizeof(f));

	for (int i=1;i<=n;i++)

		cin>>f[i];

	sort(f+1,f+1+n);

	int flag=0,max1=0,max2=0;

	for (int i=n-1;i>=1;i--)

		if (f[i]==f[i+1] && !flag){

			max1=f[i];

			flag=1;

		} else if (f[i]==f[i+1] && flag){

			if (f[i]==f[i-1] && f[i]==max1) {

				max2=f[i];

				break;

			}

				else if (f[i]!=max1){

					max2=f[i];

					break;

				} 

		}

    long long s;

	s=(long long)max1*(long long)max2;

	//cout<<max1<<" "<<max2<<endl;

	cout<<s<<endl;

}