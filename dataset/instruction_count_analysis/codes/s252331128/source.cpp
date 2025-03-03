#include <cstdio>

#include <vector>

#include <iostream>

#include <cmath>

#define INF 500000+500

#define Max 0x3f3f3f3f

#define Mod 1000000007

typedef long long int ll;

using namespace std;

ll arr[INF],brr[INF];

ll sum1[INF];

int main() 

{

	ll n;

	cin >> n;

	ll t = n+1;

	for(int i=1; i<=t; i++) {

		cin >> arr[i];

	}

	ll cnt=0;

	for(int i=1; i<=n; i++) {

		cin >> brr[i];

		if(brr[i]<=arr[i])	cnt+=brr[i];

		else if(brr[i]<=arr[i]+arr[i+1]) {

			cnt += brr[i];

			arr[i+1] -= brr[i]-arr[i];

		}else{

			cnt += arr[i]+arr[i+1];

			arr[i+1] = 0;

		}

	}

	cout << cnt << endl;

	

	

	

	

    return 0;

}