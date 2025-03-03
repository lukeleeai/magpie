#include <iostream> 

using namespace std;

const int maxn = 100005;

int GCD(int a, int b){ return b ? GCD(b, a % b) : a; }

int A[maxn],l[maxn], r[maxn];

int main(){

	int N; cin >> N;

	for(int i = 0; i < N; ++i) cin >> A[i];

	for(int i = 0; i < N; ++i) {

		l[i+1] = GCD(l[i], A[i]);

	}

	for(int i = N-1; i >= 0; --i){

		r[i] = GCD(r[i+1], A[i]);

	}

 

	int max = 0;

	for(int i = 0; i < N; ++i){

		int ll = l[i], rr = r[i+1];

		int g = GCD(ll, rr);

		if(max < g) max = g;

	}

	cout << max << endl;

	return 0;

}