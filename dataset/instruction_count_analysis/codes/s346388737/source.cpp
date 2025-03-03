#include<iostream>

#include<vector>

#include<algorithm>

#include<functional>

using namespace std;

	bool is(int x){

		for(int i=2;i*i<=x;i++)if(x%i==0)return false;

		return true;

	}

int main(){

	int n,p;



	while(cin>>n>>p,n!=-1||p!=-1){

		int cnt=0;

		n++;

		if(n==1)n++;

		vector<int>primes;

		vector<int>sums;

		while(true){

			if(is(n)){

				cnt++;

				primes.push_back(n);

			}

			if(cnt==78)break;

			n++;

		}

		//for(int i=0;i<primes.size();i++)cout<<primes[i]<<endl;

		for(int i=0;i<primes.size();i++){

			for(int j=0;j<primes.size();j++){

				if(j>primes.size())break;

				if(i<j)break;

				sums.push_back(primes[i]+primes[j]);

			}

		}

		sort(sums.begin(),sums.end());

		cout<<sums[p-1]<<endl;

	}

	return 0;

}