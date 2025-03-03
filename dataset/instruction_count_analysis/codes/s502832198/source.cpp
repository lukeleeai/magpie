#include "stdc++.h"

using namespace std;



typedef unsigned long long ull;

typedef long long ll;

typedef pair<int, int> pii;

typedef pair<ll, ll> pll;

typedef pair<double, double> pdd;

const ull mod = 1000000000 + 7;

#define REP(i,n) for(int i=0;i<(int)n;++i)

ll N, A, B;

vector<ll> h(100005);



bool check(ll num){

    ll a = 0;

    REP(i, N){

        ll b = h[i] - B*num;

        if(b>0){

            a += ((b+A-B-1)/(A-B));

        }

    }

    //cout << num << " " << a << " " << (a<=num) <<endl;

    return (a<=num);

}



ll binarySearch(ll start, ll end){

    if(start+1==end) return end;

    ll mid = (start+end)/2;

    if(check(mid)){

        return binarySearch(start, mid);

    }else{

        return binarySearch(mid, end);

    }

}



int main(){

    cin >> N >> A >> B;

    REP(i, N) cin >> h[i];

    cout << binarySearch(-1, 10000000005) << endl;

    return 0;

}