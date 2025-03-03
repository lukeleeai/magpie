#include<iostream>

#include<cstdio>

#include<stack>

#include<queue>

#include<cstring>

#include<algorithm>

#include<cmath>

#include<set>

using namespace std;

#define N 200009

#define LL long long

#define INF 0x3f3f3f3f

#define mymin(x,y) (x>=y?y:x)

#define mymax(x,y) (x>=y?x:y)

int A[N], tong[N], be[N], af[N], mark[N];

int main() {

	std::ios::sync_with_stdio(0); std::cin.tie(0);

	LL n, k;

	cin >> n >> k;

	for(int i = 1; i <= n; i++){

		cin >> A[i];

	}

	for(int i = 1; i <= n; i++){

		if(tong[A[i]] == 0) tong[A[i]] = i;

		else{

			be[i] = tong[A[i]];

			af[tong[A[i]]] = i;

			tong[A[i]] = i;

		}

	}

	for(int i = 1; i <= n; i++){

		if(be[i] == 0 && af[i] != 0){

			be[i] = tong[A[i]];

			af[be[i]] = i;

		}

	}

	LL r = 1;

	int pos = 1;

	memset(mark, 0, sizeof(mark));

	while(!mark[pos]){

	//	cout << "debug1: round: " << r << " pos: " << pos << endl;

		mark[pos] = r;

		if(af[pos] == 0){

			r++;   

			pos++;

				if(pos > n) pos = 1, r++;

		}

		else if(af[pos] < pos){

			r++;

			pos = af[pos] + 1;

		}	

		else if(af[pos] == n){

			r++;

			pos = 1;

		}

		else{

			pos = af[pos] + 1;

		}

	}

	if(k <= r){

		r = 1;

		pos = 1;

		while(r < k){

			if(af[pos] == 0){

				r++;   

				pos++;

				if(pos > n) pos = 1, r++;

			}

			else if(af[pos] < pos){

				r++;

				pos = af[pos] + 1;

			}	

			else if(af[pos] == n){

				r++;

				pos = 1;

			}

			else{

				pos = af[pos] + 1;

			}

		}

		while(pos <= n){

			while(pos <= n && af[pos] != 0 && af[pos] > pos){

				pos = af[pos] + 1;

			}

			if(pos <= n)

				cout << A[pos] << " ";

			pos++;

		}

		return 0;

	}

	int res = ((k - r) % (r - (LL)mark[pos]));

	r = 0;

	while(r < res){

		if(af[pos] == 0){

			r++;   

			pos++;

				if(pos > n) pos = 1, r++;

		}

		else if(af[pos] < pos){

			r++;

			pos = af[pos] + 1;

		}	

		else if(af[pos] == n){

			r++;

			pos = 1;

		}

		else{

			pos = af[pos] + 1;

		}

	}

	while(pos <= n){

		while(pos <= n && af[pos] != 0 && af[pos] > pos){

			pos = af[pos] + 1;

		}

		if(pos <= n)

			cout << A[pos] << " ";

		pos++;

	}

	return 0;

}



	//		cout << "debug2: round: " << r << " pos: " << pos << endl;

	//		cout << "debug3: round: " << r << " pos: " << pos << endl;

				//cout << "out: " << A[pos] << endl;