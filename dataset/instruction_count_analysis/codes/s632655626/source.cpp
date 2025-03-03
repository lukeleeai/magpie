#include<iostream>

#include<stdio.h>

#include<algorithm>

#include<vector>

#include<string.h>

#include<math.h>

#include<map>

#include<iomanip>



#define MOD 1e9+7;

#define INF 1e17+9;

#define PI acos(-1);



using namespace std;



int main() {

	

	vector<double> p(1001,0);

	for(int i=1;i<=1000;i++){

		p[i]+=((double)(i)+1)/2;

	}

	

	int n,k;

	cin >> n >> k;

	vector<double> a(n);

	

	for(int i=0;i<n;i++){

		cin >> a[i];

	}

	

	double tot=0,ans=0;

	for(int i=0;i<k;i++){

		tot+=p[a[i]];

	}

	ans=tot;

	

	for(int i=k;i<n;i++){

		tot+=p[a[i]];

		tot-=p[a[i-k]];

		ans=max(ans,tot);

	}

	

	cout << fixed << setprecision(12) << ans << endl;

	return 0;

}


