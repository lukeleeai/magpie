#include<iostream>

#include<string>

#include<queue>

#include<algorithm>

#include<map>

#include<set>

#include<vector>

#include<math.h>



using namespace std;



#define INF 1000000007

#define LINF (1LL << 62)



typedef long long i64;

typedef pair<i64,i64> P;





int n, t[202], v[202];

vector<int> ma(202020,INF);

double ans = 0;



int main(){

	cin >> n;

	int T = 0;

	for(int i = 0; i < n; i++){

		cin >> t[i];

		T += t[i]*2;

	}

	int now = 0;

	for(int i = 0; i < n; i++){

		cin >> v[i];

		for(int j = 0; j <= t[i]*2; j++){

			ma[now] = min(v[i]*2, ma[now]);

			now++;

		}

		now--;

	}

	

	for(int i = 0; i <= T; i++){

		ma[i] = min(min(T-i,i), ma[i]);

	}

	for(int i = 0; i <= T; i++){

		if(i != 0){

			if(ma[i-1] < ma[i]-1){

				ma[i] = ma[i-1]+1;

			}

			if(ma[T+1-i] < ma[T-i]-1){

				ma[T-i] = ma[T+1-i]+1;

			}

		}

	}

	for(int i = 0; i <= T; i++){

		ans += ma[i];

	}

	printf("%.10f\n", ans/4);

	

	return 0;

}