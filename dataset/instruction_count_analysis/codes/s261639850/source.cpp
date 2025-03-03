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

		for(int j=1;j<=i;j++){

			p[i]+=(double)(j)/(double)(i);

		}

	}

	

	int n,k;

	cin >> n >> k;

	vector<double> a(n);

	

	for(int i=0;i<n;i++){

		cin >> a[i];

	}

	

	double tot=0;

	for(int i=0;i<k;i++){

		tot+=p[a[i]];

	}

	double ans=tot;

	

	for(int i=k;i<n;i++){

		tot+=p[a[i]];

		tot-=p[a[i-k]];

		ans=max(ans,tot);

	}

	

	cout << fixed << setprecision(12) << ans << endl;

	return 0;

}
