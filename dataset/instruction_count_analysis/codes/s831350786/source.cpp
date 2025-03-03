#include"stdc++.h"

using namespace std;



typedef long long LL;



const LL MOD = 1e9+7;



inline LL dmod(LL x){

	return x%MOD;

}



int n,c;



LL pang[405][405];

LL ps[405][405];



void pre(){

	for(int i=0;i<=400;i++) pang[i][0] = 1LL;

	for(int i=1;i<=400;i++){

		for(int j=1;j<=400;j++){

			pang[i][j] = dmod(pang[i][j-1]*(LL)i);

		}

	}

	for(int i=0;i<=400;i++) ps[0][i] = pang[0][i];

	for(int i=1;i<=400;i++){

		for(int j=0;j<=400;j++){

			ps[i][j] = dmod(ps[i-1][j] + pang[i][j]);

		}

	}

}



//int n,c;

int A[405],B[405];



LL memo[405][405];



LL dp(int id, int sisa){

	if(id > n){

		if(sisa == 0) return 1LL;

		else return 0LL;

	}

	LL &ret = memo[id][sisa];

	if(ret!=-1) return ret;

	ret = 0LL;

	for(int i=0;i<=sisa;i++){

		ret = dmod(ret+dmod(dp(id+1,sisa-i)*dmod(ps[B[id]][i] - ps[A[id]][i]+MOD)));

	}

	return ret;

}



int main(){

	pre();

//	for(int i=0;i<=5;i++){

//		for(int j=0;j<=5;j++){

//			cout << ps[i][j] << " ";

//		}

//		cout << endl;

//	}

	memset(memo,-1,sizeof(memo));

	cin >> n >> c;

	for(int i=1;i<=n;i++){

		cin >> A[i];

		A[i]--;

	}

	for(int i=1;i<=n;i++){

		cin >> B[i];

	}

	LL ans = dp(1,c);

	cout << ans << endl;

	return 0;

}