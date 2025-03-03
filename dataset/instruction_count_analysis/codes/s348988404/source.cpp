#include<iostream> 

#include<algorithm>

#include<map>

#include <cstdlib>

using namespace std;



int main(){

    int n;

    cin>>n;

    long long r=1,a[100005];

    for(int i=0;i<n;i++){

    	cin>>a[i];

	}

	sort(a,a+n);

	if(a[0]==0){

		cout<<0;

		return 0;

	}

	for(int i=n-1;i>=0;i--){

		if(1000000000000000000/a[i]>=r) r*=a[i];

		else{

			cout<<-1;

			return 0;

		}

	}

	cout<<r;

    return 0;

}