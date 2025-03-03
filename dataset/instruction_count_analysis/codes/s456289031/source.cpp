#include"stdc++.h"



using namespace std;



#define INF 1000000007

#define LINF (1LL << 60)

#define PI 3.14159265358979



typedef long long i64;

typedef pair<i64,i64> P;



inline i64 mod(i64 a, i64 m) { return (a % m + m) % m; }



template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }







int n, t[101], d[101], v[101];

int sp[40404];

void solve(){

	cin >> n;

	for(int i = 1; i <= n; i++){

		cin >> t[i];

		t[i] *= 2;

		d[i] = d[i-1]+t[i];

	}

	for(int i = 1; i <= n; i++){

		cin >> v[i];

		v[i] *= 2;

		fill(sp+d[i-1], sp+d[i], v[i]); //max

	}

	

	for(int i = 1; i <= n; i++){

		if(v[i] > v[i-1]){

			for(int j = d[i-1]; j < d[i]; j++){

				chmin(sp[j], v[i-1]+j-d[i-1]);

			}

		}

		if(v[i] > v[i+1]){

			for(int j = d[i+1]; j >= d[i]; j--){

				chmin(sp[j], v[i+1]+d[i+1]-j);

			}

		}

	}

	for(int i = 1; i < d[n]; i++){

		chmin(sp[i], sp[i-1]+1);

	}

	for(int i = d[n]; i > 0; i--){

		chmin(sp[i], sp[i+1]+1);

	}

	

	i64 ans = 0;

	for(int i = 1; i < d[n]; i++){

		ans += sp[i];

		

	}

	printf("%.10f\n", ans/4.0);

}



int main(){

	std::cin.tie(0);

	std::ios::sync_with_stdio(false);

	int t = 1;

	//cin >> t;

	while(t--){

		solve();

	}

	

	return 0;

}
