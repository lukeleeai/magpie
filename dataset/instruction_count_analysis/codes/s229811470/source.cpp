#include "stdc++.h"

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)

#define REPD(i,n) for(ll i=n-1;i>=0;i--)

#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)

#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)

#define ALL(x) (x).begin(),(x).end() 

#define SIZE(x) ((ll)(x).size())

#define MAX(x) *max_element(ALL(x))

#define MIN(x) *min_element(ALL(x))

#define INF 1000000000

using namespace std;

typedef long long ll;



const ll M = 998244353;

vector<ll> fac(300001);

vector<ll> ifac(300001);



int Combination(int n, int r){

        int num = 1;

        for(int i = 1; i <= r; i++){

            num = num * (n - i + 1) / i;

        }

        return num;

    }



int main(void)

{

    int N, M;

    cin >> N >> M;

    

    int ans = 0;

    ans += Combination(N, 2);

    ans += Combination(M, 2);





    cout << ans << endl;

}