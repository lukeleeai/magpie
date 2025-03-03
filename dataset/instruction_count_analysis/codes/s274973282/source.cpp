#include <iostream>

#include <algorithm>

#include <cstdio>

#include <cstdlib>

#include <sstream>

#include <cstring>

#include <string>

#include <vector>

#include <set>

#include <map>

#include <queue>

#include <numeric>

#include <functional>

#include <cmath>

#include <array>



#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)

#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)

#define repr(x,fr,to) for(int (x)=(fr);(x)>=(to);(x)--)

#define all(c) (c).begin(),(c).end()

#define sz(v) (int)(v).size()



using namespace std;

typedef long long ll; typedef vector<int> VI;

typedef pair<int,int> pii;

const int mod = (int)1e9+7;



ll cp[2520][52], nx[2520][52];



int main()

{

	

	cin.tie(0); ios_base::sync_with_stdio(false);

	int n, a;

	cin >>n >>a;

	VI x(n);

	rep(i,n) cin >> x[i];

	

	memset(cp, 0, sizeof cp);

	cp[0][0]=1;

	

	rep(i, n){

		memset(nx, 0, sizeof nx);

		rep(j, a*n) rep(k,n) {

			nx[j][k] += cp[j][k];

			if( j+x[i] <= a*n ) nx[j+x[i]][k+1] += cp[j][k];

		}

		swap(cp, nx);

	}

	

	ll ans =0;

	rep(i, a*n+1) rep2(j,1,n+1){

		if(i==j*a){

			ans += cp[i][j];

			//printf("%d:%d:%lld  ",i,j,cp[i][j]);

		}

	}

	cout << ans <<endl;

	

	return 0;

}
