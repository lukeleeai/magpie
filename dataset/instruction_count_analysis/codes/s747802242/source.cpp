#include"stdc++.h"



using namespace std;

#define REPP(i,a,b,c) for(int i=a; i<=b; i+=c)

#define REP(i,a,b) REPP(i,a,b,1)

#define REVV(i,a,b,c) for(int i=a; i>=b; i-=c)

#define REV(i,a,b) REVV(i,a,b,1)

#define FOR(i,a) REP(i,0,(int)a-1)

#define FORD(i,a) REV(i,(int)a-1,0)

#define PB push_back

#define POB pop_back

#define MP make_pair

#define FI first

#define SE second

typedef long long ll;

typedef unsigned long long ull;

typedef pair < int , int > pii;

typedef vector < int > vi;

typedef vector < pii > vii;

typedef vector < ll > vl;



const double EPS = 1e-9;

const double PI = acos(-1);

const int INF = 1e9;

const ll MOD = 1e9 + 7;



ll addMod(ll a, ll b){

	return (a+b) % MOD;

}



ll mulMod(ll a, ll b){

	return (a*b) % MOD;

}



/////////////////////////////////////////////////////////



const int N = 1e5;



string str;



int solve(){

	int cnt = 0, cnt2 = 1, ret = 0;

	if(str[0] == 'p') ret++;

	REP(i,1,str.length()-1){

		if(str[i] == 'p'){

			if(cnt+1 <= cnt2){

				cnt++;

			}

			else{

				cnt2++;

				ret--;

			}

		}

		else{

			if(cnt+1 <= cnt2){

				cnt++;

				ret++;

			}

			else cnt2++;

		}

//		printf("cnt %d, cnt2 %d -> %d\n",cnt,cnt2,ret);

	}

	return ret;

}



int main(){

	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> str;

	cout << solve() << endl;

	return 0;

}