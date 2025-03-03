#include "stdc++.h"

using namespace std;

typedef long long ll;

#define P pair<int,int>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)

#define FORR(I,A,B) for(int I = ((B)-1); I >= (A); --I)

#define TO(x,t,f) ((x)?(t):(f))

#define SORT(x) (sort(x.begin(),x.end())) // 0 2 2 3 4 5 8 9

#define REV(x) (reverse(x.begin(),x.end())) //reverse

int gcd(int a,int b){if(a<b)swap(a,b);if(a%b==0)return b;return gcd(b,a%b);}

int lcm(int a,int b){int c=gcd(a,b);return ((a/c)*(b/c)*c);}//saisyo kobaisu

#define NEXTP(x) next_permutation(x.begin(),x.end())

const ll INF=1e18+7;

const ll MOD=1e9+7;

#define pri(a) cout << (a) << endl



int kosu[101];

void addkosu(int k){

	int a = k;

	FOR(i,2,k+1){

		while(a%i==0){

			a/=i;

			kosu[i]++;

		}

	}

}





int main(){

	ios::sync_with_stdio(false);

	cin.tie(0);

	int n;

	cin >> n;

	FOR(i,2,n+1)addkosu(i);

	int ans = 0;

	FOR(i,2,101){

		FOR(j,2,101){

			FOR(k,j+1,101){

				if(i==k||j==k||i==j)continue;

				if(kosu[i]>=2&&kosu[j]>=4&&kosu[k]>=4)ans++;

			}

		}

	}

	FOR(i,2,101){

		if(kosu[i]>=74)ans++;

		FOR(j,2,101){

			if(i==j)continue;

			if(kosu[i]>=14&&kosu[j]>=4)ans++;

			if(kosu[i]>=2&&kosu[j]>=24)ans++;

		}

	}

	cout << ans << endl;

}