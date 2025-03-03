#include <map>

#include <set>

#include <list>

#include <ctime>

#include <cmath>

#include <queue>

#include <stack>

#include <bitset>

#include <vector>

#include <cstdio>

#include <string>

#include <cstring>

#include <sstream>

#include <iomanip>

#include <cstdlib>

#include <iostream>

#include <algorithm>

using namespace std;

#define Size(x) ((int)(x).size())

const int INF = 1e9 + 10 , MN = 2e5 + 10 , LG = 222;

const long long BIG = 1000ll*1000*1000*1000*1000*1000 + 10;

int n , nxt[MN];

string s;

long long Nx[LG] , Ny[LG] , X[33][LG] , Y[33][LG];

int ps[33][MN];

void prep() {

	int cur = 0;

	for(int i=1;i<n;++i){

		while(cur && s[i] != s[cur]) cur = nxt[cur];

		cur += (s[i] == s[cur]);

		nxt[i+1] = cur;

	}

	Nx[0] = n - nxt[n] , Ny[0] = nxt[n];

	for(int i=0;i<Nx[0];++i)

		X[s[i]-'a'][0]++;

	for(int i=Nx[0];i<n;++i)

		Y[s[i]-'a'][0]++;

	for(int i=1;i<LG;++i){

		Nx[i] = Nx[i-1] + Ny[i-1];

		Nx[i] = min(Nx[i] , BIG);

		Ny[i] = Nx[i-1];

		for(int j=0;j<26;++j){

			X[j][i] = X[j][i-1] + Y[j][i-1];

			Y[j][i] = X[j][i-1];

			X[j][i] = min(X[j][i] , BIG);

		}

	}

	for(int i=0;i<n;++i)

		for(int j=0;j<26;++j)

			ps[j][i+1] = ps[j][i] + (s[i]-'a' == j);

}

long long get(long long val,int c) {

	for(int i=LG-1;~i;--i)

		if(Nx[i] <= val) return min(BIG , X[c][i] + get(val - Nx[i] , c));

	return ps[c][val];

}

int main() {

	cin>>s;

	n = Size(s)/2;

	prep();

	long long l , r;

	cin >> l >> r;

	for(int c=0;c<26;++c) cout << get(r , c) - get(l-1 , c) << ' ';

	puts("");

	return 0;

}

/*

Input



abaaba

6 10



Output



3 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0



Input



xx

1 1000000000000000000



Output



0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1000000000000000000 0 0



Input



vgxgpuamkvgxgvgxgpuamkvgxg

1 1000000000000000000



Output



87167725689669676 0 0 0 0 0 282080685775825810 0 0 0 87167725689669676 0 87167725689669676 0 0 87167725689669676 0 0 0 0 87167725689669676 141040342887912905 0 141040342887912905 0 0

*/