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





int main()

{

	

	cin.tie(0); ios_base::sync_with_stdio(false);

	int n, a;

	cin >>n >>a;

	VI x(n);

	rep(i,n) cin >> x[i];

	int smp=0, smm=0;

	rep(i,n){ if(a-x[i]<0) smm += a-x[i]; else smp += a-x[i];}

	int KJ =  max(abs(smp), abs(smm)) + 100;

	vector<ll> cp( KJ*2, 0);

	cp[KJ] = 1;

	auto np = cp;

	rep(i, n){

		rep2(j, KJ + smm - 2,  KJ + smp + 2) if(cp[j]>0){

			np[j + a -x[i]] += cp[j];

		}

		cp = np;

	}

	

	cout << cp[KJ] - 1 <<endl;

	return 0;

}